// DataBunchesToNotify.cpp

#include "DataBunchesToNotify.h"


DataBunchesToNotify::DataBunchesToNotify(int capacity)
	:dataBunches(capacity){
	this->length =0;
	this->capacity = capacity;
}


DataBunchesToNotify::DataBunchesToNotify(const DataBunchesToNotify& source)
	:dataBunches(source.dataBunches){
	this->length = source.length;
	this->capacity = source.capacity;
}


DataBunchesToNotify::~DataBunchesToNotify(){
}


int DataBunchesToNotify::AddDataBunchToNotify(DataBunch* pDataBunch){
	int ret = -1;
	if(this->length<this->capacity){
		ret = this->dataBunches.Store(this->length, pDataBunch);
	}
	else{
		ret = this->dataBunches.Insert(this->length, pDataBunch);
		this->capacity++;
	}
	this->length++;
	return ret;
}


int DataBunchesToNotify::FindDataBunchToNotify(DataBunch* pDataBunch){
	int index = -1;
	int i=0;
	bool found = false;
	while(i<this->length && found == false){
		if(pDataBunch == this->GetAt(i)){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}


int DataBunchesToNotify::DeleteDataBunchToNotify(int index){
	return this->dataBunches.Delete(index);
}


bool DataBunchesToNotify::IsEqual(const DataBunchesToNotify& other){
	bool ret = false;
	if(this->dataBunches.IsEqual(other.dataBunches)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataBunchesToNotify::IsNotEqual(const DataBunchesToNotify& other){
	bool ret = false;
	if(this->dataBunches.IsNotEqual(other.dataBunches)==false ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


DataBunch* DataBunchesToNotify::GetAt(int index){
	return this->dataBunches.GetAt(index);
}


DataBunchesToNotify& DataBunchesToNotify::operator=(const DataBunchesToNotify& source){
	this->dataBunches = source.dataBunches;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool DataBunchesToNotify::operator==(const DataBunchesToNotify& other){
	bool ret = false;
	if(this->dataBunches == other.dataBunches &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool DataBunchesToNotify::operator!=(const DataBunchesToNotify& other){
	bool ret = false;
	if(this->dataBunches != other.dataBunches ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


DataBunch* DataBunchesToNotify::operator[](int index){
	return this->dataBunches[index];
}