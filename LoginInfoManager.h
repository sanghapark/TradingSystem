// LoginInfoManager.h
#ifndef _LOG_IN_INFO_MANAGER_H
#define _LOG_IN_INFO_MANAGER_H

#include "Markup.h"
#include "ETradeLoginInfoManager.h"

class LoginInfoManager{
	public:
		LoginInfoManager();
		LoginInfoManager(const LoginInfoManager& source);
		~LoginInfoManager();

		// ETrade
		ETradeLoginInfo& LoadETradeLoginInfo();
		void SaveETradeLoginInfo(const ETradeLoginInfo& info);

		// Woori


		bool IsEqual(const LoginInfoManager& other);
		bool IsNotEqual(const LoginInfoManager& other);

		LoginInfoManager& operator=(const LoginInfoManager& source);
		bool operator==(const LoginInfoManager& other);
		bool operator!=(const LoginInfoManager& other);

		CMarkup& GetCMarkup() const;
		ETradeLoginInfoManager& GetETrade() const;

	private:
		void Initialize();
		void RelateCMarkupToMembers();

	private:
		CMarkup cMarkup;
		ETradeLoginInfoManager eTrade;
};

inline CMarkup& LoginInfoManager::GetCMarkup() const{
	return const_cast<CMarkup&>(this->cMarkup);
}


inline ETradeLoginInfoManager& LoginInfoManager::GetETrade() const{
	return const_cast<ETradeLoginInfoManager&>(this->eTrade);
}

#endif