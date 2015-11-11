// ExpiryCalculator.cpp

#include <tchar.h>
#include <ctime>
#include "ExpiryCalculator.h"
#include "DataConverter.h"

ExpiryCalculator::ExpiryCalculator(){
}

// 주어진 년월을 받아와서 해당월 옵션기간 생성
ExpiryCalculator::ExpiryCalculator(const tstring& expiryDate_yyyyMM)
	:marketOpenTime(_T("090000")),
	marketCloseTime(_T("130500")),
	marketCloseTimeOnExpiry(_T("145000")){

	tstring tstrYear = expiryDate_yyyyMM.substr(0,4);
	tstring tstrMonth = expiryDate_yyyyMM.substr(4,2);


	int year = DataConverter::ConvertStringToInt(tstrYear);
	QuantLib::Month month = (QuantLib::Month)DataConverter::ConvertStringToInt(tstrMonth);
	int day = 1;


	QuantLib::Date date(day, month, year);

	QuantLib::Date expiryDate = QuantLib::Date::nthWeekday(2, QuantLib::Thursday, month, year);
	QuantLib::Period period(1, QuantLib::Months);
	QuantLib::Date issueDate = expiryDate - period;
	issueDate = QuantLib::Date::nthWeekday(2, QuantLib::Friday, issueDate.month(), issueDate.year());

	this->issueDate = this->ConvertDateToYYYYMMDD(issueDate);
	this->expiryDate = this->ConvertDateToYYYYMMDD(expiryDate);
}


/*
현재 시간을 받아와서 클래스 생성
ExpiryCalculator::ExpiryCalculator(const tstring& currentDateTime)
	:marketOpenTime(_T("090000")),
	marketCloseTime(_T("130500")),
	marketCloseTimeOnExpiry(_T("145000")){

	tstring date = currentDateTime.substr(0,8);
	tstring time = currentDateTime.substr(8,6);



	int year = DataConverter::ConvertStringToInt(date.substr(0,4));
	QuantLib::Month month = (QuantLib::Month)DataConverter::ConvertStringToInt(date.substr(4,2));;
	int day = DataConverter::ConvertStringToInt(date.substr(6,2));;

	QuantLib::Date currentDate = QuantLib::Date(day, month, year);

	QuantLib::Date issueDate = QuantLib::Date::nthWeekday(2, QuantLib::Friday, month, year);

	QuantLib::Period period(1, QuantLib::Months);


	QuantLib::Date expiryDate = issueDate + period;
	expiryDate = QuantLib::Date::nthWeekday(2, QuantLib::Thursday, expiryDate.month(), expiryDate.year());


	int intTime = DataConverter::ConvertStringToInt(time);
	int intMarketCloseTimeOnExpiry = DataConverter::ConvertStringToInt(this->marketCloseTimeOnExpiry);


	QuantLib::Date preIssueDate = issueDate - period;
	preIssueDate = QuantLib::Date::nthWeekday(2, QuantLib::Friday, preIssueDate.month(), preIssueDate.year());
	QuantLib::Date preExpiryDate = expiryDate - period;
	preExpiryDate = QuantLib::Date::nthWeekday(2, QuantLib::Thursday, preExpiryDate.month(), preExpiryDate.year());

	tstring tstrPreExpiryDateTime = this->ConvertDateToYYYYMMDD(preExpiryDate).append(this->marketCloseTimeOnExpiry);

	int condition = this->CompareTimes(currentDateTime, tstrPreExpiryDateTime);


	if(condition<0){
		issueDate = preIssueDate;
		expiryDate = preExpiryDate;
	}

	QuantLib :: Calendar myCal = QuantLib::SouthKorea(); 

	bool businessDay = false;
	while(businessDay==false){
		businessDay = myCal.isBusinessDay(issueDate);
		if(businessDay == false){
			issueDate++;
		}
		else{
			businessDay==true;
		}
	}
	this->issueDate = this->ConvertDateToYYYYMMDD(issueDate);

	businessDay = false;
	while(businessDay==false){
		businessDay = myCal.isBusinessDay(expiryDate);
		if(businessDay == false){
			expiryDate--;
		}
		else{
			businessDay==true;
		}
	}
	this->expiryDate = this->ConvertDateToYYYYMMDD(expiryDate);

	this->secondsFromIssueToExpiry = this->CountLeftBusinessPeriodInSeconds(this->issueDate.append(this->marketOpenTime));

}
*/


ExpiryCalculator::ExpiryCalculator(const tstring& issueDate, const tstring& expiryDate, const tstring& marketOpenTime, const tstring& marketCloseTime, const tstring& marketCloseTimeOnExpiry)
	:issueDate(issueDate),
	expiryDate(expiryDate),
	marketOpenTime(marketOpenTime),
	marketCloseTime(marketCloseTime),
	marketCloseTimeOnExpiry(marketCloseTimeOnExpiry){
		tstring startDateTime(this->issueDate.append(this->marketOpenTime));
		this->secondsFromIssueToExpiry = this->CountLeftBusinessPeriodInSeconds(startDateTime);
}


ExpiryCalculator::ExpiryCalculator(const ExpiryCalculator& source)
	:issueDate(source.issueDate),
	expiryDate(source.expiryDate),
	marketOpenTime(source.marketOpenTime),
	marketCloseTime(source.marketCloseTime),
	marketCloseTimeOnExpiry(source.marketCloseTimeOnExpiry){
		this->secondsFromIssueToExpiry = source.secondsFromIssueToExpiry;
}


ExpiryCalculator::~ExpiryCalculator(){
}


double ExpiryCalculator::GetExpirationRatio(const tstring& dateTime){
	double ret = 0.0;

	bool validDateTime = this->CheckDateTimeBeforeExpiry(dateTime);
	if(validDateTime==true){
		double numerator = (double)this->CountLeftBusinessPeriodInSeconds(dateTime);

		tstring startDateTime(this->issueDate.append(this->marketOpenTime));


		//this->secondsFromIssueToExpiry = this->CountLeftBusinessPeriodInSeconds(startDateTime);
		//double denominator = (double)this->secondsFromIssueToExpiry;
		double denominator = 31536000.0;

		ret = numerator/denominator;
	}


	return ret;
}


int ExpiryCalculator::CountLeftBusinessPeriodInSeconds(const tstring& dateTime){
	int ret= -1;

	tstring resetDateTime = this->ResetStartDateTime(dateTime);

	int countBusinessDays = this->CountLeftBusinessDays(resetDateTime, false, false);

	tstring date = dateTime.substr(0,8);
	if(date.compare(this->expiryDate)==0){
		countBusinessDays--;
	}

	int secondsTodayToClose = this->CalSecondsUntilTodayMarketClose(resetDateTime);
	if(countBusinessDays>0){
		ret = secondsTodayToClose + countBusinessDays*(60*60*6+60*5) + (60*60*5+60*50);
	}
	else if(countBusinessDays==0){
		ret = secondsTodayToClose + (60*60*5+60*50);
	}
	else if(countBusinessDays==-1){
		ret = secondsTodayToClose;
	}

	return ret;
}

bool ExpiryCalculator::IsEqual(const ExpiryCalculator& other){
	bool ret = false;

	if(this->issueDate.compare(other.issueDate)==0 &&
		this->expiryDate.compare(other.expiryDate)==0 &&
		this->marketOpenTime.compare(other.marketOpenTime)==0 &&
		this->marketCloseTime.compare(other.marketCloseTime)==0 &&
		this->marketCloseTimeOnExpiry.compare(other.marketCloseTimeOnExpiry)==0 &&
		this->secondsFromIssueToExpiry == other.secondsFromIssueToExpiry){
			ret = true;
	}

	return ret;
}


bool ExpiryCalculator::IsNotEqual(const ExpiryCalculator& other){
	bool ret = false;

	if(this->issueDate.compare(other.issueDate)!=0 ||
		this->expiryDate.compare(other.expiryDate)!=0 ||
		this->marketOpenTime.compare(other.marketOpenTime)!=0 ||
		this->marketCloseTime.compare(other.marketCloseTime)!=0 ||
		this->marketCloseTimeOnExpiry.compare(other.marketCloseTimeOnExpiry)!=0 ||
		this->secondsFromIssueToExpiry != other.secondsFromIssueToExpiry){
			ret = true;
	}

	return ret;
}

ExpiryCalculator& ExpiryCalculator::operator=(const ExpiryCalculator& source){
	this->issueDate = source.issueDate;
	this->expiryDate = source.expiryDate;
	this->marketOpenTime = source.marketOpenTime;
	this->marketCloseTime = source.marketCloseTime;
	this->marketCloseTimeOnExpiry = source.marketCloseTimeOnExpiry;
	this->secondsFromIssueToExpiry = source.secondsFromIssueToExpiry;
	return *this;
}


bool ExpiryCalculator::operator==(const ExpiryCalculator& other){
	bool ret = false;
	if(this->issueDate==other.issueDate &&
		this->expiryDate==other.expiryDate &&
		this->marketOpenTime==other.marketOpenTime &&
		this->marketCloseTime==other.marketCloseTime &&
		this->marketCloseTimeOnExpiry==other.marketCloseTime &&
		this->secondsFromIssueToExpiry == other.secondsFromIssueToExpiry){
			ret = true;
	}
	return ret;
}


bool ExpiryCalculator::operator!=(const ExpiryCalculator& other){
	bool ret = false;
	if(this->issueDate!=other.issueDate ||
		this->expiryDate!=other.expiryDate ||
		this->marketOpenTime!=other.marketOpenTime ||
		this->marketCloseTime!=other.marketCloseTime ||
		this->marketCloseTimeOnExpiry!=other.marketCloseTime ||
		this->secondsFromIssueToExpiry != other.secondsFromIssueToExpiry){
			ret = true;
	}
	return ret;
}



int ExpiryCalculator::CountLeftBusinessDays(const tstring& dateTime, bool includeStartDate, bool includeExpiryDate){

	int count = -1;

	int startYear = DataConverter::ConvertStringToInt(dateTime.substr(0,4));
	QuantLib::Month startMonth = (QuantLib::Month)DataConverter::ConvertStringToInt(dateTime.substr(4,2));;
	int startDay = DataConverter::ConvertStringToInt(dateTime.substr(6,2));;

	int endYear = DataConverter::ConvertStringToInt(this->expiryDate.substr(0,4));;
	QuantLib::Month endMonth = (QuantLib::Month)DataConverter::ConvertStringToInt(this->expiryDate.substr(4,2));;
	int endDay = DataConverter::ConvertStringToInt(this->expiryDate.substr(6,2));;


	QuantLib :: Calendar myCal = QuantLib::SouthKorea(); 
	QuantLib :: Date date1 (startDay , startMonth , startYear);
	QuantLib :: Date date2 (endDay , endMonth , endYear);
	count = myCal.businessDaysBetween(date1, date2, includeStartDate, includeExpiryDate);

	return count;
}


tstring ExpiryCalculator::ResetStartDateTime(const tstring& startDateTime){
	tstring ret = startDateTime;

	int startYear = DataConverter::ConvertStringToInt(startDateTime.substr(0,4));
	QuantLib::Month startMonth = (QuantLib::Month)DataConverter::ConvertStringToInt(startDateTime.substr(4,2));;
	int startDay = DataConverter::ConvertStringToInt(startDateTime.substr(6,2));;

	QuantLib :: Date date(startDay , startMonth , startYear);

	QuantLib :: Calendar myCal = QuantLib::SouthKorea(); 
	while(myCal.isBusinessDay(date)==false){
		date++;
		ret = this->ConvertDateToYYYYMMDD(date).append(this->marketOpenTime);
	}

	int check = this->CheckIfMarketTime(ret);
	if(check==1){

		int startYear = DataConverter::ConvertStringToInt(ret.substr(0,4));
		QuantLib::Month startMonth = (QuantLib::Month)DataConverter::ConvertStringToInt(ret.substr(4,2));;
		int startDay = DataConverter::ConvertStringToInt(ret.substr(6,2));;

		QuantLib :: Date date(startDay , startMonth , startYear);
		date++;

		QuantLib :: Calendar myCal = QuantLib::SouthKorea(); 
		bool businessDay = myCal.isBusinessDay(date);
		while(businessDay!=true){
			if(businessDay!=true){
				date++;
			}
			businessDay = myCal.isBusinessDay(date);
		}

		ret = this->ConvertDateToYYYYMMDD(date);
		ret.append(this->marketOpenTime);

	}
	else if(check==-1){
		ret = ret.substr(0,8).append(this->marketOpenTime);
	}
	else if(check == 0){

	}

	return ret;
}


int ExpiryCalculator::CalSecondsUntilTodayMarketClose(const tstring& dateTime){
	tstring date = dateTime.substr(0,8);
	tstring sTime = dateTime.substr(8,6);
	tstring eTime;
	if(date.compare(this->expiryDate)!=0){
		eTime = this->marketCloseTime;
	}
	else{
		eTime = this->marketCloseTimeOnExpiry;
	}

	time_t tm_st;
	time_t tm_end;

	struct tm startTime;
	struct tm endTime;

	// yyyyMMddHHmmss
	startTime.tm_year = DataConverter::ConvertStringToInt(date.substr(0,4)) - 1900;
	startTime.tm_mon = DataConverter::ConvertStringToInt(date.substr(4,2)) - 1;
	startTime.tm_mday = DataConverter::ConvertStringToInt(date.substr(6,2));
	startTime.tm_hour = DataConverter::ConvertStringToInt(sTime.substr(0,2));
	startTime.tm_min = DataConverter::ConvertStringToInt(sTime.substr(2,2));
	startTime.tm_sec = DataConverter::ConvertStringToInt(sTime.substr(4,2));
	startTime.tm_isdst = 0; //썸머 타임 사용 안함

	endTime.tm_year = DataConverter::ConvertStringToInt(date.substr(0,4)) - 1900;
	endTime.tm_mon = DataConverter::ConvertStringToInt(date.substr(4,2)) - 1;
	endTime.tm_mday = DataConverter::ConvertStringToInt(date.substr(6,2));
	endTime.tm_hour = DataConverter::ConvertStringToInt(eTime.substr(0,2));
	endTime.tm_min = DataConverter::ConvertStringToInt(eTime.substr(2,2));
	endTime.tm_sec = DataConverter::ConvertStringToInt(eTime.substr(4,2));
	endTime.tm_isdst = 0; //썸머 타임 사용 안함

	tm_st = mktime(&startTime);
	tm_end = mktime(&endTime);

	int countSeconds = difftime(tm_end, tm_st);

	return countSeconds;
}


int ExpiryCalculator::CheckIfMarketTime(const tstring& dateTime){	// -1 before market, 0 at market, 1 after market
	int ret = 0;

	tstring date = dateTime.substr(0,8);
	tstring time = dateTime.substr(8,6);

	int intTime =  DataConverter::ConvertStringToInt(time);
	int intOpenTime = DataConverter::ConvertStringToInt(this->marketOpenTime);
	int intCloseTime = 0;
	if(date.compare(this->expiryDate)!=0){
		intCloseTime = DataConverter::ConvertStringToInt(this->marketCloseTime);
	}
	else{
		intCloseTime = DataConverter::ConvertStringToInt(this->marketCloseTimeOnExpiry);
	}

	if(intTime<intOpenTime && intTime<intCloseTime){
		ret = -1;
	}
	else if(intTime>=intOpenTime && intTime <=intCloseTime){
		ret = 0;
	}
	else if(intTime>intOpenTime && intTime>intCloseTime){
		ret = 1;
	}

	return ret;
}

tstring ExpiryCalculator::ConvertDateToYYYYMMDD(QuantLib::Date& date){
	tstring ret;

	tstringstream tssYear;
	tstringstream tssMonth;
	tstringstream tssDay;

	tstring strYear;
	tstring strMonth;
	tstring strDay;
	int year = date.year();
	int month = date.month();
	int day = date.dayOfMonth();


	tssYear << setw(4) << setfill(_T('0')) << year;
	strYear = tssYear.str();

	tssMonth << setw(2) << setfill(_T('0')) << month;
	strMonth = tssMonth.str();

	tssDay << setw(2) << setfill(_T('0')) << day;
	strDay = tssDay.str();


	ret = strYear.append(strMonth).append(strDay);

	return ret;
}


bool ExpiryCalculator::CheckDateTimeBeforeExpiry(const tstring& dateTime){
	bool ret = false;

	int intDate = DataConverter::ConvertStringToInt(dateTime.substr(0,8));
	int intTime = DataConverter::ConvertStringToInt(dateTime.substr(8,6));

	int intExpiryDate = DataConverter::ConvertStringToInt(this->expiryDate);
	int intMaketCloseTime = DataConverter::ConvertStringToInt(this->marketCloseTime);
	int intMarketCloseTimeOnExpiry = DataConverter::ConvertStringToInt(this->marketCloseTimeOnExpiry);



	if(intDate==intExpiryDate){
		if(intTime<=intMarketCloseTimeOnExpiry){
			ret = true;
		}
	}
	else if(intDate<intExpiryDate){
		ret  = true;
	}


	return ret;
}



int ExpiryCalculator::CompareTimes(const tstring& time, const tstring& other){

	time_t tm_time;
	time_t tm_other;

	struct tm stmTime;
	struct tm stmOther;

	// yyyyMMddHHmmss
	stmTime.tm_year = DataConverter::ConvertStringToInt(time.substr(0,4)) - 1900;
	stmTime.tm_mon = DataConverter::ConvertStringToInt(time.substr(4,2)) - 1;
	stmTime.tm_mday = DataConverter::ConvertStringToInt(time.substr(6,2));
	stmTime.tm_hour = DataConverter::ConvertStringToInt(time.substr(8,2));
	stmTime.tm_min = DataConverter::ConvertStringToInt(time.substr(10,2));
	stmTime.tm_sec = DataConverter::ConvertStringToInt(time.substr(12,2));
	stmTime.tm_isdst = 0; //썸머 타임 사용 안함

	stmOther.tm_year = DataConverter::ConvertStringToInt(other.substr(0,4)) - 1900;
	stmOther.tm_mon = DataConverter::ConvertStringToInt(other.substr(4,2)) - 1;
	stmOther.tm_mday = DataConverter::ConvertStringToInt(other.substr(6,2));
	stmOther.tm_hour = DataConverter::ConvertStringToInt(other.substr(8,2));
	stmOther.tm_min = DataConverter::ConvertStringToInt(other.substr(10,2));
	stmOther.tm_sec = DataConverter::ConvertStringToInt(other.substr(12,2));
	stmOther.tm_isdst = 0; //썸머 타임 사용 안함

	tm_time = mktime(&stmTime);
	tm_other = mktime(&stmOther);

	return difftime(tm_time, tm_other) > 0.0 ? 1 : -1;
}



void ExpiryCalculator::ResetOptionLifePeriod(const tstring& currentDateTime){
	tstring date = currentDateTime.substr(0,8);
	tstring time = currentDateTime.substr(8,6);

	this->marketOpenTime.assign(_T("090000"));
	this->marketCloseTime.assign(_T("130500"));
	this->marketCloseTimeOnExpiry.assign(_T("145000"));


	int year = DataConverter::ConvertStringToInt(date.substr(0,4));
	QuantLib::Month month = (QuantLib::Month)DataConverter::ConvertStringToInt(date.substr(4,2));;
	int day = DataConverter::ConvertStringToInt(date.substr(6,2));;

	QuantLib::Date currentDate = QuantLib::Date(day, month, year);

	QuantLib::Date issueDate = QuantLib::Date::nthWeekday(2, QuantLib::Friday, month, year);

	QuantLib::Period period(1, QuantLib::Months);


	QuantLib::Date expiryDate = issueDate + period;
	expiryDate = QuantLib::Date::nthWeekday(2, QuantLib::Thursday, expiryDate.month(), expiryDate.year());


	int intTime = DataConverter::ConvertStringToInt(time);
	int intMarketCloseTimeOnExpiry = DataConverter::ConvertStringToInt(this->marketCloseTimeOnExpiry);


	QuantLib::Date preIssueDate = issueDate - period;
	preIssueDate = QuantLib::Date::nthWeekday(2, QuantLib::Friday, preIssueDate.month(), preIssueDate.year());
	QuantLib::Date preExpiryDate = expiryDate - period;
	preExpiryDate = QuantLib::Date::nthWeekday(2, QuantLib::Thursday, preExpiryDate.month(), preExpiryDate.year());

	tstring tstrPreExpiryDateTime = this->ConvertDateToYYYYMMDD(preExpiryDate).append(this->marketCloseTimeOnExpiry);

	int condition = this->CompareTimes(currentDateTime, tstrPreExpiryDateTime);


	if(condition<0){
		issueDate = preIssueDate;
		expiryDate = preExpiryDate;
	}

	QuantLib :: Calendar myCal = QuantLib::SouthKorea(); 

	bool businessDay = false;
	while(businessDay==false){
		businessDay = myCal.isBusinessDay(issueDate);
		if(businessDay == false){
			issueDate++;
		}
		else{
			businessDay=true;
		}
	}
	this->issueDate = this->ConvertDateToYYYYMMDD(issueDate);

	businessDay = false;
	while(businessDay==false){
		businessDay = myCal.isBusinessDay(expiryDate);
		if(businessDay == false){
			expiryDate--;
		}
		else{
			businessDay=true;
		}
	}
	this->expiryDate = this->ConvertDateToYYYYMMDD(expiryDate);

	this->secondsFromIssueToExpiry = this->CountLeftBusinessPeriodInSeconds(this->issueDate.append(this->marketOpenTime));
}