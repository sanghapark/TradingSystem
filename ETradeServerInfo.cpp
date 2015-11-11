// ServerInfo.cpp

#include "ETradeServerInfo.h"

ETradeServerInfo::ETradeServerInfo(){
	this->maxTransferSize=0;
	this->connectingTime=0;
}


ETradeServerInfo::ETradeServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime)
	:serverName(serverName),
	serverAddress(serverAddress){
		this->serverType = serverType;
		this->serverPort = serverPort;
		this->maxTransferSize = maxTransferSize;
		this->connectingTime = connectingTime;
}


ETradeServerInfo::ETradeServerInfo(const ETradeServerInfo& source)
	:serverName(source.serverName),
	serverAddress(source.serverAddress){
		this->serverType = source.serverType;
		this->serverPort = source.serverPort;
		this->maxTransferSize = source.maxTransferSize;
		this->connectingTime = source.connectingTime;
}


ETradeServerInfo::~ETradeServerInfo(){
}

void ETradeServerInfo::AssignServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime){
	this->serverType=serverType;
	this->serverName.assign(serverName);
	this->serverAddress.assign(serverAddress);
	this->serverPort = serverPort;
	this->maxTransferSize = maxTransferSize;
	this->connectingTime = connectingTime;
}



ETradeServerInfo& ETradeServerInfo::operator=(const ETradeServerInfo& source){
	this->serverType=source.serverType;
	this->serverName.assign(source.serverName);
	this->serverAddress.assign(source.serverAddress);
	this->serverPort = source.serverPort;
	this->maxTransferSize = source.maxTransferSize;
	this->connectingTime = source.connectingTime;
	return *this;
}


bool ETradeServerInfo::operator==(const ETradeServerInfo& other){
	bool ret = false;
	if( this->serverType==other.serverType &&
		this->serverName==other.serverName &&
		this->serverAddress==other.serverAddress &&
		this->serverPort==other.serverPort &&
		this->maxTransferSize==other.maxTransferSize &&
		this->connectingTime == other.connectingTime){
			ret = true;
	}
	return ret;
}


bool ETradeServerInfo::operator!=(const ETradeServerInfo& other){
	bool ret = false;
	if( this->serverType!=other.serverType ||
		this->serverName!=other.serverName ||
		this->serverAddress!=other.serverAddress ||
		this->serverPort!=other.serverPort ||
		this->maxTransferSize!=other.maxTransferSize ||
		this->connectingTime != other.connectingTime){
			ret = true;
	}
	return ret;
}

bool ETradeServerInfo::IsEqual(const ETradeServerInfo& other){
	bool ret = false;
	if( this->serverType==other.serverType &&
		this->serverName.compare(other.serverName)==0 &&
		this->serverAddress.compare(other.serverAddress)==0 &&
		this->serverPort==other.serverPort &&
		this->maxTransferSize==other.maxTransferSize &&
		this->connectingTime == other.connectingTime){
			ret = true;
	}
	return ret;
}


bool ETradeServerInfo::IsNotEqual(const ETradeServerInfo& other){
	bool ret = false;
	if( this->serverType!=other.serverType ||
		this->serverName.compare(other.serverName)!=0 ||
		this->serverAddress.compare(other.serverAddress)!=0 ||
		this->serverPort!=other.serverPort ||
		this->maxTransferSize!=other.maxTransferSize ||
		this->connectingTime != other.connectingTime){
			ret = true;
	}
	return ret;
}