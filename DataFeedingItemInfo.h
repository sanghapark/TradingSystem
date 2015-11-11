#pragma once

//#include "Instrument.h"
#include "DataTypeDefinition.h"
#include "DataBlock.h"
#include "DataBunchesToNotify.h"

class Instrument;

class DataFeedingItemInfo{
	public:
		DataFeedingItemInfo();
		DataFeedingItemInfo(int id,
							const tstring& broker,
							const tstring& instrumentType,
							const tstring& instrumentName,
							const tstring& instrumentCode, 
							const tstring& trType, 
							const tstring& trCode,
							bool autoYN);
		DataFeedingItemInfo(const DataFeedingItemInfo& source);
		~DataFeedingItemInfo();

		int AssignAdviseFeedingStatus(bool status);
		int AssignUnadviseFeedingStatus(bool status);
		void AssignDataBlock(void* dataBlock, int size);
		int AddDataBunchToNotify(DataBunch* pDataBunch);
		void NotifyDataBunches();

		bool IsEqual(const DataFeedingItemInfo& other);
		bool IsNotEqual(const DataFeedingItemInfo& other);
		DataFeedingItemInfo& operator=(const DataFeedingItemInfo& source);
		bool operator==(const DataFeedingItemInfo& other);
		bool operator!=(const DataFeedingItemInfo& other);

		int GetID() const;
		tstring& GetBroker() const;
		tstring& GetInstrumentType() const;
		tstring& GetInstrumentName() const;
		tstring& GetInstrumentCode() const;
		tstring& GetTRType() const;
		tstring& GetTRCode() const;
		bool GetAutoYN() const;
		int GetRowIndex() const;
		int GetFeedingStatus() const;
		bool GetSaveSatus() const;
		DataBlock& GetDataBlock() const;
		DataBunchesToNotify& GetDataBunchesToNotify() const;

		void SetID(int id);
		void SetBroker(const tstring& broker);
		void SetInstrumentType(const tstring& instrumentType);
		void SetInstrumentName(const tstring& instrumentName);
		void SetInstrumentCode(const tstring& instrumentCode);
		void SetTRType(const tstring& trType);
		void SetTRCode(const tstring& trCode);
		void SetAutoYN(bool autoYN);
		void SetRowIndex(int rowIndex);
		void SetFeedingStatus(int feedingStatus);
		void SetSaveStatus(bool saveStatus);

	private:
		// 공개정보
		tstring broker;
		tstring instrumentType;
		tstring instrumentName;
		tstring instrumentCode;
		tstring trType;
		tstring trCode;
		bool autoYN;

		// 
		DataBlock dataBlock;
		DataBunchesToNotify dataBunchesToNotify;

		// 내부정보
		int id;
		int rowIndex;
		int feedingStatus; // -1:조회안함 , 0:조회시 실패 , 1:조회시 성공
		bool saveStatus;
};


inline int DataFeedingItemInfo::GetID() const{
	return this->id;
}

inline tstring& DataFeedingItemInfo::GetBroker() const{
	return const_cast<tstring&>(this->broker);
}

inline tstring& DataFeedingItemInfo::GetInstrumentType() const{
	return const_cast<tstring&>(this->instrumentType);
}

inline tstring& DataFeedingItemInfo::GetInstrumentName() const{
	return const_cast<tstring&>(this->instrumentName);
}

inline tstring& DataFeedingItemInfo::GetInstrumentCode() const{
	return const_cast<tstring&>(this->instrumentCode);
}


inline tstring& DataFeedingItemInfo::GetTRType() const{
	return const_cast<tstring&>(this->trType);
}

inline tstring& DataFeedingItemInfo::GetTRCode() const{
	return const_cast<tstring&>(this->trCode);
}

inline bool DataFeedingItemInfo::GetAutoYN() const{
	return this->autoYN;
}

inline int DataFeedingItemInfo::GetRowIndex() const{
	return this->rowIndex;
}


inline int DataFeedingItemInfo::GetFeedingStatus() const{
	return this->feedingStatus;
}

inline bool DataFeedingItemInfo::GetSaveSatus() const{
	return this->saveStatus;
}

inline DataBlock& DataFeedingItemInfo::GetDataBlock() const{
	return const_cast<DataBlock&>(this->dataBlock);
}


inline DataBunchesToNotify& DataFeedingItemInfo::GetDataBunchesToNotify() const{
	return const_cast<DataBunchesToNotify&>(this->dataBunchesToNotify);
}


// Setters

inline void DataFeedingItemInfo::SetID(int id){
	this->id = id;
}


inline void DataFeedingItemInfo::SetBroker(const tstring& broker){
	this->broker = broker;
}


inline void DataFeedingItemInfo::SetInstrumentType(const tstring& instrumentType){
	this->instrumentType = instrumentType;
}

inline void DataFeedingItemInfo::SetInstrumentName(const tstring& instrumentName){
	this->instrumentName = instrumentName;
}

inline void DataFeedingItemInfo::SetInstrumentCode(const tstring& instrumentCode){
	this->instrumentCode = instrumentCode;
}


inline void DataFeedingItemInfo::SetTRType(const tstring& trType){
	this->trType = trType;
}

inline void DataFeedingItemInfo::SetTRCode(const tstring& trCode){
	this->trCode = trCode;
}

inline void DataFeedingItemInfo::SetAutoYN(bool autoYN){
	this->autoYN = autoYN;
}


inline void DataFeedingItemInfo::SetRowIndex(int rowIndex){
	this->rowIndex = rowIndex;
}


inline void DataFeedingItemInfo::SetFeedingStatus(int feedingStatus){
	this->feedingStatus = feedingStatus;
}

inline void DataFeedingItemInfo::SetSaveStatus(bool saveStatus){
	this->saveStatus = saveStatus;
}