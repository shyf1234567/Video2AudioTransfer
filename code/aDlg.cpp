
// aDlg.cpp : implementation file
//
#include "stdafx.h"
#include "a.h"
#include "aDlg.h"
#include "ConWindow.h"
#include "afxdialogex.h"
#include "part1.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CaDlg dialog



CaDlg::CaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_A_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CaDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CaDlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(OPEN, &CaDlg::OnBnClickedOpen)
//	ON_EN_UPDATE(FILENAME, &CaDlg::OnEnUpdateFilename)
ON_BN_CLICKED(CLOSE, &CaDlg::OnBnClickedClose)
ON_BN_CLICKED(OPEN2, &CaDlg::OnBnClickedOpen2)
ON_BN_CLICKED(OPEN3, &CaDlg::OnBnClickedOpen3)
END_MESSAGE_MAP()


// CaDlg message handlers

BOOL CaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

void CaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CaDlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CaDlg::OnBnClickedOpen()
{
	// TODO: Add your control notification handler code here
	CString cs;
	std::string s;
	/*
	static int flag = 0;
	if (!flag) {
		Audio::Open();
		flag = 1;
	}
	*/
	GetDlgItemText(IDC_MFCEDITBROWSE1, cs);
	s = ((CT2CA)cs);
	s = part1(s);
	if (s != "") {
		MessageBox(CString(s.c_str()));
	}
}




void CaDlg::OnBnClickedClose()
{
	// TODO: Add your control notification handler code here
	DestroyWindow();
	exit(0);
}

/*
void CaDlg::OnBnClickedStop()
{
	// TODO: Add your control notification handler code here
	stop = 1;
}
*/

/*
void CaDlg::OnBnClickedPause()
{
	// TODO: Add your control notification handler code here
	pause = 1 - pause;
}
*/

/*
void CaDlg::OnBnClickedConfig()
{
	// TODO: Add your control notification handler code here
	
	CDialog config(IDD_DIALOG1);
	config.DoModal();
	
	ConWindow config;
}
*/

/*
void CaDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	
}
*/


void CaDlg::OnBnClickedOpen2()
{
	// TODO: Add your control notification handler code here
	CString cs;
	std::string s;
	GetDlgItemText(IDC_MFCEDITBROWSE1, cs);
	s = ((CT2CA)cs);
	s = part2(s, 0);
	if (s != "") {
		MessageBox(CString(s.c_str()));
	}
}


void CaDlg::OnBnClickedOpen3()
{
	// TODO: Add your control notification handler code here
	CString cs;
	std::string s;
	GetDlgItemText(IDC_MFCEDITBROWSE1, cs);
	s = ((CT2CA)cs);
	s = part2(s, 0);
	if (s != "") {
		MessageBox(CString(s.c_str()));
	}
}
