#include "/home/home/Desktop/programming/c++/dataStructures/Queue/src/Queue.h"

template <typename T>
Queue<T>::Queue(T data){
	linkedList = new LinkedList(data);
}

template <typename T>
void Queue<T>::push(T data){
	linkedList->appendAtBeggining(data);
}

template <typename T>
T* Queue<T>::pop(){
	return linkedList->deleteFromEnd();
}

template <typename T>
T* Queue<T>::getTop(){
	return linkedList->getTop();
}

template <typename T>
bool Queue<T>::isEmpty(){
	return linkedList->isEmpty();
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Queue<X>* queue){
	os<<queue->linkedList;
	return os;
}