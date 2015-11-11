// Instrument.cpp

#include "Instrument.h"

Instrument::Instrument(){
}


Instrument::Instrument(const tstring instrumentType, const tstring& instrumentCode, const tstring& instrumentName, int contractFeedingSourceID, int lboFeedingSourceID)
	:instrumentType(instrumentType),
	instrumentCode(instrumentCode),
	instrumentName(instrumentName),
	contract(contractFeedingSourceID),
	limitOrderBook(lboFeedingSourceID){
}


Instrument::Instrument(const Instrument& source)
	:contract(source.contract),
	limitOrderBook(source.limitOrderBook),
	instrumentType(source.instrumentType),
	instrumentCode(source.instrumentCode),
	instrumentName(source.instrumentName){
}


Instrument::~Instrument(){
}


void Instrument::UpdateContract(const tstring& time, double price, const tstring& type, int volume){
	this->contract.Update(time, price, type, volume);
}


void Instrument::UpdateLimitOrderBook(const AskList& offers, const AskList& bids){
	this->limitOrderBook.Update(offers, bids);
}


bool Instrument::IsEqual(const Instrument& other){
	bool ret = false;
	if(this->contract.IsEqual(other.contract)==true &&
		this->limitOrderBook.IsEqual(other.limitOrderBook)==true &&
		this->instrumentType.compare(other.instrumentType)==0 &&
		this->instrumentCode.compare(other.instrumentCode)==0 &&
		this->instrumentName.compare(other.instrumentName)==0){
			ret = true;
	}
	return ret;
}


bool Instrument::IsNotEqual(const Instrument& other){
	bool ret = false;
	if(this->contract.IsNotEqual(other.contract)==true ||
		this->limitOrderBook.IsNotEqual(other.limitOrderBook)==true ||
		this->instrumentType.compare(other.instrumentType)!=0 ||
		this->instrumentCode.compare(other.instrumentCode)!=0 ||
		this->instrumentName.compare(other.instrumentName)!=0){
			ret = true;
	}
	return ret;
}


Instrument& Instrument::operator=(const Instrument& source){
	this->contract = source.contract;
	this->limitOrderBook = source.limitOrderBook;
	this->instrumentType = source.instrumentType;
	this->instrumentCode = source.instrumentCode;
	this->instrumentName = source.instrumentCode;
	return *this;
}


bool Instrument::operator==(const Instrument& other){
	bool ret = false;
	if(this->contract == other.contract &&
		this->limitOrderBook == other.limitOrderBook &&
		this->instrumentType == other.instrumentType &&
		this->instrumentCode == other.instrumentCode &&
		this->instrumentName == other.instrumentName){
			ret = true;
	}
	return ret;
}


bool Instrument::operator!=(const Instrument& other){
	bool ret = false;
	if(this->contract != other.contract ||
		this->limitOrderBook != other.limitOrderBook ||
		this->instrumentType != other.instrumentType ||
		this->instrumentCode != other.instrumentCode ||
		this->instrumentName != other.instrumentName){
			ret = true;
	}
	return ret;
}