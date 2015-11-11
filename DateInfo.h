// DateInfo.h

#pragma once

#include "DataTypeDefinition.h"


class DateInfo{
	public:
		DateInfo();
		DateInfo(const tstring& date, bool businessDay);
		DateInfo(const DateInfo& source);
		~DateInfo();

		bool IsEqual(const DateInfo& other);
		bool IsNotEqual(const DateInfo& other);

		DateInfo& operator=(const DateInfo& source);
		bool operator==(const DateInfo& other);
		bool operator!=(const DateInfo& other);

		tstring& GetDate() const;
		bool GetBusinessDay() const;

	private:
		tstring date; // YYYYMMDD format
		bool businessDay;
};



inline tstring& DateInfo::GetDate() const{
	return const_cast<tstring&>(this->date);
}


inline bool DateInfo::GetBusinessDay() const{
	return this->businessDay;
}