// TradingSystemManager.cpp
// 
#include "TradingSystemManager.h"


InstrumentCodeMaker instrumentCodes;

TradingSystemManager::TradingSystemManager(){
	this->instrumentCodeMaker.InitilizeCodes();
	this->dataFeedingInfoManager.p_mTradingSystemManager = this;
	this->dataFeedingInfoManager.InitilizeData();
	instrumentCodes.InitilizeCodes();
	this->instrumentManager.InitializeManager();
}


TradingSystemManager::TradingSystemManager(const TradingSystemManager& source)
	:loginInfoManager(source.loginInfoManager),
	dataFeedingInfoManager(source.dataFeedingInfoManager),
	instrumentCodeMaker(source.instrumentCodeMaker),
	instrumentManager(source.instrumentManager),
	optionManager(source.optionManager){
}



TradingSystemManager::~TradingSystemManager(){
}


bool TradingSystemManager::IsEqual(const TradingSystemManager& other){
	bool ret = false;
	if (this->loginInfoManager.IsEqual(other.loginInfoManager) == true &&
		this->dataFeedingInfoManager.IsEqual(other.dataFeedingInfoManager) == true &&
		this->instrumentCodeMaker.IsEqual(other.instrumentCodeMaker) == true &&
		this->instrumentManager.IsEqual(other.instrumentManager)==true &&
		this->optionManager.IsEqual(other.optionManager)==true){
		ret = true;
	}
	return ret;
}


bool TradingSystemManager::IsNotEqual(const TradingSystemManager& other){
	bool ret = false;
	if (this->loginInfoManager.IsNotEqual(other.loginInfoManager) == true ||
		this->dataFeedingInfoManager.IsNotEqual(other.dataFeedingInfoManager) == true ||
		this->instrumentCodeMaker.IsNotEqual(other.instrumentCodeMaker)==true ||
		this->instrumentManager.IsNotEqual(other.instrumentManager)==true ||
		this->optionManager.IsNotEqual(other.optionManager)==true){
		ret = true;
	}
	return ret;
}


TradingSystemManager& TradingSystemManager::operator = (const TradingSystemManager& source){
	this->loginInfoManager = source.loginInfoManager;
	this->dataFeedingInfoManager = source.dataFeedingInfoManager;
	this->instrumentCodeMaker = source.instrumentCodeMaker;
	this->instrumentManager = source.instrumentManager;
	this->optionManager = source.optionManager;
	return *this;
}


bool TradingSystemManager::operator == (const TradingSystemManager& other){
	bool ret = false;
	if (this->loginInfoManager == other.loginInfoManager &&
		this->dataFeedingInfoManager == other.dataFeedingInfoManager &&
		this->instrumentCodeMaker == other.instrumentCodeMaker &&
		this->instrumentManager == other.instrumentManager &&
		this->optionManager == other.optionManager){
		ret = true;
	}
	return ret;
}


bool TradingSystemManager::operator != (const TradingSystemManager& other){
	bool ret = false;
	if (this->loginInfoManager != other.loginInfoManager ||
		this->dataFeedingInfoManager != other.dataFeedingInfoManager ||
		this->instrumentCodeMaker != other.instrumentCodeMaker ||
		this->instrumentManager != other.instrumentManager ||
		this->optionManager != other.optionManager){
		ret = true;
	}
	return ret;
}