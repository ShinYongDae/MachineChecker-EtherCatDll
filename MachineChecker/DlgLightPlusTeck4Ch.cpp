// DlgLightPlusTeck4Ch.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgLightPlusTeck4Ch.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/RS232DLL.lib")

// CDlgLightPlusTeck4Ch 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgLightPlusTeck4Ch, CDialog)

CDlgLightPlusTeck4Ch::CDlgLightPlusTeck4Ch(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_LIGHT_PLUSTEK_4CH, pParent)
{

}

CDlgLightPlusTeck4Ch::~CDlgLightPlusTeck4Ch()
{
	Close();
}

void CDlgLightPlusTeck4Ch::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLightPlusTeck4Ch, CDialog)
END_MESSAGE_MAP()


// CDlgLightPlusTeck4Ch 메시지 처리기입니다.


BOOL CDlgLightPlusTeck4Ch::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgLightPlusTeck4Ch::Init()
{
}

void CDlgLightPlusTeck4Ch::Close()
{
}
