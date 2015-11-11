// OptionValue.cpp

#include "OptionValue.h"


OptionValue::OptionValue(){
	this->value = 0.0;
	this->intrinsicValue = 0.0;
	this->timeValue = 0.0;
}


OptionValue::OptionValue(double value, double intrinsicValue, double timeValue){
	this->value = value;
	this->intrinsicValue = intrinsicValue;
	this->timeValue = timeValue;
}


OptionValue::OptionValue(const OptionValue& source){
	this->value = source.value;
	this->intrinsicValue = source.intrinsicValue;
	this->timeValue = source.timeValue;
}


OptionValue::~OptionValue(){
}


bool OptionValue::IsEqual(const OptionValue& other){
	bool ret  = false;
	if(this->value == other.value &&
		this->intrinsicValue == other.intrinsicValue &&
		this->timeValue == other.timeValue){
			ret = true;
	}
	return ret;
}


bool OptionValue::IsNotEqual(const OptionValue& other){
	bool ret = false;
	if(this->value != other.value ||
		this->intrinsicValue != other.intrinsicValue ||
		this->timeValue != other.timeValue){
			ret = true;
	}
	return ret;
}


OptionValue& OptionValue::operator=(const OptionValue& source){
	this->value = source.value;
	this->intrinsicValue = source.intrinsicValue;
	this->timeValue = source.timeValue;
	return *this;
}


bool OptionValue::operator==(const OptionValue& other){
	bool ret  = false;
	if(this->value == other.value &&
		this->intrinsicValue == other.intrinsicValue &&
		this->timeValue == other.timeValue){
			ret = true;
	}
	return ret;
}


bool OptionValue::operator!=(const OptionValue& other){
	bool ret = false;
	if(this->value != other.value ||
		this->intrinsicValue != other.intrinsicValue ||
		this->timeValue != other.timeValue){
			ret = true;
	}
	return ret;
}