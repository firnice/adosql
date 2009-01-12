// AdoSQL.h : main header file for the ADOSQL application
//

#if !defined(AFX_ADOSQL_H__C93E6EAE_C1ED_4C73_9603_941E87D2A369__INCLUDED_)
#define AFX_ADOSQL_H__C93E6EAE_C1ED_4C73_9603_941E87D2A369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdoSQLApp:
// See AdoSQL.cpp for the implementation of this class
//

class CAdoSQLApp : public CWinApp
{
public:
	CAdoSQLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoSQLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdoSQLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSQL_H__C93E6EAE_C1ED_4C73_9603_941E87D2A369__INCLUDED_)
