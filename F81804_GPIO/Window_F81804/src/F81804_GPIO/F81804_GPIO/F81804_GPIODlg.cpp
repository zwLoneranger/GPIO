
// F81804_GPIODlg.cpp : 实现文件
//

#include "stdafx.h"
#include "F81804_GPIO.h"
#include "F81804_GPIODlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#include <stdio.h>

#include "./include/OlsDef.h"

#ifdef RUN_TIME_DYNAMIC_LINKING
#include "./include/OlsApiInitExt.h"
#else // for Load-Time Dynamic Linking
#include "./include/OlsApi.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


static BOOL IsNT();
DWORD address, RegData32;
BYTE RegData;

void GPIO_init(void)
{
	BYTE PortVal = 0;

	//---初始化寄存器地址---//
	WriteIoPortByte(0x2e, 0x87); 
	WriteIoPortByte(0x2e, 0x87); 

	//---初始化 logic device number ---//
	//  index port is base address + 0 and data port is base address + 1
	WriteIoPortByte(0x2e, 0x07); 
	WriteIoPortByte(0x2f, 0x06);			   // 真正数值


	//---初始化 GPIO_DEC_RANGE ----//
	//  index port is base address + 0 and data port is base address + 1
	WriteIoPortByte(0x2e, 0x28); 
	PortVal = ReadIoPortByte(0x2f);
	WriteIoPortByte(0x2f, (PortVal | 0x20));  

	//---初始化 GPIO_DEC_RANGE ----//
	WriteIoPortByte(0x2e, 0x27);			  // 真正数值
	PortVal = ReadIoPortByte(0x2f);
	WriteIoPortByte(0x2f, (PortVal & 0xf3));


}




int ReadGPIOLevel(int gpnum)
{
	BYTE PinStatus = 0;
	
	// F81866
	//WriteIoPortByte(0x2e, 0x8A);				// 读取 GPIO的寄存器地址，注意：要看第几组
	//PinStatus = ReadIoPortByte(0x2f);  
	//PinStatus = ((PinStatus >> (gpnum - 80)) & 0x1);

	// F81804
	WriteIoPortByte(0x2e, 0xA2);				// 读取 GPIO的寄存器地址，注意：要看第几组
	PinStatus = ReadIoPortByte(0x2f);
	PinStatus = ((PinStatus >> (gpnum - 50)) & 0x1);

	return PinStatus;
}

BOOL IsNT()
{
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);

	return (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT);
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CF81804_GPIODlg 对话框
CF81804_GPIODlg::CF81804_GPIODlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_F81804_GPIO_DIALOG, pParent)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}


void CF81804_GPIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	// EditControl 变量
	DDX_Control(pDX, IDC_EDIT_1, m_edit_1);
	DDX_Control(pDX, IDC_EDIT_3, m_edit_3);
	DDX_Control(pDX, IDC_EDIT_5, m_edit_5);
	DDX_Control(pDX, IDC_EDIT_7, m_edit_7);
	DDX_Control(pDX, IDC_EDIT_4, m_edit_4);
	DDX_Control(pDX, IDC_EDIT_6, m_edit_6);
	DDX_Control(pDX, IDC_EDIT_8, m_edit_8);
	DDX_Control(pDX, IDC_EDIT_10, m_edit_10);
}



//----------------------------------------- 读取 GPIO 的值------------------------------------------------------//
void CF81804_GPIODlg::Refresh()
{
CString cstr, edit;
	
	// F81866
	//RegData = ReadGPIOLevel(80);

	//F81804
	RegData = ReadGPIOLevel(50);

	cstr.Format(_T("%d\r\n"), RegData);
	edit += cstr;
	m_edit_1.SetWindowText(edit);


CString cstr1, edit1;
	
	// F81866
	//RegData = ReadGPIOLevel(81);

	//F81804
	RegData = ReadGPIOLevel(51);

	cstr1.Format(_T("%d\r\n"), RegData);
	edit1 += cstr1;
	m_edit_3.SetWindowText(edit1);

CString cstr2, edit2;
	
	// F81866
	//RegData = ReadGPIOLevel(82);

	//F81804
	RegData = ReadGPIOLevel(52);

	cstr2.Format(_T("%d\r\n"), RegData);
	edit2 += cstr2;
	m_edit_5.SetWindowText(edit2);

CString cstr3, edit3;
	
	// F81866
	//RegData = ReadGPIOLevel(83);

	//F81804
	RegData = ReadGPIOLevel(53);

	cstr3.Format(_T("%d\r\n"), RegData);
	edit3 += cstr3;
	m_edit_7.SetWindowText(edit3);

CString cstr4, edit4;

	// F81866
	//RegData = ReadGPIOLevel(84);

	//F81804
	RegData = ReadGPIOLevel(54);

	cstr4.Format(_T("%d\r\n"), RegData);
	edit4 += cstr4;
	m_edit_4.SetWindowText(edit4);

CString cstr5, edit5;
	
	// F81866
	//RegData = ReadGPIOLevel(85);

	//F81804
	RegData = ReadGPIOLevel(55);

	cstr5.Format(_T("%d\r\n"), RegData);
	edit5 += cstr5;
	m_edit_6.SetWindowText(edit5);

CString cstr6, edit6;
	
	// F81866
	//RegData = ReadGPIOLevel(86);

	//F81804
	RegData = ReadGPIOLevel(56);

	cstr6.Format(_T("%d\r\n"), RegData);
	edit6 += cstr6;
	m_edit_8.SetWindowText(edit6);

CString cstr7, edit7;
	
	// F81866
	//RegData = ReadGPIOLevel(87);

	//F81804
	RegData = ReadGPIOLevel(57);

	cstr7.Format(_T("%d\r\n"), RegData);
	edit7 += cstr7;
	m_edit_10.SetWindowText(edit7);
}


BEGIN_MESSAGE_MAP(CF81804_GPIODlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()

	//----OutBUTTON处理函数----//
	ON_BN_CLICKED(IDC_OutBUTTON_1, &CF81804_GPIODlg::OnBnClickedOutbutton1)
	ON_BN_CLICKED(IDC_OutBUTTON_3, &CF81804_GPIODlg::OnBnClickedOutbutton3)
	ON_BN_CLICKED(IDC_OutBUTTON_5, &CF81804_GPIODlg::OnBnClickedOutbutton5)
	ON_BN_CLICKED(IDC_OutBUTTON_7, &CF81804_GPIODlg::OnBnClickedOutbutton7)
	ON_BN_CLICKED(IDC_OutBUTTON_4, &CF81804_GPIODlg::OnBnClickedOutbutton4)
	ON_BN_CLICKED(IDC_OutBUTTON_6, &CF81804_GPIODlg::OnBnClickedOutbutton6)
	ON_BN_CLICKED(IDC_OutBUTTON_8, &CF81804_GPIODlg::OnBnClickedOutbutton8)
	ON_BN_CLICKED(IDC_OutBUTTON_10, &CF81804_GPIODlg::OnBnClickedOutbutton10)

	//---RADIO 0 的处理函数----//
	ON_BN_CLICKED(IDC_OutRADIO_1_0, &CF81804_GPIODlg::OnBnClickedOutradio10)
	ON_BN_CLICKED(IDC_OutRADIO_3_0, &CF81804_GPIODlg::OnBnClickedOutradio30)
	ON_BN_CLICKED(IDC_OutRADIO_5_0, &CF81804_GPIODlg::OnBnClickedOutradio50)
	ON_BN_CLICKED(IDC_OutRADIO_7_0, &CF81804_GPIODlg::OnBnClickedOutradio70)
	ON_BN_CLICKED(IDC_OutRADIO_4_0, &CF81804_GPIODlg::OnBnClickedOutradio40)
	ON_BN_CLICKED(IDC_OutRADIO_6_0, &CF81804_GPIODlg::OnBnClickedOutradio60)
	ON_BN_CLICKED(IDC_OutRADIO_8_0, &CF81804_GPIODlg::OnBnClickedOutradio80)
	ON_BN_CLICKED(IDC_OutRADIO_10_0, &CF81804_GPIODlg::OnBnClickedOutradio100)

	//---RADIO 1 的处理函数----//
	ON_BN_CLICKED(IDC_OutRADIO_1_1, &CF81804_GPIODlg::OnBnClickedOutradio11)
	ON_BN_CLICKED(IDC_OutRADIO_3_1, &CF81804_GPIODlg::OnBnClickedOutradio31)
	ON_BN_CLICKED(IDC_OutRADIO_5_1, &CF81804_GPIODlg::OnBnClickedOutradio51)
	ON_BN_CLICKED(IDC_OutRADIO_7_1, &CF81804_GPIODlg::OnBnClickedOutradio71)
	ON_BN_CLICKED(IDC_OutRADIO_4_1, &CF81804_GPIODlg::OnBnClickedOutradio41)
	ON_BN_CLICKED(IDC_OutRADIO_6_1, &CF81804_GPIODlg::OnBnClickedOutradio61)
	ON_BN_CLICKED(IDC_OutRADIO_8_1, &CF81804_GPIODlg::OnBnClickedOutradio81)
	ON_BN_CLICKED(IDC_OutRADIO_10_1, &CF81804_GPIODlg::OnBnClickedOutradio101)

	//---InBUTTON 的处理函数----//
	ON_BN_CLICKED(IDC_InBUTTON_1, &CF81804_GPIODlg::OnBnClickedInbutton1)
	ON_BN_CLICKED(IDC_InBUTTON_3, &CF81804_GPIODlg::OnBnClickedInbutton3)
	ON_BN_CLICKED(IDC_InBUTTON_5, &CF81804_GPIODlg::OnBnClickedInbutton5)
	ON_BN_CLICKED(IDC_InBUTTON_7, &CF81804_GPIODlg::OnBnClickedInbutton7)
	ON_BN_CLICKED(IDC_InBUTTON_4, &CF81804_GPIODlg::OnBnClickedInbutton4)
	ON_BN_CLICKED(IDC_InBUTTON_6, &CF81804_GPIODlg::OnBnClickedInbutton6)
	ON_BN_CLICKED(IDC_InBUTTON_8, &CF81804_GPIODlg::OnBnClickedInbutton8)
	ON_BN_CLICKED(IDC_InBUTTON_10, &CF81804_GPIODlg::OnBnClickedInbutton10)

	
	
	ON_BN_CLICKED(IDC_AllOutBUTTON_0, &CF81804_GPIODlg::OnBnClickedAlloutbutton0)
	ON_BN_CLICKED(IDC_AllOutBUTTON_1, &CF81804_GPIODlg::OnBnClickedAlloutbutton1)
	ON_BN_CLICKED(IDC_AllInBUTTON, &CF81804_GPIODlg::OnBnClickedAllinbutton)
END_MESSAGE_MAP()


// CF81804_GPIODlg 消息处理程序

BOOL CF81804_GPIODlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	m_IsNT = IsNT();
	SetTimer(1, 200, NULL);


	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CF81804_GPIODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CF81804_GPIODlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	// 初始化GPIO
	GPIO_init();
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CF81804_GPIODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//------------------------------------------- Radio 通用函数-------------------------------------------//
void CF81804_GPIODlg::RadioFunction(int Radio,BYTE byte)
{
	BYTE PortVal = 0;

	// F81866
	//WriteIoPortByte(0x2e, 0x89);					// Output Data Register 

	// F81804
	WriteIoPortByte(0x2e, 0xA1);					// Output Data Register 

	PortVal = ReadIoPortByte(0x2f);

	if (Radio == 0)
	{
		WriteIoPortByte(0x2f, (PortVal & byte));
	}
	else if (Radio == 1)
	{ 
		WriteIoPortByte(0x2f, (PortVal | byte)); 
	}
	
}


//------------------------------------------- Button 通用函数-------------------------------------------//
//------------------------------------------- 0 Output    1 Input---------------------------------------//
void CF81804_GPIODlg::ButtonFunction(int direction, BYTE byte)
{
	BYTE PortVal = 0;

	// F81866 
	//WriteIoPortByte(0x2e, 0x88);					// 控制改变 GPIO 模式的寄存器地址 

	// F81804
	WriteIoPortByte(0x2e, 0xA0);					// 控制改变 GPIO 模式的寄存器地址 

	PortVal = ReadIoPortByte(0x2f); 
	if (direction == 0)
	{
		WriteIoPortByte(0x2f, (PortVal | byte));			// 0x01   
	}
	else if (direction == 1)
	{
		WriteIoPortByte(0x2f, (PortVal & byte));		   // 0xfe
	}
	

}


//-------------------------------------------- Output Button ----------------------------------------//
void CF81804_GPIODlg::OnBnClickedOutbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x01);				// 0
}


void CF81804_GPIODlg::OnBnClickedOutbutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x02);				// 1=2^0
}


void CF81804_GPIODlg::OnBnClickedOutbutton5()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x04);				// 2=2^1
}


void CF81804_GPIODlg::OnBnClickedOutbutton7()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x08);				// 4=2^2
}


void CF81804_GPIODlg::OnBnClickedOutbutton4()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x10);				// 8=2^3
}


void CF81804_GPIODlg::OnBnClickedOutbutton6()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x20);				// 16=2^4
}


void CF81804_GPIODlg::OnBnClickedOutbutton8()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x40);				// 32=2^5
}


void CF81804_GPIODlg::OnBnClickedOutbutton10()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(0,0x80);				// 64=2^6
}


//-------------------------------------------- Radio 0 ----------------------------------------//
void CF81804_GPIODlg::OnBnClickedOutradio10()
{
	// TODO: 在此添加控件通知处理程序代码
	// 调用 Radio通用函数
	RadioFunction(0,0xfe);							// 0
}




void CF81804_GPIODlg::OnBnClickedOutradio30()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xfd);							// -1 
}


void CF81804_GPIODlg::OnBnClickedOutradio50()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xfb);							// -2 
}


void CF81804_GPIODlg::OnBnClickedOutradio70()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xf7);							// -4
}


void CF81804_GPIODlg::OnBnClickedOutradio40()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xef);							// -8
}


void CF81804_GPIODlg::OnBnClickedOutradio60()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xdf);							// -16
}


void CF81804_GPIODlg::OnBnClickedOutradio80()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0xbf);							// -32
}


void CF81804_GPIODlg::OnBnClickedOutradio100()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(0,0x7f);							// -64
}

//-------------------------------------------- Radio 1 ----------------------------------------//

void CF81804_GPIODlg::OnBnClickedOutradio11()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x01);							// 0
}



void CF81804_GPIODlg::OnBnClickedOutradio31()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x02);							// 1
}


void CF81804_GPIODlg::OnBnClickedOutradio51()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x04);							// 2
}


void CF81804_GPIODlg::OnBnClickedOutradio71()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x08);							// 4
}


void CF81804_GPIODlg::OnBnClickedOutradio41()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x10);							// 8
}


void CF81804_GPIODlg::OnBnClickedOutradio61()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组	
	RadioFunction(1,0x20);							// 16
}


void CF81804_GPIODlg::OnBnClickedOutradio81()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x40);							// 32
}


void CF81804_GPIODlg::OnBnClickedOutradio101()
{
	// TODO: 在此添加控件通知处理程序代码
	// 控制寄存器地址，与第几组GPIO,GPIO5x 第5组
	RadioFunction(1,0x80);							// 48
}

//-------------------------------------------- Input Button ----------------------------------------//
void CF81804_GPIODlg::OnBnClickedInbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xfe);				 // 0

}


void CF81804_GPIODlg::OnBnClickedInbutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xfd);				// -1
}


void CF81804_GPIODlg::OnBnClickedInbutton5()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xfb);				// -2
}


void CF81804_GPIODlg::OnBnClickedInbutton7()
{
	// TODO: 在此添加控件通知处理程序代码 
	ButtonFunction(1,0xf7);				// -4
}


void CF81804_GPIODlg::OnBnClickedInbutton4()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xef);				// -8
}


void CF81804_GPIODlg::OnBnClickedInbutton6()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xdf);				// -16
}


void CF81804_GPIODlg::OnBnClickedInbutton8()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0xbf);				// -32
}


void CF81804_GPIODlg::OnBnClickedInbutton10()
{
	// TODO: 在此添加控件通知处理程序代码
	ButtonFunction(1,0x7f);				// -64
}


//---------------------------------- 在类向导中添加定时器处理函数- ---------------------------------//
void CF81804_GPIODlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Refresh();										// 定时器更新GPIO的数值
	CDialogEx::OnTimer(nIDEvent);
}



// ---------------------------------   ALL Output 0   ---------------------------------// 
void CF81804_GPIODlg::OnBnClickedAlloutbutton0()
{
	// TODO: 在此添加控件通知处理程序代码

	//输出模式
	ButtonFunction(0, 0x01);
	ButtonFunction(0, 0x02);
	ButtonFunction(0, 0x04);
	ButtonFunction(0, 0x08);
	ButtonFunction(0, 0x10);
	ButtonFunction(0, 0x20);
	ButtonFunction(0, 0x40);
	ButtonFunction(0, 0x80);

	// 值
	RadioFunction(0, 0x00);

}



// ---------------------------------   ALL Output 1   ---------------------------------// 
void CF81804_GPIODlg::OnBnClickedAlloutbutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//输出模式
	ButtonFunction(0, 0x01);
	ButtonFunction(0, 0x02);
	ButtonFunction(0, 0x04);
	ButtonFunction(0, 0x08);
	ButtonFunction(0, 0x10);
	ButtonFunction(0, 0x20);
	ButtonFunction(0, 0x40);
	ButtonFunction(0, 0x80);
	
	// 值
	RadioFunction(1, 0xff);				// |
}



// ---------------------------------   ALL	Intput   ---------------------------------// 
void CF81804_GPIODlg::OnBnClickedAllinbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	//输入模式
	//ButtonFunction(1, 0xff);			// &
	ButtonFunction(1, 0xfe);
	ButtonFunction(1, 0xfd);
	ButtonFunction(1, 0xfb);
	ButtonFunction(1, 0xf7);
	ButtonFunction(1, 0xef);
	ButtonFunction(1, 0xdf);
	ButtonFunction(1, 0xbf);
	ButtonFunction(1, 0x7f);
}
