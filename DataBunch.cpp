// DataBunch.cpp

#include "DataBunch.h"
#include "DataFeedingItemInfoList.h"


DataBunch::DataBunch(int capacity)
	:items(capacity),
	fileWriter(this){
	this->id = -1;
	this->length = 0;
	this->capacity = capacity;
	this->saveYN = false;
}

DataBunch::DataBunch(int id, const tstring& name, bool saveYN, int capacity)
	:name(name),
	items(capacity),
	fileWriter(this){
	this->id = id;
	this->length = 0;
	this->capacity = capacity;
	this->saveYN = saveYN;
}


DataBunch::DataBunch(const DataBunch& source)
	:items(source.items),
	name(source.name){
	this->id = source.id;
	this->length = source.length;
	this->capacity = source.capacity;
	this->saveYN = source.saveYN;
	this->fileWriter = source.fileWriter;
}


DataBunch::~DataBunch(){
}


void DataBunch::ClearList(){
	this->items.Clear();
	this->length = 0;
	this->capacity = 0;
}


int DataBunch::AddItemID(const DataBunchItem& item){
	int ret;
	if (this->length < this->capacity){
		ret = this->items.Store(this->length, item);
	}
	else{
		ret = this->items.Insert(this->length, item);
		this->capacity++;
	}
	this->length++;
	return ret;
}

bool DataBunch::IsIn(int itemID){
	bool ret = false;

	int i=0;
	bool found=false;
	while(i<this->GetLength() && found==false){
		int id = this->GetAt(i).GetItemID();
		if(id==itemID){
			found=true;
			ret = true;
		}
	}

	return ret;
}


bool DataBunch::CreateDir(){
	return this->fileWriter.CreateDir(this->name);
}


void DataBunch::GetNotifiedByDataFeedingItemInfo(DataFeedingItemInfo* pItem){
	if(this->saveYN==true){
		this->fileWriter.Write(const_cast<tchar*>(pItem->GetTRCode().c_str()), pItem->GetDataBlock().GetPDataBlock(), pItem->GetDataBlock().GetSize());
	}
}


bool DataBunch::IsEqual(const DataBunch& other){
	bool ret = false;
	if (this->id == other.id &&
		this->items.IsEqual(other.items) == true &&
		this->name.compare(other.name) == 0 &&
		this->length == other.length &&
		this->capacity == other.capacity &&
		this->saveYN == other.saveYN &&
		this->fileWriter.IsEqual(other.fileWriter)==true){
		ret = true;
	}
	return ret;
}


bool DataBunch::IsNotEqual(const DataBunch& other){
	bool ret = false;
	if (this->id != other.id ||
		this->items.IsNotEqual(other.items) == true ||
		this->name.compare(other.name) != 0 ||
		this->length != other.length ||
		this->capacity != other.capacity ||
		this->saveYN != other.saveYN ||
		this->fileWriter.IsNotEqual(other.fileWriter)==true){
		ret = true;
	}
	return ret;
}


DataBunchItem& DataBunch::GetAt(int index){
	return this->items.GetAt(index);
}


DataBunch& DataBunch::operator=(const DataBunch& source){
	this->id = source.id;
	this->items = source.items;
	this->length = source.length;
	this->capacity = source.capacity;
	this->saveYN = source.saveYN;
	this->name = source.name;
	this->fileWriter = source.fileWriter;
	return *this;
}


bool DataBunch::operator==(const DataBunch& other){
	bool ret = false;
	if (this->id == other.id &&
		this->items == other.items &&
		this->name == other.name &&
		this->length == other.length &&
		this->capacity == other.capacity &&
		this->saveYN == other.saveYN &&
		this->fileWriter == other.fileWriter){
		ret = true;
	}
	return ret;
}


bool DataBunch::operator!=(const DataBunch& other){
	bool ret = false;
	if (this->id != other.id ||
		this->items != other.items ||
		this->name != other.name ||
		this->length != other.length ||
		this->capacity != other.capacity ||
		this->saveYN != other.saveYN ||
		this->fileWriter != other.fileWriter){
		ret = true;
	}
	return ret;
}


DataBunchItem& DataBunch::operator[](int index){
	return this->items[index];
}