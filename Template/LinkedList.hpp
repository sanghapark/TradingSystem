//LinkedList.h
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <typename T>
class LinkedList{
	public:
		class Node{
			friend class LinkedList<T>;
			public:
				Node(){
					this->previous=this;
					this->next=this;
				}
				Node(T object){
					this->previous=this;
					this->object=object;
					this->next=this;
				}
				Node(T object, Node* next){
					this->previous=this;
					this->object=object;
					this->next=next;
				}
				Node(Node* previous, T object){
					this->previous=previous;
					this->object=object;
					this->next=this;
				}
				Node(Node* previous, T object, Node* next){
					this->previous=previous;
					this->object=object;
					this->next=next;
				}
				Node(const Node& source){
					this->previous=source.previous;
					this->object=source.object;
					this->next=source.next;
				}
				Node& operator=(const Node& source){
					this->previous=source.previous;
					this->object=source.object;
					this->next=source.next;
					return *this;
				}

				T& GetObject() const{
					return const_cast<T&>(this->object);
				}
				
				Node* GetPrevious() const{
					return this->previous;
				}

				Node* GetNext() const{
					return this->next;
				}

			private:
				Node* previous;
				T object;
				Node* next;
		};
	public:
		LinkedList();
		LinkedList(const LinkedList<T>& source);
		~LinkedList();
		Node* AppendFromHead(T object);
		Node* AppendFromTail(T object);
		Node* InsertBefore(Node* index, T object);
		Node* InsertAfter(Node* index, T object);
		Node* Delete(Node* index);
		Node* DeleteFromHead();
		Node* DeleteFromTail();
		void DeleteAllItems();
		Node* LinearSearchUnique(void* key, int(*compare)(void*, void*));
		void LinearSearchDuplicate(void* key, Node** (*indexes), int* count, int(*compare)(void*, void*));
		

		T& GetAt(int arrayIndex);
		int GetIndex(T* object);
		T& operator[](int arrayIndex);
		LinkedList<T>& operator=(const LinkedList<T>& source);


		Node* First();
		Node* Previous();
		Node* Next();
		Node* Last();

		Node* GetHead() const;
		Node* GetTail() const;
		int GetLength() const;
		Node* GetCurrent() const;

	private:
		Node* head;
		Node* tail;
		int length;
		Node* current;
};

template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::GetHead() const{
	return this->head;
}
template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::GetTail() const{
	return this->tail;
}
template <typename T>
inline typename int LinkedList<T>::GetLength() const{
	return this->length;
}
template <typename T>
inline typename LinkedList<T>::Node* LinkedList<T>::GetCurrent() const{
	return this->current;
}

template <typename T>
LinkedList<T>::LinkedList(){
	this->head=0;
	this->tail=0;
	this->length=0;
	this->current=0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& source){
	Node* preIndex=0;
	Node* index;
	Node* sourceIndex=source.head;
	this->current=0;
	for(int i=0; i<source.length; i++){
		if(sourceIndex->previous!=sourceIndex){
			index=new Node(preIndex, sourceIndex->object);
		}
		else{
			index=new Node(sourceIndex->object); 
		}
		if(sourceIndex->previous!=sourceIndex){
			preIndex->next=index;
		}
		else{
			this->head=index;
		}
		if(source.current==sourceIndex){
			this->current=index;
		}
		preIndex=index;
		sourceIndex=sourceIndex->next;
	}
	this->tail=preIndex;
	this->length=source.length;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	Node* index;
	Node* temp;
	int i=0;
	index=this->head;
	while(i<this->length){
		temp=index->next;
		if(index!=0){
			delete index;
		}
		index=temp;
		i++;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromHead(T object){
	if(this->head!=0){
		this->current=new Node(object, this->head);
	}
	else{
		this->current=new Node(object);
	}
	if(this->head!=0){
		this->head->previous=this->current;
	}
	else{
		this->tail=this->current;
	}
	this->head=this->current;
	this->length++;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::AppendFromTail(T object){
	if(this->tail!=0){
		this->current=new Node(this->tail, object);
	}
	else{
		this->current=new Node(object);
	}
	if(this->tail!=0){
		this->tail->next=this->current;
	}
	else{
		this->head=this->current;
	}
	this->tail=this->current;
	this->length++;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertBefore(Node* index, T object){
	if(index->previous!=index){
		this->current=new Node(index->previous, object, index);
	}
	else{
		this->current=new Node(object, index)
	}
	if(index->previous!=index){
		index->previous->next=this->current;
	}
	else{
		this->head=this->current;
	}
	index->previous=this->current;
	this->length++;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::InsertAfter(Node* index, T object){
	if(index->next!=index){
		this->current=new Node(index, object, index->next);
	}
	else{
		this->current=new Node(index, object);
	}
	if(index->next!=index){
		index->next->previous=this->current;
	}
	else{
		this->tail=this->current;
	}
	index->next=this->current;
	this->length++;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Delete(Node* index){
	Node* preNode;
	Node* nextNode;
	if(this->head != this->tail){
		if(index==this->head || index==this->tail){
			if(index==this->head){
				nextNode=index->next;
				this->head=nextNode;
				nextNode->previous=nextNode;
				this->current=nextNode;
			}
			else{
				preNode=index->previous;
				this->tail=preNode;
				preNode->next=preNode;
				this->current=preNode;
			}
		}
		else{
			preNode=index->previous;
			nextNode=index->next;
			preNode->next=nextNode;
			nextNode->previous=preNode;
			this->current=nextNode;
		}
	}
	else{
		this->head=0;
		this->tail=0;
		this->current=0;
	}
	if(index!=0){
		delete index;
		index=0;
	}
	this->length--;
	return index;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromHead(){
	Node* index;
	Node* nextNode;
	index=this->head;
	if(index!=this->tail){
		nextNode=index->next;
		this->head=nextNode;
		nextNode->previous=nextNode;
	}
	else{
		this->head=0;
		this->tail=0;
		this->current=0;
	}
	if(index!=0){
		delete index;
		index=0;
	}
	this->length--;
	return index;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::DeleteFromTail(){
	Node* index;
	Node* preNode;
	index=this->tail;
	if(index!=this->head){
		preNode=index->previous;
		this->tail=preNode;
		preNode->next=preNode;
	}
	else{
		this->head=0;
		this->tail=0;
		this->current=0;
	}
	if(index!=0){
		delete index;
		index=0;
	}
	this->length--;
	return index;
}


template <typename T>
void LinkedList<T>::DeleteAllItems(){
	Node* index;
	Node* temp;
	int i;
	index=this->head;
	i=0;
	while(i<this->length){
		temp=index->next;
		if(index!=0){
			delete index;
		}
		index=temp;
		i++;
	}
	this->head=0;
	this->tail=0;
	this->current=0;
	this->length=0;
}


template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::LinearSearchUnique(void* key, int(*compare)(void*, void*)){
	Node* index;
	int i=0;
	index=this->head;
	while(index!=this->tail && compare(&(index->GetObject()), key)!=0){
		index=index->next;
	}
	if(compare(&(index->object),key)!=0){
		index=0;
	}
	return index;
}


template <typename T>
void LinkedList<T>::LinearSearchDuplicate(void* key, Node** (*indexes), int* count, int(*compare)(void*, void*)){
	Node* index;
	int i;
	int j=0;
	*count=0;
	if(this->length>0){
		index=this->head;
		*indexes=new Node*[this->length];
		i=0;
		while(i<this->length){
			if(compare(&(index->object),key)==0){
				(*count)++;
				(*indexes)[j]=index;
				j++;
			}
			index=index->next;
			i++;
		}
	}
}

template <typename T>
T& LinkedList<T>::GetAt(int arrayIndex){
	int i=0;
	this->current=this->head;
	while(i<arrayIndex){
		this->current=this->current->next;
		i++;
	}
	return (this->current->object);
}

template <typename T>
int LinkedList<T>::GetIndex(T* object){

	Node* tempNode = this->First();
	Node* preNode = 0;
	int index=0;
	while(&(tempNode->GetObject())!=object && preNode!=tempNode){
		index++;
		preNode = tempNode;
		tempNode  = this->Next();
	}
	if(preNode == tempNode){
		index = -1;
	}
	return index;
}



template <typename T>
T& LinkedList<T>::operator[](int arrayIndex){
	int i=0;
	this->current=this->head;
	while(i<arrayIndex){
		this->current=this->current->next;
		i++;
	}
	return (this->current->object);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& source){
	Node* index;
	Node* temp;
	int i;
	index=this->head;
	i=0;
	while(i<this->length){
		temp=index->next;
		if(index!=0){
			delete index;
		}
		index=temp;
		i++;
	}

	Node* preIndex=0;
	Node* sourceIndex=source.head;
	this->current=0;
	for(i=0; i<source.length; i++){
		if(sourceIndex->previous!=sourceIndex){
			index=new Node(preIndex, sourceIndex->object);
		}
		else{
			index=new Node(sourceIndex->object); 
		}
		if(sourceIndex->previous!=sourceIndex){
			preIndex->next=index;
		}
		else{
			this->head=index;
		}
		if(source.current==sourceIndex){
			this->current=index;
		}
		preIndex=index;
		sourceIndex=sourceIndex->next;
	}
	this->tail=preIndex;
	this->length=source.length;
	return *this;
}


template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::First(){
	this->current=this->head;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Previous(){
	this->current=this->current->previous;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Next(){
	this->current=this->current->next;
	return this->current;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Last(){
	this->current=this->tail;
	return this->current;
}





#endif