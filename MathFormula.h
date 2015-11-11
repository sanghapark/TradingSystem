// MathFormula.h


#include <cmath>

#define PI 3.141592653589793238462643

class MathFormula{

public:
	static double CNDF(double x);

	// 등가격 구할때 사용
	static double* GetPriceAtTheMoney(double number, double increment, int* count);

};