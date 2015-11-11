// OptionParameter.cpp

#include "OptionParameter.h"


OptionParameter::OptionParameter(){
	this->underlyingAssetPrice = 0.0;
	this->timeLeft = 0.0;
	this->riskFreeRate = 0.0;
	this->volatility = 0.0;
	this->strikePrice = 0.0;
	this->premium = 0.0;
	this->premiumMarket = 0.0;
	this->numContract = 0;
	this->pointInWON = 0.0;
}


OptionParameter::OptionParameter(const OptionParameter& source)
	:optionCode(source.optionCode),
	optionType(source.optionType),
	position(source.position){
	this->underlyingAssetPrice = source.underlyingAssetPrice;
	this->timeLeft = source.timeLeft;
	this->riskFreeRate = source.riskFreeRate;
	this->volatility = source.volatility;

	this->strikePrice = source.strikePrice;
	this->premium = source.premium;
	this->premiumMarket = source.premiumMarket;
	this->numContract = source.numContract;
	this->pointInWON = source.pointInWON;
}


OptionParameter::OptionParameter(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	this->underlyingAssetPrice = underlyingAssetPrice;
	this->timeLeft = timeLeft;
	this->riskFreeRate = riskFreeRate;
	this->volatility = volatility;

	this->strikePrice = 0.0;
	this->premium = 0.0;
	this->pointInWON = 0.0;
}


OptionParameter::OptionParameter(double underlyingAssetPrice){
	this->underlyingAssetPrice = underlyingAssetPrice;
}


OptionParameter::~OptionParameter(){
}



bool OptionParameter::IsEqual(const OptionParameter& other){
	bool ret =false;
	if(this->underlyingAssetPrice == other.underlyingAssetPrice &&
		this->timeLeft == other.timeLeft &&
		this->riskFreeRate == other.riskFreeRate &&
		this->volatility == other.volatility &&
		this->optionCode.compare(other.optionCode)==0 &&
		this->optionType.compare(other.optionType)==0 &&
		this->position.compare(other.position)==0 &&
		this->strikePrice == other.strikePrice &&
		this->premium == other.premium &&
		this->premiumMarket == other.premiumMarket &&
		this->numContract == other.numContract &&
		this->pointInWON == other.pointInWON){
			ret = true;
	}
	return ret;
}


bool OptionParameter::IsNotEqual(const OptionParameter& other){
	bool ret =false;
	if(this->underlyingAssetPrice != other.underlyingAssetPrice ||
		this->timeLeft != other.timeLeft ||
		this->riskFreeRate != other.riskFreeRate ||
		this->volatility != other.volatility ||
		this->optionCode.compare(other.optionCode)!=0 ||
		this->optionType.compare(other.optionType)!=0 ||
		this->position.compare(other.position)!=0 ||
		this->strikePrice != other.strikePrice ||
		this->premium != other.premium ||
		this->premiumMarket != other.premiumMarket ||
		this->numContract != other.numContract ||
		this->pointInWON != other.pointInWON){
			ret = true;
	}
	return ret;
}


OptionParameter& OptionParameter::operator=(const OptionParameter& source){
	this->underlyingAssetPrice = source.underlyingAssetPrice;
	this->timeLeft = source.timeLeft;
	this->riskFreeRate = source.riskFreeRate;
	this->volatility = source.volatility;
	this->optionCode = source.optionCode;
	this->optionType = source.optionType;
	this->position  = source.position;
	this->strikePrice = source.strikePrice;
	this->premium = source.premium;
	this->premiumMarket = source.premiumMarket;
	this->numContract = source.numContract;
	this->pointInWON = source.pointInWON;
	return *this;
}


bool OptionParameter::operator==(const OptionParameter& other){
	bool ret =false;
	if(this->underlyingAssetPrice == other.underlyingAssetPrice &&
		this->timeLeft == other.timeLeft &&
		this->riskFreeRate == other.riskFreeRate &&
		this->volatility == other.volatility &&
		this->optionCode == other.optionCode &&
		this->optionType == other.optionType &&
		this->position == other.position &&
		this->strikePrice == other.strikePrice &&
		this->premium == other.premium &&
		this->premiumMarket == other.premiumMarket &&
		this->numContract == other.numContract &&
		this->pointInWON == other.pointInWON){
			ret = true;
	}
	return ret;
}


bool OptionParameter::operator!=(const OptionParameter& other){
	bool ret =false;
	if(this->underlyingAssetPrice != other.underlyingAssetPrice ||
		this->timeLeft != other.timeLeft ||
		this->riskFreeRate != other.riskFreeRate ||
		this->volatility != other.volatility ||
		this->optionCode != other.optionCode ||
		this->optionType != other.optionType ||
		this->position != other.position ||
		this->strikePrice != other.strikePrice ||
		this->premium != other.premium ||
		this->premiumMarket != other.premiumMarket ||
		this->numContract != other.numContract ||
		this->pointInWON != other.pointInWON){
			ret = true;
	}
	return ret;
}