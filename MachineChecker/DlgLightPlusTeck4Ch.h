#pragma once

#include "Devices/RS232.h"


// CDlgLightPlusTeck4Ch 대화 상자입니다.

class CDlgLightPlusTeck4Ch : public CDialog
{
	DECLARE_DYNAMIC(CDlgLightPlusTeck4Ch)

	void Init();
	void Close();

public:
	CDlgLightPlusTeck4Ch(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgLightPlusTeck4Ch();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_LIGHT_PLUSTEK_4CH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
