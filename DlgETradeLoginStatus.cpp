// DlgETradeLoginStatus.cpp : implementation file
//

#include "stdafx.h"
#include "TradingSystem.h"
#include "DlgETradeLoginStatus.h"
#include "afxdialogex.h"
#include "DataConverter.h"
#include "IXingAPI.h"
#include "TradingSystem.h"
#include "DlgLoginStatusTabBar.h"
#include "packet/JIF.h"

using namespace std;


// CDlgETradeLoginStatus dialog

IMPLEMENT_DYNAMIC(CDlgETradeLoginStatus, CDialog)



BEGIN_MESSAGE_MAP(CDlgETradeLoginStatus, CDialog)
	ON_WM_TIMER()
END_MESSAGE_MAP()



CDlgETradeLoginStatus::CDlgETradeLoginStatus(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgETradeLoginStatus::IDD, pParent){
	CTradingSystemApp* app = (CTradingSystemApp*)AfxGetApp();
	this->xingAPI = app->xingAPI;
}

CDlgETradeLoginStatus::~CDlgETradeLoginStatus(){
}

void CDlgETradeLoginStatus::DoDataExchange(CDataExchange* pDX){
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER_TIME_START, this->timeCtrlStart);
	DDX_Control(pDX, IDC_DATETIMEPICKER_TIME_END, this->timeCtrlEnd);
	DDX_Control(pDX, IDC_CHECK_AND_KEEP_LOGIN, this->checkKeepLogin);
}


BOOL CDlgETradeLoginStatus::OnInitDialog(){
	CDialog::OnInitDialog();

	this->WriteLoginInfoText(this->loginInfo);

	// auto login에 따라 xingAPI 로긴 함수 호출 및 로긴창 Disable
	if(this->loginInfo.GetAutoLogin()==TRUE){
		this->DisableLoginInfo();
		// XingAPI.Login();
		BOOL logged = this->LogIn();
	}
	else{
		this->EnableLoginInfo();
	}


	this->timerIDKeepLogin = (UINT_PTR)(&this->checkKeepLogin);
	this->checkKeepLogin.SetCheck(loginInfo.GetLoginTime().GetChecker());
	if(this->checkKeepLogin.GetCheck()==TRUE){
		this->SetTimer(this->timerIDKeepLogin, 5000, NULL);
	}

	return FALSE;

}




void CDlgETradeLoginStatus::WriteLoginInfoText(const ETradeLoginInfo& loginInfo){
	this->loginInfo = loginInfo;
	this->SetLoginTime();
	this->WriteUserInfoText(this->loginInfo.GetUserInfo());
	this->WriteServerInfoText(this->loginInfo.GetServerInfo());
	this->CheckAutoLogin(this->loginInfo.GetAutoLogin());
}


void CDlgETradeLoginStatus::SetLoginTime(){
	CTime currentTime = CTime::GetCurrentTime();
	CTime timeStartToSet(currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), 8, 50, 0);
	CTime timeEndToSet(currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), 15, 30, 0);

	this->timeCtrlStart.SetTime(&timeStartToSet);
	this->timeCtrlEnd.SetTime(&timeEndToSet);
	
	this->checkKeepLogin.SetCheck(loginInfo.GetLoginTime().GetChecker());
}



void CDlgETradeLoginStatus::CheckAutoLogin(BOOL autoLogin){
	if(autoLogin==TRUE){
		this->CheckDlgButton(IDC_CHECK_AUTO_LOGIN, TRUE);
	}
	else{
		this->CheckDlgButton(IDC_CHECK_AUTO_LOGIN, FALSE);
	}
}

void CDlgETradeLoginStatus::CheckBoxLogInStatus(BOOL status){
	this->CheckDlgButton(IDC_CHECK_LOGIN_STATUS, status);
}


//void CDlgETradeLoginStatus::UncheckLogInStatus(){
//	this->CheckDlgButton(IDC_CHECK_LOGIN_STATUS, FALSE);
//}



void CDlgETradeLoginStatus::WriteUserInfoText(const ETradeUserInfo& userInfo){
	((CEdit*)this->GetDlgItem(IDC_EDIT_ID))->SetWindowText(userInfo.GetID().c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_PASSWORD))->SetWindowText(userInfo.GetPassword().c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_AUTHORIZING_PASSWORD))->SetWindowText(userInfo.GetAuthorizingPassword().c_str());
	if(userInfo.GetAuthorizingPasswordErrorMsg()==TRUE){
		this->CheckDlgButton(IDC_CHECK_ERROR_MESSAGE, TRUE);
	}
	else{
		this->CheckDlgButton(IDC_CHECK_ERROR_MESSAGE, FALSE);
	}
}

void CDlgETradeLoginStatus::WriteServerInfoText(const ETradeServerInfo& serverInfo){
	DataConverter dataConverter;
	if(serverInfo.GetServerType()>0){
		((CButton*)(this->GetDlgItem(IDC_RADIO_REAL)))->SetCheck(TRUE);
	}
	else{
		((CButton*)(this->GetDlgItem(IDC_RADIO_SIMULATION)))->SetCheck(TRUE);
	}
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_NAME))->SetWindowText(serverInfo.GetServerName().c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_ADDRESS))->SetWindowText(serverInfo.GetServerAddress().c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_PORT))->SetWindowText(dataConverter.ConvertIntToString(serverInfo.GetServerPort()).c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_MAX_TRANSFER_SIZE))->SetWindowText(dataConverter.ConvertIntToString(serverInfo.GetMaxTransferSize()).c_str());
	((CEdit*)this->GetDlgItem(IDC_EDIT_CONNECTING_TIME))->SetWindowText(dataConverter.ConvertIntToString(serverInfo.GetConnectingTime()).c_str());

}


ETradeLoginInfo CDlgETradeLoginStatus::ReadLoginInfoText(){
	ETradeLoginInfo loginInfo(this->ReadAutoLogin(),
								this->ReadUserInfoText(),
								this->ReadServerInfoText(),
								this->ReadLoginTime());
	this->loginInfo = loginInfo;
	return this->loginInfo;
}

BOOL CDlgETradeLoginStatus::ReadAutoLogin(){
	return this->IsDlgButtonChecked(IDC_CHECK_AUTO_LOGIN);
}

ETradeUserInfo CDlgETradeLoginStatus::ReadUserInfoText(){
	ETradeUserInfo userInfo;
	CString id;
	CString pw;
	CString authorPW;
	BOOL errorMsg=FALSE;
	((CEdit*)this->GetDlgItem(IDC_EDIT_ID))->GetWindowText(id);
	((CEdit*)this->GetDlgItem(IDC_EDIT_PASSWORD))->GetWindowText(pw);
	((CEdit*)this->GetDlgItem(IDC_EDIT_AUTHORIZING_PASSWORD))->GetWindowText(authorPW);
	errorMsg = this->IsDlgButtonChecked(IDC_CHECK_ERROR_MESSAGE);

	userInfo.AssignUserInfo((LPCTSTR)id, (LPCTSTR)pw, (LPCTSTR)authorPW, errorMsg);
	return userInfo;
}


ETradeServerInfo CDlgETradeLoginStatus::ReadServerInfoText(){
	ETradeServerInfo serverInfo;
	int checkedButton;
	int serverType;
	CString name;
	CString address;
	CString port;
	CString maxTransferSize;
	CString connectingTime;
	DataConverter dataConverter;

	checkedButton = this->GetCheckedRadioButton(IDC_RADIO_REAL, IDC_RADIO_SIMULATION);
	switch(checkedButton){
	case IDC_RADIO_REAL:
		serverType = TRUE;
		break;
	case IDC_RADIO_SIMULATION:
		serverType = FALSE;
		break;
	default:
		serverType = FALSE;
		break;
	}

	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_NAME))->GetWindowText(name);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_ADDRESS))->GetWindowText(address);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_PORT))->GetWindowText(port);
	((CEdit*)this->GetDlgItem(IDC_EDIT_MAX_TRANSFER_SIZE))->GetWindowText(maxTransferSize);
	((CEdit*)this->GetDlgItem(IDC_EDIT_CONNECTING_TIME))->GetWindowText(connectingTime);

	serverInfo.AssignServerInfo(serverType, (LPCTSTR)name, (LPCTSTR)address, 
								dataConverter.ConvertStringToInt((LPCTSTR)port), 
								dataConverter.ConvertStringToInt((LPCTSTR)maxTransferSize), 
								dataConverter.ConvertStringToInt((LPCTSTR)connectingTime));

	return serverInfo;
}


LoginTime CDlgETradeLoginStatus::ReadLoginTime(){
	CTime cTimeTemp;
	DWORD dwordTemp;
	
	dwordTemp = this->timeCtrlStart.GetTime(cTimeTemp);
	CString cstrTimeStart= cTimeTemp.Format(_T("%H:%M:%S"));
	tstring timeStart(cstrTimeStart);

	dwordTemp = this->timeCtrlEnd.GetTime(cTimeTemp);
	CString cstrTimeEnd = cTimeTemp.Format(_T("%H:%M:%S"));
	tstring timeEnd(cstrTimeEnd);
	
	bool checker;
	LoginTime ret(timeStart, timeEnd, checker);
	return ret;
}


void CDlgETradeLoginStatus::DisableLoginInfo(){
	(CButton*)(this->GetDlgItem(IDC_CHECK_AUTO_LOGIN))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_ID))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_AUTHORIZING_PASSWORD))->EnableWindow(FALSE);
	(CButton*)(this->GetDlgItem(IDC_CHECK_ERROR_MESSAGE))->EnableWindow(FALSE);
	(CButton*)(this->GetDlgItem(IDC_RADIO_REAL))->EnableWindow(FALSE);
	(CButton*)(this->GetDlgItem(IDC_RADIO_SIMULATION))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_NAME))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_ADDRESS))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_PORT))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_MAX_TRANSFER_SIZE))->EnableWindow(FALSE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_CONNECTING_TIME))->EnableWindow(FALSE);	
	this->editable=FALSE;
}
	
void CDlgETradeLoginStatus::EnableLoginInfo(){
	(CButton*)(this->GetDlgItem(IDC_CHECK_AUTO_LOGIN))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_ID))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_PASSWORD))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_AUTHORIZING_PASSWORD))->EnableWindow(TRUE);
	(CButton*)(this->GetDlgItem(IDC_CHECK_ERROR_MESSAGE))->EnableWindow(TRUE);
	(CButton*)(this->GetDlgItem(IDC_RADIO_REAL))->EnableWindow(TRUE);
	(CButton*)(this->GetDlgItem(IDC_RADIO_SIMULATION))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_NAME))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_ADDRESS))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_SERVER_PORT))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_MAX_TRANSFER_SIZE))->EnableWindow(TRUE);
	((CEdit*)this->GetDlgItem(IDC_EDIT_CONNECTING_TIME))->EnableWindow(TRUE);
	this->editable=TRUE;
}





BOOL CDlgETradeLoginStatus::ConnectServer(){
	BOOL ret = FALSE;
	if( this->xingAPI->IsConnected()==TRUE){
		this->xingAPI->Disconnect();
	}
	ETradeServerInfo serverInfo = this->ReadServerInfoText();
	ret = this->xingAPI->Connect(GetSafeHwnd(), 
		serverInfo.GetServerAddress().c_str(), 
		serverInfo.GetServerPort(), 
		WM_USER, 
		serverInfo.GetConnectingTime(),
		serverInfo.GetMaxTransferSize());

	if( ret == FALSE ){
		int nErrorCode = this->xingAPI->GetLastError();
		CString strMsg = this->xingAPI->GetErrorMessage( nErrorCode );
		MessageBox( strMsg, TEXT("서버접속실패"), MB_ICONSTOP );
	}
	return ret;
}


BOOL CDlgETradeLoginStatus::LogIn(){
	BOOL ret = FALSE;
	BOOL connected = this->ConnectServer();
	if(connected==TRUE){
		ETradeLoginInfo loginInfo = this->GetLoginInfo();
		ret = this->xingAPI->Login(GetSafeHwnd(), 
						loginInfo.GetUserInfo().GetID().c_str(),
						loginInfo.GetUserInfo().GetPassword().c_str(),
						loginInfo.GetUserInfo().GetAuthorizingPassword().c_str(),
						loginInfo.GetServerInfo().GetServerType(),
						FALSE);
		if( ret == FALSE ){
			int nErrorCode = this->xingAPI->GetLastError();
			CString strMsg = this->xingAPI->GetErrorMessage( nErrorCode );
			MessageBox( strMsg, TEXT("로그인 실패"), MB_ICONSTOP );
			this->CheckBoxLogInStatus(FALSE);
		}
		else{
			this->CheckBoxLogInStatus(TRUE);
		}
	}
	return ret;
}

BOOL CDlgETradeLoginStatus::LogOut(){
	BOOL ret = FALSE;
	this->xingAPI->Disconnect();
	ret = this->xingAPI->Logout(GetSafeHwnd());
	if(ret = TRUE){
		this->CheckBoxLogInStatus(FALSE);
	}
	return ret;
}



void CDlgETradeLoginStatus::OnTimer(UINT_PTR nIDEvent){
	if(this->checkKeepLogin.GetCheck()==TRUE && this->BetweenBusinessHours()==TRUE){
		if(nIDEvent == this->timerIDKeepLogin){
			this->KeepConnectedAndLoggedIn();
			this->checkKeepLogin.SetCheck(TRUE);
		}
		else{
		}
	}
}



BOOL CDlgETradeLoginStatus::KeepConnectedAndLoggedIn(){
	BOOL ret = TRUE;
	BOOL connected = this->xingAPI->IsConnected();
	if(connected == FALSE){
		ret = this->LogIn();
		// ret가 TRUE면 여기서 DlgDataFeedingModule에 신호 보낸다. (Dialog 존재하면)
		AfxGetMainWnd()->SendMessage(WMU_READVISE_DATA_FEEDING, NULL, NULL);
	}
	return ret;
}



BOOL CDlgETradeLoginStatus::BetweenBusinessHours(){
	BOOL ret = FALSE;
	CTime currentTime = CTime::GetCurrentTime();

	CTime cTimeStart;
	this->timeCtrlStart.GetTime(cTimeStart);

	CTime cTimeEnd;
	this->timeCtrlEnd.GetTime(cTimeEnd);

	if(currentTime>=cTimeStart && currentTime <=cTimeEnd){
		ret = TRUE;
	}
	return ret;
}

