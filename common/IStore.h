#ifndef _I_STORE_H_
#define _I_STORE_H_

#include <objbase.h>


// {64D05A68-688A-4C46-B351-7B78810EC80D}
DEFINE_GUID(IID_IStore,
    0x64d05a68, 0x688a, 0x4c46, 0xb3, 0x51, 0x7b, 0x78, 0x81, 0xe, 0xc8, 0xd);

// {9B2C0AFC-788B-49CB-AEC0-0EB6061D105A}
DEFINE_GUID(CLSID_CStore,
    0x9b2c0afc, 0x788b, 0x49cb, 0xae, 0xc0, 0xe, 0xb6, 0x6, 0x1d, 0x10, 0x5a);


typedef struct _IStore
{
    struct IStore_Vtbl* Vtbl;
}IStore;

struct IStore_Vtbl
{
    // IUnkown methods
    HRESULT (_stdcall* QueryInterface)(IStore* This, REFIID Iid, void** ppv);
    long (_stdcall* AddRef)(IStore* This);
    long (_stdcall* Release)(IStore* This);

    // IStore Interface
    HRESULT(_stdcall* StoreValue)(IStore* This, int ToBeStored);
    HRESULT (_stdcall* RetriveValue)(IStore* This, int* ValueRetrived);
};

#endif // _I_STORE_H_
