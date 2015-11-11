// LoginTime.cpp

#include "LoginTime.h"



LoginTime::LoginTime(){
	this->checker = false;
}


LoginTime::LoginTime(const tstring& timeStart, const tstring& timeEnd, bool checker)
	:timeStart(timeStart),
	timeEnd(timeEnd){
	this->checker = checker;
}


LoginTime::LoginTime(const LoginTime& source)
	:timeStart(source.timeStart),
	timeEnd(source.timeEnd){
	this->checker  = source.checker;
}


LoginTime::~LoginTime(){
}


bool LoginTime::IsEqual(const LoginTime& other){
	bool ret = false;
	if(this->timeStart.compare(other.timeStart)==0 &&
		this->timeEnd.compare(other.timeEnd)==0 &&
		this->checker == other.checker){
			ret = true;
	}
	return ret;
}


bool LoginTime::IsNotEqual(const LoginTime& other){
	bool ret = false;
	if(this->timeStart.compare(other.timeStart)!=0 ||
		this->timeEnd.compare(other.timeEnd)!=0 ||
		this->checker != other.checker){
			ret = true;
	}
	return ret;
}


LoginTime& LoginTime::operator=(const LoginTime& source){
	this->timeStart = source.timeStart;
	this->timeEnd = source.timeEnd;
	this->checker = source.checker;
	return *this;
}


bool LoginTime::operator==(const LoginTime& other){
	bool ret = false;
	if(this->timeStart == other.timeStart &&
		this->timeEnd == other.timeEnd &&
		this->checker == other.checker){
			ret = true;
	}
	return ret;
}


bool LoginTime::operator!=(const LoginTime& other){
	bool ret = false;
	if(this->timeStart != other.timeStart ||
		this->timeEnd != other.timeEnd ||
		this->checker != other.checker){
			ret = true;
	}
	return ret;
}