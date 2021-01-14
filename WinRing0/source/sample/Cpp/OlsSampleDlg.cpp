//-----------------------------------------------------------------------------
//     Author : hiyohiyo
//       Mail : hiyohiyo@crystalmark.info
//        Web : http://openlibsys.org/
//    License : The modified BSD license
//
//                     Copyright 2007-2008 OpenLibSys.org. All rights reserved.
//-----------------------------------------------------------------------------

#include "stdafx.h"
#include "OlsSample.h"
#include "OlsSampleDlg.h"
#include "../../dll/OlsDef.h"

#ifdef RUN_TIME_DYNAMIC_LINKING
#include "../../dll/OlsApiInitExt.h"
#else // for Load-Time Dynamic Linking
#include "../../dll/OlsApi.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------
static BOOL IsNT();
DWORD address,  RegData32;
BYTE RegData;
//CString cstr, edit;

//-----------------------------------------------------------------------------
// COlsSampleDlg dialog
//-----------------------------------------------------------------------------

COlsSampleDlg::COlsSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COlsSampleDlg::IDD, pParent)
{
//	m_gp31 = 0;
//	m_gp32 = 0;
//	m_gp33 = 0;
//	m_gp34 = 0;
//	m_gp35 = 0;
//	m_gp36 = 0;
//	m_gp37 = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COlsSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
DDX_Control(pDX, IDC_EDIT2, m_gp30);
DDX_Control(pDX, IDC_EDIT3, m_gp31);
DDX_Control(pDX, IDC_EDIT4, m_gp32);
DDX_Control(pDX, IDC_EDIT5, m_gp33);
DDX_Control(pDX, IDC_EDIT6, m_gp34);
DDX_Control(pDX, IDC_EDIT7, m_gp35);
DDX_Control(pDX, IDC_EDIT8, m_gp36);
DDX_Control(pDX, IDC_EDIT9, m_gp37);
}

BEGIN_MESSAGE_MAP(COlsSampleDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, &COlsSampleDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &COlsSampleDlg::OnBnClickedOk)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_RADIO1, &COlsSampleDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &COlsSampleDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO5, &COlsSampleDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO2, &COlsSampleDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO4, &COlsSampleDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, &COlsSampleDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO7, &COlsSampleDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO9, &COlsSampleDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO11, &COlsSampleDlg::OnBnClickedRadio11)
	ON_BN_CLICKED(IDC_RADIO8, &COlsSampleDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO10, &COlsSampleDlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO12, &COlsSampleDlg::OnBnClickedRadio12)
	ON_BN_CLICKED(IDC_RADIO13, &COlsSampleDlg::OnBnClickedRadio13)
	ON_BN_CLICKED(IDC_RADIO14, &COlsSampleDlg::OnBnClickedRadio14)
	ON_BN_CLICKED(IDC_RADIO15, &COlsSampleDlg::OnBnClickedRadio15)
	ON_BN_CLICKED(IDC_RADIO16, &COlsSampleDlg::OnBnClickedRadio16)
	ON_BN_CLICKED(IDC_BUTTON1, &COlsSampleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &COlsSampleDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &COlsSampleDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &COlsSampleDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &COlsSampleDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &COlsSampleDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &COlsSampleDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &COlsSampleDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &COlsSampleDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &COlsSampleDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &COlsSampleDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &COlsSampleDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &COlsSampleDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &COlsSampleDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &COlsSampleDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &COlsSampleDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &COlsSampleDlg::OnBnClickedButton19)
END_MESSAGE_MAP()


// COlsSampleDlg message handlers

BOOL COlsSampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_IsNT = IsNT();

	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x07);

	WriteIoPortByte(0x4e,0x2c);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0x1f;
	WriteIoPortByte(0x4f,RegData);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0x30);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x02;
	WriteIoPortByte(0x4f,RegData);

	WriteIoPortByte(0x4e,0xaa);

    SetTimer(1, 200, NULL);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COlsSampleDlg::Refresh()
{
CString cstr, edit;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 0) & 0x01;

	cstr.Format(_T("%d\r\n"), RegData);
	edit += cstr;

	m_gp30.SetWindowText(edit);

CString cstr1, edit1;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 1) & 0x01;

	cstr1.Format(_T("%d\r\n"), RegData);
	edit1 += cstr1;
	m_gp31.SetWindowText(edit1);

CString cstr2, edit2;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 2) & 0x01;

	cstr2.Format(_T("%d\r\n"), RegData);
	edit2 += cstr2;
	m_gp32.SetWindowText(edit2);

CString cstr3, edit3;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 3) & 0x01;

	cstr3.Format(_T("%d\r\n"), RegData);
	edit3 += cstr3;
	m_gp33.SetWindowText(edit3);

CString cstr4, edit4;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 4) & 0x01;

	cstr4.Format(_T("%d\r\n"), RegData);
	edit4 += cstr4;
	m_gp34.SetWindowText(edit4);

CString cstr5, edit5;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 5) & 0x01;

	cstr5.Format(_T("%d\r\n"), RegData);
	edit5 += cstr5;
	m_gp35.SetWindowText(edit5);

CString cstr6, edit6;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 6) & 0x01;

	cstr6.Format(_T("%d\r\n"), RegData);
	edit6 += cstr6;
	m_gp36.SetWindowText(edit6);

CString cstr7, edit7;
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	
	RegData = (RegData >> 7) & 0x01;

	cstr7.Format(_T("%d\r\n"), RegData);
	edit7 += cstr7;
	m_gp37.SetWindowText(edit7);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COlsSampleDlg::OnPaint()
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
HCURSOR COlsSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COlsSampleDlg::OnBnClickedOk()
{
	OnOK();
}

void COlsSampleDlg::OnBnClickedCancel()
{
	OnCancel();
}


void COlsSampleDlg::OnDestroy()
{
	CDialog::OnDestroy();
}

BOOL IsNT()
{
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);

	return (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT);
}

void COlsSampleDlg::OnTimer(UINT nIDEvent) 
{
	Refresh();
   // Call base class handler.
   CDialog::OnTimer(nIDEvent);
}

void COlsSampleDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);

	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfe;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);

	RegData = ReadIoPortByte(0x4f);
	RegData |=0x01;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);

	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfd;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x02;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio5()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfb;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio6()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x04;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio7()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xf7;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio8()
{
	// TODO: 在此添加控件通知处理程序代码	
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x08;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio9()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xef;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio10()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x10;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio11()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xdf;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio12()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x20;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio13()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xbf;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio14()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x40;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio15()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0x7f;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedRadio16()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf1);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x80;
	WriteIoPortByte(0x4f,RegData);
}


void COlsSampleDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x07);

	WriteIoPortByte(0x4e,0x2c);
	RegData = ReadIoPortByte(0x4f);
	RegData |= 0xE0;
	WriteIoPortByte(0x4f,RegData);

	WriteIoPortByte(0x4e,0xaa);

	OnCancel();
}

void COlsSampleDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfe;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x01;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfd;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x02;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xfb;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x04;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xf7;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x08;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xef;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x10;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xdf;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x20;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0xbf;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x40;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton18()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData &=0x7f;
	WriteIoPortByte(0x4f,RegData);
}

void COlsSampleDlg::OnBnClickedButton19()
{
	// TODO: 在此添加控件通知处理程序代码
	WriteIoPortByte(0x4e,0x87);
	WriteIoPortByte(0x4e,0x87);

	WriteIoPortByte(0x4e,0x07);
	WriteIoPortByte(0x4f,0x09);

	WriteIoPortByte(0x4e,0xf0);
	RegData = ReadIoPortByte(0x4f);
	RegData |=0x80;
	WriteIoPortByte(0x4f,RegData);
}