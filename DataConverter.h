// DataConverter.h

#ifndef _DATA_CONVERTER_H
#define _DATA_CONVERTER_H

#include "DataTypeDefinition.h"

using namespace std;

class DataConverter{
	public:
		DataConverter();
		~DataConverter();

		static int ConvertStringToInt(const tstring& str);
		static tstring ConvertIntToString(int integer);
		static double ConvertStringToDouble(const tstring& str);
		static tstring ConvertDoubleToString(double real);
		static bool ConvertIntToBool(int yn);
		static int ConvertBoolToInt(bool yn);
		static bool ConvertStringToBool(const tstring& yn);
		static tstring ConvertBoolToString(bool yn);
		static int ConvertDoubleToInt(double value);


		static bool CheckIfNumber(const tstring& str);


		static tstring& TrimFromStart(tstring& str);
		static tstring& TrimFromEnd(tstring& str);
		static tstring& TrimFromStartAndEnd(tstring& str);
};

#endif