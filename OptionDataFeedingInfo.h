// OptionDataFeedingInfo.h
#ifndef _OPTION_DATA_FEEDING_INFO_H
#define _OPTION_DATA_FEEDING_INFO_H

#include "DataFeedingInfo.h"


class OptionDataFeedingInfo{
	public:
		OptionDataFeedingInfo();
		OptionDataFeedingInfo(const OptionDataFeedingInfo& source);
		OptionDataFeedingInfo();

	private:
		DataFeedingInfo dataFeedingInfo;
		string maturityMonth;
		string underlyingAsset;
		string optionType;
};




#endif