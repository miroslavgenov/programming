#pragma once
#include <iostream>



template<typename T>
class LinkedList{
public:
	const int EMPTY_SIZE_LENGTH = 0;
	static int totalListElements;
	T data;
	LinkedList* root = nullptr;
	LinkedList* next = nullptr;

	
	LinkedList(T data){
		totalListElements++;

		if(totalListElements == EMPTY_SIZE_LENGTH){
			root = this;
		}
		
		this->data = data;
		
	}

	~LinkedList(){
		next = nullptr;
		root = nullptr;
		delete next;
		delete root;
	}



	void appendAtBeggining(T data){
		LinkedList* currentRoot = nullptr;
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			totalListElements++;
			this->data = data;
		}else{
			
			currentRoot = new LinkedList(this->data);
			
			// if current root object have next copy the next cuz we make only constructor with T data
			if(this->next){
				currentRoot->next = this->next;
			}

			this->data = data;
			this->next = currentRoot;
		}
	}

	void appendAtEnd(T data){
		LinkedList* linkedListIterator = nullptr;
		
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			this->data = data;
			totalListElements++;	
		}else{

			linkedListIterator = this;

			// go to the last element from the list
			while(linkedListIterator->next){
				linkedListIterator = linkedListIterator->next;
			}

			linkedListIterator->next = new LinkedList(data);	
		}
	}

	void deleteFromEnd(){
		LinkedList* iterator = this;

		if(totalListElements > 1){
			
			// go before before the end
			while(iterator->next->next){
				iterator = iterator->next;
			}
	
			// null the pointer that is pointing to the end
			iterator->next = nullptr;	

			this->totalListElements--;

		}else{
			std::cout<<"delete from end"<<std::endl;
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

	void appendAtIndex(int targetIndex, T data){
		if(targetIndex >= 0 ){
			if(targetIndex == 0){
			appendAtBeggining(data);
		}else if(targetIndex >= totalListElements){
			appendAtEnd(data);
		}else if(targetIndex < totalListElements){
			// cout<<"else"<<endl;
			LinkedList* iterator = this;
			for(int i = 0;i<targetIndex-1;i++){
				iterator = iterator->next;
			}
			LinkedList* inserted = new LinkedList(data);

			if(iterator->next){
				inserted->next = iterator->next;
				iterator->next = inserted;
			}else{
				std::cout<<"fix appendAtIndex custom logic"<<std::endl;
			}
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
				else{
					LinkedList* iterator = this;
					
					for(int i =0 ;i<targetIndex-1;i++){
						iterator = iterator->next;
					}
					if(iterator->next->next){
						iterator->next = iterator->next->next;
					}
					totalListElements--;
				}  

			}


		}

	}

	void deleteFromMid(){
		LinkedList* iterator = this;

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
	friend std::ostream& operator<<(std::ostream& , LinkedList<X>*);	
};

template <typename X>
std::ostream& operator<<(std::ostream& os, LinkedList<X>* currentRoot){
	LinkedList<X>* iterator = currentRoot;
	if(currentRoot->totalListElements > currentRoot->EMPTY_SIZE_LENGTH){
		while(iterator){
			os<<iterator->data<<" ";
			iterator = iterator->next;
		}
	}
	return os;
}



template<typename T>
int LinkedList<T>::totalListElements= 0;

