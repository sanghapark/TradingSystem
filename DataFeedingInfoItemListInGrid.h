// DataFeedingInfoItemListInGrid.h
// 
#pragma once

#include "Template\Array.hpp"
#include "DataTypeDefinition.h"
#include "DataFeedingItemInfoList.h"

class DataFeedingItemInfo;


class DataFeedingInfoItemListInGrid{
	public:
		DataFeedingInfoItemListInGrid(DataFeedingItemInfoList* generalList = 0, int capacity = 50);
		DataFeedingInfoItemListInGrid(const DataFeedingItemInfoList& source);
		DataFeedingInfoItemListInGrid(const DataFeedingInfoItemListInGrid& source);
		~DataFeedingInfoItemListInGrid();

		void ClearList();
		int AddItem(DataFeedingItemInfo* pItem);
		
		DataFeedingInfoItemListInGrid PickOutItemsByBroker(const tstring& paramStrBroker);
		DataFeedingInfoItemListInGrid PickOutItemsByInstType(const tstring& paramStrInstType);
		DataFeedingInfoItemListInGrid PickOutItemsByTRType(const tstring& paramStrTRType);
		DataFeedingInfoItemListInGrid PickOutItemsByAutoCheck(int autoCheck);


		bool IsEqual(const DataFeedingInfoItemListInGrid& other);
		bool IsNotEqual(const DataFeedingInfoItemListInGrid& other);
		DataFeedingItemInfo* GetAt(int index);

		DataFeedingInfoItemListInGrid& operator=(const DataFeedingInfoItemListInGrid& source);
		bool operator==(const DataFeedingInfoItemListInGrid& other);
		bool operator!=(const DataFeedingInfoItemListInGrid& other);
		DataFeedingItemInfo* operator[](int index);

		int GetLength() const;
		int GetCapacity() const;

	public:
		DataFeedingItemInfoList* generalList;

	private:
		Array<DataFeedingItemInfo*> selectedList;
		int length;
		int capacity;
};

inline int DataFeedingInfoItemListInGrid::GetLength() const{
	return this->length;
}

inline int DataFeedingInfoItemListInGrid::GetCapacity() const{
	return this->capacity;
}