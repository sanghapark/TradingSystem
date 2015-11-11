// LoginInfoManager.cpp

#include "LoginInfoManager.h"
#include "File.h"

LoginInfoManager::LoginInfoManager(){
	this->Initialize();
}


LoginInfoManager::LoginInfoManager(const LoginInfoManager& source)
	:cMarkup(source.cMarkup),
	eTrade(source.eTrade){
}


LoginInfoManager::~LoginInfoManager(){
}


void LoginInfoManager::Initialize(){
	this->cMarkup.Load(LOG_IN_INFO);
	this->RelateCMarkupToMembers();
}


void LoginInfoManager::RelateCMarkupToMembers(){
	this->eTrade.RelateCMarkup(&(this->cMarkup));
}


ETradeLoginInfo& LoginInfoManager::LoadETradeLoginInfo(){
	return this->eTrade.ReadLoginInfo();
}


void LoginInfoManager::SaveETradeLoginInfo(const ETradeLoginInfo& info){
	this->eTrade.WriteLoginInfo(info);
	this->cMarkup.Save(LOG_IN_INFO);
}


bool LoginInfoManager::IsEqual(const LoginInfoManager& other){
	bool ret = false;
	if(this->eTrade.IsEqual(other.eTrade)==true){
		ret = true;
	}
	return ret;
}


bool LoginInfoManager::IsNotEqual(const LoginInfoManager& other){
	bool ret = false;
	if(this->eTrade.IsNotEqual(other.eTrade)==true){
		ret = true;
	}
	return ret;
}


LoginInfoManager& LoginInfoManager::operator=(const LoginInfoManager& source){
	this->cMarkup=source.cMarkup;
	this->eTrade=source.eTrade;
	return *this;
}


bool LoginInfoManager::operator==(const LoginInfoManager& other){
	bool ret = false;
	if(this->eTrade==other.eTrade){
		ret = true;
	}
	return ret;
}


bool LoginInfoManager::operator!=(const LoginInfoManager& other){
	bool ret = false;
	if(this->eTrade!=other.eTrade){
		ret = true;
	}
	return ret;
}