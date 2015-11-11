// DataBunchList.h
// 
#pragma once

#include "Template/Array.hpp"
#include "DataTypeDefinition.h"
#include "DataBunch.h"

class DataBunchList{
	public:
		DataBunchList(int capacity = 0);
		DataBunchList(const DataBunchList& source);
		~DataBunchList();

		void Clear();
		int AddDataBunch(const DataBunch& file);
		int FindDataBunch(const tstring& name);
		void InitSaving();
		void EndSaving();

		bool IsEqual(const DataBunchList& other);
		bool IsNotEqual(const DataBunchList& other);
		DataBunch& GetAt(int index);

		DataBunchList& operator=(const DataBunchList& source);
		bool operator==(const DataBunchList& other);
		bool operator!=(const DataBunchList& other);
		DataBunch& operator[](int index);

		tstring& GetDirectoryForSaving() const;
		int GetLength() const;
		int GetCapacity() const;

		void SetDirectoryForSaving(const tstring& directoryForSaving);

	private:
		tstring directoryForSaving;
		Array<DataBunch> bunches;
		int length;
		int capacity;
};

inline tstring& DataBunchList::GetDirectoryForSaving() const{
	return const_cast<tstring&>(this->directoryForSaving);
}


inline int DataBunchList::GetLength() const{
	return this->length;
}

inline int DataBunchList::GetCapacity() const{
	return this->capacity;
}

inline void DataBunchList::SetDirectoryForSaving(const tstring& directoryForSaving){
	this->directoryForSaving = directoryForSaving;
}