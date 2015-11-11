// DataBunchItem.cpp

#include "DataBunchItem.h"


DataBunchItem::DataBunchItem(){
	this->m_pData = 0;
	this->itemID = -1;
}


DataBunchItem::DataBunchItem(int itemID, DataFeedingItemInfo* m_pData){
	this->itemID  = itemID;
	this->m_pData = m_pData;
}


DataBunchItem::DataBunchItem(const DataBunchItem& source){
	this->itemID = source.itemID;
	this->m_pData = source.m_pData;
}


DataBunchItem::~DataBunchItem(){
}


bool DataBunchItem::IsEqual(const DataBunchItem& other){
	bool ret = false;
	if(this->itemID == other.itemID){
		ret = true;
	}
	return ret;
}


bool DataBunchItem::IsNotEqual(const DataBunchItem& other){
	bool ret = false;
	if(this->itemID != other.itemID){
		ret = true;
	}
	return ret;
}


DataBunchItem& DataBunchItem::operator=(const DataBunchItem& source){
	this->itemID = source.itemID;
	this->m_pData = source.m_pData;
	return *this;
}


bool DataBunchItem::operator==(const DataBunchItem& other){
	bool ret = false;
	if(this->itemID == other.itemID){
		ret = true;
	}
	return ret;
}


bool DataBunchItem::operator!=(const DataBunchItem& other){
	bool ret = false;
	if(this->itemID != other.itemID){
		ret = true;
	}
	return ret;
}