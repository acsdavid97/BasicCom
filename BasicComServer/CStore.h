#ifndef _C_STORE_H
#define _C_STORE_H

#include "IStore.h"

typedef struct _CStore
{
    IStore StoreInterface;
    volatile long RefCount;
    long StoredValue;
}CStore;

HRESULT _stdcall CStore_QueryInterface(IStore* This, REFIID Iid, void** ppv);
long _stdcall CStore_AddRef(IStore* This);
long _stdcall CStore_Release(IStore* This);

// IStore Interface
HRESULT _stdcall CStore_StoreValue(IStore* This, int ToBeStored);
HRESULT _stdcall CStore_RetriveValue(IStore* This, int* ValueRetrived);

extern struct IStore_Vtbl IStoreVtbl;

#endif // !_C_STORE_H
