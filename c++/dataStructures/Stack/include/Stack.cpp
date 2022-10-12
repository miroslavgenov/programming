#include "/home/home/Desktop/programming/c++/dataStructures/Stack/src/Stack.h"

template <typename T>
Stack<T>::Stack(T data){
	linkedList = new LinkedList(data);
}

template <typename T>
void Stack<T>::push(T data){
	if(linkedList == nullptr){
		linkedList = new LinkedList(data);
	}else{
		linkedList->appendAtEnd(data);
	}	
}

template <typename T>
T* Stack<T>::getTop(){
	LinkedList<T>* iterator = linkedList;
	

	while(iterator->next){
		iterator = iterator->next;
	}

	top = new T{*iterator->data};
	return top;
}

template <typename T>	
T* Stack<T>::pop(){
	return linkedList->deleteFromEnd();
}
	
template <typename T>
bool Stack<T>::isEmpty(){
	return linkedList->totalListElements == 0;
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Stack<X>* stack){
	os<<stack->linkedList;
	return os;
}