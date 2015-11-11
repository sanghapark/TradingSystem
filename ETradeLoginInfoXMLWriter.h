// ETradeAPILoginInfoXMLWriter.h

#ifndef _ETRADE_LOGIN_INFO_XML_WRITER_H
#define _ETRADE_LOGIN_INFO_XML_WRITER_H


#include "Markup.h"
#include "ETradeLoginInfo.h"
#include "File.h"

class ETradeLoginInfoXMLWriter{
	public:
		ETradeLoginInfoXMLWriter();
		ETradeLoginInfoXMLWriter(const ETradeLoginInfoXMLWriter& source);
		~ETradeLoginInfoXMLWriter();

		void WriteLoginInfo(const ETradeLoginInfo& loginInfo);
		CMarkup* RelateCMarkup(CMarkup* cMarkup);

		ETradeLoginInfoXMLWriter& operator=(const ETradeLoginInfoXMLWriter& source);
		bool operator==(const ETradeLoginInfoXMLWriter& other);
		bool operator!=(const ETradeLoginInfoXMLWriter& other);
		bool IsEqual(const ETradeLoginInfoXMLWriter& other);
		bool IsNotEqual(const ETradeLoginInfoXMLWriter& other);


		ETradeLoginInfo& GetLoginInfo() const;

	public:
		CMarkup* cMarkup;

	private:
		ETradeLoginInfo loginInfo;
};

inline ETradeLoginInfo& ETradeLoginInfoXMLWriter::GetLoginInfo() const{
	return const_cast<ETradeLoginInfo&>(this->loginInfo);
}



#endif