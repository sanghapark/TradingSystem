// AskList.cpp

#include "AskList.h"

AskList::AskList(int length)
	:asks(length){
	this->length = length;
}


AskList::AskList(const AskList& source)
	:asks(source.asks){
	this->length = source.length;
}


AskList::~AskList(){
}


void AskList::Update(const Ask& ask, int index){
	this->GetAt(index) = ask;
}


bool AskList::IsEqual(const AskList& other){
	bool ret= false;
	if(this->asks.IsEqual(other.asks)==true &&
		this->length == other.length){
			ret = true;
	}
	return ret;
}


bool AskList::IsNotEqual(const AskList& other){
	bool ret= false;
	if(this->asks.IsNotEqual(other.asks)==true ||
		this->length != other.length){
			ret= true;
	}
	return ret;
}


Ask& AskList::GetAt(int index){
	return this->asks.GetAt(index);
}


AskList& AskList::operator=(const AskList& source){
	this->asks = source.asks;
	this->length = source.length;
	return *this;
}


bool AskList::operator==(const AskList& other){
	bool ret= false;
	if(this->asks==other.asks &&
		this->length == other.length){
			ret = true;
	}
	return ret;
}


bool AskList::operator!=(const AskList& other){
	bool ret= false;
	if(this->asks != other.asks ||
		this->length != other.length){
			ret = true;
	}
	return ret;
}


Ask& AskList::operator[](int index){
	return this->asks[index];
}