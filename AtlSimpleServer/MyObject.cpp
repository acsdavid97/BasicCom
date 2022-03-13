// MyObject.cpp : Implementation of CMyObject

#include "pch.h"
#include "MyObject.h"


// CMyObject

HRESULT STDMETHODCALLTYPE CMyObject::GetValue(int* Value)
{
    *Value = valueStored;
    return S_OK;
}

HRESULT STDMETHODCALLTYPE CMyObject::SetValue(int Value)
{
    valueStored = Value;
    return S_OK;
}
