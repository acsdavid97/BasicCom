// dllmain.h : Declaration of module class.

class CAtlSimpleServerModule : public ATL::CAtlDllModuleT< CAtlSimpleServerModule >
{
public :
	DECLARE_LIBID(LIBID_AtlSimpleServerLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLSIMPLESERVER, "{aa42b5da-da22-4210-8641-dc58cae2da5c}")
};

extern class CAtlSimpleServerModule _AtlModule;
