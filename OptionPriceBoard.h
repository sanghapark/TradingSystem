// OptionPriceBoard.h

#pragma once

#include "OptionInfoList.h"
#include "OptionParameter.h"

class OptionPriceBoard{
	public:
		OptionPriceBoard();
		OptionPriceBoard(const OptionInfoList& callOptions, const OptionInfoList& putOptions);
		OptionPriceBoard(const OptionPriceBoard& source);
		~OptionPriceBoard();

		void Valuate(double underlyingAssetPrice, double expiryRatio, double riskFreeRate, double histVol);
		void Clear();
		OptionParameter GetOptionParameterByOptionCode(const tstring& optionCode);


		bool IsEqual(const OptionPriceBoard& other);
		bool IsNotEqual(const OptionPriceBoard& other);

		OptionPriceBoard& operator=(const OptionPriceBoard& source);
		bool operator==(const OptionPriceBoard& other);
		bool operator!=(const OptionPriceBoard& other);

		OptionInfoList& GetCallOptions() const;
		OptionInfoList& GetPutOptions() const;

		int GetNumStrikePrices() const;
		void SetNumStrikePrices(int numStrikePrices );

		double* GetStrikePricesATM() const;
		int GetCountATM() const;

	private:
		int numStrikePrices;
		OptionInfoList callOptions;
		OptionInfoList putOptions;


		// 둥가격 행사가 저장
		double* strikePricesATM;
		int countATM;

};


inline OptionInfoList& OptionPriceBoard::GetCallOptions() const{
	return const_cast<OptionInfoList&>(this->callOptions);
}
inline OptionInfoList& OptionPriceBoard::GetPutOptions() const{
	return const_cast<OptionInfoList&>(this->putOptions);
}



inline int OptionPriceBoard::GetNumStrikePrices() const{
	return this->numStrikePrices;
}
inline void OptionPriceBoard::SetNumStrikePrices(int numStrikePrices ){
	this->numStrikePrices = numStrikePrices;
}

inline double* OptionPriceBoard::GetStrikePricesATM() const{
	return this->strikePricesATM;
}

inline int OptionPriceBoard::GetCountATM() const{
	return this->countATM;
}
