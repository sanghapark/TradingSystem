// InstrumentCodeMaker.cpp

#include "InstrumentCodeMaker.h"
#include "DataConverter.h"
#include <atltime.h>


InstrumentCodeMaker::InstrumentCodeMaker(){
}


InstrumentCodeMaker::InstrumentCodeMaker(const InstrumentCodeMaker& source)
	:kospi200IndexFuturesCode(source.kospi200IndexFuturesCode){
}


InstrumentCodeMaker::~InstrumentCodeMaker(){
}

void InstrumentCodeMaker::InitilizeCodes(){
	this->kospi200IndexFuturesCode = this->MakeNearestKOSPI200IndexFuturesCode();
}

tstring InstrumentCodeMaker::MakeNearestKOSPI200IndexFuturesCode(){
	DataConverter dataConverter;
	tstring ret;
	CTime time  = CTime::GetCurrentTime();
	int intYear = dataConverter.ConvertStringToInt(dataConverter.ConvertIntToString(time.GetYear()).substr(2,4));
	int intMonth= time.GetMonth();
	int intDay = time.GetDay();
	int head = this->ZellersCongruence(intYear, intMonth, intDay);
	tstring year;
	tstring month;
	tstring day;
	bool thur2over = false;
	if(intDay<9){
		thur2over = false;
	}
	else if(intDay>14){
		thur2over = true;
	}
	else{
		if  (head <= 4){
			if(13 - head > intDay){
				thur2over = false;
			}
			else{                    
				thur2over = true;
			}
		}
		else{
			if(20 - head > intDay){
				thur2over = false;
			}
			else{                   
				thur2over = true;
			}
		}
	}

	switch(intMonth){
	case 1:
	case 2:
		month = TEXT("3");
		break;
	case 3:
		if  (thur2over)     month = TEXT("6");
		else                month = TEXT("3");
		break;
	case 4:
	case 5:
		month = TEXT("6");
		break;
	case 6:
		if  (thur2over)     month = TEXT("9");
		else                month = TEXT("6");
		break;
	case 7:
	case 8:
		month = TEXT("9");
		break;
	case 9:
		if  (thur2over)     month = TEXT("C");
		else                month = TEXT("9");
		break;
	case 10:
	case 11:
		month = TEXT("C");
		break;
	case 12:
		if  (thur2over)
		{
			month = TEXT("3");
			intYear = intYear+1;
		}
		else
			month = TEXT("C");
		break;
	}

	ret = TEXT("101") + this->MapYearToAlphabet(intYear) + month + TEXT("000");
	return ret;
}

int InstrumentCodeMaker::ZellersCongruence(int yy, int mm, int dd){
	if  (mm < 3){
		--yy;
		mm += 12;
	}
	return (105 + 5*yy/4 + 26*(mm+1)/10 + dd-1) % 7;
}

tstring InstrumentCodeMaker::MapYearToAlphabet(int year){
	tstring yearAlphabet;
	switch(year){
	case 14:
		yearAlphabet = TEXT("J");
		break;
	case 15:
		yearAlphabet = TEXT("K");
		break;
	case 16:
		yearAlphabet = TEXT("L");
		break;
	case 17:
		yearAlphabet = TEXT("M");
		break;
	case 18:
		yearAlphabet = TEXT("N");
		break;
	case 19:
		yearAlphabet = TEXT("P");
		break;
	case 20:
		yearAlphabet = TEXT("Q");
		break;
	case 21:
		yearAlphabet = TEXT("R");
		break;
	case 22:
		yearAlphabet = TEXT("S");
		break;
	case 23:
		yearAlphabet = TEXT("T");
		break;
	case 24:
		yearAlphabet = TEXT("V");
		break;
	case 25:
		yearAlphabet = TEXT("W");
		break;
	}
	return yearAlphabet;
}



bool InstrumentCodeMaker::IsEqual(const InstrumentCodeMaker& other){
	bool ret = false;
	if(this->kospi200IndexFuturesCode.compare(other.kospi200IndexFuturesCode)==0){
		ret = true;
	}
	return ret;
}


bool InstrumentCodeMaker::IsNotEqual(const InstrumentCodeMaker& other){
	bool ret = false;
	if(this->kospi200IndexFuturesCode.compare(other.kospi200IndexFuturesCode)!=0){
		ret = true;
	}
	return ret;
}

InstrumentCodeMaker& InstrumentCodeMaker::operator=(const InstrumentCodeMaker& source){
	this->kospi200IndexFuturesCode = source.kospi200IndexFuturesCode;
	return *this;
}


bool InstrumentCodeMaker::operator==(const InstrumentCodeMaker& other){
	bool ret = false;
	if(this->kospi200IndexFuturesCode==other.kospi200IndexFuturesCode){
		ret = true;
	}
	return ret;
}


bool InstrumentCodeMaker::operator!=(const InstrumentCodeMaker& other){
	bool ret = false;
	if(this->kospi200IndexFuturesCode!=other.kospi200IndexFuturesCode){
		ret = true;
	}
	return ret;
}