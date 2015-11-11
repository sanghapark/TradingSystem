// DataFeedingInfoXMLController.h
#ifndef _DATA_FEEDING_INFO_XML_CONTROLLER_H
#define _DATA_FEEDING_INFO_XML_CONTROLLER_H

#include "DataFeedingItemInfoList.h"
#include "DataBunchList.h"
#include <boost/property_tree/ptree.hpp>


class DataFeedingInfoManager;


class DataFeedingInfoXMLController{
	public:
		DataFeedingInfoXMLController(DataFeedingInfoManager* p_mDataFeedingInfoManager=0);
		DataFeedingInfoXMLController(const DataFeedingInfoXMLController& source);
		~DataFeedingInfoXMLController();

		DataFeedingItemInfoList ReadDataFeedingItemList();
		DataBunchList ReadDataBunchList();
		void SaveDataFeedingItemInfoList(const DataFeedingItemInfoList& dataFeedingItemInfoList);
		void SaveDataBunchList(const DataBunchList& dataBunchList);

		bool IsEqual(const DataFeedingInfoXMLController& other);
		bool IsNotEqual(const DataFeedingInfoXMLController& other);

		DataFeedingInfoXMLController& operator=(const DataFeedingInfoXMLController& source);
		bool operator==(const DataFeedingInfoXMLController& other);
		bool operator!=(const DataFeedingInfoXMLController& other);


	private:
		//void ClearDataFeedingItemList();
		//void ClearDataBunchList();


	public:
		DataFeedingInfoManager* p_mDataFeedingInfoManager;

	private:
};



#endif