// InstrumentList.h

#pragma  once

#include "Template/Array.hpp"
#include "Instrument.h"

class InstrumentList{
public:
	InstrumentList(int capacity=10);
	InstrumentList(const InstrumentList& source);
	~InstrumentList();

	int AddInstrument(const Instrument& instrument);
	int FindInstrument(const tstring& instrumentCode);
	InstrumentList GetInstrumentListByType(const tstring& instrumentType);
	
	bool IsEqual(const InstrumentList& other);
	bool IsNotEqual(const InstrumentList& other);
	Instrument& GetAt(int index);

	InstrumentList& operator=(const InstrumentList& source);
	bool operator==(const InstrumentList& other);
	bool operator!=(const InstrumentList& other);
	Instrument& operator[](int index);

	int GetLength() const;
	int GetCapacity() const;

private:
	Array<Instrument> instruments;
	int length;
	int capacity;
};


inline int InstrumentList::GetLength() const{
	return this->length;
}

inline int InstrumentList::GetCapacity() const{
	return this->capacity;
}