
// F81804_GPIO.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CF81804_GPIOApp: 
// �йش����ʵ�֣������ F81804_GPIO.cpp
//

class CF81804_GPIOApp : public CWinApp
{
public:
	CF81804_GPIOApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CF81804_GPIOApp theApp;