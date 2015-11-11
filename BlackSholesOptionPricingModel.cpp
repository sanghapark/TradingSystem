// BlackSholesOptionPricing.cpp

#include <cmath>
#include "BlackSholesOptionPricingModel.h"
#include "MathFormula.h"
#include "DataTypeDefinition.h"
#include "Constants.h"


BlackSholesOptionPricingModel::BlackSholesOptionPricingModel(){
	this->s = 0.0;
	this->k = 0.0;
	this->t = 0.0;
	this->r = 0.0;
	this->v = 0.0;
}


BlackSholesOptionPricingModel::BlackSholesOptionPricingModel(const BlackSholesOptionPricingModel& source)
	:optionType(source.optionType){
	this->s = source.s;
	this->k = source.k;
	this->t = source.t;
	this->r = source.t;
	this->v = source.v;
}


BlackSholesOptionPricingModel::~BlackSholesOptionPricingModel(){
}


void BlackSholesOptionPricingModel::SetParameters(const tstring& optionType, double strikePrice, double underlyingAssetPrice, double timeLeft, double riskFreeRate, double volatility){
	this->optionType = optionType;
	this->s = underlyingAssetPrice;
	this->k = strikePrice;
	this->t = timeLeft;
	this->r = riskFreeRate;
	this->v = volatility;
}


OptionValue BlackSholesOptionPricingModel::CalculateValue(){
	double value = 0.0;
	double intrinsicValue = 0.0;
	double timeValue = 0.0;

	// 만기전
	double d1=.0, d2=.0;

	d1 = (log(s/k) + (r + v*v*0.5)*t) / (v*sqrt(t));
	d2 = d1 - v*sqrt(t);

	if(this->optionType.compare(CALL_OPTION)==0){
		value = (s * MathFormula::CNDF(d1) - k * exp(-r*t) * MathFormula::CNDF(d2));
	}
	else{
		value = (k * exp(-r*t) * MathFormula::CNDF(-d2) - s * MathFormula::CNDF(-d1));
	}

	// 만기시 
	if(this->optionType.compare(CALL_OPTION)==0){
		intrinsicValue = max(0.0, s-k);
	}
	else{
		intrinsicValue = max(0.0, k-s);
	}

	timeValue = value - intrinsicValue;

	OptionValue optionValue(value, intrinsicValue, timeValue);


	return optionValue;
}

Sensitivity BlackSholesOptionPricingModel::CalculateSensitivity(){
	double delta = this->CalculateDelta();
	double gamma = this->CalculateGamma();
	double vega = this->CalculateVega();
	double theta = this->CalculateTheta();
	double rho = this->CalculateRho();
	Sensitivity sensitivity(delta, gamma, vega, theta, rho);
	return sensitivity;
}



bool BlackSholesOptionPricingModel::IsEqual(const BlackSholesOptionPricingModel& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)==0 &&
		this->s == other.s &&
		this->k == other.k &&
		this->t == other.t &&
		this->r == other.r &&
		this->v == other.v){
			ret = true;
	}
	return ret;
}


bool BlackSholesOptionPricingModel::IsNotEqual(const BlackSholesOptionPricingModel& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)!=0 ||
		this->s != other.s ||
		this->k != other.k ||
		this->t != other.t ||
		this->r != other.r ||
		this->v != other.v){
			ret = true;
	}
	return ret;
}


BlackSholesOptionPricingModel& BlackSholesOptionPricingModel::operator=(const BlackSholesOptionPricingModel& source){
	this->optionType = source.optionType;
	this->s = source.s;
	this->k = source.k;
	this->t = source.t;
	this->r = source.r;
	this->v = source.v;
	return *this;
}

bool BlackSholesOptionPricingModel::operator==(const BlackSholesOptionPricingModel& other){
	bool ret = false;
	if(this->optionType == other.optionType &&
		this->s == other.s &&
		this->k == other.k &&
		this->t == other.t &&
		this->r == other.r &&
		this->v == other.v){
			ret = true;
	}
	return ret;
}


bool BlackSholesOptionPricingModel::operator!=(const BlackSholesOptionPricingModel& other){
	bool ret = false;
	if(this->optionType != other.optionType ||
		this->s != other.s ||
		this->k != other.k ||
		this->t != other.t ||
		this->r != other.r ||
		this->v != other.v){
			ret = true;
	}
	return ret;
}


double BlackSholesOptionPricingModel::CalculateDelta(){
	double delta = 0.0;
	double d1=.0;

	d1 = (log(this->s/this->k) + (r + v*v*0.5)*this->t) / (v*sqrt(this->t));


	if(this->optionType.compare(CALL_OPTION)==0){
		delta  = MathFormula::CNDF(d1);
	}
	else{
		delta = MathFormula::CNDF(d1)-1.0;
	}

	return delta;
}


double BlackSholesOptionPricingModel::CalculateGamma(){
	double gamma = 0.0;

	double d1=.0;

	d1 = (log(this->s/this->k) + (r + v*v*0.5)*this->t) / (v*sqrt(this->t));

	gamma =  (exp(-d1*d1*0.5) / (this->s*v*sqrt(2*PI*this->t)));

	return gamma;
}


double BlackSholesOptionPricingModel::CalculateVega(){
	double vega = 0.0;

	double d1=.0, d2=.0;

	d1 = (log(this->s/this->k) + (r + v*v*0.5)*this->t) / (v*sqrt(this->t));
	d2 = d1 - v*sqrt(this->t);


	if(this->optionType.compare(CALL_OPTION)==0){
	    vega = ((-this->s*v*exp(-d1*d1*0.5)) / (2*sqrt(2*PI*this->t)) - r*this->k*exp(-r*t) * MathFormula::CNDF(d2));
	}
	else{
		vega = ((-s*v*exp(-d1*d1*0.5)) / (2*sqrt(2*PI*t)) + r*k*exp(-r*t) * MathFormula::CNDF(-d2));
	}

	return vega;
}


double BlackSholesOptionPricingModel::CalculateTheta(){
	double theta = 0.0;

	double d1=.0;

	d1 = (log(s/k) + (r + v*v*0.5)*t) / (v*sqrt(t));

	theta = (s * sqrt(t) * exp(-d1*d1*0.5) / sqrt(2*PI));

	return theta;
}


double BlackSholesOptionPricingModel::CalculateRho(){
	double rho = 0.0;

	double d2=.0;

	d2 = (log(s/k) + (r - v*v*0.5)*t) / (v*sqrt(t));

	if(this->optionType.compare(CALL_OPTION)==0){
		rho = (k*t*exp(-r*t) * MathFormula::CNDF(d2));
	}
	else{
		rho = (-k*t*exp(-r*t) * MathFormula::CNDF(-d2));
	}

	return rho;
}