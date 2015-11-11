// OptionManager.cpp

#include "OptionManager.h"


OptionManager::OptionManager(){
}


OptionManager::OptionManager(const OptionManager& source)
	:optionStrategyList(source.optionStrategyList){
}


OptionManager::~OptionManager(){
}


int OptionManager::CreateOptionStrategy(const tstring& strategyName){
	return this->optionStrategyList.CreateOptionStrategy(strategyName);
}


int OptionManager::AddOptionStrategy(const PositionList& positionList){
	return this->optionStrategyList.AddOptionStrategy(positionList);
}


int OptionManager::DeleteOptionStrategy(int index){
	return this->optionStrategyList.DeleteOptionStrategy(index);
}


int OptionManager::FindOptionStrategy(const tstring& name){
	return this->optionStrategyList.FindOptionStrategy(name);
}


bool OptionManager::IsEqual(const OptionManager& other){
	bool ret = false;
	if(this->optionStrategyList.IsEqual(other.optionStrategyList)==true){
		ret = true;
	}
	return ret;
}


bool OptionManager::IsNotEqual(const OptionManager& other){
	bool ret = false;
	if(this->optionStrategyList.IsNotEqual(other.optionStrategyList)==true){
		ret = true;
	}
	return ret;
}


OptionManager& OptionManager::operator=(const OptionManager& source){
	this->optionStrategyList = source.optionStrategyList;
	return *this;
}


bool OptionManager::operator==(const OptionManager& other){
	bool ret = false;
	if(this->optionStrategyList == other.optionStrategyList){
		ret = true;
	}
	return ret;
}


bool OptionManager::operator!=(const OptionManager& other){
	bool ret =false;
	if(this->optionStrategyList != other.optionStrategyList){
		ret = true;
	}
	return ret;
}