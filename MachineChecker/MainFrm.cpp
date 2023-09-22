
// MainFrm.cpp : CMainFrame 클래스의 구현
//

#include "stdafx.h"
#include "MachineChecker.h"

#include "MainFrm.h"
#include "MachineCheckerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_IO, &CMainFrame::OnIo)
	ON_COMMAND(ID_LIGHT1, &CMainFrame::OnLight1)
	ON_COMMAND(ID_LIGHT2, &CMainFrame::OnLight2)
	ON_COMMAND(ID_MOTION, &CMainFrame::OnMotion)
	ON_COMMAND(ID_CAMERA1, &CMainFrame::OnCamera1)
	ON_COMMAND(ID_CAMERA2, &CMainFrame::OnCamera2)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기


void CMainFrame::OnIo()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispIO();
}

void CMainFrame::OnLight1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispLight1();
}

void CMainFrame::OnLight2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispLight2();
}

void CMainFrame::OnMotion()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispMotion();
}

void CMainFrame::OnCamera1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispCamera1();
}

void CMainFrame::OnCamera2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
	pView->DispCamera2();
}
