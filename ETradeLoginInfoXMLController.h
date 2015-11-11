// ETradeLoginInfoXMLController.h
#ifndef _ETRADE_LOGIN_INFO_XML_CONTROLLER_H
#define _ETRADE_LOGIN_INFO_XML_CONTROLLER_H

#include "ETradeLoginInfoXMLReader.h"
#include "ETradeLoginInfoXMLWriter.h"

class CMarkup;

class ETradeLoginInfoXMLController{
	public:
		ETradeLoginInfoXMLController();
		ETradeLoginInfoXMLController(const ETradeLoginInfoXMLController& source);
		~ETradeLoginInfoXMLController();

		ETradeLoginInfo& ReadLoginInfo();
		void WriteLoginInfo(const ETradeLoginInfo& loginInfo);
		CMarkup* RelateCMarkup(CMarkup* cMarkup);

		ETradeLoginInfoXMLController& operator=(const ETradeLoginInfoXMLController& source);
		bool operator==(const ETradeLoginInfoXMLController& other);
		bool operator!=(const ETradeLoginInfoXMLController& other);
		bool IsEqual(const ETradeLoginInfoXMLController& other);
		bool IsNotEqual(const ETradeLoginInfoXMLController& other);


		ETradeLoginInfoXMLReader& GetXMLReader() const;
		ETradeLoginInfoXMLWriter& GetXMLWriter() const;

	public:
		CMarkup* cMarkup;

	private:
		ETradeLoginInfoXMLReader xmlReader;
		ETradeLoginInfoXMLWriter xmlWriter;
};


inline ETradeLoginInfoXMLReader& ETradeLoginInfoXMLController::GetXMLReader() const{
	return const_cast<ETradeLoginInfoXMLReader&>(this->xmlReader);
}
inline ETradeLoginInfoXMLWriter& ETradeLoginInfoXMLController::GetXMLWriter() const{
	return const_cast<ETradeLoginInfoXMLWriter&>(this->xmlWriter);
}

#endif