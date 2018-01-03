// CZXT_kesheDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CZXT_keshe.h"
#include "CZXT_kesheDlg.h"
#include "zhihuan.h"
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
// CCZXT_kesheDlg dialog

CCZXT_kesheDlg::CCZXT_kesheDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCZXT_kesheDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCZXT_kesheDlg)
	m_bsize = _T("");
	m_psize = _T("");
	m_page = _T("");
	m_jieguo = _T("");
	m_count = _T("");
	m_opt = _T("");
	m_fifo = _T("");
	m_lru = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCZXT_kesheDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCZXT_kesheDlg)
	DDX_Control(pDX, IDC_COMBO1, m_com);
	DDX_Text(pDX, IDC_EDIT1, m_bsize);
	DDX_Text(pDX, IDC_EDIT2, m_psize);
	DDX_Text(pDX, IDC_EDIT3, m_page);
	DDX_Text(pDX, IDC_EDIT4, m_jieguo);
	DDX_Text(pDX, IDC_EDIT5, m_count);
	DDX_Text(pDX, IDC_EDIT6, m_opt);
	DDX_Text(pDX, IDC_EDIT7, m_fifo);
	DDX_Text(pDX, IDC_EDIT8, m_lru);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCZXT_kesheDlg, CDialog)
	//{{AFX_MSG_MAP(CCZXT_kesheDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCZXT_kesheDlg message handlers

BOOL CCZXT_kesheDlg::OnInitDialog()
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
	m_com.AddString("Optimal");
	m_com.AddString("FIFO");
	m_com.AddString("LRU");
	//m_com.SetCurSel(0);


	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCZXT_kesheDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCZXT_kesheDlg::OnPaint() 
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
HCURSOR CCZXT_kesheDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCZXT_kesheDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int Bsize;//页面数
	int Psize;//物理块数
	int page[50];//页面串号
	char ptemp[50];
	pageInfo block[20];//物理块
	int i,length,j;
	blockInit(block,Bsize);//物理块初始化
	UpdateData();

	Bsize = atoi(m_bsize);
	Psize = atoi(m_psize);
	length = m_page.GetLength();
	blockInit(block,Bsize);//物理块初始化
	for(i=0,j=0;i<length;i+=2,j++)
		ptemp[j]=m_page.GetAt(i);
	for(i=0;i<Psize;i++)
		page[i] = ptemp[i]-'0';

	switch(m_com.GetCurSel())
	{
		case 0:Optimal(block,page,Bsize,Psize);break;
		case 1:FIFO(block,page,Bsize,Psize);break;
		case 2:LRU(block,page,Bsize,Psize);break;
	}
	m_jieguo = s;
	//char ch = count + '0';
	//m_count += ch;
	m_count.Format("%d",count);
	UpdateData(false);
	s.Empty();
	m_jieguo.Empty();
	
}

void CCZXT_kesheDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	int Bsize;//页面数
	int Psize;//物理块数
	int page[50];//页面串号
	char ptemp[50];
	pageInfo block[20];//物理块
	int i,length,j;
	blockInit(block,Bsize);//物理块初始化
	UpdateData();

	Bsize = atoi(m_bsize);
	Psize = atoi(m_psize);
	length = m_page.GetLength();
	blockInit(block,Bsize);//物理块初始化
	for(i=0,j=0;i<length;i+=2,j++)
		ptemp[j]=m_page.GetAt(i);
	for(i=0;i<Psize;i++)
		page[i] = ptemp[i]-'0';
	Optimal(block,page,Bsize,Psize);
	m_opt.Format("%.2f",(1.0)*count/Psize);
	FIFO(block,page,Bsize,Psize);
	m_fifo.Format("%.2f",(1.0)*count/Psize);
	LRU(block,page,Bsize,Psize);
	m_lru.Format("%.2f",(1.0)*count/Psize);
	s.Empty();
	m_jieguo.Empty();
	switch(m_com.GetCurSel())
	{
		case 0:Optimal(block,page,Bsize,Psize);break;
		case 1:FIFO(block,page,Bsize,Psize);break;
		case 2:LRU(block,page,Bsize,Psize);break;
	}
	m_jieguo = s;
	//char ch = count + '0';
	//m_count += ch;
	m_count.Format("%d",count);
	UpdateData(false);
	s.Empty();
	m_jieguo.Empty();
	
}
