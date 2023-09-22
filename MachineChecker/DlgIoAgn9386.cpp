// DlgIoAgn9386.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgIoAgn9386.h"
#include "afxdialogex.h"


// CDlgIoAgn9386 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgIoAgn9386, CDialog)

CDlgIoAgn9386::CDlgIoAgn9386(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_IO_AGN_9386, pParent)
{

}

CDlgIoAgn9386::~CDlgIoAgn9386()
{
	Close();
}

void CDlgIoAgn9386::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgIoAgn9386, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDlgIoAgn9386 메시지 처리기입니다.


BOOL CDlgIoAgn9386::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	//SetTimer(0, 100, NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgIoAgn9386::Init()
{
}

void CDlgIoAgn9386::Close()
{
}


void CDlgIoAgn9386::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0)
	{
		KillTimer(nIDEvent);
	}

	CDialog::OnTimer(nIDEvent);
}
