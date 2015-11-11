// HolidayList.h

#pragma once


#include "Template\Array.hpp"
#include "DataTypeDefinition.h"

class HolidayList{
	public:
		HolidayList(int capacity=10);
		HolidayList(const HolidayList& source);
		~HolidayList();

		void InitHolidays();
		int CountHolidays(const tstring& startYYYYMMDD, const tstring& endYYYYMMDD);
		int AddHoliday(const tstring& yyyyMMdd);
		bool IsHoliday(const tstring& yyyyMMdd);

		bool IsEqual(const HolidayList& other);
		bool IsNotEqual(const HolidayList& other);
		tstring& GetAt(int index);

		bool operator==(const HolidayList& other);
		bool operator!=(const HolidayList& other);
		HolidayList& operator=(const HolidayList& source);
		tstring& operator[](int index);


		int GetLength() const;
		int GetCapacity() const;

	private:
		Array<tstring> holidays; //yyyyMMdd format
		int length;
		int capacity;
};


inline int HolidayList::GetLength() const{
	return this->length;
}

inline int HolidayList::GetCapacity() const{
	return this->capacity;
}