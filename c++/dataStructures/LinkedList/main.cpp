#include <iostream>

using namespace std;

template<typename T>
class LinkedListSingle{
public:
	const int EMPTY_SIZE_LENGTH = 0;
	static int totalListElements;
	T data;
	LinkedListSingle* root = nullptr;
	LinkedListSingle* next = nullptr;

	
	LinkedListSingle(T data){
		totalListElements++;

		if(totalListElements == EMPTY_SIZE_LENGTH){
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
		LinkedListSingle* currentRoot = nullptr;
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			totalListElements++;
			this->data = data;
		}else{
			
			currentRoot = new LinkedListSingle(this->data);
			
			// if current root object have next copy the next cuz we make only constructor with T data
			if(this->next){
				currentRoot->next = this->next;
			}

			this->data = data;
			this->next = currentRoot;
		}
	}

	void insert(T data){
		LinkedListSingle* linkedListIterator = nullptr;
		
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			this->data = data;
			totalListElements++;	
		}else{

			linkedListIterator = this;

			// go to the last element from the list
			while(linkedListIterator->next){
				linkedListIterator = linkedListIterator->next;
			}

			linkedListIterator->next = new LinkedListSingle(data);	
		}
	}

	void deleteFromEnd(){
		LinkedListSingle* iterator = this;

		if(totalListElements > 1){
			
			// go before before the end
			while(iterator->next->next){
				iterator = iterator->next;
			}
	
			// null the pointer that is pointing to the end
			iterator->next = nullptr;	

			this->totalListElements--;

		}else{
			cout<<"delete from end"<<endl;
			totalListElements = 0;
		}
	}

	void deleteFromBegining(){
		if(totalListElements > EMPTY_SIZE_LENGTH){
			if(this->next){
				this->data = this->next->data;
				this->next = this->next->next;
				totalListElements--;
			}else{
				totalListElements = 0;
			}

		}
	}

	void deleteAtIndex(int targetIndex){
		// do we have elements
		if(totalListElements > EMPTY_SIZE_LENGTH){

			// is targetIndex in range
			if(targetIndex <= totalListElements - 1 && targetIndex >= EMPTY_SIZE_LENGTH){

				// use already defined methods if targetIndex is: 0, totalElements-1 , mid
				// use special method if not
				if(targetIndex == EMPTY_SIZE_LENGTH){
					deleteFromBegining();
				}else if(targetIndex == totalListElements - 1){
					deleteFromEnd();
				}else if(targetIndex == totalListElements / 2){
					deleteFromMid();
				}
				// else{}  //custom logic

			}


		}

	}

	void deleteFromMid(){
		LinkedListSingle* iterator = this;

		if(totalListElements == 1){
			deleteFromEnd();

		}else if(totalListElements > 1){
			int mid = totalListElements / 2;
			

		
			for(int i = 0; i < mid - 1; i++){
				iterator = iterator->next;
			}

			if(iterator->next->next){
				iterator->next = iterator->next->next;
				totalListElements--;
			}else if(!iterator->next->next){
				iterator->next = nullptr;
				totalListElements--;
			}	
		}		
	}

	
	template<typename X>
	friend ostream& operator<<(ostream& , LinkedListSingle<X>*);	
};

template <typename X>
ostream& operator<<(ostream& os, LinkedListSingle<X>* currentRoot){
	LinkedListSingle<X>* iterator = currentRoot;
	if(currentRoot->totalListElements > currentRoot->EMPTY_SIZE_LENGTH){
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
	
	l->insert(2);
	l->insert(3);
	cout<<l<<endl;	
	
	
	

	// cout<<l<<endl;
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteAtIndex(2);
	// l->deleteFromBegining();
	// l->deleteFromBegining();
	// l->deleteFromBegining();
	// l->deleteFromBegining();
	
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	// l->deleteFromMid();
	
	// cout<<"total elements after: "<<l->totalListElements<<endl;
	
	// cout<<l<<endl;
	

	// l->insert(5);
	// cout<<l<<" "<<l->totalListElements<<endl;
	
	
	
	
	


}