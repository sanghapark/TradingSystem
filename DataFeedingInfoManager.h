// DataFeedingInfoManager.h
#ifndef _DATA_FEEDING_INFO_MANAGER_H
#define _DATA_FEEDING_INFO_MANAGER_H

#include "Markup.h"
#include "DataFeedingInfoXMLController.h"
#include "DataFeedingItemInfoList.h"
#include "DataFeedingInfoItemListInGrid.h"

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/date_time/posix_time/time_parsers.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include <stdio.h>


class TradingSystemManager;

class DataFeedingInfoManager{
	public:
		DataFeedingInfoManager(TradingSystemManager* pTradingSystemManager=0);
		DataFeedingInfoManager(const DataFeedingInfoManager& source);
		~DataFeedingInfoManager();

		void InitilizeData();

		// XML
		DataFeedingItemInfoList& ReadDataFeedingItemList();
		DataBunchList& ReadDataBunchList();
		void SaveDataFeedingItemInfoList();
		void SaveDataBunchList();

		// DataFeedingItemInfoList
		int AddDataFeedingItemInfo(const DataFeedingItemInfo& item);
		int FindItemIndexByID(int id);


		// DataBunchList
		int AddDataBunch(const DataBunch& dataBunch);
		int RegisterDataToBunch(int index, int itemID);

		// DataFeedingItemInfo에 시그널 Notify할 함수
		void RelateDataBunchesToDataFeedingItemInfo();

		// Grid에 보여지는 목록리스트 세팅
		bool ArrangeListForGrid(const tstring& paramStrBroker, const tstring& paramStrInstType, const tstring& paramStrTRType, int paramAutoChecked);

		


		bool IsEqual(const DataFeedingInfoManager& other);
		bool IsNotEqual(const DataFeedingInfoManager& other);

		DataFeedingInfoManager& operator=(const DataFeedingInfoManager& source);
		bool operator==(const DataFeedingInfoManager& other);
		bool operator!=(const DataFeedingInfoManager& other);

		DataFeedingInfoXMLController& GetXMLController() const;
		DataFeedingItemInfoList& GetDataFeedingInfoItemList() const;
		DataFeedingInfoItemListInGrid& GetListForGrid() const;
		DataBunchList& GetDataBunchList() const;


	public:
		TradingSystemManager* p_mTradingSystemManager;

	private:
		DataFeedingInfoXMLController xmlController;

		DataFeedingItemInfoList dataFeedingInfoItemlist;
		DataFeedingInfoItemListInGrid listForGrid;
		
		DataBunchList dataBunchList;		
};


inline DataFeedingInfoXMLController& DataFeedingInfoManager::GetXMLController() const{
	return const_cast<DataFeedingInfoXMLController&>(this->xmlController);
}


inline DataFeedingItemInfoList& DataFeedingInfoManager::GetDataFeedingInfoItemList() const{
	return const_cast<DataFeedingItemInfoList&>(this->dataFeedingInfoItemlist);
}


inline DataBunchList& DataFeedingInfoManager::GetDataBunchList() const{
	return const_cast<DataBunchList&>(this->dataBunchList);
}


inline DataFeedingInfoItemListInGrid& DataFeedingInfoManager::GetListForGrid() const{
	return const_cast<DataFeedingInfoItemListInGrid&>(this->listForGrid);
}


#endif