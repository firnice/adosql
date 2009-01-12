// AdoSQLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdoSQL.h"
#include "AdoSQLDlg.h"


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
// CAdoSQLDlg dialog

CAdoSQLDlg::CAdoSQLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdoSQLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdoSQLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdoSQLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdoSQLDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdoSQLDlg, CDialog)
	//{{AFX_MSG_MAP(CAdoSQLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CON, OnBtnCon)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdoSQLDlg message handlers

BOOL CAdoSQLDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdoSQLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdoSQLDlg::OnPaint() 
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
HCURSOR CAdoSQLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdoSQLDlg::OnBtnCon() 
{
	// TODO: Add your control notification handler code here
	//然后进行下面的书写,必须要初始化COM

  ::CoInitialize(NULL);	
 _ConnectionPtr m_pConnection;//定义连个指针
 _RecordsetPtr  m_pRecordset;
    try
    {     
        m_pConnection.CreateInstance("ADODB.Connection");//具体的作用还没明白
        CString strConnectTmp;
        strConnectTmp.Format            ("Provider=SQLOLEDB;Server=.;Database=mydata;uid=sa;pwd=sa");
        _bstr_t strConnect=strConnectTmp;
        m_pConnection->Open(strConnect,"","",adModeUnknown);
        AfxMessageBox("连接成功!");
    }
    catch(_com_error e)//捕获异常
    {
        AfxMessageBox(e.Description());
    }	
	try
	{

		//创建记录集对象
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//取得表中的记录
		m_pRecordset->Open("SELECT *FROM student",m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockBatchOptimistic,adCmdText);
	}
	catch (_com_error e)
	{
		//异常 显示错误信息
		AfxMessageBox(e.Description());
	}
	CString  strName;
	while (!m_pRecordset->adoEOF)
	{
		AfxMessageBox((_bstr_t)m_pRecordset->GetCollect("姓名"));//显示
 		m_pRecordset->MoveNext();
	}
	m_pConnection->Close();
	m_pRecordset->Close();
		  
}

