// OptionInfoList.cpp

#include "OptionInfoList.h"



OptionInfoList::OptionInfoList(int capacity)
	:options(capacity){
	this->length = 0;
	this->capacity = capacity;
}


OptionInfoList::OptionInfoList(const tstring& optionType, int capacity)
	:optionType(optionType),
	options(capacity){
	this->length = 0;
	this->capacity = capacity;
}


OptionInfoList::OptionInfoList(const OptionInfoList& source)
	:optionType(source.optionType),
	options(source.options){
	this->length = source.length;
	this->capacity = source.capacity;
}



OptionInfoList::~OptionInfoList(){
}

void OptionInfoList::Valuate(double underlyingAssetPrice, double expiryRatio, double riskFreeRate, double histVol){
	for(int i=0; i<this->length; i++){
		this->GetAt(i).GetOption().CalculateValue(underlyingAssetPrice, expiryRatio, riskFreeRate, histVol);
		this->GetAt(i).GetOption().CalculateSensitivity(underlyingAssetPrice, expiryRatio, riskFreeRate, histVol);
	}
}

int OptionInfoList::AddOptionInfo(const OptionInfo& optionInfo){
	int index = -1;
	if(this->length<this->capacity){
		index = this->options.Store(this->length, optionInfo);
	}
	else{
		index = this->options.Insert(this->length, optionInfo);
		this->capacity++;
	}
	this->length++;
	return index;
}


int OptionInfoList::FindOptionInfoByStrikePrice(double strikePrice){
	int index = -1;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		if(strikePrice == this->GetAt(i).GetOption().GetStrikePrice()){
			found=true;
			index = i;
		}
		i++;
	}
	return index;
}


int OptionInfoList::FineOptionInfoByOptionCode(const tstring& optionCode){
	int index = -1;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		tstring code = this->GetAt(i).GetOption().GetOptionCode();
		if(optionCode.compare(code)==0){
			found=true;
			index = i;
		}
		i++;
	}
	return index;
}


void OptionInfoList::DeleteAll(){
	this->options.Clear();
	this->length = this->options.GetLength();
	this->capacity = this->options.GetCapacity();
}


bool OptionInfoList::IsEqual(const OptionInfoList& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)==0 &&
		this->options.IsEqual(other.options)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool OptionInfoList::IsNotEqual(const OptionInfoList& other){
	bool ret = false;
	if(this->optionType.compare(other.optionType)!=0 ||
		this->options.IsNotEqual(other.options)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


OptionInfo& OptionInfoList::GetAt(int index){
	return this->options.GetAt(index);
}


OptionInfoList& OptionInfoList::operator=(const OptionInfoList& source){
	this->optionType = source.optionType;
	this->options = source.options;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool OptionInfoList::operator==(const OptionInfoList& other){
	bool ret = false;
	if(this->optionType==other.optionType &&
		this->options==other.options &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool OptionInfoList::operator!=(const OptionInfoList& other){
	bool ret = false;
	if(this->optionType!=other.optionType ||
		this->options!=other.options ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


OptionInfo& OptionInfoList::operator[](int index){
	return this->options[index];
}