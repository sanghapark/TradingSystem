// DataBunch.h

#pragma once

#include "Template/Array.hpp"
#include "DataTypeDefinition.h"
#include "FileWriter.h"
#include "DataBunchItem.h"

class DataFeedingItemInfo;
class DataFeedingItemInfoList;

class DataBunch{
	public:
		DataBunch(int capacity  = 10);
		DataBunch(int id, const tstring& name, bool saveYN, int capacity=10);
		DataBunch(const DataBunch& source);
		~DataBunch();

		void ClearList();
		int AddItemID(const DataBunchItem& item);
		bool IsIn(int itemID);
		bool CreateDir();
		void GetNotifiedByDataFeedingItemInfo(DataFeedingItemInfo* pItem);

		bool IsEqual(const DataBunch& other);
		bool IsNotEqual(const DataBunch& other);
		DataBunchItem& GetAt(int index);

		DataBunch& operator=(const DataBunch& source);
		bool operator==(const DataBunch& other);
		bool operator!=(const DataBunch& other);
		DataBunchItem& operator[](int index);

		FileWriter& GetFileWriter() const;
		int GetID() const;
		bool GetSaveYN() const;
		int GetLength() const;
		int GetCapacity() const;
		tstring& GetName() const;

		void SetSaveYN(bool saveYN);
		void SetName(const tstring& name);

	private:
		FileWriter fileWriter;
		int id;
		bool saveYN;
		tstring name;
		Array<DataBunchItem> items;
		int length;
		int capacity;
};


inline FileWriter& DataBunch::GetFileWriter() const{
	return const_cast<FileWriter&>(this->fileWriter);
}


inline int DataBunch::GetID() const{
	return this->id;
}


inline bool DataBunch::GetSaveYN() const{
	return this->saveYN;
}

inline int DataBunch::GetLength() const{
	return this->length;
}

inline int DataBunch::GetCapacity() const{
	return this->capacity;
}

inline tstring& DataBunch::GetName() const{
	return const_cast<tstring&>(this->name);
}

inline void DataBunch::SetSaveYN(bool saveYN){
	this->saveYN = saveYN;
}

inline void DataBunch::SetName(const tstring& name){
	this->name = name;
}