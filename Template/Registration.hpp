// Registration.hpp

#ifndef _REGISTRATION_HPP
#define _REGISTRATION_HPP

#include "Template/Array.hpp"

template <typename T>
class Registration{
	public:
		Registration();
		Registration(const Registration<T>& source);
		~Registration();

		T& Register(const T& object);
		bool DeleteObject(int index);
		int FindObject(const T& object);

		bool IsEqual(const Registration<T> other);
		bool IsNotEqual(const Registration<T> other);
		T& GetAt(int index);

		T& operator[](int index);
		Registration<T>& operator=(const Registration<T> source);
		bool operator==(const Registration<T>& other);
		bool operator!=(const Registration<T>& other);

		int GetLength() const;
		int GetCapacity() const;

	private:
		Array<T> objects;
		int length;
		int capacity;
};
template <typename T>
inline int Registration<T>::GetLength() const{
	return this->length;
}
template <typename T>
inline int Registration<T>::GetCapacity() const{
	return this->capacity;
}

template <typename T>
Registration<T>::Registration()
	:objects(10){
	this->length = 0;
	this->capacity = 10;
}

template <typename T>
Registration<T>::Registration(const Registration<T>& source)
	:objects(source.objects){
	this->length = source.length;
	this->capacity = source.capacity;
}

template <typename T>
Registration<T>::~Registration(){
}

template <typename T>
T& Registration<T>::Register(const T& object){
	int index = this->FindObject(object);
	if(index<0){
		if(this->length < this->capacity){
			index = this->objects.Store(this->length, object);
		}
		else{
			index = this->objects.Insert(this->length, object);
			this->capacity++;
		}
		this->length++;
	}
	return this->objects.GetAt(index);
}

template <typename T>
bool Registration<T>::DeleteObject(int index){
	bool ret = false;
	if(index<this->capacity){
		this->objects.Delete(index);
		ret = true;
	}
	return ret;
}

template <typename T>
int Registration<T>::FindObject(const T& object){
	int i=0;
	int index =-1;
	bool found = false;
	while(found==false && i<this->length){
		if(this->objects.GetAt(i)==object){
			found = true;
			index = i;
		}
		i++;
	}
	return index;
}


template <typename T>
bool Registration<T>::IsEqual(const Registration<T> other){
	bool ret =false;
	if( this->objects.IsEqual(other.objects)==true &&
		this->length == other.length &&
		this->capacity == other.capacity){
		ret = true;
	}
	return ret;
}


template <typename T>
bool Registration<T>::IsNotEqual(const Registration<T> other){
	bool ret =false;
	if( this->objects.IsNotEqual(other.objects)==true ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}

template <typename T>
T& Registration<T>::GetAt(int index){
	return this->objects.GetAt(index);
}


template <typename T>
T& Registration<T>::operator[](int index){
	return this->objects[index];
}


template <typename T>
Registration<T>& Registration<T>::operator=(const Registration<T> source){
	this->objects = source.objects;
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}

template <typename T>
bool Registration<T>::operator==(const Registration<T>& other){
	bool ret =false;
	if( this->objects == other.objects &&
		this->length == other.length &&
		this->capacity == other.capacity){
			ret = true;
	}
	return ret;
}


template <typename T>
bool Registration<T>::operator!=(const Registration<T>& other){
	bool ret =false;
	if( this->objects != other.objects ||
		this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	return ret;
}



#endif