#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/include/LinkedListHelper.cpp"

template <typename T>
class Queue{
	LinkedListHelper<T> *linkedList = nullptr;
	


public:
	T* firstInQueue=nullptr;
	T* lastInQueue=nullptr;
	Queue(T );
	// Queue(T);
	
	void push(T data);
	
	bool isEmpty();

	T pop();

	T getTop();

	int size();

	template <typename X>
	friend std::ostream& operator<<(std::ostream& , Queue<X>*);
};