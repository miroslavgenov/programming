#include "/home/home/Desktop/programming/c++/dataStructures/Queue/src/Queue.h"

template <typename T>


Queue<T>::Queue(T data){
	linkedList = new LinkedList(data);
	firstInQueue = new T{data};
	lastInQueue = new T{data};
}

template <typename T>
void Queue<T>::push(T data){
	lastInQueue=new T{data};
	linkedList->appendAtBeggining(data);
}

template <typename T>
bool Queue<T>::isEmpty(){
	return linkedList->isEmpty();
}

template <typename T>
T* Queue<T>::pop(){

	if(LinkedList<T>::totalListElements-1==0){
		firstInQueue=nullptr;
		lastInQueue=nullptr;
	}else{
		firstInQueue = getTop();	
	}

	return linkedList->deleteFromEnd();
}

template <typename T>
T* Queue<T>::getTop(){
	return linkedList->getTop();
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Queue<X>* queue){
	os<<queue->linkedList;
	return os;
}