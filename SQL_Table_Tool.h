// SQL_Table_Tool.h : main header file for the SQL_TABLE_TOOL application
//

#if !defined(AFX_SQL_TABLE_TOOL_H__0E574E6C_C153_4B78_97E9_DD1C89A7AFBB__INCLUDED_)
#define AFX_SQL_TABLE_TOOL_H__0E574E6C_C153_4B78_97E9_DD1C89A7AFBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSQL_Table_ToolApp:
// See SQL_Table_Tool.cpp for the implementation of this class
//

class CSQL_Table_ToolApp : public CWinApp
{
public:
	CSQL_Table_ToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQL_Table_ToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSQL_Table_ToolApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQL_TABLE_TOOL_H__0E574E6C_C153_4B78_97E9_DD1C89A7AFBB__INCLUDED_)
