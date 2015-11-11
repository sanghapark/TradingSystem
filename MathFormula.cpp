// MathFormula.cpp

#include "MathFormula.h"
#include "DataTypeDefinition.h"

double MathFormula::CNDF(double x){
	double ret = 0.0;

	double absX=.0, k=.0, ReVal=.0;
	double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
	double const a4 = -1.821255978, a5 = 1.330274429;

	absX = fabs(x);
	k = 1.0 / (1.0 + 0.2316419 * absX);
	ReVal = 1.0 - (exp(-absX*absX*0.5) / sqrt(2*PI))
		* (a1*k + a2*k*k + a3*k*k*k + a4*k*k*k*k + a5*k*k*k*k*k);

	if(x < 0 )   ret =  1.0 - ReVal;
	else    ret = ReVal;

	return ret;
}


double* MathFormula::GetPriceAtTheMoney(double number, double increment, int* count){
	
	double* ret = 0;
	double sum = 0.0;

	while(sum < number){
		sum += increment;
	}

	if(number!=sum){
		double upperBoundary = sum;
		double lowerBoundary = sum - increment;

		double absUpper = abs(upperBoundary - number);
		double absLower = abs(lowerBoundary - number);

		if(absUpper > absLower){
			*count = 1;
			ret = new double[*count];
			ret[0] = lowerBoundary;
		}
		else if(absUpper < absLower){
			*count = 1;
			ret = new double[*count];
			ret[0] = upperBoundary;
		}
		else{
			*count = 2;
			ret = new double[*count];
			ret[0] = upperBoundary;
			ret[1] = lowerBoundary;
		}
	}
	else{

		*count = 1;
		ret = new double[*count];
		ret[0] = sum;
	}
	return ret;
}

