
// TradingSystem.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "TradingSystem.h"
#include "MainFrm.h"

#include "TradingSystemDoc.h"
#include "TradingSystemView.h"

#include "IXingAPI.h"
#include "TradingSystemManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTradingSystemApp

BEGIN_MESSAGE_MAP(CTradingSystemApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CTradingSystemApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// CTradingSystemApp construction

CTradingSystemApp::CTradingSystemApp(){
	SetAppID(_T("TradingSystem.AppID.NoVersion"));
	// 증권사 API 초기화
	this->xingAPI = new IXingAPI();
	this->xingAPI->Init();

	this->tradingSystemManager = new TradingSystemManager();

}

CTradingSystemApp::~CTradingSystemApp(){
	if(this->xingAPI->IsConnected()==TRUE){
		this->xingAPI->Logout(NULL);
		this->xingAPI->Disconnect();
	}
	if(this->xingAPI!=0){
		delete this->xingAPI;
	}


	if(this->tradingSystemManager!=0){
		delete this->tradingSystemManager;
	}
};

// The one and only CTradingSystemApp object

CTradingSystemApp theApp;

// CTradingSystemApp initialization

BOOL CTradingSystemApp::InitInstance(){
	CWinApp::InitInstance();
	EnableTaskbarInteraction(FALSE);

	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4); 

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTradingSystemDoc),
		RUNTIME_CLASS(CMainFrame),      
		RUNTIME_CLASS(CTradingSystemView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	
	return TRUE;
}

// CTradingSystemApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx{
	public:
		CAboutDlg();

	// Dialog Data
		enum { IDD = IDD_ABOUTBOX };

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
	protected:
		DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CTradingSystemApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CTradingSystemApp message handlers



