#include <iostream>

using namespace std;

template<typename T>
class LinkedListSingle{
public:
	static int totalListElements;
	T data;
	LinkedListSingle* root = nullptr;
	LinkedListSingle* next = nullptr;

	
	LinkedListSingle(T data){
		totalListElements++;

		if(totalListElements == 0){
			root = this;
		}
		
		this->data = data;
		
	}

	~LinkedListSingle(){
		next = nullptr;
		root = nullptr;
		delete next;
		delete root;
	}

	void insertBeforeRoot(T data){
		LinkedListSingle* currentRoot = new LinkedListSingle(this->data);
		if(this->next){
			currentRoot->next = this->next;	
		}
		
		this->data = data;
		this->next = currentRoot;	
	}

	void insert(T data){
		LinkedListSingle* linkedListIterator = this;
		
		// go to the last element from the list
		while(linkedListIterator->next){
			linkedListIterator=linkedListIterator->next;
		}

		linkedListIterator->next = new LinkedListSingle(data);
	}

	void deleteFromEnd(){
		LinkedListSingle* iterator = this;
		if(iterator->next){
			
			// go before before the end
			while(iterator->next->next){
				iterator = iterator->next;
			}
	
			// null the pointer that is pointing to the end
			iterator->next = nullptr;	

		}else{
			totalListElements = 0;
		}
		
	}

	void deleteFromMid(){
		int mid = totalListElements/2;
		
	}

	
	template<typename X>
	friend ostream& operator<<(ostream& , LinkedListSingle<X>*);	
};

template <typename X>
ostream& operator<<(ostream& os, LinkedListSingle<X>* currentRoot){
	LinkedListSingle<X>* iterator = currentRoot;
	if(currentRoot->totalListElements>0){
		while(iterator){
		os<<iterator->data<<" ";
		iterator = iterator->next;
	}
	}
	
	return os;
}



template<typename T>
int LinkedListSingle<T>::totalListElements= 0;

int main(){
	LinkedListSingle<int>* l = new LinkedListSingle(1);
	l->insert(3);
	
	l->deleteFromEnd();
	
	
	
	
	


}