// EuropeanOption.cpp

#include "EuropeanOption.h"
#include "BlackSholesOptionPricingModel.h"


EuropeanOption::EuropeanOption(){
	this->strikePrice = 0.0;
}


EuropeanOption::EuropeanOption(const EuropeanOption& source)
	:optionCode(source.optionCode),
	underlyingAssetCode(source.underlyingAssetCode),
	optionType(source.optionType),
	sensitivity(source.sensitivity),
	optionValue(source.optionValue){
	this->strikePrice = source.strikePrice;
}


EuropeanOption::EuropeanOption(const tstring& optionCode, const tstring& underlyingAssetCode, const tstring& optionType, double strikePrice)
	:optionCode(optionCode),
	underlyingAssetCode(underlyingAssetCode),
	optionType(optionType){
	this->strikePrice = strikePrice;
}


EuropeanOption::~EuropeanOption(){
}


OptionValue& EuropeanOption::CalculateValue(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	BlackSholesOptionPricingModel bsopm;
	bsopm.SetParameters(this->optionType, this->strikePrice, underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	this->optionValue = bsopm.CalculateValue();
	return this->optionValue;
}


Sensitivity& EuropeanOption::CalculateSensitivity(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	BlackSholesOptionPricingModel bsopm;
	bsopm.SetParameters(this->optionType, this->strikePrice, underlyingAssetPrice, timeLeft, riskFreeRate, volatility);
	this->sensitivity = bsopm.CalculateSensitivity();
	return this->sensitivity;
}


bool EuropeanOption::IsEqual(const EuropeanOption& other){
	bool ret = false;
	if(this->optionCode.compare(other.optionCode)==0 &&
		this->underlyingAssetCode.compare(other.underlyingAssetCode)==0 &&
		this->optionType.compare(other.optionType)==0 &&
		this->strikePrice == other.strikePrice &&
		this->sensitivity.IsEqual(other.sensitivity) == true &&
		this->optionValue.IsEqual(other.optionValue)==true){
			ret = true;
	}
	return ret;
}


bool EuropeanOption::IsNotEqual(const EuropeanOption& other){
	bool ret = false;
	if(this->optionCode.compare(other.optionCode)!=0 ||
		this->underlyingAssetCode.compare(other.underlyingAssetCode)!=0 ||
		this->optionType.compare(other.optionType)!=0 ||
		this->strikePrice != other.strikePrice ||
		this->sensitivity.IsNotEqual(other.sensitivity)==true ||
		this->optionValue.IsNotEqual(other.optionValue)==true){
			ret = true;
	}
	return ret;
}


EuropeanOption& EuropeanOption::operator=(const EuropeanOption& source){
	this->optionCode = source.optionCode;
	this->underlyingAssetCode = source.underlyingAssetCode;
	this->optionType = source.optionType;
	this->strikePrice = source.strikePrice;
	this->sensitivity = source.sensitivity;
	this->optionValue = source.optionValue;
	return *this;
}


bool EuropeanOption::operator==(const EuropeanOption& other){
	bool ret = false;
	if(this->optionCode == other.optionCode &&
		this->underlyingAssetCode == other.underlyingAssetCode &&
		this->optionType ==other.optionType &&
		this->strikePrice == other.strikePrice &&
		this->sensitivity== other.sensitivity &&
		this->optionValue == other.optionValue){
			ret = true;
	}
	return ret;
}


bool EuropeanOption::operator!=(const EuropeanOption& other){
	bool ret = false;
	if( this->optionCode != other.optionCode ||
		this->underlyingAssetCode != other.underlyingAssetCode ||
		this->optionType !=other.optionType ||
		this->strikePrice != other.strikePrice ||
		this->sensitivity != other.sensitivity ||
		this->optionValue != other.optionValue){
			ret = true;
	}
	return ret;
}