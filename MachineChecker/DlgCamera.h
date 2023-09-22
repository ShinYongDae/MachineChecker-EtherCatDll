#pragma once


// CDlgCamera 대화 상자입니다.

class CDlgCamera : public CDialog
{
	DECLARE_DYNAMIC(CDlgCamera)

	void Init();
	void Close();

public:
	CDlgCamera(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgCamera();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
