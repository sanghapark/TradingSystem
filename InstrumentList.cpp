// InstrumentList.cpp

#include "InstrumentList.h"

InstrumentList::InstrumentList(int capacity)
	:instruments(capacity){
	this->length = 0;
	this->capacity = capacity;
}

InstrumentList::InstrumentList(const InstrumentList& source)
	:instruments(source.instruments){
	this->length = source.length;
	this->capacity = source.capacity;
}


InstrumentList::~InstrumentList(){
}


int InstrumentList::AddInstrument(const Instrument& instrument){
	int index = -1;
	if(this->length<this->capacity){
		index = this->instruments.Store(this->length, instrument);
	}
	else{
		index = this->instruments.Insert(this->length, instrument);
		this->capacity++;
	}
	this->length++;
	return index;
}


int InstrumentList::FindInstrument(const tstring& instrumentCode){
	int index = -1;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		Instrument& instrument = this->GetAt(i);
		if(instrument.GetInstrumentCode().compare(instrumentCode)==0){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}


InstrumentList InstrumentList::GetInstrumentListByType(const tstring& instrumentType){
	int count=0;
	for(int i=0; i<this->length; i++){
		Instrument& instrument = this->GetAt(i);
		if(instrument.GetInstrumentType().compare(instrumentType)==0){
			count++;
		}
	}

	InstrumentList ret(count);
	for(int i=0; i<this->length; i++){
		Instrument& instrument = this->GetAt(i);
		if(instrument.GetInstrumentType().compare(instrumentType)==0){
			ret.AddInstrument(instrument);
		}
	}
	return ret;
}


bool InstrumentList::IsEqual(const InstrumentList& other){
	bool ret = false;
	if(this->instruments.IsEqual(other.instruments)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool InstrumentList::IsNotEqual(const InstrumentList& other){
	bool ret = false;
	if(this->instruments.IsNotEqual(other.instruments)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


Instrument& InstrumentList::GetAt(int index){
	return this->instruments.GetAt(index);
}


InstrumentList& InstrumentList::operator=(const InstrumentList& source){
	this->instruments = source.instruments;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}


bool InstrumentList::operator==(const InstrumentList& other){
	bool ret = false;
	if(this->instruments == other.instruments &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool InstrumentList::operator!=(const InstrumentList& other){
	bool ret = false;
	if(this->instruments != other.instruments ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


Instrument& InstrumentList::operator[](int index){
	return this->instruments[index];
}