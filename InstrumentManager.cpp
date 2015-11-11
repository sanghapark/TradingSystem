// InstrumentManager.cpp

#include "InstrumentManager.h"

InstrumentManager::InstrumentManager(){
}


InstrumentManager::InstrumentManager(const InstrumentManager& source)
	:instrumentList(source.instrumentList),
	xmlController(source.xmlController){
}


InstrumentManager::~InstrumentManager(){
}

void InstrumentManager::InitializeManager(){
	this->LoadInstrumentInfo();
}

InstrumentList& InstrumentManager::LoadInstrumentInfo(){
	this->instrumentList = this->xmlController.ReadInstrumentList();
	return this->instrumentList;
}


//void InstrumentManager::SaveInstrumentInfo(){
//	this->xmlControl
//}


int InstrumentManager::AddInstrument(const Instrument& instrument){
	return this->instrumentList.AddInstrument(instrument);
}


InstrumentList InstrumentManager::GetInstrumentListByType(const tstring& type){
	return this->instrumentList.GetInstrumentListByType(type);
}



bool InstrumentManager::IsEqual(const InstrumentManager& other){
	bool ret = false;
	if(this->instrumentList.IsEqual(other.instrumentList)==true){
		ret = true;
	}
	return ret;
}


bool InstrumentManager::IsNotEqual(const InstrumentManager& other){
	bool ret = false;
	if(this->instrumentList.IsNotEqual(other.instrumentList)==true){
		ret = true;
	}
	return ret;
}



InstrumentManager& InstrumentManager::operator=(const InstrumentManager& source){
	this->instrumentList = source.instrumentList;
	return *this;
}


bool InstrumentManager::operator==(const InstrumentManager& other){
	bool ret = false;
	if(this->instrumentList == other.instrumentList){
		ret = true;
	}
	return ret;
}


bool InstrumentManager::operator!=(const InstrumentManager& other){
	bool ret = false;
	if(this->instrumentList != other.instrumentList){
		ret = true;
	}
	return ret;
}