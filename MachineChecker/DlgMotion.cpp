// DlgMotion.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MachineChecker.h"
#include "DlgMotion.h"
#include "afxdialogex.h"

#pragma comment (lib, "Devices/EtherCatDLL.lib")

#include "MainFrm.h"
#include "MachineCheckerDoc.h"
#include "MachineCheckerView.h"

// CDlgMotion 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgMotion, CDialog)

CDlgMotion::CDlgMotion(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_MOTION, pParent)
{
	m_pEtherCat = NULL;
}

CDlgMotion::~CDlgMotion()
{
	Close();
}

void CDlgMotion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMotion, CDialog)
END_MESSAGE_MAP()


// CDlgMotion 메시지 처리기입니다.


BOOL CDlgMotion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetForegroundWindow();

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgMotion::Init()
{
	//LoadParam();
	if (!m_pEtherCat)
	{
		m_pEtherCat = new CEtherCat(this);
		if (!m_pEtherCat->InitBoard())
		{
			AfxMessageBox(_T("XMP 보드 초기화 실패, 다시 시작하세요.!!!"));
			PostMessage(WM_CLOSE);
		}
	}
}

void CDlgMotion::Close()
{
	if (m_pEtherCat)
	{
		delete m_pEtherCat;
		m_pEtherCat = NULL;
	}
}

//void CDlgMotion::LoadParam()
//{
//	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
//	CMachineCheckerView *pView = (CMachineCheckerView*)pFrame->GetActiveView();
//	CMachineCheckerDoc *pDoc = (CMachineCheckerDoc*)pFrame->GetActiveDocument();
//
//	CString sVal, sIdx;
//	TCHAR szData[200];
//	TCHAR sep[] = _T(",/;\r\n\t");
//	TCHAR *token;
//	TCHAR *stopstring;
//
//	int nID, nCol, i, nAxisID;
//
///*
//	// [CONTROL PARAM]
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL MOTION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotMotion = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotMotion = 0;
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL AXIS"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotAxis = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotAxis = 0;
//	m_nTotAxis = m_ParamCtrl.nTotAxis;
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL MOTOR"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotMotor = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotMotor = 0;
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL FILTER"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotFilter = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotFilter = 0;
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL CAPTURE"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotCapture = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotCapture = 0;
//	if (0 < ::GetPrivateProfileString(_T("CONTROL PARAM"), _T("TOTAL SEQUENCE"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//		m_ParamCtrl.nTotSequence = _ttoi(szData);
//	else
//		m_ParamCtrl.nTotSequence = 0;
//
//	// CreateObject - DataParam
//	if (!m_pParamMotion)
//		m_pParamMotion = new MotionMotion[m_ParamCtrl.nTotMotion];
//	if (!m_pParamAxis)
//		m_pParamAxis = new MotionAxis[m_ParamCtrl.nTotAxis];
//	if (!m_pParamMotor)
//		m_pParamMotor = new MotionMotor[m_ParamCtrl.nTotMotor];
//
//
//
//	// [OBJECT MAPPING]
//	for (nID = 0; nID < m_ParamCtrl.nTotAxis; nID++)
//	{
//		sIdx.Format(_T("AXIS%d"), nID);
//		if (0 < ::GetPrivateProfileString(_T("OBJECT MAPPING"), sIdx, NULL, szData, sizeof(szData), m_sPathMotionParam))
//		{
//			token = _tcstok(szData, sep);
//			nCol = 0;
//			if (token != NULL)
//				m_pParamAxis[nID].stAxisMap.nMappingMotor[nCol] = _ttoi(token);
//
//			while (token != NULL)
//			{
//				nCol++;
//				if (nCol >= 5)
//					break;
//				token = _tcstok(NULL, sep);
//				if (token != NULL)
//					m_pParamAxis[nID].stAxisMap.nMappingMotor[nCol] = _ttoi(token);
//			}
//
//			m_pParamAxis[nID].stAxisMap.nNumMotor = nCol;
//		}
//		else
//			m_pParamAxis[nID].stAxisMap.nNumMotor = 0;
//	}
//	for (nID = 0; nID < m_ParamCtrl.nTotMotion; nID++)
//	{
//		sIdx.Format(_T("MS%d"), nID);
//		if (0 < ::GetPrivateProfileString(_T("OBJECT MAPPING"), sIdx, NULL, szData, sizeof(szData), m_sPathMotionParam))
//		{
//			token = _tcstok(szData, sep);
//			nCol = 0;
//			if (token != NULL)
//			{
//				m_pParamMotion[nID].stMsMap.nMappingAxis[nCol] = nAxisID = _ttoi(token);
//				m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nNumMotor = m_pParamAxis[nAxisID].stAxisMap.nNumMotor;
//				for (i = 0; i < m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nNumMotor; i++)
//					m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nMappingMotor[i] = m_pParamAxis[nAxisID].stAxisMap.nMappingMotor[i];
//			}
//
//			while (token != NULL)
//			{
//				nCol++;
//				if (nCol >= 5)
//					break;
//				token = _tcstok(NULL, sep);
//				if (token != NULL)
//				{
//					m_pParamMotion[nID].stMsMap.nMappingAxis[nCol] = nAxisID = _ttoi(token);
//					m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nNumMotor = m_pParamAxis[nAxisID].stAxisMap.nNumMotor;
//					for (i = 0; i < m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nNumMotor; i++)
//						m_pParamMotion[nID].stMsMap.stMappingMotor[nCol].nMappingMotor[i] = m_pParamAxis[nAxisID].stAxisMap.nMappingMotor[i];
//				}
//			}
//
//			m_pParamMotion[nID].stMsMap.nNumAxis = nCol;
//		}
//		else
//			m_pParamMotion[nID].stMsMap.nNumAxis = 0;
//	}
//
//
//	// [AXIS PARAM]
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("AXIS NAME"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].sName = CString(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].sName = CString(token);
//		}
//	}
//	else
//		m_pParamAxis[nID].sName = _T(""); // Axis Name
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamAxis[nID].fSpd = 0.0; // [mm/s]
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("ACCELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamAxis[nID].fAcc = 0.0; // [G]=9.8*10^6[m/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("DECELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fDec = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fDec = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamAxis[nID].fDec = 0.0; // [G]=9.8*10^6[m/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("ACCELERATION PERIOD"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fAccPeriod = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fAccPeriod = _tcstod(token, &stopstring); // [%]
//		}
//	}
//	else
//		m_pParamAxis[nID].fAccPeriod = 0.0;
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("MAX ACCELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fMaxAccel = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fMaxAccel = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamAxis[nID].fMaxAccel = 0.0; // [G]=9.8*10^6[m/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("MIN JERK TIME"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fMinJerkTime = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fMinJerkTime = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamAxis[nID].fMinJerkTime = 0.0; // [sec]
//
//	if (0 < ::GetPrivateProfileString(_T("AXIS PARAM"), _T("INPOSITION LENGTH"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamAxis[nID].fInpRange = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotAxis)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamAxis[nID].fInpRange = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamAxis[nID].fInpRange = 0.0;	// Fine position tolerance of each motor
//
//
//											// [MOTOR PARAM]
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("MOTOR TYPE"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bType = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bType = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bType = 1; // 0: Servo Motor, 1: Step Motor
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("MOTOR RATING SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].fRatingSpeed = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].fRatingSpeed = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotor[nID].fRatingSpeed = 0.0; // 0: Servo Motor, 1: Step Motor
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("MOTOR DIRECTION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].nDir = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].nDir = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].nDir = 1; // -1: CCW, 1: CW
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("FEEDBACK SOURCE"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bEncoder = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bEncoder = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bEncoder = 0; // 1: External Encoder 0: Internal Pulse Out
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("ENCODER PULSE"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].nEncPulse = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].nEncPulse = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].nEncPulse = 0; // [pulse/rev]
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("LEAD PITCH"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].fLeadPitch = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].fLeadPitch = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotor[nID].fLeadPitch = 0.0; // Ball Screw Lead Pitch [mm]
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("ENCODER MULTIPLIER"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].nEncMul = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].nEncMul = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].nEncMul = 0; // Encoder Multiplier
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("GEAR RATIO"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].fGearRatio = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].fGearRatio = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotor[nID].fGearRatio = 0.0; // Gear Ratio
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("AMP ENABLE LEVEL"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bAmpEnableLevel = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bAmpEnableLevel = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bAmpEnableLevel = 1; // Amp Enable Level 0: Low Active 1: High Active
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("AMP FAULT LEVEL"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bAmpFaultLevel = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bAmpFaultLevel = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bAmpFaultLevel = 1; // Amp Fault Level 0: Low Active 1: High Active
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("POS LIMIT SENSOR LEVEL"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bPosLimitLevel = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bPosLimitLevel = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bPosLimitLevel = 1; // Positive Limit sensor active Level 0: Low Active 1: High Active
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("NEG LIMIT SENSOR LEVEL"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bNegLimitLevel = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bNegLimitLevel = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bNegLimitLevel = 1; // Negative Limit sensor active Level 0: Low Active 1: High Active
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("HOME SENSOR LEVEL"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].bHomeLevel = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].bHomeLevel = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotor[nID].bHomeLevel = 1; // Home sensor active Level 0: Low Active 1: High Active
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("POSITIVE SOFTWARE LIMIT"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].fPosLimit = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].fPosLimit = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotor[nID].fPosLimit = 0.0; // Sotftware positive motion limit
//
//	if (0 < ::GetPrivateProfileString(_T("MOTOR PARAM"), _T("NEGATIVE SOFTWARE LIMIT"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotor[nID].fNegLimit = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotor)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotor[nID].fNegLimit = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotor[nID].fNegLimit = 0.0; // Sotftware negative motion limit
//
//
//											// [MOTION PARAM]
//	if (0 < ::GetPrivateProfileString(_T("MOTION PARAM"), _T("ESTOP TIME"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].dEStopTime = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].dEStopTime = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].dEStopTime = 0.1; // [Sec]
//
//											  // [HOME PARAM]
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("ACTION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.bAct = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.bAct = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.bAct = 0; // 0: Don't 1:Do
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("SEARCH DIRECTION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.nDir = _ttoi(token);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.nDir = _ttoi(token);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.nDir = -1; // -1: Minus 1:Plus
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("ESCAPE LENGTH"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.fEscLen = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.fEscLen = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.fEscLen = 0.0; // Escape length from home sensor touch position
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("1'st SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.f1stSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.f1stSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.f1stSpd = 0.0; // [mm/s] or [deg/s^2] Fast speed for home search 
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("2'nd SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.f2ndSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.f2ndSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.f2ndSpd = 0.0; // [mm/s] or [deg/s^2] Fast speed for home search 
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("ACCELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.fAcc = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.fAcc = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.fAcc = 0.0; // [mm/s^2] or [deg/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("SHIFT"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.fShift = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.fShift = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.fShift = 0.0; // [mm]
//
//	if (0 < ::GetPrivateProfileString(_T("HOME PARAM"), _T("OFFSET"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Home.fOffset = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Home.fOffset = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Home.fOffset = 0.0; // [mm] or [deg]
//
//
//												// [SPEED PARAM]
//	if (0 < ::GetPrivateProfileString(_T("SPEED PARAM"), _T("SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fSpd = 0.0; // [mm/s]
//
//	if (0 < ::GetPrivateProfileString(_T("SPEED PARAM"), _T("ACCELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fAcc = 0.0; // [G]=9.8*10^6[m/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("SPEED PARAM"), _T("DECELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fDec = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fDec = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fDec = 0.0; // [G]=9.8*10^6[m/s^2]
//
//	if (0 < ::GetPrivateProfileString(_T("SPEED PARAM"), _T("ACCELERATION PERIOD"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fAccPeriod = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fAccPeriod = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fAccPeriod = 0.0; // [%]
//
//
//													// [JOG PARAM]
//	if (0 < ::GetPrivateProfileString(_T("JOG PARAM"), _T("FAST SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fJogFastSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fJogFastSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fJogFastSpd = 0.0; // [mm/s] or [deg/s^2] Fast speed
//
//	if (0 < ::GetPrivateProfileString(_T("JOG PARAM"), _T("MIDDLE SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fJogMidSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fJogMidSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fJogMidSpd = 0.0; // [mm/s] or [deg/s^2] Middle speed
//
//	if (0 < ::GetPrivateProfileString(_T("JOG PARAM"), _T("LOW SPEED"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fJogLowSpd = _tcstod(token, &stopstring);
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fJogLowSpd = _tcstod(token, &stopstring);
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fJogLowSpd = 0.0; // [mm/s] or [deg/s^2] Middle speed
//
//	if (0 < ::GetPrivateProfileString(_T("JOG PARAM"), _T("ACCELERATION"), NULL, szData, sizeof(szData), m_sPathMotionParam))
//	{
//		token = _tcstok(szData, sep);
//		nID = 0;
//		if (token != NULL)
//			m_pParamMotion[nID].Speed.fJogAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//
//		while (token != NULL)
//		{
//			nID++;
//			if (nID >= m_ParamCtrl.nTotMotion)
//				break;
//			token = _tcstok(NULL, sep);
//			if (token != NULL)
//				m_pParamMotion[nID].Speed.fJogAcc = _tcstod(token, &stopstring)*9.8*1000.0;
//		}
//	}
//	else
//		m_pParamMotion[nID].Speed.fJogAcc = 0.0; // [G]=9.8*10^6[m/s^2]
//*/
//}
