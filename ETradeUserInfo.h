#ifndef _ETRADE_USER_INFO_H
#define _ETRADE_USER_INFO_H

#include "tstring.h"


class ETradeUserInfo{
public:
	ETradeUserInfo();
	ETradeUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg);
	ETradeUserInfo(const ETradeUserInfo& source);
	~ETradeUserInfo();

	void AssignUserInfo(const tstring& id, const tstring& password, const tstring& authorizingPassword, bool authorizingPasswordErrorMsg);

	ETradeUserInfo& operator=(const ETradeUserInfo& source);
	bool operator==(const ETradeUserInfo& other);
	bool operator!=(const ETradeUserInfo& other);
	bool IsEqual(const ETradeUserInfo& other);
	bool IsNotEqual(const ETradeUserInfo& other);


	void SetID(const tstring& id);
	void SetPassword(const tstring& password);
	void SetAuthorizingPassword(const tstring& authorizingPassword);
	void SetGetAuthorizingPasswordErrorMsg(bool authorizingPasswordErrorMsg);

	tstring& GetID() const;
	tstring& GetPassword() const;
	tstring& GetAuthorizingPassword() const;
	bool GetAuthorizingPasswordErrorMsg() const;


private:
	tstring id;
	tstring password;
	tstring authorizingPassword;
	bool authorizingPasswordErrorMsg;
};


inline void ETradeUserInfo::SetID(const tstring& id){
	this->id.assign(id);
}

inline void ETradeUserInfo::SetPassword(const tstring& password){
	this->password.assign(password);
}

inline void ETradeUserInfo::SetAuthorizingPassword(const tstring& authorizingPassword){
	this->authorizingPassword.assign(authorizingPassword);
}

inline void ETradeUserInfo::SetGetAuthorizingPasswordErrorMsg(bool authorizingPasswordErrorMsg){
	this->authorizingPasswordErrorMsg=authorizingPasswordErrorMsg;
}


inline tstring& ETradeUserInfo::GetID() const{
	return const_cast<tstring&>(this->id);
}

inline tstring& ETradeUserInfo::GetPassword() const{
	return const_cast<tstring&>(this->password);
}

inline tstring& ETradeUserInfo::GetAuthorizingPassword() const{
	return const_cast<tstring&>(this->authorizingPassword);
}

inline bool ETradeUserInfo::GetAuthorizingPasswordErrorMsg() const{
	return this->authorizingPasswordErrorMsg;
}

#endif