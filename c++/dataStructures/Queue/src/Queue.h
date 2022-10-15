#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"

template <typename T>
class Queue{
	LinkedList<T>* linkedList = nullptr;
public:
	
	Queue(T);
	
	void push(T data);
	
	T* pop();

	T* getTop();

	bool isEmpty();

	template <typename X>
	friend std::ostream& operator<<(std::ostream& , Queue<X>*);
};