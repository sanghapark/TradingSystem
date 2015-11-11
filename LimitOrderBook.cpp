// LimirOrderBook.cpp

#include "LimitOrderBook.h"

LimitOrderBook::LimitOrderBook(int feedingSourceID)
	:offers(10),
	bids(10){
	this->feedingSourceID = feedingSourceID;
}


LimitOrderBook::LimitOrderBook(const LimitOrderBook& source)
	:offers(source.offers),
	bids(source.bids){
	this->feedingSourceID = source.feedingSourceID;
}


LimitOrderBook::~LimitOrderBook(){
}


void LimitOrderBook::Update(const AskList& offers, const AskList& bids){
	this->offers = offers;
	this->bids = bids;
}


bool LimitOrderBook::IsEqual(const LimitOrderBook& other){
	bool ret = false;
	if(this->offers.IsEqual(other.offers)==true &&
		this->bids.IsEqual(other.bids)==true &&
		this->feedingSourceID == other.feedingSourceID){
			ret = true;
	}
	return ret;
}


bool LimitOrderBook::IsNotEqual(const LimitOrderBook& other){
	bool ret = false;
	if(this->offers.IsNotEqual(other.offers)==true ||
		this->bids.IsNotEqual(other.bids)==true ||
		this->feedingSourceID != other.feedingSourceID){
			ret = true;
	}
	return ret;
}


LimitOrderBook& LimitOrderBook::operator=(const LimitOrderBook& source){
	this->offers = source.offers;
	this->bids = source.bids;
	this->feedingSourceID = source.feedingSourceID;
	return *this;
}


bool LimitOrderBook::operator==(const LimitOrderBook& other){
	bool ret = false;
	if(this->offers==other.offers &&
		this->bids==other.bids &&
		this->feedingSourceID == other.feedingSourceID){
			ret = true;
	}
	return ret;
}


bool LimitOrderBook::operator!=(const LimitOrderBook& other){
	bool ret = false;
	if(this->offers!=other.offers ||
		this->bids!=other.bids ||
		this->feedingSourceID != other.feedingSourceID){
			ret = true;
	}
	return ret;
}