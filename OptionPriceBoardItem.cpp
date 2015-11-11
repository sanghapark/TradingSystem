// OptionPriceBoardItem.cpp

#include "OptionPriceBoardItem.h"


OptionPriceBoardItem::OptionPriceBoardItem(){
	this->strikePrice = 0.0;
}

OptionPriceBoardItem::OptionPriceBoardItem(double strikePrice,
					  const EuropeanOption& callOption,
					  const OptionValue& brokerCallOptionValue,
					  const Sensitivity& brokerCallOptionSensitivity,
					  const EuropeanOption& putOption,
					  const OptionValue& brokerPutOptionValue,
					  const Sensitivity& brokerPutOptionSensitivity)
	:callOption(callOption),
	brokerCallOptionValue(brokerCallOptionValue),
	brokerCallOptionSensitivity(brokerCallOptionSensitivity),
	putOption(putOption),
	brokerPutOptionValue(brokerPutOptionValue),
	brokerPutOptionSensitivity(brokerPutOptionSensitivity){
	this->strikePrice = strikePrice;
}

OptionPriceBoardItem::OptionPriceBoardItem(const OptionPriceBoardItem& source)
	:callOption(source.callOption),
	brokerCallOptionValue(source.brokerCallOptionValue),
	brokerCallOptionSensitivity(source.brokerCallOptionSensitivity),
	putOption(source.putOption),
	brokerPutOptionValue(source.brokerPutOptionValue),
	brokerPutOptionSensitivity(source.brokerPutOptionSensitivity){
	this->strikePrice = source.strikePrice;
}

OptionPriceBoardItem::~OptionPriceBoardItem(){
}


void OptionPriceBoardItem::CalculateValue(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	this->callOption.CalculateValue(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	this->putOption.CalculateValue(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
}


void OptionPriceBoardItem::CalculateSensitivity(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	this->callOption.CalculateSensitivity(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	this->putOption.CalculateSensitivity(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
}



bool OptionPriceBoardItem::IsEqual(const OptionPriceBoardItem& other){
	bool ret = false;

	if(this->strikePrice == other.strikePrice &&
		this->callOption.IsEqual(other.callOption)==true &&
		this->brokerCallOptionValue.IsEqual(other.brokerCallOptionValue)==true &&
		this->brokerCallOptionSensitivity.IsEqual(other.brokerCallOptionSensitivity)==true &&
		this->putOption.IsEqual(other.putOption)==true &&
		this->brokerPutOptionValue.IsEqual(other.brokerPutOptionValue)==true &&
		this->brokerPutOptionSensitivity.IsEqual(other.brokerPutOptionSensitivity)==true){
		ret = true;
	}

	return ret;
}

bool OptionPriceBoardItem::IsNotEqual(const OptionPriceBoardItem& other){
	bool ret = false;

	if(this->strikePrice != other.strikePrice ||
		this->callOption.IsNotEqual(other.callOption)==true ||
		this->brokerCallOptionValue.IsNotEqual(other.brokerCallOptionValue)==true ||
		this->brokerCallOptionSensitivity.IsNotEqual(other.brokerCallOptionSensitivity)==true ||
		this->putOption.IsNotEqual(other.putOption)==true ||
		this->brokerPutOptionValue.IsNotEqual(other.brokerPutOptionValue)==true ||
		this->brokerPutOptionSensitivity.IsNotEqual(other.brokerPutOptionSensitivity)==true){
			ret = true;
	}

	return ret;
}

bool OptionPriceBoardItem::operator==(const OptionPriceBoardItem& other){
	bool ret = false;

	if(this->strikePrice == other.strikePrice &&
		this->callOption==other.callOption &&
		this->brokerCallOptionValue==other.brokerCallOptionValue &&
		this->brokerCallOptionSensitivity==other.brokerCallOptionSensitivity &&
		this->putOption==other.putOption &&
		this->brokerPutOptionValue==other.brokerPutOptionValue &&
		this->brokerPutOptionSensitivity==other.brokerPutOptionSensitivity){
			ret = true;
	}

	return ret;
}

bool OptionPriceBoardItem::operator!=(const OptionPriceBoardItem& other){
	bool ret = false;

	if(this->strikePrice != other.strikePrice ||
		this->callOption!=other.callOption ||
		this->brokerCallOptionValue!=other.brokerCallOptionValue ||
		this->brokerCallOptionSensitivity!=other.brokerCallOptionSensitivity ||
		this->putOption!=other.putOption ||
		this->brokerPutOptionValue!=other.brokerPutOptionValue ||
		this->brokerPutOptionSensitivity!=other.brokerPutOptionSensitivity){
			ret = true;
	}

	return ret;
}

OptionPriceBoardItem& OptionPriceBoardItem::operator=(const OptionPriceBoardItem& source){
	this->strikePrice = source.strikePrice ;
	this->callOption = source.callOption;
	this->brokerCallOptionValue = source.brokerCallOptionValue;
	this->brokerCallOptionSensitivity = source.brokerCallOptionSensitivity;

	this->putOption = source.putOption;
	this->brokerPutOptionValue = source.brokerPutOptionValue;
	this->brokerPutOptionSensitivity = source.brokerPutOptionSensitivity;

	return *this;
}