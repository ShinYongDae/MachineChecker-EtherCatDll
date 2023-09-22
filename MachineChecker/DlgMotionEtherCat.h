#pragma once

#include "Devices/EtherCat.h"

enum OnOffAction { OFF, ON };

// CDlgMotionEtherCat 대화 상자입니다.

class CDlgMotionEtherCat : public CDialog
{
	DECLARE_DYNAMIC(CDlgMotionEtherCat)

	CEtherCat *m_pEtherCat;

	void Init();
	void Close();

public:
	CDlgMotionEtherCat(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgMotionEtherCat();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_MOTION_ETHERCAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
};
