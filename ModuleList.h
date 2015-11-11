// ModuleList.h

#ifndef _MODULE_LIST_H
#define _MODULE_LIST_H

#include "DataFeederList.h"
#include "stdafx.h"

class ModuleList{
	public:
		ModuleList();
		ModuleList(const ModuleList& source);
		~ModuleList();

		void LoadModuleList();

		ModuleList& operator=(const ModuleList& source);
		bool operator==(const ModuleList& other);
		bool operator!=(const ModuleList& other);
		bool IsEqual(const ModuleList& other);
		bool IsNotEqual(const ModuleList& other);

		DataFeederList& GetDataFeederList() const;

	private:
		DataFeederList dataFeederList;
};

inline DataFeederList& ModuleList::GetDataFeederList() const{
	return const_cast<DataFeederList&>(this->dataFeederList);
}


#endif