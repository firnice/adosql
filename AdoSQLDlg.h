// AdoSQLDlg.h : header file
//

#if !defined(AFX_ADOSQLDLG_H__74DC3978_E3F5_4C98_9463_9A9A00EB7E67__INCLUDED_)
#define AFX_ADOSQLDLG_H__74DC3978_E3F5_4C98_9463_9A9A00EB7E67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAdoSQLDlg dialog

class CAdoSQLDlg : public CDialog
{
// Construction
public:
	CAdoSQLDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAdoSQLDlg)
	enum { IDD = IDD_ADOSQL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoSQLDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdoSQLDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnCon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOSQLDLG_H__74DC3978_E3F5_4C98_9463_9A9A00EB7E67__INCLUDED_)
