// CZXT_kesheDlg.h : header file
//

#if !defined(AFX_CZXT_KESHEDLG_H__82CF05FE_A9AA_4BA9_A4A1_D6EE78282E68__INCLUDED_)
#define AFX_CZXT_KESHEDLG_H__82CF05FE_A9AA_4BA9_A4A1_D6EE78282E68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCZXT_kesheDlg dialog

class CCZXT_kesheDlg : public CDialog
{
// Construction
public:
	CCZXT_kesheDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCZXT_kesheDlg)
	enum { IDD = IDD_CZXT_KESHE_DIALOG };
	CComboBox	m_com;
	CString	m_bsize;
	CString	m_psize;
	CString	m_page;
	CString	m_jieguo;
	CString	m_count;
	CString	m_opt;
	CString	m_fifo;
	CString	m_lru;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCZXT_kesheDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCZXT_kesheDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CZXT_KESHEDLG_H__82CF05FE_A9AA_4BA9_A4A1_D6EE78282E68__INCLUDED_)
