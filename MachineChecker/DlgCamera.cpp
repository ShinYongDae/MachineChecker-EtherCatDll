// DlgCamera.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgCamera.h"
#include "afxdialogex.h"


// CDlgCamera 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgCamera, CDialog)

CDlgCamera::CDlgCamera(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_CAMERA, pParent)
{

}

CDlgCamera::~CDlgCamera()
{
}

void CDlgCamera::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCamera, CDialog)
END_MESSAGE_MAP()


// CDlgCamera 메시지 처리기입니다.


BOOL CDlgCamera::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgCamera::Init()
{
}

void CDlgCamera::Close()
{
}
