// MFCLibraryNativeTest.h : main header file for the MFCLibraryNativeTest DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCLibraryNativeTestApp
// See MFCLibraryNativeTest.cpp for the implementation of this class
//

class CMFCLibraryNativeTestApp : public CWinApp
{
public:
	CMFCLibraryNativeTestApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	
};
