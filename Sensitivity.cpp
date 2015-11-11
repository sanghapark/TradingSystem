// Sensitivity.cpp

#include "Sensitivity.h"



Sensitivity::Sensitivity(){
	this->delta = 0.0;
	this->gamma = 0.0;
	this->vega = 0.0;
	this->theta = 0.0;
	this->rho = 0.0;
}


Sensitivity::Sensitivity(double delta, double gamma, double vega, double theta, double rho){
	this->delta = delta;
	this->gamma = gamma;
	this->vega = vega;
	this->theta = theta;
	this->rho = rho;
}

Sensitivity::Sensitivity(const Sensitivity& source){
	this->delta = source.delta;
	this->gamma = source.gamma;
	this->vega = source.vega;
	this->theta = source.theta;
	this->rho = source.rho;
}


Sensitivity::~Sensitivity(){
}


bool Sensitivity::IsEqual(const Sensitivity& other){
	bool ret = false;
	if(this->delta == other.delta &&
		this->gamma == other.gamma &&
		this->vega == other.vega &&
		this->theta == other.theta &&
		this->rho == other.rho){
			ret = true;
	}
	return ret;
}


bool Sensitivity::IsNotEqual(const Sensitivity& other){
	bool ret = false;
	if(this->delta != other.delta ||
		this->gamma != other.gamma ||
		this->vega != other.vega ||
		this->theta != other.theta ||
		this->rho != other.rho){
			ret = true;
	}
	return ret;
}



Sensitivity& Sensitivity::operator=(const Sensitivity& source){
	this->delta = source.delta;
	this->gamma = source.gamma;
	this->vega = source.vega;
	this->theta = source.theta;
	this->rho = source.rho;
	return *this;
}


bool Sensitivity::operator==(const Sensitivity& other){
	bool ret = false;
	if(this->delta == other.delta &&
		this->gamma == other.gamma &&
		this->vega == other.vega &&
		this->theta == other.theta &&
		this->rho == other.rho){
			ret = true;
	}
	return ret;
}


bool Sensitivity::operator!=(const Sensitivity& other){
	bool ret = false;
	if(this->delta != other.delta ||
		this->gamma != other.gamma ||
		this->vega != other.vega ||
		this->theta != other.theta ||
		this->rho != other.rho){
			ret = true;
	}
	return ret;
}