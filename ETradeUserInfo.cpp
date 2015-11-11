
#include "ETradeUserInfo.h"


ETradeUserInfo::ETradeUserInfo(){
	this->authorizingPasswordErrorMsg=false;
}


ETradeUserInfo::ETradeUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg)
	:id(id),
	password(password),
	authorizingPassword(authorizingPassword){
		this->authorizingPasswordErrorMsg = authorizingPasswordErrorMsg;
}


ETradeUserInfo::ETradeUserInfo(const ETradeUserInfo& source)
	:id(source.id),
	password(source.password),
	authorizingPassword(source.authorizingPassword){
		this->authorizingPasswordErrorMsg = source.authorizingPasswordErrorMsg;
}


ETradeUserInfo::~ETradeUserInfo(){}


void ETradeUserInfo::AssignUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg){
	this->id.assign(id);
	this->password.assign(password);
	this->authorizingPassword.assign(authorizingPassword);
	this->authorizingPasswordErrorMsg = authorizingPasswordErrorMsg;
}


ETradeUserInfo& ETradeUserInfo::operator=(const ETradeUserInfo& source){
	this->id.assign(source.id);
	this->password.assign(source.password);
	this->authorizingPassword.assign(source.authorizingPassword);
	this->authorizingPasswordErrorMsg=source.authorizingPasswordErrorMsg;
	return *this;
}


bool ETradeUserInfo::operator==(const ETradeUserInfo& other){
	bool ret = false;
	if( this->id==other.id &&
		this->password==other.password &&
		this->authorizingPassword==other.authorizingPassword &&
		this->authorizingPasswordErrorMsg==other.authorizingPasswordErrorMsg){
			ret = true;
	}
	return ret;
}


bool ETradeUserInfo::operator!=(const ETradeUserInfo& other){
	bool ret = false;
	if( this->id!=other.id ||
		this->password!=other.password ||
		this->authorizingPassword!=other.authorizingPassword ||
		this->authorizingPasswordErrorMsg!=other.authorizingPasswordErrorMsg){
			ret = true;
	}
	return ret;
}

bool ETradeUserInfo::IsEqual(const ETradeUserInfo& other){
	bool ret = false;
	if( this->id.compare(other.id)==0 &&
		this->password.compare(other.password)==0 &&
		this->authorizingPassword.compare(other.authorizingPassword)==0 &&
		this->authorizingPasswordErrorMsg==other.authorizingPasswordErrorMsg){
			ret = true;
	}
	return ret;
}


bool ETradeUserInfo::IsNotEqual(const ETradeUserInfo& other){
	bool ret = false;
	if( this->id.compare(other.id)!=0 ||
		this->password.compare(other.password)!=0 ||
		this->authorizingPassword.compare(other.authorizingPassword)!=0 ||
		this->authorizingPasswordErrorMsg==other.authorizingPasswordErrorMsg){
			ret = true;
	}
	return ret;
}