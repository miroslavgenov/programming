#include "/home/home/Desktop/programming/c++/dataStructures/Queue/src/Queue.h"

template <typename T>
Queue<T>::Queue(T data){
	linkedList = new LinkedListHelper(data);
	firstInQueue = data;
	lastInQueue = data;
}

template <typename T>
void Queue<T>::push(T data){
	lastInQueue= data;
    linkedList->appendAtBegining(data);
}

template <typename T>
bool Queue<T>::isEmpty(){
	return linkedList->isListEmpty();
}

template <typename T>
T Queue<T>::pop(){
	
    if(linkedList->size() - 1 == 0){
		firstInQueue=nullptr;
		lastInQueue=nullptr;
    }else{
        firstInQueue = getTop();
    }

	return linkedList->deleteAtEnd();
}


template <typename T>
int Queue<T>::size(){
	return linkedList->size();
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Queue<X>* queue){
	queue->linkedList->print();
	return os;
}