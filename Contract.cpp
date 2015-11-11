// Contract.cpp

#include "Contract.h"



Contract::Contract(int feedingSourceID){
	this->price = 0;
	this->volume =0;
	this->feedingSourceID = feedingSourceID;
}


Contract::Contract(const Contract& source)
	:time(source.time),
	type(source.type){
	this->price = source.price;
	this->volume = source.volume;
	this->feedingSourceID = source.feedingSourceID;
}


Contract::~Contract(){
}


void Contract::Update(const tstring& time, double price, const tstring& type, int volume){
	this->time = time;
	this->price = price;
	this->type = type;
	this->volume = volume;
}


bool Contract::IsEqual(const Contract& other){
	bool ret = false;
	if(this->time.compare(other.time)==0 && 
		this->price == other.price &&
		this->type.compare(other.type)==0 &&
		this->volume ==other.volume &&
		this->feedingSourceID == other.feedingSourceID){
			ret = true;
	}
	return ret;
}


bool Contract::IsNotEqual(const Contract& other){
	bool ret = false;
	if(this->time.compare(other.time)!=0 || 
		this->price != other.price ||
		this->type.compare(other.type)!=0 ||
		this->volume != other.volume ||
		this->feedingSourceID != other.feedingSourceID){
			ret = true;
	}
	return ret;
}


Contract& Contract::operator=(const Contract& source){
	this->time = source.time;
	this->price = source.price;
	this->type  = source.type;
	this->volume = source.volume;
	this->feedingSourceID = source.feedingSourceID;
	return *this;
}


bool Contract::operator==(const Contract& other){
	bool ret = false;
	if(this->time==other.time && 
		this->price == other.price &&
		this->type==other.type &&
		this->volume ==other.volume &&
		this->feedingSourceID == other.feedingSourceID){
			ret = true;
	}
	return ret;
}


bool Contract::operator!=(const Contract& other){
	bool ret = false;
	if(this->time!=other.time || 
		this->price != other.price ||
		this->type!=other.type ||
		this->volume != other.volume ||
		this->feedingSourceID != other.feedingSourceID){
			ret = true;
	}
	return ret;
}