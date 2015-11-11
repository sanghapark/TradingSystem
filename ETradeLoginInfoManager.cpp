// ETradeLoginInfoManager.cpp

#include "ETradeLoginInfoManager.h"
#include "Markup.h"

ETradeLoginInfoManager::ETradeLoginInfoManager(){
	this->cMarkup =0;
}


ETradeLoginInfoManager::ETradeLoginInfoManager(const ETradeLoginInfoManager& source)
	:xmlCtrl(source.xmlCtrl),
	eTradeLoginInfo(source.eTradeLoginInfo){
}


ETradeLoginInfoManager::~ETradeLoginInfoManager(){
}


ETradeLoginInfo& ETradeLoginInfoManager::ReadLoginInfo(){
	return this->xmlCtrl.ReadLoginInfo();
}


void ETradeLoginInfoManager::WriteLoginInfo(const ETradeLoginInfo& loginInfo){
	this->xmlCtrl.WriteLoginInfo(loginInfo);
}


CMarkup* ETradeLoginInfoManager::RelateCMarkup(CMarkup* cMarkup){
	this->cMarkup = cMarkup;
	this->xmlCtrl.RelateCMarkup(cMarkup);
	return this->cMarkup;
}


ETradeLoginInfoManager& ETradeLoginInfoManager::operator=(const ETradeLoginInfoManager& source){
	this->cMarkup = source.cMarkup;
	this->xmlCtrl = source.xmlCtrl;
	this->eTradeLoginInfo = source.eTradeLoginInfo;
	return *this;
}


bool ETradeLoginInfoManager::operator==(const ETradeLoginInfoManager& other){
	bool ret = false;
	if(this->xmlCtrl==other.xmlCtrl &&
		this->eTradeLoginInfo==other.eTradeLoginInfo &&
		this->cMarkup==other.cMarkup){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfoManager::operator!=(const ETradeLoginInfoManager& other){
	bool ret= false;
	if(this->xmlCtrl!=other.xmlCtrl ||
		this->eTradeLoginInfo!=other.eTradeLoginInfo ||
		this->cMarkup!=other.cMarkup){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfoManager::IsEqual(const ETradeLoginInfoManager& other){
	bool ret = false;
	if(this->xmlCtrl.IsEqual(other.xmlCtrl)==true &&
		this->eTradeLoginInfo.IsEqual(other.eTradeLoginInfo)==true &&
		this->cMarkup==other.cMarkup){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfoManager::IsNotEqual(const ETradeLoginInfoManager& other){
	bool ret = false;
	if(this->xmlCtrl.IsNotEqual(other.xmlCtrl)==true ||
		this->eTradeLoginInfo.IsNotEqual(other.eTradeLoginInfo)==true ||
		this->cMarkup!=other.cMarkup){
			ret = true;
	}
	return ret;
}