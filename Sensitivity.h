// Sensitivity.h

#pragma once

class Sensitivity{

	public:
		Sensitivity();
		Sensitivity(double delta, double gamma, double vega, double theta, double rho);
		Sensitivity(const Sensitivity& source);
		~Sensitivity();

		bool IsEqual(const Sensitivity& other);
		bool IsNotEqual(const Sensitivity& other);

		Sensitivity& operator=(const Sensitivity& source);
		bool operator==(const Sensitivity& other);
		bool operator!=(const Sensitivity& other);

		double GetDelta() const;
		double GetGamma() const;
		double GetVega() const;
		double GetTheta() const;
		double GetRho() const;

	private:
		double delta;
		double gamma;
		double vega;
		double theta;
		double rho;
};

inline double Sensitivity::GetDelta() const{
	return this->delta;
}
inline double Sensitivity::GetGamma() const{
	return this->gamma;
}
inline double Sensitivity::GetVega() const{
	return this->vega;
}
inline double Sensitivity::GetTheta() const{
	return this->theta;
}
inline double Sensitivity::GetRho() const{
	return this->rho;
}