
// aDlg.h : header file
//

#pragma once


// CaDlg dialog
class CaDlg : public CDialog
{
// Construction
public:
	CaDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeMfceditbrowse1();
	afx_msg void OnBnClickedOpen();
//	afx_msg void OnEnUpdateFilename();
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedOpen2();
	afx_msg void OnBnClickedOpen3();
};
