#pragma once

#include "Devices/EtherCat.h"



// CDlgMotion 대화 상자입니다.

class CDlgMotion : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotion)

	CEtherCat *m_pEtherCat;

	void Init();
	void Close();

public:
	CDlgMotion(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMotion();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
