// DataBlock.cpp

#include "DataBlock.h"
#include "Constants.h"
#include "./packet/FC0.h"
#include "./packet/FH0.h"
#include "./packet/S3_.h"
#include "./packet/H1_.h"
#include "./packet/OC0.h"
#include "./packet/OH0.h"
#include <afxwin.h>


DataBlock::DataBlock(){
	this->size = 0;
	this->pDataBlock = 0;
}


DataBlock::DataBlock(const tstring& broker, const tstring& trCode){
	this->pDataBlock = 0;
	this->size = 0;
	if (broker.compare(ETRADE) == 0){
		if (trCode.compare(FC0) == 0){
			this->pDataBlock = malloc(sizeof(FC0_OutBlock)); //new FC0_OutBlock();
			this->size = sizeof(FC0_OutBlock);
		}
		else if (trCode.compare(FH0) == 0){
			this->pDataBlock = malloc(sizeof(FH0_OutBlock)); //new FH0_OutBlock();
			this->size = sizeof(FH0_OutBlock);
		}
		else if (trCode.compare(S3_) == 0){
			this->pDataBlock = malloc(sizeof(S3__OutBlock)); //new S3__OutBlock();
			this->size = sizeof(S3__OutBlock);
		}
		else if (trCode.compare(H1_) == 0){
			this->pDataBlock = malloc(sizeof(H1__OutBlock)); //new H1__OutBlock();
			this->size = sizeof(H1__OutBlock);
		}
		else if (trCode.compare(OC0) == 0){
			this->pDataBlock = malloc(sizeof(OC0_OutBlock)); //new OC0_OutBlock();
			this->size = sizeof(OC0_OutBlock);
		}
		else if (trCode.compare(OH0) == 0){
			this->pDataBlock = malloc(sizeof(OH0_OutBlock)); //new OH0_OutBlock();
			this->size = sizeof(OH0_OutBlock);
		}
	}
	else if (broker.compare(WOORI) == 0){
	}
}


DataBlock::DataBlock(const DataBlock& source){
	this->size = source.size;
	this->pDataBlock = malloc(source.size);
	memcpy(this->pDataBlock, source.pDataBlock, sizeof(source.size));
}


DataBlock::~DataBlock(){
	if (this->pDataBlock != 0){
		free(this->pDataBlock);
	}
}


void DataBlock::AssignDataBlock(void* dataBlock, int size){
	if (this->pDataBlock != 0 && size == this->size){
		memcpy(this->pDataBlock, dataBlock, this->size);
	}
	
}


bool DataBlock::IsEqual(const DataBlock& other){
	bool ret = false;
	if (this->size == other.size &&
		memcmp(this->pDataBlock, other.pDataBlock, sizeof(other.size)) == 0){
		ret = true;
	}
	return ret;
}


bool DataBlock::IsNotEqual(const DataBlock& other){
	bool ret = false;
	if (this->size != other.size ||
		memcmp(this->pDataBlock, other.pDataBlock, sizeof(other.size)) != 0){
		ret = true;
	}
	return ret;
}


DataBlock& DataBlock::operator = (const DataBlock& source){
	this->size = source.size;
	if (this->pDataBlock != 0){
		free(this->pDataBlock);
		this->pDataBlock = 0;
	}
	this->pDataBlock = malloc(source.size);
	memcpy(this->pDataBlock, source.pDataBlock, source.size);
	return *this;
}


bool DataBlock::operator == (const DataBlock& other){
	bool ret = false;
	if (this->size == other.size &&
		memcmp(this->pDataBlock, other.pDataBlock, sizeof(other.size)) == 0){
		ret = true;
	}
	return ret;
}


bool DataBlock::operator != (const DataBlock& other){
	bool ret = false;
	if (this->size != other.size ||
		memcmp(this->pDataBlock, other.pDataBlock, sizeof(other.size)) != 0){
		ret = true;
	}
	return ret;
}