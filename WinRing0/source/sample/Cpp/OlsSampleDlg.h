//-----------------------------------------------------------------------------
//     Author : hiyohiyo
//       Mail : hiyohiyo@crystalmark.info
//        Web : http://openlibsys.org/
//    License : The modified BSD license
//
//                          Copyright 2007 OpenLibSys.org. All rights reserved.
//-----------------------------------------------------------------------------

#pragma once
#include "afxwin.h"


// COlsSampleDlg dialog
class COlsSampleDlg : public CDialog
{
// Construction
public:
	COlsSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_OLSSAMPLE_DIALOG };
//	UINT	m_gp31;
//	UINT	m_gp32;
//	UINT	m_gp33;
//	UINT	m_gp34;
//	UINT	m_gp35;
//	UINT	m_gp36;
//	UINT	m_gp37;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	BOOL m_IsNT;
	void Refresh();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	CEdit m_gp30;
	CEdit m_gp31;
	CEdit m_gp32;
	CEdit m_gp33;
	CEdit m_gp34;
	CEdit m_gp35;
	CEdit m_gp36;
	CEdit m_gp37;
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
public:
	afx_msg void OnBnClickedRadio1();
public:
	afx_msg void OnBnClickedRadio3();
public:
	afx_msg void OnBnClickedRadio5();
public:
	afx_msg void OnBnClickedRadio2();
public:
	afx_msg void OnBnClickedRadio4();
public:
	afx_msg void OnBnClickedRadio6();
public:
	afx_msg void OnBnClickedRadio7();
public:
	afx_msg void OnBnClickedRadio9();
public:
	afx_msg void OnBnClickedRadio11();
public:
	afx_msg void OnBnClickedRadio13();
public:
	afx_msg void OnBnClickedRadio15();
public:
	afx_msg void OnBnClickedRadio8();
public:
	afx_msg void OnBnClickedRadio10();
public:
	afx_msg void OnBnClickedRadio12();
public:
	afx_msg void OnBnClickedRadio14();
public:
	afx_msg void OnBnClickedRadio16();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton4();
public:
	afx_msg void OnBnClickedButton5();
public:
	afx_msg void OnBnClickedButton6();
public:
	afx_msg void OnBnClickedButton7();
public:
	afx_msg void OnBnClickedButton8();
public:
	afx_msg void OnBnClickedButton9();
public:
	afx_msg void OnBnClickedButton10();
public:
	afx_msg void OnBnClickedButton11();
public:
	afx_msg void OnBnClickedButton12();
public:
	afx_msg void OnBnClickedButton13();
public:
	afx_msg void OnBnClickedButton14();
public:
	afx_msg void OnBnClickedButton15();
public:
	afx_msg void OnBnClickedButton16();
public:
	afx_msg void OnBnClickedButton17();
public:
	afx_msg void OnBnClickedButton18();
public:
	afx_msg void OnBnClickedButton19();
};
