// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <initguid.h>
#include "CStore.h"
#include "CStoreClassFactory.h"
#include <strsafe.h>

volatile long gCStore_Count = 0;
volatile long gLock_Count = 0;

static CStoreCF* gClassFactory = NULL;

_Check_return_
STDAPI  DllGetClassObject(
    _In_ REFCLSID rclsid,
    _In_ REFIID riid,
    _Outptr_ LPVOID FAR* ppv
)
{
    if (!IsEqualIID(rclsid, &CLSID_CStore))
    {
        return CLASS_E_CLASSNOTAVAILABLE;
    }

    if (gClassFactory == NULL)
    {
        gClassFactory = (CStoreCF*)malloc(sizeof(CStoreCF));
        if (!gClassFactory)
        {
            return E_OUTOFMEMORY;
        }


        gClassFactory->ClassFactoryInterface.lpVtbl = &CStoreCFVtbl;
        gClassFactory->RefCount = 1;
    }

    return gClassFactory->ClassFactoryInterface.lpVtbl->QueryInterface(
        &gClassFactory->ClassFactoryInterface, riid, ppv);
}

__control_entrypoint(DllExport)
STDAPI DllCanUnloadNow(void)
{
    if (InterlockedCompareExchange(&gCStore_Count, 0, 0) == 0
        && InterlockedCompareExchange(&gLock_Count, 0, 0) == 0)
    {
        return S_OK;
    }
    return S_FALSE;
}

STDAPI DllRegisterServer(void)
{
    LPOLESTR cstoreGuidStr = NULL;
    HKEY clsidKey = NULL;
    HKEY clsidInProcServerKey = NULL;

    HRESULT hres = StringFromCLSID(&CLSID_CStore, &cstoreGuidStr);
    if (FAILED(hres))
    {
        printf("lol\n");
        return hres;
    }

    WCHAR regPathBuf[MAX_PATH] = { 0 };
    hres = StringCchPrintfW(regPathBuf, MAX_PATH, L"CLSID\\%ls", cstoreGuidStr);
    if (FAILED(hres))
    {
        printf("StringCchPrintfW 0x%x\n", hres);
        goto CleanUp;
    }

    HMODULE thisModule = GetModuleHandleW(L"BasicComServer");
    if (!thisModule)
    {
        hres = HRESULT_FROM_WIN32(GetLastError());
        printf("GetModuleHandleW failed with GLE: %d\n", GetLastError());
        goto CleanUp;
    }

    WCHAR modulePathBuf[MAX_PATH] = { 0 };
    if (!GetModuleFileNameW(thisModule, modulePathBuf, MAX_PATH))
    {
        hres = HRESULT_FROM_WIN32(GetLastError());
        printf("GetModuleFileNameW failed with GLE: %d\n", GetLastError());
        goto CleanUp;
    }

    LSTATUS status = RegCreateKeyExW(HKEY_CLASSES_ROOT, regPathBuf, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &clsidKey, NULL);
    if (status != ERROR_SUCCESS)
    {
        hres = HRESULT_FROM_WIN32(status);
        printf("RegCreateKeyExW 0x%x\n", status);
        goto CleanUp;
    }

    status = RegSetValueExW(clsidKey, NULL, 0, REG_SZ, (PBYTE)L"MyStore", sizeof(L"MyStore"));
    if (status != ERROR_SUCCESS)
    {
        hres = HRESULT_FROM_WIN32(status);
        printf("RegSetValueExW 0x%x\n", status);
        goto CleanUp;
    }

    status = RegCreateKeyExW(clsidKey, L"InProcServer32", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &clsidInProcServerKey, NULL);
    if (status != ERROR_SUCCESS)
    {
        hres = HRESULT_FROM_WIN32(status);
        printf("RegCreateKeyExW 0x%x\n", status);
        goto CleanUp;
    }

    DWORD dataLen = (lstrlenW(modulePathBuf) + 1) * sizeof(WCHAR);
    status = RegSetValueExW(clsidInProcServerKey, NULL, 0, REG_SZ, (PBYTE)modulePathBuf, dataLen);
    if (status != ERROR_SUCCESS)
    {
        hres = HRESULT_FROM_WIN32(status);
        printf("RegCreateKeyExW 0x%x\n", status);
        goto CleanUp;
    }

    hres = S_OK;

CleanUp:
    if (clsidInProcServerKey)
    {
        RegCloseKey(clsidInProcServerKey);
    }

    if (clsidKey)
    {
        RegCloseKey(clsidKey);
    }

    if (cstoreGuidStr)
    {
        CoTaskMemFree(cstoreGuidStr);
    }
    return hres;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    UNREFERENCED_PARAMETER(lpReserved);
    UNREFERENCED_PARAMETER(hModule);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        if (gClassFactory)
        {
            free(gClassFactory);
        }
        break;
    }
    return TRUE;
}
