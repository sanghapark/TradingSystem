// ServerInfo.h
#ifndef _ETRADE_SERVER_INFO_H
#define _ETRADE_SERVER_INFO_H

#include "DataTypeDefinition.h"


class ETradeServerInfo{
public:
	ETradeServerInfo();
	ETradeServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime);
	ETradeServerInfo(const ETradeServerInfo& source);
	~ETradeServerInfo();

	void AssignServerInfo(int serverType, const tstring& serverName, const tstring& serverAddress, int serverPort, int maxTransferSize, int connectingTime);

	ETradeServerInfo& operator=(const ETradeServerInfo& source);
	bool operator==(const ETradeServerInfo& other);
	bool operator!=(const ETradeServerInfo& other);
	bool IsEqual(const ETradeServerInfo& other);
	bool IsNotEqual(const ETradeServerInfo& other);

	void SetServerType(int serverType);
	void SetServerName(const tstring& serverName);
	void SetServerAddress(const tstring& serverAddress);
	void SetServerPort(int serverPort);
	void SetMaxTransferSize(int maxTransferSize);
	void SetConnectingTime(int connectingTime); 

	int GetServerType() const;
	tstring& GetServerName() const;
	tstring& GetServerAddress() const;
	int GetServerPort() const;
	int GetMaxTransferSize() const;
	int GetConnectingTime() const;		// 무슨 시간인지 불확신

private:
	int serverType;				// 실서버 or 모의투자
	tstring serverName;				// HTS
	tstring serverAddress;			// hts.etrade.co.kr, ...
	int serverPort;					// 20001,...
	int maxTransferSize;			//in Bytes
	int connectingTime;				//in seconds
};


inline void ETradeServerInfo::SetServerType(int serverType){
	this->serverType = serverType;
}
inline void ETradeServerInfo::SetServerName(const tstring& serverName){
	this->serverName.assign(serverName);
}
inline void ETradeServerInfo::SetServerAddress(const tstring& serverAddress){
	this->serverAddress.assign(serverAddress);
}
inline void ETradeServerInfo::SetServerPort(int serverPort){
	this->serverPort = serverPort;
}
inline void ETradeServerInfo::SetMaxTransferSize(int maxTransferSize){
	this->maxTransferSize = maxTransferSize;
}
inline void ETradeServerInfo::SetConnectingTime(int connectingTime){
	this->connectingTime = connectingTime;
}

inline int ETradeServerInfo::GetServerType() const{
	return this->serverType;
}

inline tstring& ETradeServerInfo::GetServerName() const{
	return const_cast<tstring&>(this->serverName);
}


inline tstring& ETradeServerInfo::GetServerAddress() const{
	return const_cast<tstring&>(this->serverAddress);
}


inline int ETradeServerInfo::GetServerPort() const{
	return this->serverPort;
}


inline int ETradeServerInfo::GetMaxTransferSize() const{
	return this->maxTransferSize;
}


inline int ETradeServerInfo::GetConnectingTime() const{
	return this->connectingTime;
}


#endif