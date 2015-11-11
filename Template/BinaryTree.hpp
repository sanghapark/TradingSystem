//BinaryTree.h
#ifndef _BINARYTREE_H
#define _BINARYTREE_H

template <typename T>
class BinaryTree{
	public:
		class Node{
			friend BinaryTree;
			public:
				Node(){
					this->left=0;
					this->key=0;
					this->right=0;
				}
				Node(T key){
					this->left=0;
					this->key=key;
					this->right=0;
				}
				Node(const Node& source){
					this->left=source.left;
					this->key=source.key;
					this->right=source.right;
				}
				void CopyToBuffer(Node* node, T* (*array), int* count){
					if(node!=0){
						CopyToBuffer(node->left, array, count);
						(*array)[*count]=node->key;
						(*count)++;
						CopyToBuffer(node->right, array, count);
					}
				}
				Node* DeleteAllItems(){
					if(this!=0){
						this->left=this->left->DeleteAllItems();
						this->right=this->right->DeleteAllItems();
						delete this;
					}
					return 0;
				}
				static Node* MakeTree(Node* parentNode, T (*array), int low, int high, int(*compareKey)(void*, void*)){
					Node* node=0;
					if(low<=high){
						int middle=(low+high)/2;
						node = new Node(array[middle]);
						if(parentNode!=0){
							if(compareKey(&(parentNode->key), &(node->key))<0){
								parentNode->right=node;
							}
							else{
								parentNode->left=node;
							}
						}
						MakeTree(node, array, low, middle-1, compareKey);
						MakeTree(node, array, middle+1, high, compareKey);
					}
					return node;
				}
				void CopyToNode(Node* sourceIndex, Node* parentIndex, Node* sourceParentIndex){
					Node* temp = new Node(sourceIndex->GetKey());
					if(sourceParentIndex->right==sourceIndex){
						parentIndex->right=temp;
					}
					else{
						parentIndex->left=temp;
					}
					CopyToNode(sourceIndex->left, temp, sourceIndex);
					CopyToNode(sourceIndex->right, temp, sourceIndex);
				}
				T& GetKey() const{
					return const_cast<T&>(this->key);
				}
			private:
				Node* left;
				T key;
				Node* right;			
		};
	public:
		BinaryTree();
		BinaryTree(const BinaryTree& source);
		~BinaryTree();

		Node* Insert(T key, int(*compareKey)(void*, void*));
		Node* Search(T key, int(*compareKey)(void*, void*));
		Node* Delete(T key, int(*compareKey)(void*, void*));

		void MakeBalance(int(*compare)(void*, void*));
		void CopyToBuffer(T* (*array), int* count);
		void DeleteAllItems();
		void MakeTree(T (*array), int count, int(*compare)(void*, void*));

		Node* GetRoot() const;
		int GetLength() const;
		int GetBalance() const;

		BinaryTree& operator=(const BinaryTree& source);

	private:
		Node* root;
		int length;
		int balance;
};

template <typename T>
inline BinaryTree<T>::Node* BinaryTree<T>::GetRoot() const{
	return this->root;
}
template <typename T>
inline int BinaryTree<T>::GetLength() const{
	return this->length;
}
template <typename T>
inline int BinaryTree<T>::GetBalance() const{
	return this->balance;
}

template <typename T>
BinaryTree<T>::BinaryTree(){
	this->root=0;
	this->length=0;
	this->balance=0;
}
template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& source){
	if(source.length>0){
		this->root=new Node(source.root->key);
		this->root->CopyToNode(source.root, this->root, 0);
	}
	this->length  = source.length;
	this->balance = source.balance;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
	this->DeleteAllItems();
}

template <typename T>
BinaryTree<T>::Node* BinaryTree<T>::Insert(T key, int(*compareKey)(void*, void*)){
	Node* node = new Node(key);
	Node* index=this->root;
	Node* parentIndex=0;
	while(index!=0){
		parentIndex=index;
		if(compareKey(&(index->key), &key)>0){
			index=index->left;
		}
		else{
			index=index->right;
		}
	}
	if(parentIndex!=0){
		if(compareKey(&(parentIndex->key), &key)>0){
			parentIndex->left=node;
		}
		else{
			parentIndex->right=node;
		}
	}
	else{
		this->root=node;
	}
	if(compareKey(&(this->root->key), &key)>0){
		this->balance--;
	}
	else{
		this->balance++;
	}
	this->length++;
	return node; 
}
template <typename T>
BinaryTree<T>::Node* BinaryTree<T>::Search(T key, int(*compareKey)(void*, void*)){
	Node* index=this->root;
	while(index!=0 && compareKey(&(index->key), &key)){
		if(compareKey(&(index->key), &key)>0){
			index=index->left;
		}
		else{
			index=index->right;
		}
	}
	return index;
}
template <typename T>
BinaryTree<T>::Node* BinaryTree<T>::Delete(T key, int(*compareKey)(void*, void*)){
	Node* index;
	Node* parentIndex=0;
	Node* replace;
	Node* parentReplace=0;
	index=this->root;
	while(index!=0 && compareKey(&(index->key), &key)!=0){
		parentIndex=index;
		if(compareKey(&(index->key), &key)<0){
			index=index->right;
		}
		else{
			index=index->left;
		}
	}
	if(index!=0 && compareKey(&(index->key), &key)==0){
		if(this->length>1){
			if(compareKey(&(this->root->key), &key)>0){
				this->balance++;
			}
			else{
				this->balance--;
			}
		}
		if(index->right!=0){
			replace=index->right;
			while(replace->left!=0){
				parentReplace=replace;
				replace=replace->left;
			}
		}
		else{
			if(index->left!=0){
				replace=index->left;
				while(replace->right!=0){
					parentReplace=replace;
					replace=replace->right;
				}
			}
		}
		if(index->left==0 && index->right!=0){
			if(parentReplace!=0){
				parentReplace->left=replace->right;
				replace->right=index->right;
			}
		}
		if(index->left!=0 && index->right==0){
			if(parentReplace!=0){
				parentReplace->right=replace->left;
				replace->left=index->left;
			}
		}
		if(index->left!=0 && index->right!=0){
			if(parentReplace!=0){
				parentReplace->left=replace->right;
				replace->right=index->right;
			}
			replace->left=index->left;
		}
		if(parentIndex!=0){
			if(parentIndex->left==index){
				if(index->left==0 && index->right==0){
					parentIndex->left=0;
				}
				else{
					parentIndex->left=replace;
				}
			}
			else{
				if(index->left==0 && index->right==0){
					parentIndex->right=0;
				}
				else{
					parentIndex->right=replace;
				}
			}
		}
		else{
			if(index->left==0 && index->right==0){
				this->root=0;
			}
			else{
				this->root=replace;
			}
		}
		this->length--;
	}
	if(index!=0){
		delete index;
		index=0;
	}
	return index;
}

template <typename T>
void BinaryTree<T>::MakeBalance(int (*compareKey)(void*, void*)){
	int middle;
	int rightNodes;
	int leftNodes;
	int count=0;
	T (*array);
	
	CopyToBuffer(&array, &count);
	DeleteAllItems();
	MakeTree(array, count, compareKey);
	
	middle=(this->length+1)/2;
	rightNodes=this->length-middle;
	leftNodes=middle-1;
	this->balance=rightNodes-leftNodes;
	
	if(array!=0){
		delete[] array;
	}
}
template <typename T>
void BinaryTree<T>::CopyToBuffer(T* (*array), int* count){
	*array=new T[this->length];
	*count=0;
	this->root->CopyToBuffer(this->root, array, count);
}
template <typename T>
void BinaryTree<T>::DeleteAllItems(){
	this->root->DeleteAllItems();
	this->root=0;
	this->length=0;
	this->balance=0;
}
template <typename T>
void BinaryTree<T>::MakeTree(T (*array), int count, int(*compareKey)(void*, void*)){
	this->root=Node::MakeTree(this->root, array, 0, count-1, compareKey);
	this->length=count;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& source){
	if(this->root!=0){
		this->root->DeleteAllItems();
	}
	if(source.length>0){
		this->root = new Node(source.root->GetKey());
		this->root->CopyToNode(source.root, this->root, 0);
	}
	this->length  = source.length;
	this->balance = source.balance;
	return *this;
}

#endif //_BINARYTREE_H