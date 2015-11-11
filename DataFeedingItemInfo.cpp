// DataFeedingListItemInfo.cpp

#include "DataFeedingItemInfo.h"
#include "Constants.h"
#include "DataBunch.h"
#include <afxwin.h>
#include "./packet/FC0.h"
#include "./packet/FH0.h"
#include "./packet/S3_.h"
#include "./packet/H1_.h"
#include "./packet/OC0.h"
#include "./packet/OH0.h"

DataFeedingItemInfo::DataFeedingItemInfo(){
	this->id = 0;
	this->autoYN = false;
	this->rowIndex = -1;
	this->feedingStatus = -1;
	this->saveStatus = true;
}


DataFeedingItemInfo::DataFeedingItemInfo(int id,
										const tstring& broker,
										const tstring& instrumentType,
										const tstring& instrumentName,
										const tstring& instrumentCode,
										const tstring& trType,
										const tstring& trCode,
										bool autoYN)
	:broker(broker),
	instrumentType(instrumentType),
	instrumentName(instrumentName),
	instrumentCode(instrumentCode),
	trType(trType),
	trCode(trCode),
	dataBlock(broker, trCode){
	this->id = id;
	this->autoYN = autoYN;
	this->rowIndex = -1;
	this->feedingStatus = -1;
	this->saveStatus = true;
}


DataFeedingItemInfo::DataFeedingItemInfo(const DataFeedingItemInfo& source)
	:broker(source.broker),
	instrumentType(source.instrumentType),
	instrumentName(source.instrumentName),
	instrumentCode(source.instrumentCode),
	trType(source.trType),
	trCode(source.trCode),
	dataBlock(source.dataBlock),
	dataBunchesToNotify(source.dataBunchesToNotify){
	this->id = source.id;
	this->autoYN = source.autoYN;
	this->rowIndex = source.rowIndex;
	this->feedingStatus = source.feedingStatus;
	this->saveStatus = source.saveStatus;
}


DataFeedingItemInfo::~DataFeedingItemInfo(){
}

int DataFeedingItemInfo::AssignAdviseFeedingStatus(bool status){
	if(status == true){
		this->feedingStatus = 1;
	}
	else{
		this->feedingStatus = 0;
	}
	return this->feedingStatus;
}


int DataFeedingItemInfo::AssignUnadviseFeedingStatus(bool status){
	if(status == false){
		int preStatus = this->feedingStatus;
		if(preStatus == 1){
			this->feedingStatus = 1;
		}
		else{
			this->feedingStatus = -1;
		}
	}
	else{
		this->feedingStatus = -1;
	}
	return this->feedingStatus;
}


int DataFeedingItemInfo::AddDataBunchToNotify(DataBunch* pDataBunch){
	return this->dataBunchesToNotify.AddDataBunchToNotify(pDataBunch);
}


void DataFeedingItemInfo::AssignDataBlock(void* dataBlock, int size){
	this->dataBlock.AssignDataBlock(dataBlock, size);
	this->NotifyDataBunches();
}

void DataFeedingItemInfo::NotifyDataBunches(){
	for(int i=0; i<this->dataBunchesToNotify.GetLength(); i++){
		DataBunch* pDataBunch = this->dataBunchesToNotify.GetAt(i);
		pDataBunch->GetNotifiedByDataFeedingItemInfo(this);
	}
}


bool DataFeedingItemInfo::IsEqual(const DataFeedingItemInfo& other){
	bool ret = false;
	if (this->id == other.id &&
		this->broker.compare(other.broker)==0 &&
		this->instrumentType.compare(other.instrumentType) == 0 &&
		this->instrumentName.compare(other.instrumentName) == 0 &&
		this->instrumentCode.compare(other.instrumentCode) == 0 &&
		this->trType.compare(other.trType) == 0 &&
		this->trCode.compare(other.trCode) == 0 &&
		this->autoYN==other.autoYN &&
		this->rowIndex == other.rowIndex &&
		this->feedingStatus == other.feedingStatus &&
		this->saveStatus == other.saveStatus &&
		this->dataBlock.IsEqual(other.dataBlock)==true &&
		this->dataBunchesToNotify.IsEqual(other.dataBunchesToNotify) == true){
		ret = true;
	}
	return ret;
}


bool DataFeedingItemInfo::IsNotEqual(const DataFeedingItemInfo& other){
	bool ret = false;
	if (this->id != other.id ||
		this->broker.compare(other.broker)!=0 ||
		this->instrumentType.compare(other.instrumentType) != 0 ||
		this->instrumentName.compare(other.instrumentName) != 0 ||
		this->instrumentCode.compare(other.instrumentCode) != 0 ||
		this->trType.compare(other.trType) != 0 ||
		this->trCode.compare(other.trCode) != 0 ||
		this->autoYN != other.autoYN ||
		this->rowIndex != other.rowIndex ||
		this->feedingStatus != other.feedingStatus ||
		this->saveStatus != other.saveStatus ||
		this->dataBlock.IsNotEqual(other.dataBlock)!=true ||
		this->dataBunchesToNotify.IsNotEqual(other.dataBunchesToNotify) != true){
		ret = true;
	}
	return ret;
}


DataFeedingItemInfo& DataFeedingItemInfo::operator=(const DataFeedingItemInfo& source){
	this->id = source.id;
	this->broker = source.broker;
	this->instrumentType = source.instrumentType;
	this->instrumentName = source.instrumentName;
	this->instrumentCode = source.instrumentCode;
	this->trType = source.trType;
	this->trCode = source.trCode;
	this->autoYN = source.autoYN;
	this->rowIndex = source.rowIndex;
	this->feedingStatus = source.feedingStatus;
	this->saveStatus = source.saveStatus;
	this->dataBlock = source.dataBlock;
	this->dataBunchesToNotify = source.dataBunchesToNotify;
	return *this;
}


bool DataFeedingItemInfo::operator==(const DataFeedingItemInfo& other){
	bool ret = false;
	if (this->id == other.id &&
		this->broker == other.broker &&
		this->instrumentType == other.instrumentType &&
		this->instrumentName == other.instrumentName &&
		this->instrumentCode == other.instrumentCode &&
		this->trType == other.trType&&
		this->trCode == other.trCode &&
		this->autoYN == other.autoYN &&
		this->rowIndex == other.rowIndex &&
		this->feedingStatus == other.feedingStatus &&
		this->saveStatus == other.saveStatus &&
		this->dataBlock == other.dataBlock &&
		this->dataBunchesToNotify == other.dataBunchesToNotify){
		ret = true;
	}
	return ret;
}


bool DataFeedingItemInfo::operator!=(const DataFeedingItemInfo& other){
	bool ret = false;
	if (this->id != other.id ||
		this->broker!=other.broker ||
		this->instrumentType != other.instrumentType ||
		this->instrumentName != other.instrumentName ||
		this->instrumentCode != other.instrumentCode ||
		this->trType != other.trType ||
		this->trCode != other.trCode ||
		this->autoYN != other.autoYN ||
		this->rowIndex != other.rowIndex ||
		this->feedingStatus != other.feedingStatus ||
		this->saveStatus != other.saveStatus ||
		this->dataBlock != other.dataBlock ||
		this->dataBunchesToNotify != other.dataBunchesToNotify){
		ret = true;
	}
	return ret;
}