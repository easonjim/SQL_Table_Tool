// SQL_Table_ToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SQL_Table_Tool.h"
#include "SQL_Table_ToolDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSQL_Table_ToolDlg dialog

CSQL_Table_ToolDlg::CSQL_Table_ToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSQL_Table_ToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSQL_Table_ToolDlg)
	m_User = _T("");
	m_Password = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSQL_Table_ToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSQL_Table_ToolDlg)
	DDX_Control(pDX, IDC_IPADDRESS_IP, m_IP);
	DDX_Control(pDX, IDC_ADODC_DATABASE, m_DatabaseADO);
	DDX_Control(pDX, IDC_ADODC_ETABLE, m_ETableADO);
	DDX_Control(pDX, IDC_ADODC_TABLE, m_TableADO);
	DDX_Control(pDX, IDC_DATAGRID_DATABASE, m_DatabaseDG);
	DDX_Control(pDX, IDC_DATAGRID_ETABLE, m_ETableDG);
	DDX_Control(pDX, IDC_DATAGRID_TABLE, m_TableDG);
	DDX_Text(pDX, IDC_EDIT_USER, m_User);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSQL_Table_ToolDlg, CDialog)
	//{{AFX_MSG_MAP(CSQL_Table_ToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_LOCAL, OnRadioLocal)
	ON_BN_CLICKED(IDC_RADIO_REMOTE, OnRadioRemote)
	ON_BN_CLICKED(IDC_BUTTON_LINK, OnButtonLink)
	ON_BN_CLICKED(IDC_BUTTON_CANCEL, OnButtonCancel)
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSQL_Table_ToolDlg message handlers

BOOL CSQL_Table_ToolDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CSQL_Table_ToolDlg::InitDlg();//初始化BUTTON状态

	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSQL_Table_ToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSQL_Table_ToolDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSQL_Table_ToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BEGIN_EVENTSINK_MAP(CSQL_Table_ToolDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CSQL_Table_ToolDlg)
	ON_EVENT(CSQL_Table_ToolDlg, IDC_ADODC_DATABASE, 201 /* MoveComplete */, OnMoveCompleteAdodcDatabase, VTS_I4 VTS_DISPATCH VTS_PI4 VTS_DISPATCH)
	ON_EVENT(CSQL_Table_ToolDlg, IDC_ADODC_TABLE, 201 /* MoveComplete */, OnMoveCompleteAdodcTable, VTS_I4 VTS_DISPATCH VTS_PI4 VTS_DISPATCH)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()


void CSQL_Table_ToolDlg::OnRadioLocal() 
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_IPADDRESS_IP))->EnableWindow(FALSE); //禁用编辑框状态
	((CEdit*)GetDlgItem(IDC_EDIT_USER))->EnableWindow(FALSE); 
	((CEdit*)GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(FALSE); 
}

void CSQL_Table_ToolDlg::OnRadioRemote() 
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_IPADDRESS_IP))->EnableWindow(TRUE); //启动编辑框状态
	((CEdit*)GetDlgItem(IDC_EDIT_USER))->EnableWindow(TRUE); 
	((CEdit*)GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(TRUE);
}

void CSQL_Table_ToolDlg::InitDlg()//初始化BUTTON状态
{
	((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->SetCheck(1);//初始化RADIO被选种
	((CEdit*)GetDlgItem(IDC_IPADDRESS_IP))->EnableWindow(FALSE); //禁用编辑框状态
	((CEdit*)GetDlgItem(IDC_EDIT_USER))->EnableWindow(FALSE); 
	((CEdit*)GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(FALSE); 
}

void CSQL_Table_ToolDlg::OnButtonLink() 
{
	// TODO: Add your control notification handler code here
	((CEdit*)GetDlgItem(IDC_IPADDRESS_IP))->EnableWindow(FALSE); //禁用编辑框状态
	((CEdit*)GetDlgItem(IDC_EDIT_USER))->EnableWindow(FALSE); 
	((CEdit*)GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(FALSE); 
	((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->EnableWindow(FALSE);//禁用RADIO
	((CButton*)GetDlgItem(IDC_RADIO_REMOTE))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_LINK))->EnableWindow(FALSE);//禁用连接按钮
	if (((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->GetCheck()==1)//判断是否是本地还是远程
	{
		DBConStr.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=%s;Data Source=.","master");
		//AfxMessageBox(DBConStr);
		m_DatabaseADO.SetConnectionString(DBConStr);
		CString sql = "select Name from sysdatabases";
		m_DatabaseADO.SetCommandType(1);
		m_DatabaseADO.SetRecordSource(sql);
		m_DatabaseADO.Refresh();
		m_DatabaseDG.SetRefDataSource(m_DatabaseADO.GetRecordset());
	}
	else
	{
		UpdateData(TRUE);//获取控件变量
		CString strIP;
		m_IP.GetWindowText(strIP);//转换IP
		DBConStr.Format("Provider=SQLOLEDB.1;Password=%s;Persist Security Info=True;User ID=%s;Initial Catalog=%s;Data Source=%s",m_Password,m_User,"master",strIP);
	//	AfxMessageBox(DBConStr);
		m_DatabaseADO.SetConnectionString(DBConStr);
		CString sql = "select Name from sysdatabases";
		m_DatabaseADO.SetCommandType(1);
		m_DatabaseADO.SetRecordSource(sql);
		m_DatabaseADO.Refresh();
		m_DatabaseDG.SetRefDataSource(m_DatabaseADO.GetRecordset());
	}

}

void CSQL_Table_ToolDlg::OnButtonCancel() 
{
	// TODO: Add your control notification handler code here
	((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->EnableWindow(TRUE);//启用RADIO
	((CButton*)GetDlgItem(IDC_RADIO_REMOTE))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_LINK))->EnableWindow(TRUE);//启用连接按钮
	if (((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->GetCheck()==0)
	{	
		((CEdit*)GetDlgItem(IDC_IPADDRESS_IP))->EnableWindow(TRUE); //启用编辑框状态
		((CEdit*)GetDlgItem(IDC_EDIT_USER))->EnableWindow(TRUE); 
		((CEdit*)GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(TRUE); 
	}
	

}


void CSQL_Table_ToolDlg::OnMoveCompleteAdodcDatabase(long adReason, LPDISPATCH pError, long FAR* adStatus, LPDISPATCH pRecordset) 
{
	// TODO: Add your control notification handler code here
	try
	{
		_RecordsetPtr pRs;
		_variant_t varFld;
		CString sqlstr;
		pRs.CreateInstance(__uuidof(Recordset));
		pRecordset->QueryInterface(IID_IDispatch,(void **)&pRs);
		if (!pRs->adoEOF&&!pRs->BOF)
		{
			varFld = pRs->Fields->GetItem("Name")->Value;
			CString strName(_T(varFld.bstrVal));
			strName.TrimRight();
			if (((CButton*)GetDlgItem(IDC_RADIO_LOCAL))->GetCheck()==1)//判断是否是本地还是远程
			{
				DBConStr.Format("Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=%s;Data Source=.",strName);
			}
			else
			{
				CString strIP;
				m_IP.GetWindowText(strIP);//转换IP
				DBConStr.Format("Provider=SQLOLEDB.1;Password=%s;Persist Security Info=True;User ID=%s;Initial Catalog=%s;Data Source=%s",m_Password,m_User,strName,strIP);
			}
			m_TableADO.SetConnectionString(DBConStr);
			CString sqlstr = "select Name from sysobjects where xtype='u'";
			m_TableADO.SetCommandType(1);
			m_TableADO.SetRecordSource(sqlstr);
			m_TableADO.Refresh();
			m_TableDG.SetRefDataSource(m_TableADO.GetRecordset());
		}
	}catch(_com_error e)
	{
		MessageBox("错误！","提示",MB_OK);
	}
}

void CSQL_Table_ToolDlg::OnMoveCompleteAdodcTable(long adReason, LPDISPATCH pError, long FAR* adStatus, LPDISPATCH pRecordset) 
{
	// TODO: Add your control notification handler code here
	try
	{
		_RecordsetPtr pRs;
		_variant_t varFld;
		CString sqlstr;
		pRs.CreateInstance(__uuidof(Recordset));
		pRecordset->QueryInterface(IID_IDispatch,(void **)&pRs);
		if (!pRs->adoEOF&&!pRs->BOF)
		{
			varFld = pRs->Fields->GetItem("Name")->Value;
			CString strName(_T(varFld.bstrVal));
			strName.TrimRight();
			m_ETableADO.SetConnectionString(DBConStr);
			CString sqlstr;
			sqlstr.Format("select * from %s",strName);
			m_ETableADO.SetCommandType(1);
			m_ETableADO.SetRecordSource(sqlstr);
			m_ETableADO.Refresh();
			m_ETableDG.SetRefDataSource(m_ETableADO.GetRecordset());
		}
	}catch(_com_error e)
	{
		MessageBox("错误！","提示",MB_OK);
	}
}



BOOL CSQL_Table_ToolDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message==WM_KEYDOWN&&pMsg->wParam==VK_ESCAPE)//屏蔽EXC键
	{
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

UINT CSQL_Table_ToolDlg::OnNcHitTest(CPoint point) //设置鼠标在客户区可以移动真个对话框
{
	// TODO: Add your message handler code here and/or call default
	CRect rc;
   	GetClientRect(&rc);
	ClientToScreen(&rc);
  	return rc.PtInRect(point) ? HTCAPTION : CDialog::OnNcHitTest(point);
}
