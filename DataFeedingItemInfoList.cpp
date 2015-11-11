// DataFeedingItemInfoList.cpp

#include "DataFeedingItemInfoList.h"


DataFeedingItemInfoList::DataFeedingItemInfoList(int capacity)
	:list(capacity){
	this->length = 0;
	this->capacity = capacity;
}


DataFeedingItemInfoList::DataFeedingItemInfoList(const DataFeedingItemInfoList& source)
	:list(source.list){
	this->length = source.length;
	this->capacity = source.capacity;
}


DataFeedingItemInfoList::~DataFeedingItemInfoList(){
}


int DataFeedingItemInfoList::FindIndexOfDataFeedingItemInfo(const tstring& broker, const tstring& instrumentCode, const tstring& trType){
	int index=-1;
	int found = false;
	int i = 0;
	while (i < this->length && found == false){
		DataFeedingItemInfo& info = this->GetAt(i);
		if (broker.compare(info.GetBroker())==0 &&
			instrumentCode.compare(info.GetInstrumentCode()) == 0 &&
			trType.compare(info.GetTRType()) == 0){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}



int DataFeedingItemInfoList::FindIndexOfItemByID(int id){
	int index = -1;
	int found = false;
	int i = 0;
	while (i < this->length && found == false){
		DataFeedingItemInfo& info = this->GetAt(i);
		if (info.GetID()==id){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}


int DataFeedingItemInfoList::AddDataFeedingItemInfo(const DataFeedingItemInfo& info){
	int ret;
	if (this->length < this->capacity){
		ret = this->list.Store(this->length, info);
	}
	else{
		ret = this->list.Insert(this->length, info);
		this->capacity++;
	}
	this->length++;
	return ret;
}


void DataFeedingItemInfoList::ClearList(){
	this->list.Clear();
	this->length = 0;
	this->capacity = 0;
}


void DataFeedingItemInfoList::DeleteDataFeedingItemInfo(int index){
	this->list.Delete(index);
	this->length--;
	this->capacity--;
}


int DataFeedingItemInfoList::GetItemIndexByRowNumber(int rowIndex){
	int index = -1;
	int i = 0;
	bool found = false;
	while (i < this->length && found == false){
		DataFeedingItemInfo& item = this->GetAt(i);
		if (item.GetRowIndex() == rowIndex){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}





bool DataFeedingItemInfoList::IsEqual(const DataFeedingItemInfoList& other){
	bool ret = false;
	if (this->list.IsEqual(other.list) == true &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataFeedingItemInfoList::IsNotEqual(const DataFeedingItemInfoList& other){
	bool ret = false;
	if (this->list.IsNotEqual(other.list) == true ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataFeedingItemInfo& DataFeedingItemInfoList::GetAt(int index){
	return this->list.GetAt(index);
}


DataFeedingItemInfoList& DataFeedingItemInfoList::operator=(const DataFeedingItemInfoList& source){
	this->list = source.list;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool DataFeedingItemInfoList::operator==(const DataFeedingItemInfoList& other){
	bool ret = false;
	if (this->list == other.list &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataFeedingItemInfoList::operator!=(const DataFeedingItemInfoList& other){
	bool ret = false;
	if (this->list != other.list ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataFeedingItemInfo& DataFeedingItemInfoList::operator[](int index){
	return this->list[index];
}
