
#include "DataFeederList.h"

#include "Markup.h"
#include "File.h"
#include "DataConverter.h"

DataFeederList::DataFeederList(int capacity)
	:dataFeederArr(capacity){
	this->length=0;
	this->capacity=capacity;
}


DataFeederList::DataFeederList(const DataFeederList& source)
	:dataFeederArr(source.dataFeederArr){
		this->length=source.length;
		this->capacity=source.capacity;
}


DataFeederList::~DataFeederList(){}


void DataFeederList::LoadDataFeederModuleList(){
	CMarkup* xml = new CMarkup();
	DataConverter dataConverter;
	xml->Load(MODULELIST);
	tstring feeder(TEXT("Broker"));
	int count=1;

	xml->ResetPos();
	xml->FindElem(TEXT("ModuleList"));
	xml->IntoElem();
	xml->FindElem(TEXT("DataFeeder"));
	count = dataConverter.ConvertStringToInt(xml->GetAttrib(TEXT("count")));

	xml->IntoElem();
	for(int i=1; i<=count; i++){
		tstring fd = feeder + dataConverter.ConvertIntToString(i);
		xml->FindElem(fd);
		tstring broker = xml->GetData();
		this->AddBrokerName(broker);
		fd.clear();
	}
	if(xml!=0){
		delete xml;
	}
}


int DataFeederList::AddBrokerName(const tstring& name){
	int index = -1;
	if(this->length<this->capacity){
		this->dataFeederArr.Store(this->length, name);
	}
	else{
		this->dataFeederArr.Insert(this->length, name);
		this->capacity++;
	}
	this->length++;
	return index;
}


DataFeederList& DataFeederList::operator=(const DataFeederList& source){
	this->dataFeederArr=source.dataFeederArr;
	this->length=source.length;
	this->capacity=source.capacity;
	return *this;
}


bool DataFeederList::operator==(const DataFeederList& other){
	bool ret = false;
	if(this->dataFeederArr==other.dataFeederArr &&
		this->length==other.length &&
		this->capacity==other.capacity){
			ret = true;
	}
	return ret;
}


bool DataFeederList::operator!=(const DataFeederList& other){
	bool ret = false;
	if(this->dataFeederArr!=other.dataFeederArr ||
		this->length!=other.length ||
		this->capacity!=other.capacity){
			ret = true;
	}
	return ret;
}


bool DataFeederList::IsEqual(const DataFeederList& other){
	bool ret = false;
	if(this->dataFeederArr.IsEqual(other.dataFeederArr)==true &&
		this->length==other.length &&
		this->capacity==other.capacity){
			ret = true;
	}
	return ret;
}


bool DataFeederList::IsNotEqual(const DataFeederList& other){
	bool ret = false;
	if(this->dataFeederArr.IsNotEqual(other.dataFeederArr)==true ||
		this->length!=other.length ||
		this->capacity!=other.capacity){
			ret = true;
	}
	return ret;
}


tstring& DataFeederList::operator[](int index){
	return this->dataFeederArr[index];
}


tstring& DataFeederList::GetAt(int index){
	return this->dataFeederArr.GetAt(index);
}