// DlgCameraViewWorks12k.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCameraViewWorks12k.h"
#include "afxdialogex.h"


// CDlgCameraViewWorks12k 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgCameraViewWorks12k, CDialog)

CDlgCameraViewWorks12k::CDlgCameraViewWorks12k(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA_VIEWWORKS_12K, pParent)
{

}

CDlgCameraViewWorks12k::~CDlgCameraViewWorks12k()
{
}

void CDlgCameraViewWorks12k::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCameraViewWorks12k, CDialog)
END_MESSAGE_MAP()


// CDlgCameraViewWorks12k 메시지 처리기입니다.


BOOL CDlgCameraViewWorks12k::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgCameraViewWorks12k::Init()
{
}

void CDlgCameraViewWorks12k::Close()
{
}
