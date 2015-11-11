// ModuleList.cpp

#include "ModuleList.h"

ModuleList::ModuleList(){
}


ModuleList::ModuleList(const ModuleList& source)
	:dataFeederList(source.dataFeederList){
}


ModuleList::~ModuleList(){
}


void ModuleList::LoadModuleList(){
	this->dataFeederList.LoadDataFeederModuleList();
}


ModuleList& ModuleList::operator=(const ModuleList& source){
	dataFeederList=source.dataFeederList;
	return *this;
}

bool ModuleList::operator==(const ModuleList& other){
	bool ret = false;
	if(this->dataFeederList==other.dataFeederList){
			ret = true;
	}
	return ret;
}


bool ModuleList::operator!=(const ModuleList& other){
	bool ret = false;
	if(this->dataFeederList!=other.dataFeederList){
			ret = true;
	}
	return ret;
}


bool ModuleList::IsEqual(const ModuleList& other){
	bool ret = false;
	if(this->dataFeederList.IsEqual(other.dataFeederList)==true){
			ret = true;
	}
	return ret;
}


bool ModuleList::IsNotEqual(const ModuleList& other){
	bool ret = false;
	if(this->dataFeederList.IsNotEqual(other.dataFeederList)==true){
			ret = true;
	}
	return ret;
}