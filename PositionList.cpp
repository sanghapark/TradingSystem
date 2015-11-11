// PositionList.cpp

#include "PositionList.h"
#include "Constants.h"
#include "LongPosition.h"
#include "ShortPosition.h"

PositionList::PositionList(int capacity)
	:positions(capacity){
	this->length = 0;
	this->capacity = capacity;
}

PositionList::PositionList(const tstring& name, int capacity)
	:name(name),
	positions(capacity){
	this->length = 0;
	this->capacity = capacity;
}


PositionList::PositionList(const PositionList& source)
	:name(source.name),
	positions(source.capacity){

	for(int i=0; i<source.length; i++){
		Position* temp = (const_cast<PositionList&>(source)).GetAt(i);

		if(temp->GetPositionType().compare(LONG_POSITION)==0){
			LongPosition* tempLongPosition = (LongPosition*)temp;
			this->positions[i] = new LongPosition(*tempLongPosition);
		}
		else if((temp->GetPositionType().compare(SHORT_POSITION)==0)){
			ShortPosition* tempShortPosition = (ShortPosition*)temp;
			this->positions[i] = new ShortPosition(*tempShortPosition);
		}
	}

	this->length = source.length;
	this->capacity = source.capacity;
}


PositionList::~PositionList(){
	for(int i=0; i<this->length; i++){
		if(this->positions[i]!=0){
			delete this->positions[i];
		}
	}
}


int PositionList::AddPosition(Position* m_position){
	int index = -1;
	if(this->length<this->capacity){
		index = this->positions.Store(this->length, m_position);
	}
	else{
		index = this->positions.Insert(this->length, m_position);
		this->capacity++;
	}
	this->length++;
	return index;
}


int PositionList::DeletePosition(int index){
	int ret = this->positions.Delete(index);
	this->length--;
	this->capacity--;
	return ret;
}


int PositionList::FindPosition(Position* position){
	int index= -1;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		if(this->positions.GetAt(i)==position){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}



int PositionList::FindPositionByPositionNumber(int positoinNumber){
	int index=-1;
	bool found = false;
	int i=0;
	while(i<this->length && found==false){
		if(this->positions.GetAt(i)->GetPositionNumber()==positoinNumber){
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}



double PositionList::GetStrikePriceMin(){
	double minStikePrice = -1.0;

	if(this->length>0){
		minStikePrice = this->positions.GetAt(0)->GetOption().GetStrikePrice();
		for(int i=1; i<this->length; i++){
			double other = this->positions.GetAt(i)->GetOption().GetStrikePrice();
			if(minStikePrice>other){
				minStikePrice = other;
			}
		}
	}

	return minStikePrice;
}


double PositionList::GetStrikePriceMax(){
	double maxStikePrice = -1.0;

	if(this->length>0){
		maxStikePrice = this->positions.GetAt(0)->GetOption().GetStrikePrice();
		for(int i=1; i<this->length; i++){
			double other = this->positions.GetAt(i)->GetOption().GetStrikePrice();
			if(maxStikePrice<other){
				maxStikePrice = other;
			}
		}
	}

	return maxStikePrice;
}



bool PositionList::IsEqual(const PositionList& other){
	bool ret = false;
	if( this->name.compare(other.name)==0 &&
		this->positions.IsEqual(other.positions)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool PositionList::IsNotEqual(const PositionList& other){
	bool ret = false;
	if( this->name.compare(other.name)!=0 ||
		this->positions.IsNotEqual(other.positions)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


Position* PositionList::GetAt(int index){
	return this->positions.GetAt(index);
}


PositionList& PositionList::operator=(const PositionList& source){
	this->name = source.name;
	this->positions.Clear();

	PositionList tempList(source);

	this->positions = tempList.positions;

	for(int i=0; i<source.length; i++){
		Position* temp = tempList.GetAt(i);
		if(temp->GetPositionType().compare(LONG_POSITION)==0){
			LongPosition* tempLongPosition = (LongPosition*)temp;
			this->positions[i] = new LongPosition(*tempLongPosition);
		}
		else if((temp->GetPositionType().compare(SHORT_POSITION)==0)){
			ShortPosition* tempShortPosition = (ShortPosition*)temp;
			this->positions[i] = new ShortPosition(*tempShortPosition);
		}
	}


	this->length = tempList.length;
	this->capacity = tempList.capacity;
	return *this;
}


bool PositionList::operator==(const PositionList& other){
	bool ret = false;
	if( this->name == other.name &&
		this->positions == other.positions &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


bool PositionList::operator!=(const PositionList& other){
	bool ret = false;
	if( this->name != other.name ||
		this->positions != other.positions ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}


Position* PositionList::operator[](int index){
	return this->positions[index];
}