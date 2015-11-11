// DataBlock.h

#pragma once

#include "DataTypeDefinition.h"

class DataFeedingItemInfo;

class DataBlock{
	public:
		DataBlock();
		DataBlock(const tstring& broker, const tstring& trCode);
		DataBlock(const DataBlock& source);
		~DataBlock();

		void AssignDataBlock(void* dataBlock, int size);

		bool IsEqual(const DataBlock& other);
		bool IsNotEqual(const DataBlock& other);

		DataBlock& operator=(const DataBlock& source);
		bool operator==(const DataBlock& other);
		bool operator!=(const DataBlock& other);

		int GetSize() const;
		void* GetPDataBlock() const;

	private:
		int size;
		void* pDataBlock;
};

inline int DataBlock::GetSize() const{
	return this->size;
}

inline void* DataBlock::GetPDataBlock() const{
	return this->pDataBlock;
}