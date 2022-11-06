#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"

template <typename T>
class Queue{
	LinkedList<T>* linkedList = nullptr;


public:
	T* firstInQueue=nullptr;
	T* lastInQueue=nullptr;

	Queue(T);
	
	void push(T data);
	
	bool isEmpty();

	T* pop();

	T* getTop();

	template <typename X>
	friend std::ostream& operator<<(std::ostream& , Queue<X>*);
};