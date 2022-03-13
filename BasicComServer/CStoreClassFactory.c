#include "pch.h"
#include "CStoreClassFactory.h"
#include "CStore.h"

extern volatile long gCStore_Count;
extern volatile long gLock_Count;

HRESULT _stdcall CStoreCF_QueryInterface(IClassFactory* This, REFIID Iid, void** ppv)
{
    CStoreCF* factory = CONTAINING_RECORD(This, CStoreCF, ClassFactoryInterface);
    if (IsEqualIID(Iid, &IID_IUnknown) || IsEqualIID(Iid, &IID_IClassFactory))
    {
        *ppv = &factory->ClassFactoryInterface;
        factory->ClassFactoryInterface.lpVtbl->AddRef(This);
        return S_OK;
    }

    *ppv = NULL;
    return E_NOINTERFACE;
}

ULONG _stdcall CStoreCF_AddRef(IClassFactory* This)
{
    CStoreCF* factory = CONTAINING_RECORD(This, CStoreCF, ClassFactoryInterface);
    return InterlockedIncrement(&factory->RefCount);
}

ULONG _stdcall CStoreCF_Release(IClassFactory* This)
{
    CStoreCF* factory = CONTAINING_RECORD(This, CStoreCF, ClassFactoryInterface);
    unsigned long refcount = InterlockedDecrement(&factory->RefCount);
    if (refcount == 0)
    {
        free(factory);
    }

    return refcount;
}

HRESULT CStoreCF_CreateInstance(IClassFactory* This, IUnknown* UnkOuter, REFIID Iid, void** ppv)
{
    UNREFERENCED_PARAMETER(This);

    if (UnkOuter)
    {
        return CLASS_E_NOAGGREGATION;
    }

    CStore* newCStore = (CStore*)malloc(sizeof(CStore));
    if (!newCStore)
    {
        return E_OUTOFMEMORY;
    }

    newCStore->StoreInterface.Vtbl = &IStoreVtbl;
    newCStore->StoredValue = 0;
    newCStore->RefCount = 1;
    HRESULT result = newCStore->StoreInterface.Vtbl->QueryInterface(&newCStore->StoreInterface, Iid, ppv);
    if (FAILED(result))
    {
        free(newCStore);
        return result;
    }

    newCStore->StoreInterface.Vtbl->Release(&newCStore->StoreInterface);

    InterlockedIncrement(&gCStore_Count);

    return S_OK;
}

HRESULT CStoreCF_LockServer(IClassFactory* This, BOOL Lock)
{
    UNREFERENCED_PARAMETER(This);

    if (Lock)
    {
        InterlockedIncrement(&gLock_Count);
    }
    else
    {
        InterlockedDecrement(&gLock_Count);
    }

    return S_OK;
}

struct IClassFactoryVtbl CStoreCFVtbl = {
    CStoreCF_QueryInterface,
    CStoreCF_AddRef,
    CStoreCF_Release,
    CStoreCF_CreateInstance,
    CStoreCF_LockServer
};