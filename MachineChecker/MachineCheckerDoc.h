
// MachineCheckerDoc.h : CMachineCheckerDoc 클래스의 인터페이스
//


#pragma once

#define MAX_LIGHT	4
#define MAX_CAMERA	4


struct stInfo
{
	CString sProgramVersion, sMachineName, sConfigFileVersion;

	stInfo()
	{
		sProgramVersion = _T(""); sMachineName = _T(""); sConfigFileVersion = _T("");
	}
};

struct stDevices
{
	int nNumLight, nNumCamera;
	CString sIO, sLight[MAX_LIGHT], sMotion, sCamera[MAX_CAMERA], sTrigger, s2DBarcode;

	stDevices()
	{
		int i;
		nNumLight = 0; nNumCamera = 0;
		sIO = _T(""); sMotion = _T(""); sTrigger = _T(""); s2DBarcode = _T("");		
		for (i = 0; i < MAX_LIGHT; i++) sLight[i] = _T("");
		for (i = 0; i < MAX_CAMERA; i++) sCamera[i] = _T("");
	}
};

struct stConfig
{
	stInfo Info;
	stDevices Devices;
};

class CMachineCheckerDoc : public CDocument
{
	stConfig m_stConfig;
	CString m_sPathPrevConfigFolder, m_sNamePrevConfigFile;

protected: // serialization에서만 만들어집니다.
	CMachineCheckerDoc();
	DECLARE_DYNCREATE(CMachineCheckerDoc)

// 특성입니다.
public:

// 작업입니다.
public:
	CString GetPathPrevConfigFolder();
	CString GetNamePrevConfigFile();
	void SetPathPrevConfigFolder(CString sPath);
	void SetNamePrevConfigFile(CString sName);

	BOOL LoadConfig(CString sPath, CString& sData);
	CString GetProgramVersion();
	CString GetConfigFileVersion();
	CString GetMachineName();
	CString GetDeviceNameIO();
	CString GetDeviceNameLight(int nIndex);
	CString GetDeviceNameMotion();
	CString GetDeviceNameCamera(int nIndex);
	CString GetDeviceNameTrigger();
	CString GetDeviceName2DBarcode();

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CMachineCheckerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
