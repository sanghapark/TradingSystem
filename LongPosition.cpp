// LongPosition.cpp

#include "LongPosition.h"
#include "BlackSholesOptionPricingModel.h"
#include "Constants.h"

LongPosition::LongPosition()
	:positionType(LONG_POSITION){
	this->value = 0.0;
	this->instrinsicValue = 0.0;
	this->timeValue = 0.0;
	this->payoff = 0.0;
	this->premium = 0.0;
	this->numContract = 0;
	this->positionNumber = 0;
	this->returnExit = 0.0;
}


LongPosition::LongPosition(const LongPosition& source)
	:positionType(source.GetPositionType()),
	option(source.option){
	this->value = source.value;
	this->instrinsicValue = source.instrinsicValue;
	this->timeValue = source.timeValue;
	this->payoff = source.payoff;
	this->premium = source.premium;
	this->numContract = source.numContract;
	this->positionNumber = source.positionNumber;
	this->returnExit = source.returnExit;
}


LongPosition::LongPosition(const EuropeanOption& option, double premium, int numContract)
	:positionType(LONG_POSITION),
	option(option){
	this->value = 0.0;
	this->instrinsicValue = 0.0;
	this->timeValue = 0.0;
	this->payoff = 0.0;
	this->premium = -1.0*premium;
	this->numContract = numContract;
	this->positionNumber = 0;
	this->returnExit = 0.0;
}


LongPosition::~LongPosition(){
}


void LongPosition::Valuate(const OptionParameter& parameter){

	double underlyingAssetPrice = parameter.GetUnderlyingAssetPrice();
	double timeLeft = parameter.GetTimeLeft();
	double riskFreeRate = parameter.GetRiskFreeRate();
	double volatility = parameter.GetVolatility();
	double pointInWon = parameter.GetPointInWON();
	
	// BlackSholesOptionPricingModel °è»ê

	OptionValue optionValue = this->option.CalculateValue(underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	double valueByBSOPM = optionValue.GetValue();
	double valueAtExp = optionValue.GetIntrinsicValue();

	this->value = (valueByBSOPM + this->premium)*double(this->numContract);
	this->instrinsicValue = (valueAtExp + this->premium)*double(this->numContract);
	this->timeValue = (this->value - this->instrinsicValue)*double(this->numContract);
	this->payoff = this->instrinsicValue;

	if(option.GetOptionType().compare(CALL_OPTION)==0){
		this->returnExit = underlyingAssetPrice - this->option.GetStrikePrice() - this->premium;
	}
	else if(option.GetOptionType().compare(PUT_OPTION)==0){
		this->returnExit = this->option.GetStrikePrice() - underlyingAssetPrice - this->premium;
	}
	
}


bool LongPosition::IsEqual(const LongPosition& other){
	bool ret = false;
	if(this->positionType.compare(other.positionType)==0 &&
		this->option.IsEqual(other.option)==true &&
		this->value == other.value &&
		this->instrinsicValue == other.value &&
		this->timeValue == other.timeValue &&
		this->payoff == other.payoff &&
		this->premium == other.premium &&
		this->numContract == other.numContract &&
		this->positionNumber == other.positionNumber &&
		this->returnExit == other.returnExit){
			ret = true;
	}
	return ret;
}


bool LongPosition::IsNotEqual(const LongPosition& other){
	bool ret = false;
	if(this->positionType.compare(other.positionType)!=0 ||
		this->option.IsNotEqual(other.option)==true ||
		this->value != other.value ||
		this->instrinsicValue != other.value ||
		this->timeValue != other.timeValue ||
		this->payoff != other.payoff ||
		this->premium != other.premium ||
		this->numContract != other.numContract ||
		this->positionNumber != other.positionNumber ||
		this->returnExit != other.returnExit){
			ret = true;
	}
	return ret;
}


LongPosition& LongPosition::operator=(const LongPosition& source){
	this->positionType = source.positionType;
	this->option = source.option;
	this->value = source.value;
	this->instrinsicValue = source.instrinsicValue;
	this->timeValue = source.timeValue;
	this->payoff = source.payoff;
	this->premium = source.premium;
	this->numContract = source.numContract;
	this->positionNumber = source.positionNumber;
	this->returnExit = source.returnExit;
	return *this;
}


bool LongPosition::operator==(const LongPosition& other){
	bool ret = false;
	if(this->positionType == other.positionType&&
		this->option == other.option &&
		this->value == other.value &&
		this->instrinsicValue == other.value &&
		this->timeValue == other.timeValue &&
		this->payoff == other.payoff &&
		this->premium == other.premium &&
		this->numContract == other.numContract &&
		this->positionNumber == other.positionNumber &&
		this->returnExit == other.returnExit){
			ret = true;
	}
	return ret;
}


bool LongPosition::operator!=(const LongPosition& other){
	bool ret = false;
	if(this->positionType != other.positionType ||
		this->option != other.option ||
		this->value != other.value ||
		this->instrinsicValue != other.value ||
		this->timeValue != other.timeValue ||
		this->payoff != other.payoff ||
		this->premium != other.premium ||
		this->numContract != other.numContract ||
		this->positionNumber != other.positionNumber ||
		this->returnExit != other.returnExit){
			ret = true;
	}
	return ret;
}