// Ask.cpp

#include "Ask.h"

Ask::Ask(){
	this->price = 0;
	this->quantity = 0;
	this->count = 0;
}


Ask::Ask(const Ask& source){
	this->price = source.price;
	this->quantity = source.quantity;
	this->count = source.count;
}


Ask::~Ask(){
}


void Ask::Update(double price, int quantity, int count){
	this->price = price;
	this->quantity = quantity;
	this->count = count;
}


bool Ask::IsEqual(const Ask& other){
	bool ret = false;
	if(this->price == other.price &&
		this->quantity == other.quantity &&
		this->count == other.count){
			ret = true;
	}
	return ret;
}


bool Ask::IsNotEqual(const Ask& other){
	bool ret = false;
	if(this->price != other.price ||
		this->quantity != other.quantity ||
		this->count != other.count){
			ret = true;
	}
	return ret;
}


Ask& Ask::operator=(const Ask& source){
	this->price = source.price;
	this->quantity = source.quantity;
	this->count = source.count;
	return *this;
}


bool Ask::operator==(const Ask& other){
	bool ret = false;
	if(this->price == other.price &&
		this->quantity == other.quantity &&
		this->count == other.count){
			ret = true;
	}
	return ret;
}


bool Ask::operator!=(const Ask& other){
	bool ret = false;
	if(this->price != other.price ||
		this->quantity != other.quantity ||
		this->count != other.count){
			ret = true;
	}
	return ret;
}
