// ETradeLoginInfoXMLWriter.cpp

#include "ETradeLoginInfoXMLWriter.h"
#include "DataConverter.h"

ETradeLoginInfoXMLWriter::ETradeLoginInfoXMLWriter(){
	this->cMarkup =0;
}


ETradeLoginInfoXMLWriter::ETradeLoginInfoXMLWriter(const ETradeLoginInfoXMLWriter& source)
	:loginInfo(source.loginInfo){
}

ETradeLoginInfoXMLWriter::~ETradeLoginInfoXMLWriter(){
}


void ETradeLoginInfoXMLWriter::WriteLoginInfo(const ETradeLoginInfo& loginInfo){
	this->cMarkup->ResetPos();
	this->cMarkup->FindElem(TEXT("Brokers"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("ETrade"));
	this->cMarkup->IntoElem();

	this->cMarkup->FindElem(_T("LoginTime"));
	this->cMarkup->SetAttrib(_T("checker"), DataConverter::ConvertBoolToString(loginInfo.GetLoginTime().GetChecker()));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(_T("TimeStart"));
	this->cMarkup->SetData(loginInfo.GetLoginTime().GetTimeStart());
	this->cMarkup->FindElem(_T("TimeEnd"));
	this->cMarkup->SetData(loginInfo.GetLoginTime().GetTimeEnd());
	this->cMarkup->OutOfElem();


	this->cMarkup->FindElem(TEXT("LoginInfo"));
	this->cMarkup->SetAttrib(TEXT("auto"), loginInfo.GetAutoLogin());
	this->cMarkup->IntoElem();

	// UserInfo
	this->cMarkup->FindElem(TEXT("UserInfo"));
	this->cMarkup->IntoElem();

	this->cMarkup->FindElem(TEXT("ID"));
	this->cMarkup->SetData(loginInfo.GetUserInfo().GetID());

	this->cMarkup->FindElem(TEXT("Password"));
	this->cMarkup->SetData(loginInfo.GetUserInfo().GetPassword());

	this->cMarkup->FindElem(TEXT("AuthorizingPassword"));
	this->cMarkup->SetData(loginInfo.GetUserInfo().GetAuthorizingPassword());

	this->cMarkup->FindElem(TEXT("AuthorizingPasswordErrorMsg"));
	this->cMarkup->SetData(loginInfo.GetUserInfo().GetAuthorizingPasswordErrorMsg());
	this->cMarkup->OutOfElem();

	// ServerInfo
	this->cMarkup->FindElem(TEXT("ServerInfo"));
	this->cMarkup->IntoElem();

	this->cMarkup->FindElem(TEXT("ServerType"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetServerType());

	this->cMarkup->FindElem(TEXT("ServerName"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetServerName());

	this->cMarkup->FindElem(TEXT("ServerAddress"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetServerAddress());

	this->cMarkup->FindElem(TEXT("ServerPort"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetServerPort());

	this->cMarkup->FindElem(TEXT("MaxTransferSize"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetMaxTransferSize());

	this->cMarkup->FindElem(TEXT("ConnectingTime"));
	this->cMarkup->SetData(loginInfo.GetServerInfo().GetConnectingTime());

	//this->cMarkup->Save(LOG_IN_INFO);
}


CMarkup* ETradeLoginInfoXMLWriter::RelateCMarkup(CMarkup* cMarkup){
	this->cMarkup = cMarkup;
	return this->cMarkup;
}



ETradeLoginInfoXMLWriter& ETradeLoginInfoXMLWriter::operator=(const ETradeLoginInfoXMLWriter& source){
	this->cMarkup = source.cMarkup;
	this->loginInfo = source.loginInfo;
	return *this;
}


bool ETradeLoginInfoXMLWriter::operator==(const ETradeLoginInfoXMLWriter& other){
	bool ret = false;
	if(	this->loginInfo==other.loginInfo &&
		this->cMarkup == other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLWriter::operator!=(const ETradeLoginInfoXMLWriter& other){
	bool ret = false;
	if(	this->loginInfo!=other.loginInfo ||
		this->cMarkup!=other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLWriter::IsEqual(const ETradeLoginInfoXMLWriter& other){
	bool ret = false;
	if(	this->loginInfo.IsEqual(other.loginInfo)==true &&
		this->cMarkup==other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLWriter::IsNotEqual(const ETradeLoginInfoXMLWriter& other){
	bool ret = false;
	if(	this->loginInfo.IsNotEqual(other.loginInfo)!=true &&
		this->cMarkup!=other.cMarkup){
		ret = true;
	}
	return ret;
}