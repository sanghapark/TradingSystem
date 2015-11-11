// DataFeedingInfoManager.cpp

#include "DataFeedingInfoManager.h"
#include "File.h"
#include "Constants.h"
#include "TradingSystemManager.h"



DataFeedingInfoManager::DataFeedingInfoManager(TradingSystemManager* pTradingSystemManager){
	this->xmlController.p_mDataFeedingInfoManager = this;
	this->p_mTradingSystemManager = pTradingSystemManager;
}


DataFeedingInfoManager::DataFeedingInfoManager(const DataFeedingInfoManager& source){
}


DataFeedingInfoManager::~DataFeedingInfoManager(){
}

void DataFeedingInfoManager::InitilizeData(){
	this->ReadDataFeedingItemList();
	this->ReadDataBunchList();
	this->RelateDataBunchesToDataFeedingItemInfo();
}


DataFeedingItemInfoList& DataFeedingInfoManager::ReadDataFeedingItemList(){
	this->dataFeedingInfoItemlist = this->xmlController.ReadDataFeedingItemList();
	return this->dataFeedingInfoItemlist;
}


DataBunchList& DataFeedingInfoManager::ReadDataBunchList(){
	this->dataBunchList = this->xmlController.ReadDataBunchList();
	return this->dataBunchList;
}


void DataFeedingInfoManager::SaveDataFeedingItemInfoList(){
	this->xmlController.SaveDataFeedingItemInfoList(this->dataFeedingInfoItemlist);
}


void DataFeedingInfoManager::SaveDataBunchList(){
	this->xmlController.SaveDataBunchList(this->dataBunchList);
}


int DataFeedingInfoManager::AddDataFeedingItemInfo(const DataFeedingItemInfo& item){
	return this->dataFeedingInfoItemlist.AddDataFeedingItemInfo(item);
}


int DataFeedingInfoManager::FindItemIndexByID(int id){
	return this->dataFeedingInfoItemlist.FindIndexOfItemByID(id);
}


int DataFeedingInfoManager::AddDataBunch(const DataBunch& dataBunch){
	return this->dataBunchList.AddDataBunch(dataBunch);
}


int DataFeedingInfoManager::RegisterDataToBunch(int index, int itemID){
	int ret = -1;
	if(this->dataBunchList.GetAt(index).IsIn(itemID)==false){
		ret = this->dataBunchList.GetAt(index).AddItemID(itemID);
	}
	return ret;
}


void DataFeedingInfoManager::RelateDataBunchesToDataFeedingItemInfo(){
	for(int i=0; i<this->dataBunchList.GetLength(); i++){
		DataBunch& dataBunch = this->dataBunchList.GetAt(i);
		for(int j=0; j<dataBunch.GetLength(); j++){
			DataBunchItem& dataBunchItem = dataBunch.GetAt(j);
			int itemID = dataBunchItem.GetItemID();

			int itemIndex = this->dataFeedingInfoItemlist.FindIndexOfItemByID(itemID);
			if(itemIndex>=0){
				DataFeedingItemInfo& item = this->dataFeedingInfoItemlist.GetAt(itemIndex);
				item.AddDataBunchToNotify(&dataBunch);
			}
		}
	}
}




bool DataFeedingInfoManager::ArrangeListForGrid(const tstring& paramStrBroker, const tstring& paramStrInstType, const tstring& paramStrTRType, int paramAutoChecked){
	bool ret = false;
	if(this->dataFeedingInfoItemlist.GetLength()>0){
		DataFeedingInfoItemListInGrid tempListForGrid(this->dataFeedingInfoItemlist);

		if (paramStrBroker.compare(ALL) != 0){
			tempListForGrid = tempListForGrid.PickOutItemsByBroker(paramStrBroker);
		}

		if (paramStrInstType.compare(ALL) != 0){
			tempListForGrid = tempListForGrid.PickOutItemsByInstType(paramStrInstType);
		}

		if (paramStrTRType.compare(ALL) != 0){
			tempListForGrid = tempListForGrid.PickOutItemsByTRType(paramStrTRType);
		}

		if (paramAutoChecked != BST_UNCHECKED){
			tempListForGrid = tempListForGrid.PickOutItemsByAutoCheck(paramAutoChecked);
		}

		this->listForGrid = tempListForGrid;
		ret = true;
	}
	return ret;
}





bool DataFeedingInfoManager::IsEqual(const DataFeedingInfoManager& other){
	bool ret = false;
	if(	this->dataFeedingInfoItemlist.IsEqual(other.dataFeedingInfoItemlist)==true &&
		this->dataBunchList.IsEqual(other.dataBunchList) == true &&
		this->listForGrid.IsEqual(other.listForGrid) == true){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoManager::IsNotEqual(const DataFeedingInfoManager& other){
	bool ret = false;
	if (this->dataFeedingInfoItemlist.IsNotEqual(other.dataFeedingInfoItemlist) == true ||
		this->dataBunchList.IsNotEqual(other.dataBunchList) == true ||
		this->listForGrid.IsNotEqual(other.listForGrid) == true){
		ret = true;
	}
	return ret;
}


DataFeedingInfoManager& DataFeedingInfoManager::operator=(const DataFeedingInfoManager& source){
	this->dataFeedingInfoItemlist = source.dataFeedingInfoItemlist;
	this->dataBunchList = source.dataBunchList;
	this->listForGrid = source.listForGrid;
	return *this;
}


bool DataFeedingInfoManager::operator==(const DataFeedingInfoManager& other){
	bool ret = false;
	if( this->dataFeedingInfoItemlist == other.dataFeedingInfoItemlist &&
		this->dataBunchList == other.dataBunchList &&
		this->listForGrid == other.listForGrid){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoManager::operator!=(const DataFeedingInfoManager& other){
	bool ret = false;
	if(this->dataFeedingInfoItemlist!=other.dataFeedingInfoItemlist ||
		this->dataBunchList != other.dataBunchList ||
		this->listForGrid != other.listForGrid){
		ret = true;
	}
	return ret;
}






