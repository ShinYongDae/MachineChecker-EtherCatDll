#pragma once

#include "Devices/RS232.h"

#define MAX_LIGHT_CH	4

// CDlgLight 대화 상자입니다.

class CDlgLight : public CDialog
{
	DECLARE_DYNAMIC(CDlgLight)

	CRs232 m_Rs232;
	BOOL m_bRs232Run;
	CString m_sRcvRs232;
	CString m_sDispRcvRs232;
	BOOL m_bCh[MAX_LIGHT_CH];
	int m_nCh[MAX_LIGHT_CH];

	void Init();
	void Close();
	CString Rcv();
	BOOL Send(CString str);
	BOOL Set(int nCh, int nVal = -1);
	int Get(int nCh);
	void Reset(int nCh);
	char* TCHARToChar(TCHAR *tszStr);

public:
	CDlgLight(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgLight();

	afx_msg LRESULT OnReceiveRs232(WPARAM wP, LPARAM lP);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIGHT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnTest();
};
