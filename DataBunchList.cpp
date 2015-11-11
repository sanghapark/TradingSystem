// DataFile.cpp

#include "DataBunchList.h"

DataBunchList::DataBunchList(int capacity)
	:bunches(capacity){
	this->length = 0;
	this->capacity = capacity;
}


DataBunchList::DataBunchList(const DataBunchList& source)
	:bunches(source.bunches),
	directoryForSaving(source.directoryForSaving){
	this->length = source.length;
	this->capacity = source.capacity;
}


DataBunchList::~DataBunchList(){
}


void DataBunchList::Clear(){
	this->bunches.Clear();
	this->length = 0;
	this->capacity = 0;
}


int DataBunchList::AddDataBunch(const DataBunch& file){
	int index = -1;
	if (this->length < this->capacity){
		index = this->bunches.Store(this->length, file);
	}
	else{
		index = this->bunches.Insert(this->length, file);
		this->capacity++;
	}
	this->length++;
	return index;
}


int DataBunchList::FindDataBunch(const tstring& name){
	int index = -1;
	bool found = false;
	int i = 0;
	while (i < this->length && found == false){
		if (this->GetAt(i).GetName().compare(name) == 0){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}



void DataBunchList::InitSaving(){
	for(int i=0; i<this->length; i++){
		DataBunch& dataBunch = this->GetAt(i);
		if(dataBunch.GetSaveYN()==true){
			dataBunch.CreateDir();
		}
	}
}


void DataBunchList::EndSaving(){
	for(int i=0; i<this->length; i++){
		DataBunch& dataBunch = this->GetAt(i);
		if(dataBunch.GetSaveYN()==true){
			dataBunch.GetFileWriter().GetWriter().clear();
			dataBunch.GetFileWriter().GetWriter().close();
		}
	}
}



bool DataBunchList::IsEqual(const DataBunchList& other){
	bool ret = false;
	if (this->bunches.IsEqual(other.bunches) == true &&
		this->directoryForSaving.compare(other.directoryForSaving) == 0 &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataBunchList::IsNotEqual(const DataBunchList& other){
	bool ret = false;
	if (this->bunches.IsNotEqual(other.bunches) == true ||
		this->directoryForSaving.compare(other.directoryForSaving) != 0 ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataBunch& DataBunchList::GetAt(int index){
	return this->bunches.GetAt(index);
}



DataBunchList& DataBunchList::operator = (const DataBunchList& source){
	this->bunches = source.bunches;
	this->length = source.length;
	this->capacity = source.capacity;
	this->directoryForSaving = source.directoryForSaving;
	return *this;
}


bool DataBunchList::operator == (const DataBunchList& other){
	bool ret = false;
	if (this->bunches == other.bunches &&
		this->directoryForSaving == other.directoryForSaving &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


bool DataBunchList::operator != (const DataBunchList& other){
	bool ret = false;
	if (this->bunches != other.bunches ||
		this->directoryForSaving != other.directoryForSaving ||
		this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	return ret;
}


DataBunch& DataBunchList::operator[](int index){
	return this->bunches[index];
}