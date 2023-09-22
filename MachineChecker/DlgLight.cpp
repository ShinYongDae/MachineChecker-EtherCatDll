// DlgLight.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgLight.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/RS232DLL.lib")

// CDlgLight 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgLight, CDialog)

CDlgLight::CDlgLight(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_LIGHT, pParent)
{
	m_sRcvRs232 = _T("");
	m_sDispRcvRs232 = _T("");

	int i;
	for (i = 0; i < MAX_LIGHT_CH; i++)
	{
		m_bCh[i] = FALSE;
		m_nCh[i] = 0;
	}

}

CDlgLight::~CDlgLight()
{
	Close();
}

void CDlgLight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgLight, CDialog)
	ON_MESSAGE(WM_RECEIVE_RS232, OnReceiveRs232)
	ON_BN_CLICKED(IDC_BTN_TEST, &CDlgLight::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CDlgLight 메시지 처리기입니다.


BOOL CDlgLight::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();
	//Set(0, 255);
	//Set(1, 255);
	//Set(2, 255);
	//Set(3, 255);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgLight::Init()
{
	//// Verify DLL
	//CString sM;
	//sM.Format(_T("Parent Handle is %d"), this->GetSafeHwnd());
	//AfxMessageBox(sM);

	m_Rs232.SetHwnd(this->GetSafeHwnd());
	m_Rs232.m_nPort = 3;
	m_Rs232.m_dwBaudRate = 9600;
	m_Rs232.m_bCR = FALSE;
	m_Rs232.m_bLF = FALSE;
	m_bRs232Run = m_Rs232.OpenComPort();
	if (!m_bRs232Run)
		AfxMessageBox(_T("조명 제어장치가 초기화되지 않았습니다."));
}

void CDlgLight::Close()
{
	if (m_bRs232Run)
	{
		m_Rs232.DestroyRs232();
		m_bRs232Run = FALSE;
	}
}

LRESULT CDlgLight::OnReceiveRs232(WPARAM wP, LPARAM lP)
{
	CString str;
	str.Format(_T("%s"), m_Rs232.m_cRxBuffer);
	m_sRcvRs232 += str;			// Temporary Buffer
	m_sDispRcvRs232 += str;		// Permanent Buffer

	m_Rs232.ClearReceive();

	GetDlgItem(IDC_EDIT_RECEIVE)->SetWindowText(m_sDispRcvRs232);

	return 0L;
}

CString CDlgLight::Rcv()
{
	CString sRcv = m_sRcvRs232;
	m_Rs232.ClearReceive();
	m_sRcvRs232 = _T("");

	return sRcv;
}

BOOL CDlgLight::Send(CString str)
{
	int nLen = str.GetLength();

	//char* cSend = new char[nLen+1];
	//strcpy(cSend, str);
	char* pRtn = NULL;
	TCHAR* cSend = new TCHAR[nLen + 1];
	wsprintf(cSend, TEXT("%s"), str);
	BOOL bRtn = m_Rs232.WriteRs232Block(pRtn = TCHARToChar(cSend), nLen); if (pRtn) delete pRtn; pRtn = NULL;
	delete cSend;

	return TRUE;
}

BOOL CDlgLight::Set(int nCh, int nVal)
{
	if (nVal < 0)
		nVal = m_nCh[nCh];
	else
	{
		if (nVal > 255)
			nVal = 255;
		m_nCh[nCh] = nVal;
	}

	if (!nVal)
		m_bCh[nCh] = FALSE;
	else
		m_bCh[nCh] = TRUE;

	CString str;
	str.Format(_T("setbrightness %d %d"), nCh, nVal);
	Send(str);

	return TRUE;
}

int CDlgLight::Get(int nCh)
{
	return m_nCh[nCh];
}

void CDlgLight::Reset(int nCh)
{
	CString str;
	str.Format(_T("setbrightness %d %d"), nCh, 0);
	Send(str);
	m_bCh[nCh] = FALSE;
}

char* CDlgLight::TCHARToChar(TCHAR *tszStr) // TCHAR* returned must be deleted... 
{
	char *szStr = NULL;
	int nLength;

	USES_CONVERSION;
	LPWSTR lpWideCharStr = T2W(tszStr);

	nLength = WideCharToMultiByte(CP_ACP, 0, lpWideCharStr, -1, NULL, NULL, NULL, NULL);
	szStr = new char[nLength + 1];
	WideCharToMultiByte(CP_ACP, 0, lpWideCharStr, -1, szStr, nLength, NULL, NULL);

	return szStr;
}


void CDlgLight::OnBnClickedBtnTest()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Set(0, 255);
	//Set(1, 255);
	//Set(2, 255);
	//Set(3, 255);
}
