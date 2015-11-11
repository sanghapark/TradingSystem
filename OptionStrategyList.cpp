// OptionStrategy.cpp

#include "OptionStrategyList.h"


OptionStrategyList::OptionStrategyList(int capacity)
	:optionStrategies(capacity){
	this->length= 0;
	this->capacity = capacity;
}


OptionStrategyList::OptionStrategyList(const OptionStrategyList& source)
	:optionStrategies(source.optionStrategies){
	this->length = source.length;
	this->capacity = source.capacity;
}


OptionStrategyList::~OptionStrategyList(){
}


int OptionStrategyList::CreateOptionStrategy(const tstring& strategyName){
	int index = -1;
	PositionList positionList(strategyName);
	if(this->length<this->capacity){
		index = this->optionStrategies.Store(this->length, positionList);
	}
	else{
		index = this->optionStrategies.Insert(this->length, positionList);
		this->capacity++;
	}
	this->length++;
	return index;
}


int OptionStrategyList::AddOptionStrategy(const PositionList& positionList){
	int index = -1;
	if(this->length<this->capacity){
		index = this->optionStrategies.Store(this->length, positionList);
	}
	else{
		index = this->optionStrategies.Insert(this->length, positionList);
		this->capacity++;
	}
	this->length++;
	return index;
}


int OptionStrategyList::DeleteOptionStrategy(int index){
	int ret = -1;
	
	if(this->length>0){
		ret = this->optionStrategies.Delete(index);
	}
	this->length--;
	this->capacity--;
	return ret;
}


int OptionStrategyList::FindOptionStrategy(const tstring& name){
	int index = -1;
	int i =0;
	bool found = false;
	while(i<this->length && found==false){
		if(name.compare(this->GetAt(i).GetName())==0){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}


bool OptionStrategyList::IsEqual(const OptionStrategyList& other){
	bool ret = false;
	if(this->optionStrategies.IsEqual(other.optionStrategies)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool OptionStrategyList::IsNotEqual(const OptionStrategyList& other){
	bool ret = false;
	if(this->optionStrategies.IsNotEqual(other.optionStrategies)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


PositionList& OptionStrategyList::GetAt(int index){
	return this->optionStrategies.GetAt(index);
}


OptionStrategyList& OptionStrategyList::operator=(const OptionStrategyList& source){
	this->optionStrategies = source.optionStrategies;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool OptionStrategyList::operator==(const OptionStrategyList& other){
	bool ret = false;
	if(this->optionStrategies == other.optionStrategies &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool OptionStrategyList::operator!=(const OptionStrategyList& other){
	bool ret = false;
	if(this->optionStrategies != other.optionStrategies ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}