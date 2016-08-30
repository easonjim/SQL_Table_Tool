// SQL_Table_ToolDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_SQL_TABLE_TOOLDLG_H__ED224E05_40FE_4390_8849_3DCBF8854E4D__INCLUDED_)
#define AFX_SQL_TABLE_TOOLDLG_H__ED224E05_40FE_4390_8849_3DCBF8854E4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSQL_Table_ToolDlg dialog

class CSQL_Table_ToolDlg : public CDialog
{
// Construction
public:
	CString DBConStr;//定义DATABASE连接字符串
	void InitDlg();
	CSQL_Table_ToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSQL_Table_ToolDlg)
	enum { IDD = IDD_SQL_TABLE_TOOL_DIALOG };
	CIPAddressCtrl	m_IP;
	CAdodc	m_DatabaseADO;
	CAdodc	m_ETableADO;
	CAdodc	m_TableADO;
	CDataGrid	m_DatabaseDG;
	CDataGrid	m_ETableDG;
	CDataGrid	m_TableDG;
	CString	m_User;
	CString	m_Password;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSQL_Table_ToolDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSQL_Table_ToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMoveCompleteAdodcDatabase(long adReason, LPDISPATCH pError, long FAR* adStatus, LPDISPATCH pRecordset);
	afx_msg void OnMoveCompleteAdodcTable(long adReason, LPDISPATCH pError, long FAR* adStatus, LPDISPATCH pRecordset);
	afx_msg void OnRadioLocal();
	afx_msg void OnRadioRemote();
	afx_msg void OnButtonLink();
	afx_msg void OnButtonCancel();
	afx_msg UINT OnNcHitTest(CPoint point);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SQL_TABLE_TOOLDLG_H__ED224E05_40FE_4390_8849_3DCBF8854E4D__INCLUDED_)
