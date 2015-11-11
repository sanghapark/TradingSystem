// DateInfo.cpp

#include "DateInfo.h"




DateInfo::DateInfo(){
}


DateInfo::DateInfo(const tstring& date, bool businessDay)
	:date(date){
	this->businessDay = businessDay;
}


DateInfo::DateInfo(const DateInfo& source)
	:date(source.date){
	this->businessDay = source.businessDay;
}


DateInfo::~DateInfo(){
}


bool DateInfo::IsEqual(const DateInfo& other){
	bool ret = false;
	if(date.compare(other.date)==0 &&
		this->businessDay == other.businessDay){
			ret = true;
	}
	return ret;
}


bool DateInfo::IsNotEqual(const DateInfo& other){
	bool ret = false;
	if(date.compare(other.date)!=0 ||
		this->businessDay != other.businessDay){
			ret = true;
	}
	return ret;
}


DateInfo& DateInfo::operator=(const DateInfo& source){
	this->date = source.date;
	this->businessDay = source.businessDay;
	return *this;
}


bool DateInfo::operator==(const DateInfo& other){
	bool ret = false;
	if(this->date == other.date &&
		this->businessDay == other.businessDay){
			ret = true;
	}
	return ret;
}


bool DateInfo::operator!=(const DateInfo& other){
	bool ret = false;
	if(this->date != other.date ||
		this->businessDay != other.businessDay){
			ret = true;
	}
	return ret;
}