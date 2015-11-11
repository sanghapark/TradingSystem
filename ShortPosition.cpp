// ShortPosition.cpp

#include <cmath>
#include "ShortPosition.h"
#include "Constants.h"

ShortPosition::ShortPosition()
	:positionType(SHORT_POSITION){
	this->value = 0.0;
	this->payoff = 0.0;
	this->premium = 0.0;
	this->numContract = 0;
	this->positionNumber = 0;
	this->returnExit = 0.0;
}


ShortPosition::ShortPosition(const ShortPosition& source)
	:positionType(source.positionType),
	option(source.option){
	this->value  = source.value;
	this->payoff = source.payoff;
	this->premium = source.premium;
	this->numContract = source.numContract;
	this->positionNumber = source.positionNumber;
	this->returnExit = source.returnExit;
}


ShortPosition::ShortPosition(const EuropeanOption& option, double premium, int numContract)
	:positionType(SHORT_POSITION),
	option(option){
	this->value = 0.0;
	this->payoff = 0.0;
	this->premium = premium;
	this->numContract = numContract;
	this->positionNumber = 0;
	this->returnExit = 0.0;
}


ShortPosition::~ShortPosition(){
}


void ShortPosition::Valuate(const OptionParameter& parameter){
	double underlyingAssetPrice = parameter.GetUnderlyingAssetPrice();
	double timeLeft = parameter.GetTimeLeft();
	double riskFreeRate = parameter.GetRiskFreeRate();
	double volatility = parameter.GetVolatility();

	OptionValue optionValue = this->option.CalculateValue(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	double valueByBSOPM = optionValue.GetValue();
	double valueAtExp = optionValue.GetIntrinsicValue();
	double dblContract(this->numContract);

	double timeValue = (valueByBSOPM - valueAtExp)*dblContract;

	if(option.GetOptionType().compare(CALL_OPTION)==0){
		this->payoff = (min(premium, option.GetStrikePrice() - underlyingAssetPrice + premium))*dblContract;
		this->value = this->payoff - timeValue; // long timeValueÇØÁà¾ßµÊ
		this->returnExit = this->option.GetStrikePrice() - underlyingAssetPrice + this->premium;
	}
	else if(option.GetOptionType().compare(PUT_OPTION)==0){
		this->payoff = (min(premium, underlyingAssetPrice - option.GetStrikePrice() + premium))*dblContract;
		this->value = this->payoff - timeValue; // long timeValueÇØÁà¾ßµÊ
		this->returnExit = underlyingAssetPrice - this->option.GetStrikePrice() + this->premium;
	}
}


bool ShortPosition::IsEqual(const ShortPosition& other){
	bool ret = false;
	if(positionType.compare(other.positionType)==0 &&
		this->option.IsEqual(other.option)==true &&
		this->value == other.value &&
		this->payoff == other.payoff &&
		this->premium == other.premium &&
		this->numContract == other.numContract &&
		this->positionNumber == other.positionNumber &&
		this->returnExit == other.returnExit){
			ret = true;
	}
	return ret;
}


bool ShortPosition::IsNotEqual(const ShortPosition& other){
	bool ret = false;
	if(positionType.compare(other.positionType)!=0 ||
		this->option.IsNotEqual(other.option)==true ||
		this->value != other.value ||
		this->payoff != other.payoff ||
		this->premium != other.premium ||
		this->numContract != other.numContract ||
		this->positionNumber != other.positionNumber ||
		this->returnExit != other.returnExit){
			ret = true;
	}
	return ret;
}


ShortPosition& ShortPosition::operator=(const ShortPosition& source){
	this->positionType = source.positionType;
	this->option = source.option;
	this->value = source.value;
	this->payoff = source.payoff;
	this->premium = source.premium;
	this->numContract = source.numContract;
	this->positionNumber = source.positionNumber;
	this->returnExit = source.returnExit;
	return *this;
}


bool ShortPosition::operator==(const ShortPosition& other){
	bool ret = false;
	if(positionType == other.positionType &&
		this->option ==other.option &&
		this->value == other.value &&
		this->payoff == other.payoff &&
		this->premium == other.premium &&
		this->numContract == other.numContract &&
		this->positionNumber == other.positionNumber &&
		this->returnExit == other.returnExit){
			ret = true;
	}
	return ret;
}


bool ShortPosition::operator!=(const ShortPosition& other){
	bool ret = false;
	if(positionType != other.positionType ||
		this->option != other.option ||
		this->value != other.value ||
		this->payoff != other.payoff ||
		this->premium != other.premium ||
		this->numContract != other.numContract ||
		this->positionNumber != other.positionNumber ||
		this->returnExit != other.returnExit){
			ret = true;
	}
	return ret;
}