//Array.h
#ifndef _ARRAY_H
#define _ARRAY_H

template <typename T>
class Array{
	public:
		Array(int capcity=100);
		~Array();
		Array(const Array& source);

		T& operator[](int index);
		Array& operator =(const Array& source);
		bool operator==(const Array& other);
		bool operator!=(const Array& other);
		bool IsEqual(const Array& other);
		bool IsNotEqual(const Array& other);
		
		T* GetFront() const;
		int GetLength() const;
		int GetCapacity() const;
		
		T& GetAt(int index);
		int Store(int index, T object);
		int Insert(int index, T object);
		int AppendFromFront(T objedt);
		int AppendFromRear(T object);
		int Modify(int index, T objcet);
		int Delete(int index);
		int DeleteFromFront();
		int DeleteFromRear();
		int BinarySearchUnique(void *key, int (*compare)(void*, void*));
		int LinearSearchUnique(void *key, int (*compare)(void*, void*));
		void LinearSearchDuplicate(void *key, int* (*indexes), int *count, int (*compare)(void*, void*));
		void SelectionSort(int (*compare)(void*, void*));
		void InsertionSort(int (*compare)(void*, void*));
		void MergerSort(Array& one, Array& other, int (*compare)(void*, void*));
		void Clear();

	private:
		T (*front);
		int capacity;
		int length;
};

template <typename T>
inline T* Array<T>::GetFront() const{
	return this->front;
}

template <typename T>
inline int Array<T>::GetLength() const{
	return this->length;
}

template <typename T>
inline int Array<T>::GetCapacity() const{
	return this->capacity;
}

template <typename T>
Array<T>::Array(int capacity){
	this->front = new T[capacity];
	this->capacity = capacity;
	this->length = 0;
}

template <typename T>
Array<T>::~Array(){
	if(this->front!=0){
		delete[] this->front;
		this->front = 0;
	}
}

template <typename T>
Array<T>::Array(const Array& source)
	:length(source.length),
	capacity(source.capacity){
	int i=0;
	this->front = new T[source.capacity];
	while(i<source.length){
		this->front[i]=source.front[i];
		i++;
	}
}

template <typename T>
Array<T>& Array<T>::operator =(const Array& source){
	int i=0;
	if(this->front!=0){
		delete[] this->front;
		this->front = 0;
	}
	this->front = new T[source.capacity];
	while(i<source.length){
		this->front[i] = source.front[i];
		i++;
	}
	this->length = source.length;
	this->capacity = source.capacity;
	return *this;
}

template <typename T>
T& Array<T>::operator [](int index){
	return this->front[index];	
}

template <typename T>
T& Array<T>::GetAt(int index){
	return this->front[index];
}

template <typename T>
int Array<T>::Store(int index, T object){
	this->front[index] = object;
	this->length++;	
	return index;
}

//Insert 정의부
template <typename T>
int Array<T>::Insert(int index, T object){
	int i = 0;
	int j = 0;
	T(*temp);
	temp = new T[this->capacity+1];
	while(i < index){
		temp[j] = this->front[i];
		j++;
		i++;
	}
	j = index +1;
	while(i < this->length){
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if(this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;
	return index;
}

//AppendFromFront 정의부
template <typename T>
int Array<T>::AppendFromFront(T object){
	int i = 0;
	int j = 1;
	T (*temp);
	int index = 0;
	temp = new T[this->capacity +1];
	while(i < this->length){
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if(this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;
	return index;
}

//AppendFromRear 정의부
template <typename T>
int Array<T>::AppendFromRear(T object){
	int i = 0;
	int j = 0;
	int index = this->capacity;
	T (*temp);
	temp = new T[this->capacity +1];
	while(i < this->length){
		temp[j] = this->front[i];
		j++;
		i++;
	}
	if(this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	this->front = temp;
	this->capacity++;
	this->front[index] = object;
	this->length++;
	return index;
}

//Delete 정의부
template <typename T>
int Array<T>::Delete(int index){
	int i = 0;
	int j = 0;
	T (*temp)=0;
	if(this->capacity > 1){
		temp = new T[this->capacity - 1];
		while(i < index){
			temp[j] = this->front[i];
			j++;
			i++;
		}
		i = index + 1;
		while(i < this->length){
			temp[j] = this->front[i];
			j++;
			i++;
		}
	}
	if (this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	if(this->length > 0){
		this->front = temp;
	}
	this->length--;
	this->capacity--;
	
	index = -1;
	return index;
}

//DeleteFromFront 정의부
template <typename T>
int Array<T>::DeleteFromFront(){
	int i = 1;
	int j = 0;
	int index = -1;
	T (*temp)=0;
	if(this->length > 1){
		temp = new T[this->capacity - 1];
		while(i < this->length){
			temp[j] = this->front[i];
			j++;
			i++;
		}
	}
	if (this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	if(this->length > 1){
		this->front = temp;
	}
	this->length--;
	this->capacity--;
	return index;
}

//DeleteFromRear 정의부
template <typename T>
int Array<T>::DeleteFromRear(){
	int i = 0;
	int j = 0;
	int index = -1;
	T (*temp)=0;
	if(this->length > 1){
		temp = new T[this->capacity - 1];
		while(i < this->length - 1){
			temp[j] = this->front[i];
			j++;
			i++;
		}
	}
	if (this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	if(this->length > 1){
		this->front = temp;
	}
	this->length--;
	this->capacity--;
	return index;
}

//Modify  정의부
template <typename T>
int Array<T>::Modify(int index, T object){
	this->front[index] = object;
	return index;
}

//LinearSearchUnique 정의부
template <typename T>
int Array<T>::LinearSearchUnique(void *key, int (*compare)(void *, void *)){
	int index = -1;
	int i = 0;
	while(i < this->length && compare(*(this->front + i), key) != 0){
		i++;
	}
	if(i < this->length){
		index = i;
	}
	return index;
}

//LinearSearchDuplicate 정의부
template <typename T>
void Array<T>::LinearSearchDuplicate(void *key, int *(*indexes), int *count, int (*compare)(void *, void *)){
	int i = 0;
	int j = 0;
	*indexes = new int[this->length];
	*count = 0;
	while(i < this->length){
		if(compare(this->front + i, key) ==0 ){
			(*indexes)[j] = i;
			j++;
			(*count)++;
		}
		i++;
	}
}

//BinarySearchUnique 정의부
template <typename T>
int Array<T>::BinarySearchUnique(void *key, int (*compare)(void *, void *)){
	int index = -1;
	int i = 0;
	int startL, endL, center;
	startL = 0;
	endL = this->length-1;
	center = (startL + endL)/2;
	while(startL <= endL && compare(this->front + center, key) != 0){
		if(compare(this->front + center, key) > 0){
			endL = center - 1;
		}
		else if(compare(this->front + center, key) < 0){
			startL = center + 1;
		}
		center = (startL + endL)/2;
	}
	if(startL <= endL){
		index = center;
	}
	return index;
}


//Clear 정의부
template <typename T>
void Array<T>::Clear(){
	if(this->front != 0){
		delete[] this->front;
		this->front = 0;
	}
	this->length = 0;
	this->capacity = 0;
}


//SelectionSort 정의부
template <typename T>
void Array<T>::SelectionSort(int (*compare)(void *, void *)){
	int i, j, index;
	T temp;
	for(i = 0; i < this->length ; i++){
		index = i;
		for(j = i; j < this->length; j++){
			if(compare(this->front + index, this->front + j) >= 1){
				index = j;
			}
		}
		temp = this->front[i];
		this->front[i] = this->front[index];
		this->front[index] = temp;
	}
}

//InsertionSort 정의부
template <typename T>
void Array<T>::InsertionSort(int (*compare)(void *, void *)){
	int i = 1;
	int j;
	T temp;
	while(i < this->length){
		temp = this->front[i];
		j = i;
		while(j > 0 && compare((this->front + (j-1)), &temp) > 0){
			this->front[j] = this->front[j-1];
			j--;
		}
		this->front[j] = temp;
		i++;
	}
}

//MergerSort 정의부
template <typename T>
void Array<T>::MergerSort(Array& one, Array& other, int (*compare)(void *, void *)){
	int i=0;
	int j=0;
	int k=0;

	if(this->front != 0)	{
		delete this->front;
		this->front = 0;
	}
	this->front = new T[one.length + other.length];

	while(i<=one.length && j<= other.length)	{
		if(compare(one.front+i, other.front+j)<0)	{
			this->front[k] = one.front[i];
			k++;
			i++;
		} else {
			this->front[k] = other.front[j];
			k++;
			j++;
		}
	}
	while(j<=other.length)	{
		this->front[k] = other.front[j];
		k++;
		j++;
	}
	while(i<=one.length)	{
		this->front[k] = one.front[i];
		k++;
		i++;
	}
	this->capacity = one.length + other.length;
	this->length = one.length + other.length;
}



template <typename T>
bool Array<T>::operator==(const Array& other){
	bool ret = true;
	int i=0;
	bool equalElement = true;
	if(	this->length == other.length &&
		this->capacity == other.capacity){
		while(equalElement && i<this->length){
			if(this->front[i] != other.front[i]){
				equalElement = false;
			}
			i++;
		}
		if(equalElement==false){
			ret = false;
		}
	}
	else{
		ret = false;
	}
	return ret;
}

template <typename T>
bool Array<T>::operator!=(const Array& other){
	bool ret = false;
	int i=0;
	bool notEqual = false;
	if(	this->length != other.length ||
		this->capacity != other.capacity){
		ret = true;
	}
	else{
		while(notEqual==false && i<this->length){
			if(this->front[i] != other.front[i]){
				notEqual = true;
			}
			i++;
		}
		if(notEqual==true){
			ret = true;
		}
	}
	return ret;
}


template <typename T>
bool Array<T>::IsEqual(const Array& other){
	bool ret = true;
	int i=0;
	bool equalElement = true;
	if(	this->length == other.length &&
		this->capacity == other.capacity){
			while(equalElement && i<this->length){
				if(this->front[i] != other.front[i]){
					equalElement = false;
				}
				i++;
			}
			if(equalElement==false){
				ret = false;
			}
	}
	else{
		ret = false;
	}
	return ret;
}

template <typename T>
bool Array<T>::IsNotEqual(const Array& other){
	bool ret = false;
	int i=0;
	bool notEqual = false;
	if(	this->length != other.length ||
		this->capacity != other.capacity){
			ret = true;
	}
	else{
		while(notEqual==false && i<this->length){
			if(this->front[i] != other.front[i]){
				notEqual = true;
			}
			i++;
		}
		if(notEqual==true){
			ret = true;
		}
	}
	return ret;
}


#endif