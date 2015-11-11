// LimitOrderBook.h

#pragma once

#include "AskList.h"
#include "DataTypeDefinition.h"

class LimitOrderBook{
	public:
		LimitOrderBook(int feedingSourceID=-1);
		LimitOrderBook(const LimitOrderBook& source);
		~LimitOrderBook();

		void Update(const AskList& offers, const AskList& bids);

		bool IsEqual(const LimitOrderBook& other);
		bool IsNotEqual(const LimitOrderBook& other);

		LimitOrderBook& operator=(const LimitOrderBook& source);
		bool operator==(const LimitOrderBook& other);
		bool operator!=(const LimitOrderBook& other);


		AskList& GetOffers() const;
		AskList& GetBids() const;
		int GetFeedingSourceID() const;

		void SetFeedingSourceID(int feedingSourceID);

	private:
		AskList offers;
		AskList bids;
		int feedingSourceID;
};

inline AskList& LimitOrderBook::GetOffers() const{
	return const_cast<AskList&>(this->offers);
}

inline AskList& LimitOrderBook::GetBids() const{
	return const_cast<AskList&>(this->bids);
}

inline int LimitOrderBook::GetFeedingSourceID() const{
	return this->feedingSourceID;
}

inline void LimitOrderBook::SetFeedingSourceID(int feedingSourceID){
	this->feedingSourceID = feedingSourceID;
}