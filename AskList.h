// AskList.h

#pragma once

#include "Template/Array.hpp"
#include "Ask.h"

class AskList{
	public:
		AskList(int length=10);
		AskList(const AskList& source);
		~AskList();

		void Update(const Ask& ask, int index);

		bool IsEqual(const AskList& other);
		bool IsNotEqual(const AskList& other);
		Ask& GetAt(int index);

		AskList& operator=(const AskList& source);
		bool operator==(const AskList& other);
		bool operator!=(const AskList& other);
		Ask& operator[](int index);
	
		int GetLength() const;
		int GetCapacity() const;
	private:
		Array<Ask> asks;
		int length;
};

inline int AskList::GetLength() const{
	return this->length;
}