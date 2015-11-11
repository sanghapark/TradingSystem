// LoginInfo.h
#ifndef _ETRADE_LOGIN_INFO_H
#define _ETRADE_LOGIN_INFO_H

#include "DataTypeDefinition.h"
#include "ETradeServerInfo.h"
#include "ETradeUserInfo.h"
#include "LoginTime.h"

class ETradeLoginInfo{
public:
	ETradeLoginInfo();
	//ETradeLoginInfo(const ETradeUserInfo& userInfo, const ETradeServerInfo& serverInfo);
	ETradeLoginInfo(bool autoLogin, const ETradeUserInfo& userInfo, const ETradeServerInfo& serverInfo, const LoginTime& loginTime);
	ETradeLoginInfo(const ETradeLoginInfo& source);
	~ETradeLoginInfo();

	void AssignUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg);
	void AssignServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime);

	ETradeLoginInfo& operator=(const ETradeLoginInfo& source);
	bool operator==(const ETradeLoginInfo& other);
	bool operator!=(const ETradeLoginInfo& other);
	bool IsEqual(const ETradeLoginInfo& other);
	bool IsNotEqual(const ETradeLoginInfo& other);

	void SetAutoLogin(bool autoLogin);
	void SetServerInfo(const ETradeServerInfo& serverInfo);
	void SetUserInfo(const ETradeUserInfo& userInfo);
	void SetLoginTime(const LoginTime& loginTime);

	bool GetAutoLogin() const;
	ETradeServerInfo& GetServerInfo() const;
	ETradeUserInfo& GetUserInfo() const;
	LoginTime& GetLoginTime() const;

private:
	bool autoLogin;
	ETradeServerInfo serverInfo;
	ETradeUserInfo userInfo;
	LoginTime loginTime;
};

inline void ETradeLoginInfo::SetAutoLogin(bool autoLogin){
	this->autoLogin = autoLogin;
}


inline void ETradeLoginInfo::SetServerInfo(const ETradeServerInfo& serverInfo){
	this->serverInfo = serverInfo;
}

inline void ETradeLoginInfo::SetUserInfo(const ETradeUserInfo& userInfo){
	this->userInfo = userInfo;
}


inline void ETradeLoginInfo::SetLoginTime(const LoginTime& loginTime){
	this->loginTime = loginTime;
}


inline bool ETradeLoginInfo::GetAutoLogin() const{
	return this->autoLogin;
}



inline ETradeServerInfo& ETradeLoginInfo::GetServerInfo() const{
	return const_cast<ETradeServerInfo&>(this->serverInfo);
}


inline ETradeUserInfo& ETradeLoginInfo::GetUserInfo() const{
	return const_cast<ETradeUserInfo&>(this->userInfo);
}


inline LoginTime& ETradeLoginInfo::GetLoginTime() const{
	return const_cast<LoginTime&>(this->loginTime);
}


#endif
