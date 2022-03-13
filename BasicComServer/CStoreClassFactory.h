#ifndef _C_STORE_CLASS_FACTORY_H_
#define _C_STORE_CLASS_FACTORY_H_

#include <objbase.h>

// {0CE608BE-9925-4B46-A555-F96868C7FCB9}
DEFINE_GUID(IID_CStoreCF,
    0xce608be, 0x9925, 0x4b46, 0xa5, 0x55, 0xf9, 0x68, 0x68, 0xc7, 0xfc, 0xb9);

// {5CBD2E58-2E3C-4964-BB8C-CD77411744E4}
DEFINE_GUID(CLSID_CStoreCF,
    0x5cbd2e58, 0x2e3c, 0x4964, 0xbb, 0x8c, 0xcd, 0x77, 0x41, 0x17, 0x44, 0xe4);


typedef struct _CStoreCF
{
    IClassFactory ClassFactoryInterface;
    volatile long RefCount;
}CStoreCF;

HRESULT _stdcall CStoreCF_QueryInterface(IClassFactory* This, REFIID Iid, void** ppv);
ULONG _stdcall CStoreCF_AddRef(IClassFactory* This);
ULONG _stdcall CStoreCF_Release(IClassFactory* This);

HRESULT CStoreCF_CreateInstance(IClassFactory* This, IUnknown* UnkOuter, REFIID Iid, void** ppv);
HRESULT CStoreCF_LockServer(IClassFactory* This, BOOL Lock);

extern struct IClassFactoryVtbl CStoreCFVtbl;

#endif // !_C_STORE_CLASS_FACTORY_H_
