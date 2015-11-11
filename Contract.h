// Contract.h

#pragma once

#include "DataTypeDefinition.h"


class Contract{
	public:
		Contract(int feedingSourceID=-1);
		Contract(const Contract& source);
		~Contract();

		void Update(const tstring& time, double price, const tstring& type, int volume);
		
		bool IsEqual(const Contract& other);
		bool IsNotEqual(const Contract& other);

		Contract& operator=(const Contract& source);
		bool operator==(const Contract& other);
		bool operator!=(const Contract& other);

		tstring& GetTime() const;
		double GetPrice() const;
		tstring& GetType() const;
		int GetVolume() const;
		int GetFeedingSourceID() const;

		void SetFeedingSourceID(int feedingSourceID);

	private:
		tstring time;
		double price;
		tstring type;
		int volume;
		int feedingSourceID; // 
};

inline tstring& Contract::GetTime() const{
	return const_cast<tstring&>(this->time);
}


inline double Contract::GetPrice() const{
	return this->price;
}


inline tstring& Contract::GetType() const{
	return const_cast<tstring&>(this->type);
}


inline int Contract::GetVolume() const{
	return this->volume;
}


inline int Contract::GetFeedingSourceID() const{
	return this->feedingSourceID;
}

inline void Contract::SetFeedingSourceID(int feedingSourceID){
	this->feedingSourceID = feedingSourceID;
}