// PositionList.h

#pragma once

#include <string>
#include "Template\Array.hpp"
#include "Position.h"


using namespace std;

class PositionList{
	public:
		PositionList(int capacity=10);
		PositionList(const tstring& name, int capacity=10);
		PositionList(const PositionList& source);
		~PositionList();

		int AddPosition(Position* m_position);
		int DeletePosition(int index);
		int FindPosition(Position* position);
		int FindPositionByPositionNumber(int positoinNumber);
		double GetStrikePriceMin();
		double GetStrikePriceMax();

		bool IsEqual(const PositionList& other);
		bool IsNotEqual(const PositionList& other);
		Position* GetAt(int index);

		PositionList& operator=(const PositionList& source);
		bool operator==(const PositionList& other);
		bool operator!=(const PositionList& other);
		Position* operator[](int index);

		tstring& GetName() const;
		int GetLength() const;
		int GetCapacity() const;

		void SetName(const tstring& name);

	private:
		tstring name;
		Array<Position*> positions;
		int length;
		int capacity;
};


inline tstring& PositionList::GetName() const{
	return const_cast<tstring&>(this->name);
}


inline int PositionList::GetLength() const{
	return this->length;
}

inline int PositionList::GetCapacity() const{
	return this->capacity;
}


inline void PositionList::SetName(const tstring& name){
	this->name = name;
}