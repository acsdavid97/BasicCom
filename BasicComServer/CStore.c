#include "pch.h"
#include "CStore.h"
#include <intrin.h>

extern volatile long gCStore_Count;

HRESULT _stdcall CStore_QueryInterface(IStore* This, REFIID Iid, void** ppv)
{
    CStore* cStore = CONTAINING_RECORD(This, CStore, StoreInterface);
    if (IsEqualIID(Iid, &IID_IStore) || IsEqualGUID(Iid, &IID_IUnknown))
    {
        *ppv = &cStore->StoreInterface;
        cStore->StoreInterface.Vtbl->AddRef(This);
        return S_OK;
    }

    *ppv = NULL;
    return E_NOINTERFACE;
}

long _stdcall CStore_AddRef(IStore* This)
{
    CStore* cStore = CONTAINING_RECORD(This, CStore, StoreInterface);
    return InterlockedIncrement(&cStore->RefCount);
}

long _stdcall CStore_Release(IStore* This)
{
    CStore* cStore = CONTAINING_RECORD(This, CStore, StoreInterface);
    long refCount = InterlockedDecrement(&cStore->RefCount);
    if (refCount == 0)
    {
        free(cStore);
        InterlockedDecrement(&gCStore_Count);
    }

    return refCount;
}

// IStore Interface
HRESULT _stdcall CStore_StoreValue(IStore* This, int ToBeStored)
{
    CStore* cStore = CONTAINING_RECORD(This, CStore, StoreInterface);
    InterlockedExchange(&cStore->StoredValue, ToBeStored);
    return S_OK;
}

HRESULT _stdcall CStore_RetriveValue(IStore* This, int* ValueRetrived)
{
    CStore* cStore = CONTAINING_RECORD(This, CStore, StoreInterface);
    *ValueRetrived = InterlockedCompareExchange(&cStore->StoredValue, 0, 0);
    return S_OK;
}

struct IStore_Vtbl IStoreVtbl = {
    CStore_QueryInterface,
    CStore_AddRef,
    CStore_Release,
    CStore_StoreValue,
    CStore_RetriveValue
};
