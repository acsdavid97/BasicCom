#include <stdio.h>

#include <initguid.h>
#include "IStore.h"


int main()
{
    HRESULT hres = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (FAILED(hres))
    {
        printf("CoInitializeEx failed with 0x%x\n", hres);
        return 0;
    }

    IStore* store = NULL;
    hres = CoCreateInstance(&CLSID_CStore, NULL, CLSCTX_INPROC_SERVER, &IID_IStore, &store);
    if (FAILED(hres))
    {
        printf("CoCreateInstance failed with 0x%x\n", hres);
        goto CleanUp;
    }

    hres = store->Vtbl->StoreValue(store, 123);
    if (FAILED(hres))
    {
        printf("StoreValue failed 0x%x\n", hres);
        goto CleanUp;
    }

    int myInt = 0;
    hres = store->Vtbl->RetriveValue(store, &myInt);
    if (FAILED(hres))
    {
        printf("RetriveValue failed 0x%x\n", hres);
        goto CleanUp;
    }

    printf("[SUCCESS] got: %d\n", myInt);

CleanUp:
    if (store)
    {
        store->Vtbl->Release(store);
    }
    CoUninitialize();

    return 0;
}