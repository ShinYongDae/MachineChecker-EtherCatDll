#pragma once

// CDlgIO 대화 상자입니다.

class CDlgIO : public CDialog
{
	DECLARE_DYNAMIC(CDlgIO)

	void Init();
	void Close();

public:
	CDlgIO(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgIO();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_IO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
