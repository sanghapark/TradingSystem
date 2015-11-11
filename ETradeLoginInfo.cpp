// LoginInfo.cpp

#include "ETradeLoginInfo.h"

ETradeLoginInfo::ETradeLoginInfo(){
	this->autoLogin = false;
}

//ETradeLoginInfo::ETradeLoginInfo(const ETradeUserInfo& userInfo, const ETradeServerInfo& serverInfo)
//	:serverInfo(serverInfo),
//	userInfo(userInfo){
//	this->autoLogin = false;
//}
//
ETradeLoginInfo::ETradeLoginInfo(bool autoLogin, const ETradeUserInfo& userInfo, const ETradeServerInfo& serverInfo, const LoginTime& loginTime)
	:serverInfo(serverInfo),
	userInfo(userInfo),
	loginTime(loginTime){
		this->autoLogin = autoLogin;
}


ETradeLoginInfo::ETradeLoginInfo(const ETradeLoginInfo& source)
	:serverInfo(source.serverInfo),
	userInfo(source.userInfo),
	loginTime(source.loginTime){
		this->autoLogin = source.autoLogin;
}


ETradeLoginInfo::~ETradeLoginInfo(){
}


void ETradeLoginInfo::AssignUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg){
	this->userInfo.AssignUserInfo(id, password, authorizingPassword, authorizingPasswordErrorMsg);
}

void ETradeLoginInfo::AssignServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime){
	this->serverInfo.AssignServerInfo(serverType, serverName, serverAddress, serverPort, maxTransferSize, connectingTime);
}


ETradeLoginInfo& ETradeLoginInfo::operator=(const ETradeLoginInfo& source){
	this->autoLogin = source.autoLogin;
	this->serverInfo  = source.serverInfo;
	this->userInfo = source.userInfo;
	this->loginTime = source.loginTime;
	return *this;
}


bool ETradeLoginInfo::operator==(const ETradeLoginInfo& other){
	bool ret= false;
	if( this->autoLogin == other.autoLogin &&
		this->serverInfo==other.serverInfo &&
		this->userInfo==other.userInfo &&
		this->loginTime == other.loginTime){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfo::operator!=(const ETradeLoginInfo& other){
	bool ret= false;
	if( this->autoLogin!=other.autoLogin ||
		this->serverInfo!=other.serverInfo ||
		this->userInfo!=other.userInfo ||
		this->loginTime != other.loginTime){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfo::IsEqual(const ETradeLoginInfo& other){
	bool ret=false;
	if( this->autoLogin == other.autoLogin &&
		this->serverInfo.IsEqual(other.serverInfo)==true &&
		this->userInfo.IsEqual(other.userInfo)==true &&
		this->loginTime.IsEqual(other.loginTime) == true){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfo::IsNotEqual(const ETradeLoginInfo& other){
	bool ret=false;
	if( this->autoLogin != other.autoLogin ||
		this->serverInfo.IsNotEqual(other.serverInfo)==true ||
		this->userInfo.IsNotEqual(other.userInfo)==true ||
		this->loginTime.IsNotEqual(other.loginTime) == true){
			ret = true;
	}
	return ret;
}