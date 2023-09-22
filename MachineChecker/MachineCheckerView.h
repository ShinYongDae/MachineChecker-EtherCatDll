
// MachineCheckerView.h : CMachineCheckerView 클래스의 인터페이스
//

#pragma once
#include "MachineCheckerDoc.h"


class CMachineCheckerView : public CFormView
{
	void InitMenu();
	void SetMenu();
	CString FileBrowse();

	void ShowDlgIO();
	void ShowDlgLight(int nIndex);
	void ShowDlgMotion();
	void ShowDlgCamera(int nIndex);
	void ShowDlgTrigger();
	void ShowDlg2DBarcode();

protected: // serialization에서만 만들어집니다.
	CMachineCheckerView();
	DECLARE_DYNCREATE(CMachineCheckerView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MACHINECHECKER_FORM };
#endif

// 특성입니다.
public:
	CMachineCheckerDoc* GetDocument() const;

// 작업입니다.
public:
	void DispIO();
	void DispLight1();
	void DispLight2();
	void DispMotion();
	void DispCamera1();
	void DispCamera2();

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CMachineCheckerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnOpen();
};

#ifndef _DEBUG  // MachineCheckerView.cpp의 디버그 버전
inline CMachineCheckerDoc* CMachineCheckerView::GetDocument() const
   { return reinterpret_cast<CMachineCheckerDoc*>(m_pDocument); }
#endif

