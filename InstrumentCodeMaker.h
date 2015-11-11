// InstrumentCodeMaker.h
#ifndef _INSTRUMENT_CODE_MAKER_H
#define _INSTRUMENT_CODE_MAKER_H

#include "DataTypeDefinition.h"

class InstrumentCodeMaker{
	public:
		InstrumentCodeMaker();
		InstrumentCodeMaker(const InstrumentCodeMaker& source);
		~InstrumentCodeMaker();

		void InitilizeCodes();
		tstring MakeNearestKOSPI200IndexFuturesCode();

		bool IsEqual(const InstrumentCodeMaker& other);
		bool IsNotEqual(const InstrumentCodeMaker& other);

		InstrumentCodeMaker& operator=(const InstrumentCodeMaker& source);
		bool operator==(const InstrumentCodeMaker& other);
		bool operator!=(const InstrumentCodeMaker& other);

		tstring& GetKOSPI200IndexFuturesCode() const;

	private:
		int ZellersCongruence(int yy, int mm, int dd);
		tstring MapYearToAlphabet(int year);

	private:
		tstring kospi200IndexFuturesCode;
};


inline tstring& InstrumentCodeMaker::GetKOSPI200IndexFuturesCode() const{
	return const_cast<tstring&>(this->kospi200IndexFuturesCode);
}


#endif