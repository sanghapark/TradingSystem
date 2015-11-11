// OptionPriceBoard.cpp

#include <tchar.h>
#include "OptionPriceBoard.h"
#include "MathFormula.h"
#include "Constants.h"

OptionPriceBoard::OptionPriceBoard(){
	this->numStrikePrices = 0;
	this->strikePricesATM = 0;
	this->countATM = 0;

}


OptionPriceBoard::OptionPriceBoard(const OptionInfoList& callOptions, const OptionInfoList& putOptions)
	:callOptions(callOptions),
	putOptions(putOptions){
	this->numStrikePrices = callOptions.GetLength();

	this->strikePricesATM = 0;
	this->countATM = 0;



}


OptionPriceBoard::OptionPriceBoard(const OptionPriceBoard& source)
	:callOptions(source.callOptions),
	putOptions(source.putOptions){
	this->numStrikePrices = source.numStrikePrices;

	memcpy_s(this->strikePricesATM, source.countATM, source.strikePricesATM, sizeof(double));
	this->countATM = source.countATM;
}



OptionPriceBoard::~OptionPriceBoard(){
	if(this->strikePricesATM!=0){
		delete [] this->strikePricesATM;
	}
}


void OptionPriceBoard::Valuate(double underlyingAssetPrice, double expiryRatio, double riskFreeRate, double histVol){
	// 등가격 행사가 계산
	if(this->strikePricesATM!=0){
		delete [] this->strikePricesATM;
		this->strikePricesATM = 0;
		this->countATM = 0;
	}
	this->strikePricesATM = MathFormula::GetPriceAtTheMoney(underlyingAssetPrice, 2.5, &(this->countATM));
	
	// 하나씩 이론가 계산
	this->callOptions.Valuate(underlyingAssetPrice, expiryRatio, riskFreeRate, histVol);
	this->putOptions.Valuate(underlyingAssetPrice, expiryRatio, riskFreeRate, histVol);
}

void OptionPriceBoard::Clear(){
	this->callOptions.DeleteAll();
	this->putOptions.DeleteAll();
	if(this->strikePricesATM != 0){
		delete [] this->strikePricesATM;
		this->strikePricesATM =  0;
	}
	this->countATM = 0;
}


OptionParameter OptionPriceBoard::GetOptionParameterByOptionCode(const tstring& optionCode){
	OptionParameter param;

	tstring optionTypeNum = optionCode.substr(0,1);

	int index = -1;
	if(optionTypeNum.compare(_T("2"))==0){
		index = this->callOptions.FineOptionInfoByOptionCode(optionCode);
		if(index>=0){
			OptionInfo& optionInfo = this->callOptions.GetAt(index);
			param.SetOptionCode(optionInfo.GetOption().GetOptionCode());
			param.SetOptionType(CALL_OPTION);
			param.SetStrikePrice(optionInfo.GetStrikePrice());
			param.SetPremium(optionInfo.GetOption().GetOptionValue().GetValue());
			param.SetPremiumMarket(optionInfo.GetMarketPrice());
		}
	}
	else if(optionTypeNum.compare(_T("3"))==0){
		index = this->putOptions.FineOptionInfoByOptionCode(optionCode);
		if(index>=0){
			OptionInfo& optionInfo = this->putOptions.GetAt(index);
			param.SetOptionCode(optionInfo.GetOption().GetOptionCode());
			param.SetOptionType(PUT_OPTION);
			param.SetStrikePrice(optionInfo.GetStrikePrice());
			param.SetPremium(optionInfo.GetOption().GetOptionValue().GetValue());
			param.SetPremiumMarket(optionInfo.GetMarketPrice());
		}
	}

	return param;
}




bool OptionPriceBoard::IsEqual(const OptionPriceBoard& other){
	bool ret= false;

	if(this->callOptions.IsEqual(other.callOptions)==true &&
		this->putOptions.IsEqual(other.putOptions)==true &&
		this->numStrikePrices == other.numStrikePrices &&
		memcmp(this->strikePricesATM, other.strikePricesATM, sizeof(double))==0){
			ret = true;
	}
	return ret;
}



bool OptionPriceBoard::IsNotEqual(const OptionPriceBoard& other){
	bool ret= false;

	if(this->callOptions.IsNotEqual(other.callOptions)==true ||
		this->putOptions.IsNotEqual(other.putOptions)==true ||
		this->numStrikePrices != other.numStrikePrices ||
		memcmp(this->strikePricesATM, other.strikePricesATM, sizeof(double))!=0){
			ret = true;
	}
	return ret;
}


OptionPriceBoard& OptionPriceBoard::operator=(const OptionPriceBoard& source){
	this->callOptions = source.callOptions;
	this->putOptions = source.putOptions;
	this->numStrikePrices = source.numStrikePrices;
	memcpy_s(this->strikePricesATM, source.countATM, source.strikePricesATM, sizeof(double));
	this->countATM = source.countATM;
	return *this;
}


bool OptionPriceBoard::operator==(const OptionPriceBoard& other){
	bool ret =false;
	if(this->callOptions==other.callOptions &&
		this->putOptions==other.putOptions &&
		this->numStrikePrices == other.numStrikePrices &&
		memcmp(this->strikePricesATM, other.strikePricesATM, sizeof(double))==0){
			ret = true;
	}
	return ret;
}



bool OptionPriceBoard::operator!=(const OptionPriceBoard& other){
	bool ret =false;
	if(this->callOptions!=other.callOptions ||
		this->putOptions!=other.putOptions ||
		this->numStrikePrices != other.numStrikePrices ||
		memcmp(this->strikePricesATM, other.strikePricesATM, sizeof(double))!=0){
			ret = true;
	}
	return ret;
}