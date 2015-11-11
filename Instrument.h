// Instrument.h

#pragma once

#include "Contract.h"
#include "LimitOrderBook.h"


class Instrument{
public:
	Instrument();
	Instrument(const tstring instrumentType, const tstring& instrumentCode, const tstring& instrumentName, int contractFeedingSourceID, int lboFeedingSourceID);
	Instrument(const Instrument& source);
	~Instrument();

	// 이 업데이트 함수로 DataFeedingItemInfo에서 피딩 받음
	void UpdateContract(const tstring& time, double price, const tstring& type, int volume);
	void UpdateLimitOrderBook(const AskList& offers, const AskList& bids);

	bool IsEqual(const Instrument& other);
	bool IsNotEqual(const Instrument& other);

	Instrument& operator=(const Instrument& source);
	bool operator==(const Instrument& other);
	bool operator!=(const Instrument& other);

	Contract& GetContract() const;
	LimitOrderBook& GetLimitOrderBook() const;
	tstring& GetInstrumentType() const;
	tstring& GetInstrumentCode() const;
	tstring& GetInstrumentName() const;

private:
	Contract contract;
	LimitOrderBook limitOrderBook;
	tstring instrumentType;
	tstring instrumentCode;
	tstring instrumentName;
};


inline Contract& Instrument::GetContract() const{
	return const_cast<Contract&>(this->contract);
}


inline LimitOrderBook& Instrument::GetLimitOrderBook() const{
	return const_cast<LimitOrderBook&>(this->limitOrderBook);
}


inline tstring& Instrument::GetInstrumentType() const{
	return const_cast<tstring&>(this->instrumentType);
}


inline tstring& Instrument::GetInstrumentCode() const{
	return const_cast<tstring&>(this->instrumentCode);
}


inline tstring& Instrument::GetInstrumentName() const{
	return const_cast<tstring&>(this->instrumentName);
}