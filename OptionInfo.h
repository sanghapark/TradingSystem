// OptionInfo.h

#pragma once

#include "EuropeanOption.h"


class OptionInfo{
public:
	OptionInfo();
	OptionInfo(const tstring& optionType, double marketPrice, double strikePrice, const EuropeanOption& option, const OptionValue& brokerOptionValue, const Sensitivity& brokerSensitivity);
	OptionInfo(const OptionInfo& source);
	~OptionInfo();

	bool IsEqual(const OptionInfo& other);
	bool IsNotEqual(const OptionInfo& other);

	OptionInfo& operator=(const OptionInfo& source);
	bool operator==(const OptionInfo& other);
	bool operator!=(const OptionInfo& other);

	tstring& GetOptionType() const;
	double GetMarketPrice() const;
	double GetStrikePrice() const;
	EuropeanOption& GetOption() const;
	OptionValue& GetBrokerOptionValue() const;
	Sensitivity& GetBrokerSensitivity() const;


private:
	tstring optionType;
	double marketPrice;
	double strikePrice;
	EuropeanOption option;
	OptionValue brokerOptionValue;
	Sensitivity brokerSensitivity;
};


inline tstring& OptionInfo::GetOptionType() const{
	return const_cast<tstring&>(this->optionType);
}

inline double OptionInfo::GetMarketPrice() const{
	return this->marketPrice;
}

inline double OptionInfo::GetStrikePrice() const{
	return this->strikePrice;
}


inline EuropeanOption& OptionInfo::GetOption() const{
	return const_cast<EuropeanOption&>(this->option);
}


inline OptionValue& OptionInfo::GetBrokerOptionValue() const{
	return const_cast<OptionValue&>(this->brokerOptionValue);
}


inline Sensitivity& OptionInfo::GetBrokerSensitivity() const{
	return const_cast<Sensitivity&>(this->brokerSensitivity);
}