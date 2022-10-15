#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"

template <typename T>
class Deque{
	LinkedList<T> *linkedList = nullptr;

public:	
	Deque(T data);
	
	T* popAtRight();

	T* popAtLeft();

	void pushAtRight(T data);

	void pushAtLeft(T data);

	T* getTop();

	bool isEmpty();

	template <typename X>
	friend std::ostream& operator<<(std::ostream&, Deque<X>*);
};