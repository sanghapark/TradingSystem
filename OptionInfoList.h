// OptionInfoList.h

#pragma once


#include "Template/Array.hpp"
#include "OptionInfo.h"



class OptionInfoList{
public:
	OptionInfoList(int capacity=50);
	OptionInfoList(const tstring& optionType, int capacity=50);
	OptionInfoList(const OptionInfoList& source);
	~OptionInfoList();

	void Valuate(double underlyingAssetPrice, double expiryRatio, double riskFreeRate, double histVol);
	int AddOptionInfo(const OptionInfo& optionInfo);
	int FindOptionInfoByStrikePrice(double strikePrice);
	int FineOptionInfoByOptionCode(const tstring& optionCode);
	void DeleteAll();

	bool IsEqual(const OptionInfoList& other);
	bool IsNotEqual(const OptionInfoList& other);
	OptionInfo& GetAt(int index);

	OptionInfoList& operator=(const OptionInfoList& source);
	bool operator==(const OptionInfoList& other);
	bool operator!=(const OptionInfoList& other);
	OptionInfo& operator[](int index);

	tstring& GetOptionType() const;
	int GetLength() const;
	int GetCapacity() const;

private:
	tstring optionType;
	Array<OptionInfo> options;
	int length;
	int capacity;
};



inline tstring& OptionInfoList::GetOptionType() const{
	return const_cast<tstring&>(this->optionType);
}


inline int OptionInfoList::GetLength() const{
	return this->length;
}


inline int OptionInfoList::GetCapacity() const{
	return this->capacity;
}

