#pragma once

#include "ETradeLoginInfoXMLController.h"
#include "ETradeLoginInfoManager.h"

class IXingAPI;

class CDlgETradeLoginStatus : public CDialog{
	DECLARE_DYNAMIC(CDlgETradeLoginStatus)

	public:
		CDlgETradeLoginStatus(CWnd* pParent = NULL);   // standard constructor
		virtual ~CDlgETradeLoginStatus();
		virtual BOOL OnInitDialog();

		// User-define Functions
		void SetLoginTime();
		void WriteLoginInfoText(const ETradeLoginInfo& loginInfo);
		void CheckAutoLogin(BOOL autoLogin);
		void CheckBoxLogInStatus(BOOL status);
		//void UncheckLogInStatus();
		void WriteUserInfoText(const ETradeUserInfo& userInfo);
		void WriteServerInfoText(const ETradeServerInfo& serverInfo);

		ETradeLoginInfo ReadLoginInfoText();
		BOOL ReadAutoLogin();
		ETradeUserInfo ReadUserInfoText();
		ETradeServerInfo ReadServerInfoText();
		LoginTime ReadLoginTime();

		void DisableLoginInfo();
		void EnableLoginInfo();

		BOOL GetEditable() const;
		ETradeLoginInfo& GetLoginInfo() const;
		void SetLoginInfo(const ETradeLoginInfo& info);

		BOOL ConnectServer();
		BOOL LogIn();
		BOOL LogOut();
		BOOL KeepConnectedAndLoggedIn();

	public:
		IXingAPI* xingAPI;	

	// Dialog Data
		enum { IDD = IDD_DIALOG_ETRADE_LOGIN_STATUS_BAR };

	private:
		ETradeLoginInfo loginInfo;

	protected:
		BOOL editable;

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

		DECLARE_MESSAGE_MAP()
		afx_msg void OnTimer(UINT_PTR nIDEvent);

	private:

		BOOL BetweenBusinessHours();


		CButton checkKeepLogin;
		CDateTimeCtrl timeCtrlStart;
		CDateTimeCtrl timeCtrlEnd;

		UINT_PTR timerIDKeepLogin;

};


inline BOOL CDlgETradeLoginStatus::GetEditable() const{
	return this->editable;
}

inline ETradeLoginInfo& CDlgETradeLoginStatus::GetLoginInfo() const{
	return const_cast<ETradeLoginInfo&>(this->loginInfo);
}

inline void CDlgETradeLoginStatus::SetLoginInfo(const ETradeLoginInfo& info){
	this->loginInfo = info;
}