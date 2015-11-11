// OptionParameter.h

#pragma once

#include "DataTypeDefinition.h"

class OptionParameter{
public:
	OptionParameter();
	OptionParameter(const OptionParameter& source);
	OptionParameter(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);
	OptionParameter(double underlyingAssetPrice);
	~OptionParameter();

	bool IsEqual(const OptionParameter& other);
	bool IsNotEqual(const OptionParameter& other);

	OptionParameter& operator=(const OptionParameter& soure);
	bool operator==(const OptionParameter& other);
	bool operator!=(const OptionParameter& other);


	// Getter
	double GetUnderlyingAssetPrice() const;
	double GetTimeLeft() const;
	double GetRiskFreeRate() const;
	double GetVolatility() const;

	tstring& GetOptionCode() const;
	tstring& GetOptionType() const;
	tstring& GetPosition() const;
	double GetStrikePrice() const;
	double GetPremium() const;
	double GetPremiumMarket() const;
	int GetNumContract() const;
	double GetPointInWON() const;

	// Setter
	void SetUnderlyingAssetPrice(double underlyingAssetPrice);
	void SetTimeLeft(double timeLeft);
	void SetRiskFreeRate(double riskFreeRate);
	void SetVolatility(double volatility);

	void SetOptionCode(const tstring& optionCode);
	void SetOptionType(const tstring& optionType);
	void SetPosition(const tstring& position);
	void SetStrikePrice(double strikePrice);
	void SetPremium(double premium);
	void SetPremiumMarket(double premiumMarket);
	void SetNumContract(int numContract);
	void SetPointInWON(double pointInWON);

private:

	double underlyingAssetPrice;
	double timeLeft;
	double riskFreeRate;
	double volatility;

	tstring optionCode;
	tstring optionType;
	tstring position;
	double strikePrice;
	double premium;
	double premiumMarket;

	int numContract;

	double pointInWON;

};



inline double OptionParameter::GetUnderlyingAssetPrice() const{
	return this->underlyingAssetPrice;
}


inline double OptionParameter::GetTimeLeft() const{
	return this->timeLeft;
}


inline double OptionParameter::GetRiskFreeRate() const{
	return this->riskFreeRate;
}


inline double OptionParameter::GetVolatility() const{
	return this->volatility;
}

inline tstring& OptionParameter::GetOptionCode() const{
	return const_cast<tstring&>(this->optionCode);
}


inline tstring& OptionParameter::GetOptionType() const{
	return const_cast<tstring&>(this->optionType);
}


inline tstring& OptionParameter::GetPosition() const{
	return const_cast<tstring&>(this->position);
}


inline double OptionParameter::GetStrikePrice() const{
	return this->strikePrice;
}


inline double OptionParameter::GetPremium() const{
	return this->premium;
}

inline double OptionParameter::GetPremiumMarket() const{
	return this->premiumMarket;
}


inline int OptionParameter::GetNumContract() const{
	return this->numContract;
}


inline double OptionParameter::GetPointInWON() const{
	return this->pointInWON;
}


inline void OptionParameter::SetUnderlyingAssetPrice(double underlyingAssetPrice){
	this->underlyingAssetPrice = underlyingAssetPrice;
}


inline void OptionParameter::SetTimeLeft(double timeLeft){
	this->timeLeft = timeLeft;
}


inline void OptionParameter::SetRiskFreeRate(double riskFreeRate){
	this->riskFreeRate = riskFreeRate;
}


inline void OptionParameter::SetVolatility(double volatility){
	this->volatility = volatility;
}


inline void OptionParameter::SetOptionCode(const tstring& optionCode){
	this->optionCode= optionCode;
}


inline void OptionParameter::SetOptionType(const tstring& optionType){
	this->optionType = optionType;
}


inline void OptionParameter::SetPosition(const tstring& position){
	this->position = position;
}


inline void OptionParameter::SetStrikePrice(double strikePrice){
	this->strikePrice = strikePrice;
}


inline void OptionParameter::SetPremium(double premium){
	this->premium = premium;
}


inline void OptionParameter::SetPremiumMarket(double premiumMarket){
	this->premiumMarket = premiumMarket;
}


inline void OptionParameter::SetNumContract(int numContract){
	this->numContract = numContract;
}


inline void OptionParameter::SetPointInWON(double pointInWON){
	this->pointInWON = pointInWON;
}