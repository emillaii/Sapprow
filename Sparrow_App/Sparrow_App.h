
// Sparrow_App.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSparrowAppApp:
// See Sparrow_App.cpp for the implementation of this class
//

class CSparrowAppApp : public CWinApp
{
public:
	CSparrowAppApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSparrowAppApp theApp;
