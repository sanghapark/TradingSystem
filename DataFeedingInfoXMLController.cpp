// DataFeedingInfoXMLController.cpp

#include "DataFeedingInfoXMLController.h"
#include "DataConverter.h"
#include "File.h"
#include "InstrumentCodeMaker.h"
#include "DataFeedingInfoManager.h"
#include "TradingSystemManager.h"

#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

DataFeedingInfoXMLController::DataFeedingInfoXMLController(DataFeedingInfoManager* p_mDataFeedingInfoManager){
	this->p_mDataFeedingInfoManager =p_mDataFeedingInfoManager;
}


DataFeedingInfoXMLController::DataFeedingInfoXMLController(const DataFeedingInfoXMLController& source){
	this->p_mDataFeedingInfoManager = source.p_mDataFeedingInfoManager;
}


DataFeedingInfoXMLController::~DataFeedingInfoXMLController(){
}



//DataFeedingItemInfoList DataFeedingInfoXMLController::ReadDataFeedingItemList(){
//	DataFeedingItemInfoList dataFeedingItemInfoList;
//	DataConverter converter;
//
//	tifstream fileOpen(DATA_FEEDING_INFO);
//	tstringstream buffer;
//	buffer << fileOpen.rdbuf();
//	fileOpen.close();
//	tstring content(buffer.str());
//	this->doc.parse<0>(&content[0]);
//
//	// GetRootNode
//	xml_node<tchar>* pRoot = this->doc.first_node(TEXT("DataFeedingInfo"));  // DataFeedingInfo
//	xml_node<tchar>* pDataFeedingItems = pRoot->first_node(); // DataFeedingItems
//	xml_node<tchar>* pItem;
//
//	xml_node<tchar>* pDataBunches = pDataFeedingItems->next_sibling();
//	xml_node<tchar>* pDataBunch = pDataBunches->first_node();
//	xml_node<tchar>* pData = pDataBunch->first_node();
//
//	// DataFeedingItems Iterate
//	for( pItem = pDataFeedingItems->first_node(); pItem; pItem = pItem->next_sibling()){		
//		int id;
//		tstring broker, instrument, name, code, trType, trCode;
//		bool autoYN;
//
//		xml_attribute<tchar>* pItemAttr = pItem->first_attribute();
//		id = converter.ConvertStringToInt(pItemAttr->value());
//
//		pItemAttr = pItemAttr->next_attribute();
//		broker = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		instrument = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		name = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		code = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		trType = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		trCode = pItemAttr->value();
//		
//		pItemAttr = pItemAttr->next_attribute();
//		autoYN = converter.ConvertStringToBool(pItemAttr->value());
//
//		DataFeedingItemInfo item(id, broker, instrument, name, code, trType, trCode, autoYN);
//		dataFeedingItemInfoList.AddDataFeedingItemInfo(item);
//	}
//
//	this->doc.clear();
//
//	dataFeedingItemInfoList.GetAt(10).SetInstrumentCode(InstrumentCodeMaker::MakeNearestKOSPI200IndexFuturesCode());
//	dataFeedingItemInfoList.GetAt(11).SetInstrumentCode(InstrumentCodeMaker::MakeNearestKOSPI200IndexFuturesCode());
//
//	return dataFeedingItemInfoList;
//}


DataFeedingItemInfoList DataFeedingInfoXMLController::ReadDataFeedingItemList(){
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(DATA_FEEDING_INFO, pt);

	DataFeedingItemInfoList ret;

	BOOST_FOREACH(ptree::value_type const& item, pt.get_child(TEXT("DataFeedingInfo.DataFeedingItemList"))){
		if(item.first == TEXT("Item")){
			int id = item.second.get<int>(TEXT("<xmlattr>.id"));
			tstring broker(item.second.get<tstring>(TEXT("<xmlattr>.broker")));
			tstring type(item.second.get<tstring>(TEXT("<xmlattr>.type")));
			tstring name(item.second.get<tstring>(TEXT("<xmlattr>.name")));
			tstring code(item.second.get<tstring>(TEXT("<xmlattr>.code")));
			tstring trType(item.second.get<tstring>(TEXT("<xmlattr>.trType")));
			tstring trCode(item.second.get<tstring>(TEXT("<xmlattr>.trCode")));
			bool autoYN = item.second.get<bool>(TEXT("<xmlattr>.auto"));
			if(id==11 || id==12){
				code = this->p_mDataFeedingInfoManager->p_mTradingSystemManager->GetInstrumentCodeMaker().GetKOSPI200IndexFuturesCode();
			}
			DataFeedingItemInfo itemToAdd(id,broker, type, name, code, trType, trCode, autoYN);
			ret.AddDataFeedingItemInfo(itemToAdd);
		}
	}
	return ret;
}


//DataBunchList DataFeedingInfoXMLController::ReadDataBunchList(){
//	DataConverter converter;
//	DataBunchList dataBunchList;
//
//	tifstream fileOpen(DATA_FEEDING_INFO);
//	tstringstream buffer;
//	buffer << fileOpen.rdbuf();
//	fileOpen.close();
//	tstring content(buffer.str());
//	this->doc.parse<0>(&content[0]);
//
//	// GetRootNode
//	xml_node<tchar>* pRoot = this->doc.first_node();  // DataFeedingInfo
//	xml_node<tchar>* pDataFeedingItems = pRoot->first_node(); // DataFeedingItems
//	xml_node<tchar>* pDataBunches = pDataFeedingItems->next_sibling();
//	xml_node<tchar>* pDataBunch = pDataBunches->first_node();
//	xml_node<tchar>* pData = pDataBunch->first_node();
//
//
//	for(pDataBunch = pDataBunches->first_node(); pDataBunch; pDataBunch = pDataBunch->next_sibling()){
//		tstring name;
//		bool saveYN;
//		DataBunch dataBunch;
//
//		xml_attribute<tchar>* pDataBunchAttr = pDataBunch->first_attribute();
//		name = pDataBunchAttr->value();
//		saveYN = converter.ConvertStringToBool(pDataBunchAttr->next_attribute()->value());
//
//		dataBunch.SetName(name);
//		dataBunch.SetSaveYN(saveYN);
//
//		for(pData = pDataBunch->first_node(); pData; pData->next_sibling()){
//			int itemID;
//
//			xml_attribute<tchar>* pDataAttr = pData->first_attribute();
//			itemID = converter.ConvertStringToInt(pDataAttr->value());
//			if(dataBunch.IsIn(itemID)==false){
//				dataBunch.AddItemID(itemID);
//			}
//		}
//		
//		dataBunchList.AddDataBunch(dataBunch);
//	}
//	this->doc.clear();
//	return dataBunchList;
//}

DataBunchList DataFeedingInfoXMLController::ReadDataBunchList(){
	DataBunchList dataBunchList;
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(DATA_FEEDING_INFO, pt);

	ptree nodeDataBunch = pt.get_child(TEXT("DataFeedingInfo.DataBunchList")); 

	BOOST_FOREACH(ptree::value_type const& dataBunchNode, nodeDataBunch){

		if(dataBunchNode.first == TEXT("DataBunch")){
			int id = dataBunchNode.second.get<int>(TEXT("<xmlattr>.id"));
			tstring name(dataBunchNode.second.get<tstring>(TEXT("<xmlattr>.name")));
			bool saveYN = dataBunchNode.second.get<bool>(TEXT("<xmlattr>.save"));
			
			DataBunch dataBunch(id, name, saveYN);
			//ptree dataNodeTemp = nodeDataBunch.get_child("DataBunch");
			BOOST_FOREACH(ptree::value_type const& dataNode, dataBunchNode.second){
				if(dataNode.first == TEXT("Data")){
					int itemID = dataNode.second.get<int>(TEXT("<xmlattr>.itemID"));
					DataBunchItem item(itemID);
					dataBunch.AddItemID(item);
				}
			}
			dataBunchList.AddDataBunch(dataBunch);

		}
	}
	return dataBunchList;
}


//void DataFeedingInfoXMLController::SaveDataFeedingItemInfoList(const DataFeedingItemInfoList& dataFeedingItemInfoList){
//	DataConverter converter;
//
//	tifstream fileOpen(DATA_FEEDING_INFO);
//	tstringstream buffer;
//	buffer << fileOpen.rdbuf();
//	fileOpen.close();
//	tstring content(buffer.str());
//	this->doc.parse<0>(&content[0]);
//
//	// clear 기존 데이터
//	this->ClearDataFeedingItemList();
//
//	// GetRootNode
//	xml_node<tchar>* pRoot = this->doc.first_node();  // DataFeedingInfo
//	xml_node<tchar>* pDataFeedingItemList = pRoot->first_node();
//	xml_node<tchar>* item = this->doc.allocate_node(node_element, TEXT("Item"));
//
//	for(int i=0; i<dataFeedingItemInfoList.GetLength(); i++){
//		DataFeedingItemInfo& itemInfo = const_cast<DataFeedingItemInfoList&>(dataFeedingItemInfoList).GetAt(i);
//		pDataFeedingItemList->append_node(item);
//		tstring id = converter.ConvertIntToString(i+1);
//		item->append_attribute(this->doc.allocate_attribute(TEXT("id"), id.c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("broker"), itemInfo.GetBroker().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("type"), itemInfo.GetInstrumentType().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("name"), itemInfo.GetInstrumentName().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("code"), itemInfo.GetInstrumentCode().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("trType"), itemInfo.GetTRType().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("trCode"), itemInfo.GetTRCode().c_str()));
//		item->append_attribute(this->doc.allocate_attribute(TEXT("auto"), converter.ConvertBoolToString(itemInfo.GetAutoYN()).c_str()));
//	}
//
//	tofstream file_stored(DATA_FEEDING_INFO);
//	file_stored << this->doc;
//	file_stored.close();
//
//	this->doc.clear();
//}


void DataFeedingInfoXMLController::SaveDataFeedingItemInfoList(const DataFeedingItemInfoList& dataFeedingItemInfoList){
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(DATA_FEEDING_INFO, pt);

	ptree& nodeDataFeedingItemList = pt.get_child(TEXT("DataFeedingInfo.DataFeedingItemList"));
	nodeDataFeedingItemList.clear();

	for(int i=0; i<dataFeedingItemInfoList.GetLength(); i++){
		DataFeedingItemInfo& item = const_cast<DataFeedingItemInfoList&>(dataFeedingItemInfoList).GetAt(i);
		ptree& nodeItem = nodeDataFeedingItemList.add(TEXT("DataFeedingInfo.DataFeedingItemList.Item"), TEXT(""));
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.id"), item.GetID());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.broker"), item.GetBroker());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.type"), item.GetInstrumentType());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.name"), item.GetInstrumentName());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.code"), item.GetInstrumentCode());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.trType"), item.GetTRType());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.trCode"), item.GetTRCode());
		nodeDataFeedingItemList.put(TEXT("<xmlattr>.auto"), item.GetAutoYN());
	}
	write_xml(DATA_FEEDING_INFO, pt);
}



//void DataFeedingInfoXMLController::SaveDataBunchList(const DataBunchList& dataBunchList){
//	DataConverter converter;
//
//	tifstream fileOpen(DATA_FEEDING_INFO);
//	tstringstream buffer;
//	buffer << fileOpen.rdbuf();
//	fileOpen.close();
//	tstring content(buffer.str());
//	this->doc.parse<0>(&content[0]);
//
//	// Clear 기존 데이터
//	this->ClearDataBunchList();
//
//	// GetRootNode
//	xml_node<tchar>* pRoot = this->doc.first_node();  // DataFeedingInfo
//	xml_node<tchar>* pDataBunchList = pRoot->last_node();
//	xml_node<tchar>* pDataBunch = this->doc.allocate_node(node_element, TEXT("DataBunch"));
//	xml_node<tchar>* pData = this->doc.allocate_node(node_element, TEXT("Data"));
//
//	for(int i=0; i<dataBunchList.GetLength(); i++){
//		DataBunch& dataBunch = const_cast<DataBunchList&>(dataBunchList).GetAt(i);
//		pDataBunchList->append_node(pDataBunch);
//		pDataBunch->append_attribute(this->doc.allocate_attribute(TEXT("name"), dataBunch.GetName().c_str()));
//		pDataBunch->append_attribute(this->doc.allocate_attribute(TEXT("name"), converter.ConvertBoolToString(dataBunch.GetSaveYN()).c_str()));
//		for(int j=0; j<dataBunch.GetLength(); j++){
//			pDataBunch->append_node(pData);
//			pData->append_attribute(this->doc.allocate_attribute(TEXT("itemID"), converter.ConvertIntToString(dataBunch.GetAt(j)).c_str()));
//		}
//	}
//	tofstream file_stored(DATA_FEEDING_INFO);
//	file_stored << this->doc;
//	file_stored.close();
//	this->doc.clear();
//}

void DataFeedingInfoXMLController::SaveDataBunchList(const DataBunchList& dataBunchList){
	using boost::property_tree::ptree;
	ptree pt;
	read_xml(DATA_FEEDING_INFO, pt);

	ptree& nodeDataBunchList = pt.get_child(TEXT("DataFeedingInfo.DataBunchList"));
	nodeDataBunchList.clear();

	for(int i=0; i<dataBunchList.GetLength(); i++){
		DataBunch& dataBunch = const_cast<DataBunchList&>(dataBunchList).GetAt(i);
		ptree& nodeDataBunch = nodeDataBunchList.add(TEXT("DataFeedingInfo.DataBunchList.DataBunch"), TEXT(""));
		nodeDataBunch.put(TEXT("<xmlattr>.id"), dataBunch.GetID());
		nodeDataBunch.put(TEXT("<xmlattr>.name"), dataBunch.GetName());
		nodeDataBunch.put(TEXT("<xmlattr>.save"), dataBunch.GetSaveYN());
		for(int j=0; j<dataBunch.GetLength(); j++){
			int itemID = const_cast<DataBunch&>(dataBunch).GetAt(j).GetItemID();
			ptree& nodeData = nodeDataBunch.add(TEXT("DataFeedingInfo.DataBunchList.DataBunch.Data"), TEXT(""));
			nodeData.put(TEXT("<xmlattr>.itemID"), itemID);
		}
	}
	write_xml(DATA_FEEDING_INFO, pt);
}



//void DataFeedingInfoXMLController::ClearDataFeedingItemList(){
//	xml_node<tchar>* pRoot = doc.first_node();  // DataFeedingInfo
//	xml_node<tchar>* pDataFeedingItems = pRoot->first_node(); // DataFeedingItems
//
//	pDataFeedingItems->remove_all_nodes();
//	pDataFeedingItems->remove_all_attributes();
//
//	tofstream file_stored(DATA_FEEDING_INFO);
//	file_stored << doc;
//	file_stored.close();
//}
//
//
//
//void DataFeedingInfoXMLController::ClearDataBunchList(){
//	xml_node<tchar>* pRoot = doc.first_node();  // DataFeedingInfo
//	xml_node<tchar>* pDataFeedingItems = pRoot->first_node(); // DataFeedingItems
//	xml_node<tchar>* pDataBunches = pDataFeedingItems->next_sibling();
//
//	pDataBunches->remove_all_nodes();
//	pDataBunches->remove_all_attributes();
//
//	tofstream file_stored(DATA_FEEDING_INFO);
//	file_stored << doc;
//	file_stored.close();
//}




bool DataFeedingInfoXMLController::IsEqual(const DataFeedingInfoXMLController& other){
	bool ret = false;
	if(this->p_mDataFeedingInfoManager == other.p_mDataFeedingInfoManager){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoXMLController::IsNotEqual(const DataFeedingInfoXMLController& other){
	bool ret = false;
	if(this->p_mDataFeedingInfoManager != other.p_mDataFeedingInfoManager){
		ret = true;
	}
	return ret;
}


DataFeedingInfoXMLController& DataFeedingInfoXMLController::operator=(const DataFeedingInfoXMLController& source){
	this->p_mDataFeedingInfoManager = source.p_mDataFeedingInfoManager;
	return *this;
}


bool DataFeedingInfoXMLController::operator==(const DataFeedingInfoXMLController& other){
	bool ret = false;
	if(this->p_mDataFeedingInfoManager == other.p_mDataFeedingInfoManager){
		ret = true;
	}
	return ret;
}


bool DataFeedingInfoXMLController::operator!=(const DataFeedingInfoXMLController& other){
	bool ret = false;
	if(this->p_mDataFeedingInfoManager != other.p_mDataFeedingInfoManager){
		ret = true;
	}
	return ret;
}