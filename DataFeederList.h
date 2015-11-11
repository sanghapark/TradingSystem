// DataFeederList.h

#ifndef _DATA_FEEDER_LIST_H
#define _DATA_FEEDER_LIST_H

#include "tstring.h"
#include "Template/Array.hpp"




class DataFeederList{
	public:
		DataFeederList(int capacity=10);
		DataFeederList(const DataFeederList& source);
		~DataFeederList();

		void LoadDataFeederModuleList();

		int AddBrokerName(const tstring& name);

		DataFeederList& operator=(const DataFeederList& source);
		bool operator==(const DataFeederList& other);
		bool operator!=(const DataFeederList& other);
		bool IsEqual(const DataFeederList& other);
		bool IsNotEqual(const DataFeederList& other);
		tstring& operator[](int index);
		tstring& GetAt(int index);

		int GetLength() const;
		int GetCapacity() const;

	private:
		Array<tstring> dataFeederArr;
		int length;
		int capacity;
};

inline int DataFeederList::GetLength() const{
	return this->length;
}
inline int DataFeederList::GetCapacity() const{
	return this->capacity;
}

#endif