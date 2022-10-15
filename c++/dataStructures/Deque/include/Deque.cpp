#include "/home/home/Desktop/programming/c++/dataStructures/Deque/src/Deque.h"

template <typename T>
Deque<T>::Deque(T data){
	linkedList = new LinkedList(data);
}
	
template <typename T>
T* Deque<T>::popAtRight(){
	return linkedList->deleteFromEnd();
}

template <typename T>
T* Deque<T>::popAtLeft(){
	return linkedList->deleteFromBegining();
}

template <typename T>
void Deque<T>::pushAtRight(T data){
	linkedList->appendAtEnd(data);
}

template <typename T>
void Deque<T>::pushAtLeft(T data){
	linkedList->appendAtBeggining(data);
}

template <typename T>
T* Deque<T>::getTop(){
	return linkedList->getTop();
}

template <typename T>
bool Deque<T>::isEmpty(){
	return linkedList->totalListElements == 0;
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Deque<X>* d){
	os<<d->linkedList;
	return os;
}