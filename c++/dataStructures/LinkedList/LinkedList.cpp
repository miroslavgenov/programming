#pragma once
#include <iostream>
#include <vector>

// Issue: can assign head data in to the construtor
// Issue: if i make more than one LinkedList object in one file there will be conflict with the 
// 		  totalListelements variables



//TODO: redesign the class
//		make structure and dont use the class as a Linked list use the class as a helper
// 		who can add , delete , etc. This will remove the conflict

//Issue: the redesign will be follow up by the other child classes

template<typename T>
class LinkedList{
public:
	const int EMPTY_SIZE_LENGTH = 0;
	static int totalListElements;
	// clean the variables
	T* data = nullptr;
	T* top = nullptr;
	LinkedList* root = nullptr;
	LinkedList* next = nullptr;
	std::vector<T> linkedListsDatas;

	

	int size(){
		return this->totalListElements;
	}

	LinkedList(T data){
		totalListElements++;

		if(totalListElements == EMPTY_SIZE_LENGTH){
			root = this;
		}
		
		this->data = new T{data};
		
	}

	~LinkedList(){
		next = nullptr;
		root = nullptr;
		data = nullptr;
		delete next;
		delete root;
		delete data;
	}

	void appendAtBeggining(T data){
		LinkedList* currentRoot = nullptr;
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			totalListElements++;
			this->data = new T{data};
		}else{
			
			currentRoot = new LinkedList(*this->data);
			
			// if current root object have next copy the next cuz we make only constructor with T data
			if(this->next){
				currentRoot->next = this->next;
			}

			this->data = new T{data};
			this->next = currentRoot;
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


	void appendAtEnd(T data){
		LinkedList* linkedListIterator = nullptr;
		
		if(this->totalListElements == this->EMPTY_SIZE_LENGTH){
			this->data = new T {data};
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

	T* deleteFromBegining(){
		T* dataFromBegining = nullptr;

		if(totalListElements > EMPTY_SIZE_LENGTH){
			if(this->next){
				dataFromBegining = new T{*this->data};

				*this->data = *this->next->data;
				this->next = this->next->next;
				totalListElements--;

				return dataFromBegining;
				
			}else{
				dataFromBegining  = new T{*this->data};
				totalListElements = 0;
				return dataFromBegining;
			}

		}
		return nullptr;
	}




	T* deleteAtIndex(int targetIndex){
		T* dataAtIndex = nullptr;
		// do we have elements
		if(totalListElements > EMPTY_SIZE_LENGTH){

			// is targetIndex in range
			if(targetIndex <= totalListElements - 1 && targetIndex >= EMPTY_SIZE_LENGTH){

				// use already defined methods if targetIndex is: 0, totalElements-1 , mid
				// use special method if not
				if(targetIndex == EMPTY_SIZE_LENGTH){
					dataAtIndex  = new T{*deleteFromBegining()};
					return dataAtIndex;
				}else if(targetIndex == totalListElements - 1){
					dataAtIndex = new T{*deleteFromEnd()};
					return dataAtIndex;
				}else if(targetIndex == totalListElements / 2){
					dataAtIndex = new T{* deleteFromMid()};
					return dataAtIndex;
				}
				else{
					LinkedList* iterator = this;
					
					for(int i =0 ;i<targetIndex-1;i++){
						iterator = iterator->next;
					}
					if(iterator->next->next){
						dataAtIndex = new T{*iterator->next->data};
						iterator->next = iterator->next->next;
						totalListElements--;
						return dataAtIndex;
					}else{
						std::cout<<"delete at index error check i element have only next"<<std::endl;
					}
					// totalListElements--;
				}  

			}


		}
		return nullptr;

	}

	T* deleteFromMid(){
		LinkedList* iterator = this;
		T* dataFromMid = nullptr;

		if(totalListElements == 1){
			// std::cout<<"totalListElements == 1"<<std::endl;
			// std::cout<<"total 1"<<std::endl;
			dataFromMid = new T{*deleteFromEnd()};
			// return new T{deleteFromEnd()};
			return dataFromMid;

		}else if(totalListElements > 1){
			int mid = totalListElements / 2;
			T* dataFromMid = nullptr;
			// std::cout<<"totalListElements>1"<<std::endl;
		
			for(int i = 0; i < mid - 1; i++){
				iterator = iterator->next;
			}

			if(iterator->next->next){
				dataFromMid = new T{*iterator->next->data};
				iterator->next = iterator->next->next;
				totalListElements--;
				return dataFromMid;
			}else if(!iterator->next->next){
				dataFromMid = new T{*iterator->next->data};
				iterator->next = nullptr;
				totalListElements--;
				return dataFromMid;
			}	
		}		
		return nullptr;
	}


	T* deleteFromEnd(){
		LinkedList* iterator = this;
		T* dataFromEnd = nullptr;

		if(totalListElements > 1){
			// std::cout<<"totalListElements>1"<<std::endl;
			// go before before the end
			while(iterator->next->next){
				iterator = iterator->next;
			}
	
			
			// T* data = new T{iterator->next->data};
			dataFromEnd  = new T{*iterator->next->data};

			// null the pointer that is pointing to the end
			iterator->next = nullptr;	

			this->totalListElements--;

			return dataFromEnd;


		}else{
			// std::cout<<"delete from end"<<std::endl;
			
			dataFromEnd = new T{*data};
			totalListElements = 0;
			return dataFromEnd;
		}
		return nullptr;
	}	

	T* getTop(){
		LinkedList<T> *iterator = this;
		while(iterator->next){
			iterator = iterator->next;
		}
		top = new T{*iterator->data};
		return top;
	}
	
	bool isEmpty(){
		return this->totalListElements == 0;
	}

	// Todo: deleteValue
	// first -> search the value if is in the list
	// then -> find the index and use delete index
	// done
	
	T* deleteByValue(T targetValue){
		// std::cout<<"Hello from deleteByValue"<<std::endl;
		LinkedList<T>* rootPointer = this;
		// std::cout<<"Total elements: "<<totalListElements<<std::endl;
		bool isTargetValueFound=false;
		int targetValueIndex=0;

		// search the target value and get the index
		while(rootPointer){
			targetValueIndex+=1;
			if(*rootPointer->data == targetValue){
				
				// std::cout<<"value is in the list"<<std::endl;
				// std::cout<<*rootPointer->data<<std::endl;
				isTargetValueFound=true;
				break;
			}
			rootPointer = rootPointer->next;	
		}

		if(isTargetValueFound == true){
			targetValueIndex-=1;
			// std::cout<<"targetValue:"<<targetValue<<" is found at index: "<<targetValueIndex<<" and can be deleted"<<std::endl;
			return deleteAtIndex(targetValueIndex);

		}else{
			std::cout<<"targetValue is not found and can't be deleted"<<std::endl;
		}
		return nullptr;
	}

	template<typename X>
	friend std::ostream& operator<<(std::ostream& , LinkedList<X>*);	

};

template <typename X>
std::ostream& operator<<(std::ostream& os, LinkedList<X>* currentRoot){
	LinkedList<X>* iterator = currentRoot;
	if(currentRoot->totalListElements > currentRoot->EMPTY_SIZE_LENGTH){
		while(iterator){
			os<<*iterator->data<<" ";
			iterator = iterator->next;
		}
	}
	return os;
}



template<typename T>
int LinkedList<T>::totalListElements= 0;
