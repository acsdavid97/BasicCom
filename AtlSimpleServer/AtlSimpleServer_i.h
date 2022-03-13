

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 05:14:07 2038
 */
/* Compiler settings for AtlSimpleServer.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __AtlSimpleServer_i_h__
#define __AtlSimpleServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyObject_FWD_DEFINED__
#define __IMyObject_FWD_DEFINED__
typedef interface IMyObject IMyObject;

#endif 	/* __IMyObject_FWD_DEFINED__ */


#ifndef __MyObject_FWD_DEFINED__
#define __MyObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class MyObject MyObject;
#else
typedef struct MyObject MyObject;
#endif /* __cplusplus */

#endif 	/* __MyObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyObject_INTERFACE_DEFINED__
#define __IMyObject_INTERFACE_DEFINED__

/* interface IMyObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ab332f20-7d60-4110-a682-92b095d4a4b8")
    IMyObject : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetValue( 
            /* [retval][out] */ int *Value) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ int Value) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IMyObject * This,
            /* [retval][out] */ int *Value);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IMyObject * This,
            /* [in] */ int Value);
        
        END_INTERFACE
    } IMyObjectVtbl;

    interface IMyObject
    {
        CONST_VTBL struct IMyObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyObject_GetValue(This,Value)	\
    ( (This)->lpVtbl -> GetValue(This,Value) ) 

#define IMyObject_SetValue(This,Value)	\
    ( (This)->lpVtbl -> SetValue(This,Value) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyObject_INTERFACE_DEFINED__ */



#ifndef __AtlSimpleServerLib_LIBRARY_DEFINED__
#define __AtlSimpleServerLib_LIBRARY_DEFINED__

/* library AtlSimpleServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AtlSimpleServerLib;

EXTERN_C const CLSID CLSID_MyObject;

#ifdef __cplusplus

class DECLSPEC_UUID("579bca31-7ab8-4503-a43d-908853213360")
MyObject;
#endif
#endif /* __AtlSimpleServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


