// InstrumentInfoXMLController.h

#pragma once


#include "InstrumentList.h"

class InstrumentInfoXMLController{
	public:
	

		InstrumentInfoXMLController();
		InstrumentInfoXMLController(const InstrumentInfoXMLController& source);
		~InstrumentInfoXMLController();

		InstrumentList ReadInstrumentList();
		//void SaveInstrumentList();

	
	private:

};