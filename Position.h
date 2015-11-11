// Position.h

#pragma once

#include <string>
#include "EuropeanOption.h"
#include "OptionParameter.h"


using namespace std;

class Position{
public:
	virtual ~Position(){};
	virtual void Valuate(const OptionParameter& parameter)=0;
	virtual double GetValue() const = 0;
	virtual double GetPayoff() const = 0;
	virtual tstring& GetPositionType() const =0;
	virtual EuropeanOption& GetOption() const=0;
	virtual double GetPremium() const=0;
	virtual int GetNumContract() const=0;
	virtual int GetPositionNumber() const=0;
	virtual void SetPositionNumber(int positionNumber)=0;

	virtual double GetReturnExit() const=0;
};