// ETradeLoginInfoManager.h
#ifndef _ETRADE_LOG_IN_INFO_MANAGER_H
#define _ETRADE_LOG_IN_INFO_MANAGER_H

#include "ETradeLoginInfo.h"
#include "ETradeLoginInfoXMLController.h"

class CMarkup;

class ETradeLoginInfoManager{
	public:
		ETradeLoginInfoManager();
		ETradeLoginInfoManager(const ETradeLoginInfoManager& source);
		~ETradeLoginInfoManager();

		ETradeLoginInfo& ReadLoginInfo();
		void WriteLoginInfo(const ETradeLoginInfo& loginInfo);
		CMarkup* RelateCMarkup(CMarkup* cMarkup);

		ETradeLoginInfoManager& operator=(const ETradeLoginInfoManager& source);
		bool operator==(const ETradeLoginInfoManager& other);
		bool operator!=(const ETradeLoginInfoManager& other);

		bool IsEqual(const ETradeLoginInfoManager& other);
		bool IsNotEqual(const ETradeLoginInfoManager& other);

		ETradeLoginInfoXMLController& GetXMLCtrl() const;
		ETradeLoginInfo& GetETradeLoginInfo() const;
		void SetETradeLoginInfo(const ETradeLoginInfo& eTradeLoginInfo);

	public:
		CMarkup* cMarkup;

	private:
		ETradeLoginInfoXMLController xmlCtrl;
		ETradeLoginInfo eTradeLoginInfo;
};

inline ETradeLoginInfoXMLController& ETradeLoginInfoManager::GetXMLCtrl() const{
	return const_cast<ETradeLoginInfoXMLController&>(this->xmlCtrl);
}


inline ETradeLoginInfo& ETradeLoginInfoManager::GetETradeLoginInfo() const{
	return const_cast<ETradeLoginInfo&>(this->eTradeLoginInfo);
}

inline void ETradeLoginInfoManager::SetETradeLoginInfo(const ETradeLoginInfo& eTradeLoginInfo){
	this->eTradeLoginInfo = eTradeLoginInfo;
}

#endif