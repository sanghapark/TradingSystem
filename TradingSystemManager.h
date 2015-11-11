// TradingSystemManager.h
// 
#pragma once

#include "LoginInfoManager.h"
#include "DataFeedingInfoManager.h"
#include "InstrumentCodeMaker.h"
#include "InstrumentManager.h"
#include "OptionManager.h"


class TradingSystemManager{
public:
	TradingSystemManager();
	TradingSystemManager(const TradingSystemManager& source);
	~TradingSystemManager();


	bool IsEqual(const TradingSystemManager& other);
	bool IsNotEqual(const TradingSystemManager& other);

	TradingSystemManager& operator=(const TradingSystemManager& source);
	bool operator==(const TradingSystemManager& other);
	bool operator!=(const TradingSystemManager& other);

	InstrumentCodeMaker& GetInstrumentCodeMaker() const;
	LoginInfoManager& GetLoginInfoManager() const;
	DataFeedingInfoManager& GetDataFeedingInfoManager() const;
	InstrumentManager& GetInstrumentManager() const;
	OptionManager& GetOptionManager() const;

private:
	InstrumentCodeMaker instrumentCodeMaker;
	LoginInfoManager loginInfoManager;
	DataFeedingInfoManager dataFeedingInfoManager;
	InstrumentManager instrumentManager;
	OptionManager optionManager;
};

extern InstrumentCodeMaker instrumentCodes;

inline InstrumentCodeMaker& TradingSystemManager::GetInstrumentCodeMaker() const{
	return const_cast<InstrumentCodeMaker&>(this->instrumentCodeMaker);
}

inline LoginInfoManager& TradingSystemManager::GetLoginInfoManager() const{
	return const_cast<LoginInfoManager&>(this->loginInfoManager);
}

inline DataFeedingInfoManager& TradingSystemManager::GetDataFeedingInfoManager() const{
	return const_cast<DataFeedingInfoManager&>(this->dataFeedingInfoManager);
}


inline InstrumentManager& TradingSystemManager::GetInstrumentManager() const{
	return const_cast<InstrumentManager&>(this->instrumentManager);
}


inline OptionManager& TradingSystemManager::GetOptionManager() const{
	return const_cast<OptionManager&>(this->optionManager);
}