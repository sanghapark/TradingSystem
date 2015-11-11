// HolidayList.cpp

#include <tchar.h>
#include "HolidayList.h"
#include "DataConverter.h"


HolidayList::HolidayList(int capacity)
	:holidays(capacity){
	this->length = 0;
	this->capacity=0;
}

HolidayList::HolidayList(const HolidayList& source)
	:holidays(source.holidays){
	this->length = source.length;
	this->capacity = source.capacity;
}


HolidayList::~HolidayList(){
}



int HolidayList::CountHolidays(const tstring& startYYYYMMDD, const tstring& endYYYYMMDD){
	int count =-1;
	int startDate = DataConverter::ConvertStringToInt(startYYYYMMDD);
	int endDate = DataConverter::ConvertStringToInt(endYYYYMMDD);

	if(this->length>0){
		int firstHoliday = DataConverter::ConvertStringToInt(this->GetAt(0));
		int lastHoliday = DataConverter::ConvertStringToInt(this->GetAt(this->length));

		if(startDate>=firstHoliday && endDate<=lastHoliday){
			count = 0;
			for(int i=0; i<this->length; i++){
				int holiday = DataConverter::ConvertStringToInt(this->GetAt(i));

				if(holiday>startDate && holiday<endDate){
					count++;
				}

			}

		}
		
	}

	return count;
}

void HolidayList::InitHolidays(){
	this->AddHoliday(_T("20140101"));
	this->AddHoliday(_T("20140130"));
	this->AddHoliday(_T("20140131"));
	this->AddHoliday(_T("20140201"));
	this->AddHoliday(_T("20140301"));
	this->AddHoliday(_T("20140505"));
	this->AddHoliday(_T("20140506"));
	this->AddHoliday(_T("20140606"));
	this->AddHoliday(_T("20140815"));
	this->AddHoliday(_T("20140907"));
	this->AddHoliday(_T("20140908"));
	this->AddHoliday(_T("20140909"));
	this->AddHoliday(_T("20140910"));
	this->AddHoliday(_T("20141003"));
	this->AddHoliday(_T("20141009"));
	this->AddHoliday(_T("20141225"));
}

int HolidayList::AddHoliday(const tstring& yyyyMMdd){
	int index = -1;
	if(this->length<this->capacity){
		index = this->holidays.Store(this->length, yyyyMMdd);
	}
	else{
		index = this->holidays.Insert(this->length, yyyyMMdd);
		this->capacity++;
	}
	this->length++;
	return index;
}


bool HolidayList::IsHoliday(const tstring& yyyyMMdd){
	bool ret = false;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		if(this->GetAt(i).compare(yyyyMMdd)==0){
			found = true;
		}
		i++;
	}
	return ret;
}


bool HolidayList::IsEqual(const HolidayList& other){
	bool ret = false;
	if(this->holidays.IsEqual(other.holidays)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool HolidayList::IsNotEqual(const HolidayList& other){
	bool ret = false;
	if(this->holidays.IsNotEqual(other.holidays)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


tstring& HolidayList::GetAt(int index){
	return this->holidays.GetAt(index);
}


bool HolidayList::operator==(const HolidayList& other){
	bool ret = false;
	if(this->holidays==other.holidays &&
		this->length==other.length &&
		this->capacity==other.capacity){
			ret = true;
	}
	return ret;
}


bool HolidayList::operator!=(const HolidayList& other){
	bool ret = false;
	if(this->holidays!=other.holidays ||
		this->length!=other.length ||
		this->capacity!=other.capacity){
			ret = true;
	}
	return ret;
}


HolidayList& HolidayList::operator=(const HolidayList& source){
	this->holidays = source.holidays;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}

tstring& HolidayList::operator[](int index){
	return this->holidays[index];
}