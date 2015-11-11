// ETradeLoginInfoXMLReader.h
#ifndef _ETRADE_LOGIN_INFO_XML_READER_H
#define _ETRADE_LOGIN_INFO_XML_READER_H

#include "ETradeLoginInfo.h"
#include "File.h"
#include "Markup.h"

using namespace std;

class ETradeLoginInfoXMLReader{
	public:
		ETradeLoginInfoXMLReader();
		ETradeLoginInfoXMLReader(const ETradeLoginInfoXMLReader& source);
		~ETradeLoginInfoXMLReader();

		ETradeLoginInfo& ReadLoginInfo();
		CMarkup* RelateCMarkup(CMarkup* cMarkup);

		ETradeLoginInfoXMLReader& operator=(const ETradeLoginInfoXMLReader& source);
		bool operator==(const ETradeLoginInfoXMLReader& other);
		bool operator!=(const ETradeLoginInfoXMLReader& other);
		bool IsEqual(const ETradeLoginInfoXMLReader& other);
		bool IsNotEqual(const ETradeLoginInfoXMLReader& other);

		ETradeLoginInfo& GetLoginInfo() const;

	private:
		LoginTime& ReadLoginTime();
		bool ReadAutoLogin();
		ETradeUserInfo& ReadUserInfo();
		ETradeServerInfo& ReadServerInfo();

	public:
		CMarkup* cMarkup;

	private:
		ETradeLoginInfo loginInfo;
};


inline ETradeLoginInfo& ETradeLoginInfoXMLReader::GetLoginInfo() const{
	return const_cast<ETradeLoginInfo&>(this->loginInfo);
}



#endif //_XING_API_LOGIN_INFO_XML_READER_H