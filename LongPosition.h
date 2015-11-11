// LongPositon.h

#pragma once

#include "DataTypeDefinition.h"
#include "Position.h"
#include "EuropeanOption.h"

using namespace std;

class LongPosition : public Position{

public:
	LongPosition();
	LongPosition(const LongPosition& source);
	LongPosition(const EuropeanOption& option, double premium, int numContract);
	virtual ~LongPosition();

	virtual void Valuate(const OptionParameter& parameter);

	bool IsEqual(const LongPosition& other);
	bool IsNotEqual(const LongPosition& other);

	LongPosition& operator=(const LongPosition& source);
	bool operator==(const LongPosition& other);
	bool operator!=(const LongPosition& other);

	virtual tstring& GetPositionType() const;
	virtual EuropeanOption& GetOption() const;
	virtual double GetValue() const;
	double GetInstrinsicValue() const;
	double GetTimeValue() const;
	virtual double GetPayoff() const;
	virtual double GetPremium() const;
	virtual int GetNumContract() const;
	virtual int GetPositionNumber() const;
	virtual void SetPositionNumber(int positionNumber);
	virtual double GetReturnExit() const;

private:
	tstring positionType; // "long"

	EuropeanOption option;
	double value;		// 프리미엄 차감한 value이다
	double instrinsicValue;
	double timeValue;
	double payoff; // at maturity
	double premium;
	int numContract;
	int positionNumber;
	double returnExit;
};

inline tstring& LongPosition::GetPositionType() const{
	return const_cast<tstring&>(this->positionType);
}



inline EuropeanOption& LongPosition::GetOption() const{
	return const_cast<EuropeanOption&>(this->option);
}


inline double LongPosition::GetValue() const{
	return this->value;
}

inline double LongPosition::GetInstrinsicValue() const{
	return this->instrinsicValue;
}
inline double LongPosition::GetTimeValue() const{
	return this->timeValue;
}


inline double LongPosition::GetPayoff() const{
	return this->payoff;
}

inline double LongPosition::GetPremium() const{
	return this->premium;
}


inline int LongPosition::GetNumContract() const{
	return this->numContract;
}


inline int LongPosition::GetPositionNumber() const{
	return this->positionNumber;
}


inline void LongPosition::SetPositionNumber(int positionNumber){
	this->positionNumber = positionNumber;
}


inline double LongPosition::GetReturnExit() const{
	return this->returnExit;
}