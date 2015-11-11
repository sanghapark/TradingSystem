// ShortPosition.h

#pragma once

#include <string>
#include "Position.h"
#include "EuropeanOption.h"
#include "OptionParameter.h"

using namespace std;



class ShortPosition : public Position{
public:
	ShortPosition();
	ShortPosition(const ShortPosition& source);
	ShortPosition(const EuropeanOption& option, double premium, int numContract);
	~ShortPosition();

	void Valuate(const OptionParameter& parameter);

	bool IsEqual(const ShortPosition& other);
	bool IsNotEqual(const ShortPosition& other);

	ShortPosition& operator=(const ShortPosition& source);
	bool operator==(const ShortPosition& other);
	bool operator!=(const ShortPosition& other);

	virtual tstring& GetPositionType() const;
	virtual EuropeanOption& GetOption() const;
	virtual double GetValue() const;
	virtual double GetPayoff() const;
	virtual double GetPremium() const;
	virtual int GetNumContract() const;
	virtual int GetPositionNumber() const;
	virtual void SetPositionNumber(int positionNumber);
	virtual double GetReturnExit() const;
private:
	tstring positionType; // "short"
	
	EuropeanOption  option;
	double value;
	double payoff;
	double premium;
	int numContract;
	int positionNumber;
	double returnExit;
};



inline tstring& ShortPosition::GetPositionType() const{
	return const_cast<tstring&>(this->positionType);
}


inline EuropeanOption& ShortPosition::GetOption() const{
	return const_cast<EuropeanOption&>(this->option);
}


inline double ShortPosition::GetValue() const{
	return  this->value;
}


inline double ShortPosition::GetPayoff() const{
	return this->payoff;
}

inline double ShortPosition::GetPremium() const{
	return this->premium;
}

inline int ShortPosition::GetNumContract() const{
	return this->numContract;
}

inline int ShortPosition::GetPositionNumber() const{
	return this->positionNumber;
}


inline void ShortPosition::SetPositionNumber(int positionNumber){
	this->positionNumber = positionNumber;
}



inline double ShortPosition::GetReturnExit() const{
	return this->returnExit;
}