// OptionPriceBoardItem.h

#pragma once

#include "EuropeanOption.h"


class OptionPriceBoardItem{
public:
	OptionPriceBoardItem();
	OptionPriceBoardItem(double strikePrice,
							const EuropeanOption& callOption,
							const OptionValue& brokerCallOptionValue,
							const Sensitivity& brokerCallOptionSensitivity,
							const EuropeanOption& putOption,
							const OptionValue& brokerPutOptionValue,
							const Sensitivity& brokerPutOptionSensitivity);
	OptionPriceBoardItem(const OptionPriceBoardItem& source);
	~OptionPriceBoardItem();

	void CalculateValue(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);
	void CalculateSensitivity(double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility);

	bool IsEqual(const OptionPriceBoardItem& other);
	bool IsNotEqual(const OptionPriceBoardItem& other);
	
	bool operator==(const OptionPriceBoardItem& other);
	bool operator!=(const OptionPriceBoardItem& other);
	OptionPriceBoardItem& operator=(const OptionPriceBoardItem& source);


	double GetStrikePrice() const;
	EuropeanOption& GetCallOption() const;
	OptionValue& GetBrokerCallOptionValue() const;
	Sensitivity& GetBrokerCallOptionSensitivity() const;
	EuropeanOption& GetPutOption() const;
	OptionValue& GetBrokerPutOptionValue() const;
	Sensitivity& GetBrokerPutOptionSensitivity() const;


private:
	double strikePrice;
	
	EuropeanOption callOption;
	OptionValue brokerCallOptionValue;
	Sensitivity brokerCallOptionSensitivity;

	EuropeanOption putOption;
	OptionValue brokerPutOptionValue;
	Sensitivity brokerPutOptionSensitivity;
};

inline double OptionPriceBoardItem::GetStrikePrice() const{
	return this->strikePrice;
}


inline EuropeanOption& OptionPriceBoardItem::GetCallOption() const{
	return const_cast<EuropeanOption&>(this->callOption);
}


inline OptionValue& OptionPriceBoardItem::GetBrokerCallOptionValue() const{
	return const_cast<OptionValue&>(this->brokerCallOptionValue);
}


inline Sensitivity& OptionPriceBoardItem::GetBrokerCallOptionSensitivity() const{
	return const_cast<Sensitivity&>(this->brokerCallOptionSensitivity);
}


inline EuropeanOption& OptionPriceBoardItem::GetPutOption() const{
	return const_cast<EuropeanOption&>(this->putOption);
}


inline OptionValue& OptionPriceBoardItem::GetBrokerPutOptionValue() const{
	return const_cast<OptionValue&>(this->brokerPutOptionValue);
}


inline Sensitivity& OptionPriceBoardItem::GetBrokerPutOptionSensitivity() const{
	return const_cast<Sensitivity&>(this->brokerPutOptionSensitivity);
}
