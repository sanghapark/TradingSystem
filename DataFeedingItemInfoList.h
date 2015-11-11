// DataFeedingItemInfoList.h
#pragma once

#include "Template/Array.hpp"
#include "DataFeedingItemInfo.h"


class DataFeedingItemInfoList{
	public:
		DataFeedingItemInfoList(int capacity=20);
		DataFeedingItemInfoList(const DataFeedingItemInfoList& source);
		~DataFeedingItemInfoList();

		int FindIndexOfDataFeedingItemInfo(const tstring& broker, const tstring& instrumentCode, const tstring& trType);
		int FindIndexOfItemByID(int id);
		int AddDataFeedingItemInfo(const DataFeedingItemInfo& info);
		void ClearList();
		void DeleteDataFeedingItemInfo(int index);

		int GetItemIndexByRowNumber(int rowIndex);

		bool IsEqual(const DataFeedingItemInfoList& other);
		bool IsNotEqual(const DataFeedingItemInfoList& other);
		DataFeedingItemInfo& GetAt(int index);

		DataFeedingItemInfoList& operator=(const DataFeedingItemInfoList& source);
		bool operator==(const DataFeedingItemInfoList& other);
		bool operator!=(const DataFeedingItemInfoList& other);
		DataFeedingItemInfo& operator[](int index);

		int GetLength() const;
		int GetCapacity() const;
	
	public:

	private:
		Array<DataFeedingItemInfo> list;
		int length;
		int capacity;
};

inline int DataFeedingItemInfoList::GetLength() const{
	return this->length;
}

inline int DataFeedingItemInfoList::GetCapacity() const{
	return this->capacity;
}