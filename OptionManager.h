// OptionManager.h

#pragma once


#include "OptionStrategyList.h"


class OptionManager{
public:
	OptionManager();
	OptionManager(const OptionManager& source);
	~OptionManager();

	int CreateOptionStrategy(const tstring& strategyName);
	int AddOptionStrategy(const PositionList& positionList);
	int DeleteOptionStrategy(int index);
	int FindOptionStrategy(const tstring& name);

	bool IsEqual(const OptionManager& other);
	bool IsNotEqual(const OptionManager& other);

	OptionManager& operator=(const OptionManager& source);
	bool operator==(const OptionManager& other);
	bool operator!=(const OptionManager& other);

	OptionStrategyList& GetOptionStrategyList() const;


private:
	OptionStrategyList optionStrategyList;

};


inline OptionStrategyList& OptionManager::GetOptionStrategyList() const{
	return const_cast<OptionStrategyList&>(this->optionStrategyList);
}