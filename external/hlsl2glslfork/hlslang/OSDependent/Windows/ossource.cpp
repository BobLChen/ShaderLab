// Copyright (c) The HLSL2GLSLFork Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.txt file.


#include "osinclude.h"
//
// This file contains contains the window's specific functions
//

#if !(defined(_WIN32) || defined(_WIN64))
#error Trying to build a windows specific file in a non windows build.
#endif


//
// Thread Local Storage Operations
//
OS_TLSIndex OS_AllocTLSIndex()
{
	DWORD dwIndex = TlsAlloc();
	if (dwIndex == TLS_OUT_OF_INDEXES) {
		assert(0 && "OS_AllocTLSIndex(): Unable to allocate Thread Local Storage");
		return OS_INVALID_TLS_INDEX;
	}

	return dwIndex;
}


bool OS_SetTLSValue(OS_TLSIndex nIndex, void *lpvValue)
{
	if (nIndex == OS_INVALID_TLS_INDEX) {
		assert(0 && "OS_SetTLSValue(): Invalid TLS Index");
		return false;
	}

	if (TlsSetValue(nIndex, lpvValue))
		return true;
	else
		return false;
}


bool OS_FreeTLSIndex(OS_TLSIndex nIndex)
{
	if (nIndex == OS_INVALID_TLS_INDEX) {
		assert(0 && "OS_SetTLSValue(): Invalid TLS Index");
		return false;
	}

	if (TlsFree(nIndex))
		return true;
	else
		return false;
}
