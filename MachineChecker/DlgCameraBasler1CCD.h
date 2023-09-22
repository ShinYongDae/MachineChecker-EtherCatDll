#pragma once


// CDlgCameraBasler1CCD 대화 상자입니다.

class CDlgCameraBasler1CCD : public CDialog
{
	DECLARE_DYNAMIC(CDlgCameraBasler1CCD)

	void Init();
	void Close();

public:
	CDlgCameraBasler1CCD(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDlgCameraBasler1CCD();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_CAMERA_BASLER_1CCD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
