// InstrumentInfoXMLController.cpp


#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>

#include "InstrumentInfoXMLController.h"
#include "File.h"
#include "Instrument.h"
#include "TradingSystemManager.h"

InstrumentInfoXMLController::InstrumentInfoXMLController(){
}


InstrumentInfoXMLController::InstrumentInfoXMLController(const InstrumentInfoXMLController& source){
}


InstrumentInfoXMLController::~InstrumentInfoXMLController(){
}


InstrumentList InstrumentInfoXMLController::ReadInstrumentList(){
	using boost::property_tree::ptree;

	ptree pt;
	read_xml(INSTRUMENT_INFO, pt);

	InstrumentList ret;

	BOOST_FOREACH(ptree::value_type const& item, pt.get_child(_T("InstrumentInfo"))){
		if(item.first == _T("Instrument")){
			tstring type(item.second.get<tstring>(TEXT("<xmlattr>.type")));
			tstring name(item.second.get<tstring>(TEXT("<xmlattr>.name")));
			tstring code(item.second.get<tstring>(TEXT("<xmlattr>.code")));
			if(name.compare(_T("KOSPI200Index"))==0){
				code = instrumentCodes.GetKOSPI200IndexFuturesCode();
			}
			int contractFeedingSourceID =  item.second.get<int>(TEXT("<xmlattr>.contract"));
			int lboFeedingSourceID =  item.second.get<int>(TEXT("<xmlattr>.limitOrderBook"));
			Instrument instrument(type, code, name, contractFeedingSourceID, lboFeedingSourceID);
			ret.AddInstrument(instrument);
		}
	}
	return ret;
}