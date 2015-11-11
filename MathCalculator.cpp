// MathCalculator.cpp

#include <cmath>
#include "MathCalculator.h"



MathCalculator::MathCalculator(){
}


MathCalculator::~MathCalculator(){
}


double MathCalculator::Round(double value, int upToNthDigits){
	return (floor(value*pow(float(10), upToNthDigits))/pow(float(10), upToNthDigits));
}