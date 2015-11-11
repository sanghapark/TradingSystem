// InstrumentManager.h

#pragma once

#include "InstrumentList.h"
#include "InstrumentInfoXMLController.h"

class InstrumentManager{
	public:
		InstrumentManager();
		InstrumentManager(const InstrumentManager& source);
		~InstrumentManager();

		void InitializeManager();
		InstrumentList& LoadInstrumentInfo();
		//void SaveInstrumentInfo();

		int AddInstrument(const Instrument& instrument);
		InstrumentList GetInstrumentListByType(const tstring& type);

		bool IsEqual(const InstrumentManager& other);
		bool IsNotEqual(const InstrumentManager& other);

		InstrumentManager& operator=(const InstrumentManager& source);
		bool operator==(const InstrumentManager& other);
		bool operator!=(const InstrumentManager& other);

		InstrumentList& GetInstrumentList() const;
		InstrumentInfoXMLController& GetXMLController() const;
	private:
		InstrumentList instrumentList;
		InstrumentInfoXMLController xmlController;
};


inline InstrumentList& InstrumentManager::GetInstrumentList() const{
	return const_cast<InstrumentList&>(this->instrumentList);
}


inline InstrumentInfoXMLController& InstrumentManager::GetXMLController() const{
	return const_cast<InstrumentInfoXMLController&>(this->xmlController);
}