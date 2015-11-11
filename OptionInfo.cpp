// OptionInfo.cpp

#include "OptionInfo.h"



OptionInfo::OptionInfo(){
}


OptionInfo::OptionInfo(const tstring& optionType, double marketPrice, double strikePrice, const EuropeanOption& option, const OptionValue& brokerOptionValue, const Sensitivity& brokerSensitivity)
	:optionType(optionType),
	option(option),
	brokerOptionValue(brokerOptionValue),
	brokerSensitivity(brokerSensitivity){
	this->marketPrice = marketPrice;
	this->strikePrice = strikePrice;
}


OptionInfo::OptionInfo(const OptionInfo& source)
	:optionType(source.optionType),
	option(source.option),
	brokerOptionValue(source.brokerOptionValue),
	brokerSensitivity(source.brokerSensitivity){
	this->marketPrice = source.marketPrice;
	this->strikePrice = source.strikePrice;
}


OptionInfo::~OptionInfo(){
}


bool OptionInfo::IsEqual(const OptionInfo& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)==0 &&
		this->option.IsEqual(other.option)==true &&
		this->brokerOptionValue.IsEqual(other.brokerOptionValue)==true &&
		this->brokerSensitivity.IsEqual(other.brokerSensitivity)==true &&
		this->marketPrice == other.marketPrice &&
		this->strikePrice == other.strikePrice){
			ret = true;
	}
	return ret;
}


bool OptionInfo::IsNotEqual(const OptionInfo& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)!=0 ||
		this->option.IsNotEqual(other.option)==true ||
		this->brokerOptionValue.IsNotEqual(other.brokerOptionValue)==true ||
		this->brokerSensitivity.IsNotEqual(other.brokerSensitivity)==true ||
		this->marketPrice != other.marketPrice ||
		this->strikePrice != other.strikePrice){
			ret = true;
	}
	return ret;
}


OptionInfo& OptionInfo::operator=(const OptionInfo& source){
	this->optionType = source.optionType;
	this->option = source.option;
	this->brokerOptionValue = source.brokerOptionValue;
	this->brokerSensitivity = source.brokerSensitivity;
	this->marketPrice = source.marketPrice;
	this->strikePrice = source.strikePrice;
	return *this;
}


bool OptionInfo::operator==(const OptionInfo& other){
	bool ret = false;
	if(this->optionType==other.optionType &&
		this->option== other.option &&
		this->brokerOptionValue == other.brokerOptionValue &&
		this->brokerSensitivity == other.brokerSensitivity &&
		this->marketPrice == other.marketPrice &&
		this->strikePrice == other.strikePrice){
			ret = true;
	}
	return ret;
}


bool OptionInfo::operator!=(const OptionInfo& other){
	bool ret = false;
	if(this->optionType!=other.optionType ||
		this->option!=other.option ||
		this->brokerOptionValue != other.brokerOptionValue ||
		this->brokerSensitivity != other.brokerSensitivity ||
		this->marketPrice != other.marketPrice ||
		this->strikePrice != other.strikePrice){
			ret = true;
	}
	return ret;
}