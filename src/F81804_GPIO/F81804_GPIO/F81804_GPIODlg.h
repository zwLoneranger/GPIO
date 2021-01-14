
// F81804_GPIODlg.h : ͷ�ļ�
//

#pragma once
#include "include\OlsApi.h"
#include "afxwin.h"


// CF81804_GPIODlg �Ի���
class CF81804_GPIODlg : public CDialogEx
{
// ����
public:
	CF81804_GPIODlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_F81804_GPIO_DIALOG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	BOOL m_IsNT;
	void Refresh();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

	void RadioFunction(int Radio,BYTE byte);
	void ButtonFunction(int direction,BYTE byte);

	// ʱ���¼�������
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	// Output Button
	afx_msg void OnBnClickedOutbutton1();
	afx_msg void OnBnClickedOutbutton3();
	afx_msg void OnBnClickedOutbutton5();
	afx_msg void OnBnClickedOutbutton7();
	afx_msg void OnBnClickedOutbutton4();
	afx_msg void OnBnClickedOutbutton6();
	afx_msg void OnBnClickedOutbutton8();
	afx_msg void OnBnClickedOutbutton10();

	// Output radio 0
	afx_msg void OnBnClickedOutradio10();
	afx_msg void OnBnClickedOutradio30();
	afx_msg void OnBnClickedOutradio50();
	afx_msg void OnBnClickedOutradio70();
	afx_msg void OnBnClickedOutradio40();
	afx_msg void OnBnClickedOutradio60();
	afx_msg void OnBnClickedOutradio80();
	afx_msg void OnBnClickedOutradio100();

	// Output radio 1
	afx_msg void OnBnClickedOutradio11();
	afx_msg void OnBnClickedOutradio31();
	afx_msg void OnBnClickedOutradio51();
	afx_msg void OnBnClickedOutradio71();
	afx_msg void OnBnClickedOutradio41();
	afx_msg void OnBnClickedOutradio61();
	afx_msg void OnBnClickedOutradio81();
	afx_msg void OnBnClickedOutradio101();

	// Input Button
	afx_msg void OnBnClickedInbutton1();
	afx_msg void OnBnClickedInbutton3();
	afx_msg void OnBnClickedInbutton5();
	afx_msg void OnBnClickedInbutton7();
	afx_msg void OnBnClickedInbutton4();
	afx_msg void OnBnClickedInbutton6();
	afx_msg void OnBnClickedInbutton8();
	afx_msg void OnBnClickedInbutton10();

	// Edit Control Value
	CEdit m_edit_1;
	CEdit m_edit_3;
	CEdit m_edit_5;
	CEdit m_edit_7;
	CEdit m_edit_4;
	CEdit m_edit_6;
	CEdit m_edit_8;
	CEdit m_edit_10;

	afx_msg void OnBnClickedAlloutbutton0();
	afx_msg void OnBnClickedAlloutbutton1();
	afx_msg void OnBnClickedAllinbutton();
};
