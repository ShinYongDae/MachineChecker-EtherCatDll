// DlgMotionEtherCat.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotionEtherCat.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/EtherCatDLL.lib")

// CDlgMotionEtherCat 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMotionEtherCat, CDialog)

CDlgMotionEtherCat::CDlgMotionEtherCat(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION_ETHERCAT, pParent)
{

}

CDlgMotionEtherCat::~CDlgMotionEtherCat()
{
}

void CDlgMotionEtherCat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotionEtherCat, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgMotionEtherCat::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgMotionEtherCat::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgMotionEtherCat::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDlgMotionEtherCat::OnBnClickedCheck4)
END_MESSAGE_MAP()


// CDlgMotionEtherCat 메시지 처리기입니다.


BOOL CDlgMotionEtherCat::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgMotionEtherCat::Init()
{
	//LoadParam();
}

void CDlgMotionEtherCat::Close()
{
}


void CDlgMotionEtherCat::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(0, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(1, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(2, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}


void CDlgMotionEtherCat::OnBnClickedCheck4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	BOOL bOn = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	//if (!m_pEtherCat->SetAmpEnable(3, bOn))
	//{
	//	CString sMsg;
	//	sMsg.Format(_T("Amp %s Error."), bOn ? _T("Enable") : _T("Disable"));
	//	AfxMessageBox(sMsg);
	//}
}
