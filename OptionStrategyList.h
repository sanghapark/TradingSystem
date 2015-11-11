// OptionStrategyList.h

#pragma once
#include "Template\Array.hpp"
#include "PositionList.h"

class OptionStrategyList{
public:
	OptionStrategyList(int capacity=10);
	OptionStrategyList(const OptionStrategyList& source);
	~OptionStrategyList();

	int CreateOptionStrategy(const tstring& strategyName);
	int AddOptionStrategy(const PositionList& positionList);
	int DeleteOptionStrategy(int index);
	int FindOptionStrategy(const tstring& name);
	
	bool IsEqual(const OptionStrategyList& other);
	bool IsNotEqual(const OptionStrategyList& other);
	PositionList& GetAt(int index);

	OptionStrategyList& operator=(const OptionStrategyList& source);
	bool operator==(const OptionStrategyList& other);
	bool operator!=(const OptionStrategyList& other);

	int GetLength() const;
	int GetCapacity() const;

private:
	Array<PositionList> optionStrategies;
	int length;
	int capacity;
};



inline int OptionStrategyList::GetLength() const{
	return this->length;
}

inline int OptionStrategyList::GetCapacity() const{
	return this->capacity;
}