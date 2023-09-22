#pragma once


// CDlgIoAgn9386 대화 상자입니다.

class CDlgIoAgn9386 : public CDialog
{
	DECLARE_DYNAMIC(CDlgIoAgn9386)

	void Init();
	void Close();

public:
	CDlgIoAgn9386(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgIoAgn9386();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_IO_AGN_9386 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
