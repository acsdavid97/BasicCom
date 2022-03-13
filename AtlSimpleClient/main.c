#include <stdio.h>

#include "d:\tmp\BasicCom\AtlSimpleServer\AtlSimpleServer_i.h"

int main()
{
    HRESULT hres = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (FAILED(hres))
    {
        printf("CoInitializeEx failed with 0x%x\n", hres);
        return 0;
    }

    IMyObject* store = NULL;
    hres = CoCreateInstance(&CLSID_MyObject, NULL, CLSCTX_LOCAL_SERVER, &IID_IMyObject, &store);
    if (FAILED(hres))
    {
        printf("CoCreateInstance failed with 0x%x\n", hres);
        goto CleanUp;
    }

    hres = store->lpVtbl->SetValue(store, 123);
    if (FAILED(hres))
    {
        printf("SetValue failed 0x%x\n", hres);
        goto CleanUp;
    }

    int myInt = 0;
    hres = store->lpVtbl->GetValue(store, &myInt);
    if (FAILED(hres))
    {
        printf("GetValue failed 0x%x\n", hres);
        goto CleanUp;
    }

    printf("[SUCCESS] got: %d\n", myInt);

CleanUp:
    if (store)
    {
        store->lpVtbl->Release(store);
    }
    CoUninitialize();

    return 0;
}