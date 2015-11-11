// DataConverter.cpp
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "DataConverter.h"
#include "Constants.h"


DataConverter::DataConverter(){}
DataConverter::~DataConverter(){}

int DataConverter::ConvertStringToInt(const tstring& str){
	int ret;
	tstringstream ss(str);
	ss >> ret;
	return ret;
}


double DataConverter::ConvertStringToDouble(const tstring& str){
	double ret;
	tstringstream ss(str);
	ss >> ret;
	return ret;
}

tstring DataConverter::ConvertIntToString(int integer){
	tstringstream ss;
	ss << integer;
	return ss.str();
}

tstring DataConverter::ConvertDoubleToString(double real){
	tstringstream ss;
	ss << real;
	return ss.str();
}

bool DataConverter::ConvertIntToBool(int yn){
	bool ret = false;
	if (yn != 0){
		ret = true;
	}
	return ret;
}

int DataConverter::ConvertBoolToInt(bool yn){
	int ret = 0;
	if (yn == true){
		yn = 1;
	}
	return ret;
}

bool DataConverter::ConvertStringToBool(const tstring& yn){
	bool ret = false;
	if(yn.compare(_T("true"))==0){
		ret = true;
	}
	return ret;
}

tstring DataConverter::ConvertBoolToString(bool yn){
	tstring ret(_T("false"));
	if(yn==true){
		ret = _T("true");
	}
	return ret;
}

int DataConverter::ConvertDoubleToInt(double value){
	double dx = value < 0.0 ? -0.5 : 0.5;
	return static_cast<int>(value + dx);
}



bool DataConverter::CheckIfNumber(const tstring& str){
	bool ret = true;

	double ff;
	tistringstream istr;

	// set the stream to have your string as its base
	istr.str(str);

	// now try to read the number:
	istr >> ff;
	if (istr.fail())
	{
		ret =false;
	}
	return ret;
}



tstring& DataConverter::TrimFromStart(tstring& str){
	str.erase(str.begin(), find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(std::isspace))));
	return str;
}



tstring& DataConverter::TrimFromEnd(tstring& str){
	str.erase(find_if(str.rbegin(), str.rend(), not1(ptr_fun<int, int>(isspace))).base(), str.end());
	return str;
}



tstring& DataConverter::TrimFromStartAndEnd(tstring& str){
	return TrimFromStart(TrimFromEnd(str));
}