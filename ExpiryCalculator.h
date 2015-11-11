// ExpiryCalculator.h

#pragma once

#include <ql/quantlib.hpp>
#include "DataTypeDefinition.h"


class ExpiryCalculator{
public:
	ExpiryCalculator();
	
	ExpiryCalculator(const tstring& expiryDate_yyyyMM);

	//ExpiryCalculator(const tstring& currentDateTime); //yyyyMMddHHmmSS
	
	ExpiryCalculator(const tstring& issueDate, const tstring& expiryDate, const tstring& marketOpenTime, const tstring& marketCloseTime, const tstring& marketCloseTimeOnExpiry);
	ExpiryCalculator(const ExpiryCalculator& source);
	~ExpiryCalculator();


	double GetExpirationRatio(const tstring& dateTime);
	void ResetOptionLifePeriod(const tstring& currentDateTime);

	bool IsEqual(const ExpiryCalculator& other);
	bool IsNotEqual(const ExpiryCalculator& other);

	ExpiryCalculator& operator=(const ExpiryCalculator& source);
	bool operator==(const ExpiryCalculator& other);
	bool operator!=(const ExpiryCalculator& other);

	tstring& GetIssueDate() const;
	tstring& GetExpiryDate() const;
	tstring& GetMarketOpenTime() const;
	tstring& GetMarketCloseTime() const;
	tstring& GetMarketCloseTimeOnExpiry() const;
	int GetSecondsFromIssueToExpiry() const;

	void SetIssueDate(const tstring& issueDate);
	void SetExpiryDate(const tstring& expiryDate);
	void SetMarketOpenTime(const tstring& marketOpenTime);
	void SetMarketCloseTime(const tstring& marketCloseTime);
	void SetMarketCloseTimeOnExpiry(const tstring& marketCloseTimeOnExpiry);
	void SetSecondsFromIssueToExpiry(int seconsFromIssueToExpiry);

private:
	int CountLeftBusinessPeriodInSeconds(const tstring& dateTime);
	int CountLeftBusinessDays(const tstring& dateTime, bool includeStartDate=false, bool includeExpiryDate=false);
	tstring ResetStartDateTime(const tstring& startDateTime);
	int CalSecondsUntilTodayMarketClose(const tstring& dateTime);
	int CheckIfMarketTime(const tstring& dateTime); // -1 before market, 0 at market, 1 after market
	tstring ConvertDateToYYYYMMDD(QuantLib::Date& date);
	bool CheckDateTimeBeforeExpiry(const tstring& dateTime);
	int CompareTimes(const tstring& time, const tstring& other);

private:
	tstring issueDate; //yyyyMMdd
	tstring expiryDate;
	tstring marketOpenTime; //090000
	tstring marketCloseTime; //130500
	tstring marketCloseTimeOnExpiry; // 145000

	int secondsFromIssueToExpiry;
};




inline tstring& ExpiryCalculator::GetIssueDate() const{
	return const_cast<tstring&>(this->issueDate);
}

inline tstring& ExpiryCalculator::GetExpiryDate() const{
	return const_cast<tstring&>(this->expiryDate);
}

inline tstring& ExpiryCalculator::GetMarketOpenTime() const{
	return const_cast<tstring&>(this->marketOpenTime);
}

inline tstring& ExpiryCalculator::GetMarketCloseTime() const{
	return const_cast<tstring&>(this->marketCloseTime);
}

inline tstring& ExpiryCalculator::GetMarketCloseTimeOnExpiry() const{
	return const_cast<tstring&>(this->marketCloseTimeOnExpiry);
}

inline int ExpiryCalculator::GetSecondsFromIssueToExpiry() const{
	return this->secondsFromIssueToExpiry;
}


inline void ExpiryCalculator::SetIssueDate(const tstring& issueDate){
	this->issueDate = issueDate;
}

inline void ExpiryCalculator::SetExpiryDate(const tstring& expiryDate){
	this->expiryDate= expiryDate;
}


inline void ExpiryCalculator::SetMarketOpenTime(const tstring& marketOpenTime){
	this->marketOpenTime = marketOpenTime;
}


inline void ExpiryCalculator::SetMarketCloseTime(const tstring& marketCloseTime){
	this->marketCloseTime = marketCloseTime;
}


inline void ExpiryCalculator::SetMarketCloseTimeOnExpiry(const tstring& marketCloseTimeOnExpiry){
	this->marketCloseTimeOnExpiry = marketCloseTimeOnExpiry;
}

inline void ExpiryCalculator::SetSecondsFromIssueToExpiry(int seconsFromIssueToExpiry){
	this->secondsFromIssueToExpiry = seconsFromIssueToExpiry;
}