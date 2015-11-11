// DataFeedingItemListInGrid.cpp
// 
#include "DataFeedingInfoItemListInGrid.h"
#include "DataFeedingItemInfo.h"
#include "DataFeedingItemInfoList.h"
#include "Constants.h"


DataFeedingInfoItemListInGrid::DataFeedingInfoItemListInGrid(DataFeedingItemInfoList* generalList, int capacity)
	:selectedList(capacity){
	this->generalList = generalList;
	this->length = 0;
	this->capacity = capacity;
}

DataFeedingInfoItemListInGrid::DataFeedingInfoItemListInGrid(const DataFeedingItemInfoList& source)
	:selectedList(source.GetCapacity()){
	this->generalList = &(const_cast<DataFeedingItemInfoList&>(source));
	this->capacity = source.GetCapacity();
	this->length = 0;
	for (int i = 0; i < source.GetLength(); i++){
		DataFeedingItemInfo* pItem = &(this->generalList->GetAt(i));
		this->selectedList.Store(i, pItem);
		pItem->SetRowIndex(i + 1);
		this->length++;
	}
}


DataFeedingInfoItemListInGrid::DataFeedingInfoItemListInGrid(const DataFeedingInfoItemListInGrid& source)
	:selectedList(source.selectedList){
	this->generalList = source.generalList;
	this->length = source.length;
	this->capacity = source.capacity;
}


DataFeedingInfoItemListInGrid::~DataFeedingInfoItemListInGrid(){
}


void DataFeedingInfoItemListInGrid::ClearList(){
	this->selectedList.Clear();
	this->length = 0;
	this->capacity = 0;
}


int DataFeedingInfoItemListInGrid::AddItem(DataFeedingItemInfo* pItem){
	int ret;
	if (this->length < this->capacity){
		ret = this->selectedList.Store(this->length, pItem);
	}
	else{
		ret = this->selectedList.Insert(this->length, pItem);
		this->capacity++;
	}
	this->length++;
	return ret;
}



DataFeedingInfoItemListInGrid DataFeedingInfoItemListInGrid::PickOutItemsByBroker(const tstring& paramStrBroker){
	int count = 0;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetBroker().compare(paramStrBroker) == 0){
			count++;
		}
	}

	DataFeedingInfoItemListInGrid ret(this->generalList, count);

	int rowIndex = 1;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetBroker().compare(paramStrBroker) == 0){
			ret.AddItem(pItem);
			pItem->SetRowIndex(rowIndex);
			rowIndex++;
		}
		else{
			pItem->SetRowIndex(-1);
		}
	}
	return ret;
}


DataFeedingInfoItemListInGrid DataFeedingInfoItemListInGrid::PickOutItemsByInstType(const tstring& paramStrInstType){
	int count = 0;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetInstrumentType().compare(paramStrInstType) == 0){
			count++;
		}
	}

	DataFeedingInfoItemListInGrid ret(this->generalList, count);

	int rowIndex = 1;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetInstrumentType().compare(paramStrInstType) == 0){
			ret.AddItem(pItem);
			pItem->SetRowIndex(rowIndex);
			rowIndex++;
		}
		else{
			pItem->SetRowIndex(-1);
		}
	}
	return ret;
}


DataFeedingInfoItemListInGrid DataFeedingInfoItemListInGrid::PickOutItemsByTRType(const tstring& paramStrTRType){
	int count = 0;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetTRType().compare(paramStrTRType) == 0){
			count++;
		}
	}

	DataFeedingInfoItemListInGrid ret(this->generalList, count);

	int rowIndex = 1;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetTRType().compare(paramStrTRType) == 0){
			ret.AddItem(pItem);
			pItem->SetRowIndex(rowIndex);
			rowIndex++;
		}
		else{
			pItem->SetRowIndex(-1);
		}
	}
	return ret;
}


DataFeedingInfoItemListInGrid DataFeedingInfoItemListInGrid::PickOutItemsByAutoCheck(int autoCheck){
	int count = 0;
	bool boolAutoCheck = false;
	if (autoCheck !=0){
		boolAutoCheck = true;
	}
	 
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetAutoYN()==boolAutoCheck){
			count++;
		}
	}

	DataFeedingInfoItemListInGrid ret(this->generalList, count);

	int rowIndex = 1;
	for (int i = 0; i < this->length; i++){
		DataFeedingItemInfo* pItem = this->GetAt(i);
		if (pItem->GetAutoYN() == boolAutoCheck){
			ret.AddItem(pItem);
			pItem->SetRowIndex(rowIndex);
			rowIndex++;
		}
		else{
			pItem->SetRowIndex(-1);
		}
	}
	return ret;
}





bool DataFeedingInfoItemListInGrid::IsEqual(const DataFeedingInfoItemListInGrid& other){
	bool ret = false;
	if (this->generalList == other.generalList &&
		this->selectedList.IsEqual(other.selectedList) == true &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoItemListInGrid::IsNotEqual(const DataFeedingInfoItemListInGrid& other){
	bool ret = false;
	if (this->generalList != other.generalList ||
		this->selectedList.IsNotEqual(other.selectedList) == true ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataFeedingItemInfo* DataFeedingInfoItemListInGrid::GetAt(int index){
	return this->selectedList.GetAt(index);
}


DataFeedingInfoItemListInGrid& DataFeedingInfoItemListInGrid::operator=(const DataFeedingInfoItemListInGrid& source){
	this->generalList = source.generalList;
	this->selectedList = source.selectedList;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool DataFeedingInfoItemListInGrid::operator==(const DataFeedingInfoItemListInGrid& other){
	bool ret = false;
	if (this->generalList == other.generalList &&
		this->selectedList == other.selectedList &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoItemListInGrid::operator!=(const DataFeedingInfoItemListInGrid& other){
	bool ret = false;
	if (this->generalList != other.generalList ||
		this->selectedList != other.selectedList ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataFeedingItemInfo* DataFeedingInfoItemListInGrid::operator[](int index){
	return this->selectedList[index];
}
