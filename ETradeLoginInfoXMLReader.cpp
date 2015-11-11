// XingAPILoginInfoXMLReader.cpp
#include "ETradeLoginInfoXMLReader.h"
#include "DataTypeDefinition.h"
#include "DataConverter.h"

ETradeLoginInfoXMLReader::ETradeLoginInfoXMLReader(){
	this->cMarkup=0;
}


ETradeLoginInfoXMLReader::ETradeLoginInfoXMLReader(const ETradeLoginInfoXMLReader& source)
	:loginInfo(source.loginInfo){
}

ETradeLoginInfoXMLReader::~ETradeLoginInfoXMLReader(){
}

ETradeLoginInfo& ETradeLoginInfoXMLReader::ReadLoginInfo(){
	this->ReadLoginTime();
	this->ReadAutoLogin();
	this->ReadUserInfo();
	this->ReadServerInfo();
	return this->loginInfo;
}


CMarkup* ETradeLoginInfoXMLReader::RelateCMarkup(CMarkup* cMarkup){
	this->cMarkup = cMarkup;
	return this->cMarkup;
}

LoginTime& ETradeLoginInfoXMLReader::ReadLoginTime(){
	this->cMarkup->ResetPos();
	this->cMarkup->FindElem(_T("Brokers"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(_T("ETrade"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(_T("LoginTime"));

	bool checker = DataConverter::ConvertStringToBool(this->cMarkup->GetAttrib(_T("checker")));
	
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(_T("TimeStart"));
	tstring timeStart = this->cMarkup->GetData();

	this->cMarkup->FindElem(_T("TimeEnd"));
	tstring timeEnd = this->cMarkup->GetData();

	LoginTime loginTime(timeStart, timeEnd, checker);

	this->loginInfo.SetLoginTime(loginTime);
	return this->loginInfo.GetLoginTime();
}


bool  ETradeLoginInfoXMLReader::ReadAutoLogin(){
	bool ret = false;
	this->cMarkup->ResetPos();
	this->cMarkup->FindElem(TEXT("Brokers"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("ETrade"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("LoginInfo"));
	tstring temp = this->cMarkup->GetAttrib(TEXT("auto"));
	if(temp.compare(TEXT("1"))==0){
		ret = true;
	}
	this->loginInfo.SetAutoLogin(ret);
	return this->loginInfo.GetAutoLogin();
}

ETradeUserInfo& ETradeLoginInfoXMLReader::ReadUserInfo(){
	tstring id;
	tstring password;
	tstring authorizingPassword;
	tstring tempErrorMsg;
	bool errorMsg;
	this->cMarkup->ResetPos();
	this->cMarkup->FindElem(TEXT("Brokers"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("ETrade"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("LoginInfo"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("UserInfo"));
	this->cMarkup->IntoElem();

	this->cMarkup->FindElem(TEXT("ID"));
	id = this->cMarkup->GetData();

	this->cMarkup->FindElem(TEXT("Password"));
	password = this->cMarkup->GetData();

	this->cMarkup->FindElem(TEXT("AuthorizingPassword"));
	authorizingPassword = this->cMarkup->GetData();

	this->cMarkup->FindElem(TEXT("AuthorizingPasswordErrorMsg"));
	tempErrorMsg = this->cMarkup->GetData();
	if(tempErrorMsg.compare(TEXT("1"))==0){
		errorMsg = true;
	}
	else{
		errorMsg = false;
	}
	this->loginInfo.GetUserInfo().AssignUserInfo(id, password, authorizingPassword, errorMsg);
	return this->loginInfo.GetUserInfo();
}

ETradeServerInfo& ETradeLoginInfoXMLReader::ReadServerInfo(){
	tstring tempServerType;
	bool serverType;
	tstring serverName;
	tstring serverAddress;
	tstring tempServerPort;
	int	serverPort;
	tstring tempMaxTransferSize;
	int maxTransferSize;
	tstring tempConnectingTime;
	int connectingTime;

	DataConverter dataConverter;

	this->cMarkup->ResetPos();
	this->cMarkup->FindElem(TEXT("Brokers"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("ETrade"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("LoginInfo"));
	this->cMarkup->IntoElem();

	this->cMarkup->FindElem(TEXT("ServerInfo"));
	this->cMarkup->IntoElem();
	this->cMarkup->FindElem(TEXT("ServerType"));
	tempServerType = this->cMarkup->GetData();
	if(tempServerType.compare(TEXT("1"))==0){
		serverType = true;
	}
	else{
		serverType = false;
	}

	this->cMarkup->FindElem(TEXT("ServerName"));
	serverName = this->cMarkup->GetData();

	this->cMarkup->FindElem(TEXT("ServerAddress"));
	serverAddress = this->cMarkup->GetData();

	this->cMarkup->FindElem(TEXT("ServerPort"));
	tempServerPort = this->cMarkup->GetData();
	//serverPort = atoi(tempServerPort.c_str());
	serverPort = dataConverter.ConvertStringToInt(tempServerPort.c_str());

	this->cMarkup->FindElem(TEXT("MaxTransferSize"));
	tempMaxTransferSize = this->cMarkup->GetData();
	//maxTransferSize = atoi(tempMaxTransferSize.c_str());
	maxTransferSize = dataConverter.ConvertStringToInt(tempMaxTransferSize.c_str());

	this->cMarkup->FindElem(TEXT("ConnectingTime"));
	tempConnectingTime = this->cMarkup->GetData();
	//connectingTime = atoi(tempConnectingTime.c_str());
	connectingTime = dataConverter.ConvertStringToInt(tempConnectingTime.c_str());

	this->loginInfo.GetServerInfo().AssignServerInfo(serverType, serverName, serverAddress, serverPort, maxTransferSize, connectingTime);
	return this->loginInfo.GetServerInfo();
}



ETradeLoginInfoXMLReader& ETradeLoginInfoXMLReader::operator=(const ETradeLoginInfoXMLReader& source){
	this->cMarkup = source.cMarkup;
	this->loginInfo = source.loginInfo;
	return *this;
}


bool ETradeLoginInfoXMLReader::operator==(const ETradeLoginInfoXMLReader& other){
	bool ret = false;
	if(	this->loginInfo==other.loginInfo &&
		this->cMarkup==other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLReader::operator!=(const ETradeLoginInfoXMLReader& other){
	bool ret = false;
	if(	this->loginInfo!=other.loginInfo ||
		this->cMarkup!=other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLReader::IsEqual(const ETradeLoginInfoXMLReader& other){
	bool ret = false;
	if(	this->loginInfo.IsEqual(other.loginInfo)==true &&
		this->cMarkup==other.cMarkup){
		ret = true;
	}
	return ret;
}


bool ETradeLoginInfoXMLReader::IsNotEqual(const ETradeLoginInfoXMLReader& other){
	bool ret = false;
	if(	this->loginInfo.IsNotEqual(other.loginInfo)!=true ||
		this->cMarkup!=other.cMarkup){
		ret = true;
	}
	return ret;
}