// ETradeLoginInfoXMLController.cpp

#include "ETradeLoginInfoXMLController.h"
#include "Markup.h"

ETradeLoginInfoXMLController::ETradeLoginInfoXMLController(){
	this->cMarkup=0;
}


ETradeLoginInfoXMLController::ETradeLoginInfoXMLController(const ETradeLoginInfoXMLController& source)
	:xmlReader(source.xmlReader),
	xmlWriter(source.xmlWriter){
}


ETradeLoginInfoXMLController::~ETradeLoginInfoXMLController(){
}


ETradeLoginInfo& ETradeLoginInfoXMLController::ReadLoginInfo(){
	return this->xmlReader.ReadLoginInfo();
}


void ETradeLoginInfoXMLController::WriteLoginInfo(const ETradeLoginInfo& loginInfo){
	this->xmlWriter.WriteLoginInfo(loginInfo);
}


CMarkup* ETradeLoginInfoXMLController::RelateCMarkup(CMarkup* cMarkup){
	this->cMarkup = cMarkup;
	this->xmlReader.RelateCMarkup(this->cMarkup);
	this->xmlWriter.RelateCMarkup(this->cMarkup);
	return this->cMarkup;
}


ETradeLoginInfoXMLController& ETradeLoginInfoXMLController::operator=(const ETradeLoginInfoXMLController& source){
	this->cMarkup = source.cMarkup;
	this->xmlWriter=source.xmlWriter;
	this->xmlReader = source.xmlReader;
	return *this;
}


bool ETradeLoginInfoXMLController::operator==(const ETradeLoginInfoXMLController& other){
	bool ret = false;
	if(this->xmlReader==other.xmlReader &&
		this->xmlWriter==other.xmlWriter &&
		this->cMarkup == other.cMarkup){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLController::operator!=(const ETradeLoginInfoXMLController& other){
	bool ret = false;
	if(this->xmlReader!=other.xmlReader ||
		this->xmlWriter!=other.xmlWriter ||
		this->cMarkup!=other.cMarkup){
			ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLController::IsEqual(const ETradeLoginInfoXMLController& other){
	bool ret = false;
	if(this->xmlReader.IsEqual(other.xmlReader)==true &&
		this->xmlWriter.IsEqual(other.xmlWriter)==true &&
		this->cMarkup==other.cMarkup){
			ret =true;
	}
	return ret;
}


bool ETradeLoginInfoXMLController::IsNotEqual(const ETradeLoginInfoXMLController& other){
	bool ret = false;
	if(this->xmlReader.IsNotEqual(other.xmlReader)==true ||
		this->xmlWriter.IsNotEqual(other.xmlWriter)==true ||
		this->cMarkup!=other.cMarkup){
			ret = true;
	}
	return ret;
}