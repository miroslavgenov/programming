#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/include/LinkedListHelper.cpp"

//NOTE: remove from stack by value
template <typename T>
class Stack{
public:
	LinkedListHelper<T>* linkedListHelper = nullptr;
	
	Stack(){}
	
	Stack(T );
	
	void push(T );

	T getTop();
	
	T pop();

	int size();

	bool isEmpty();
	
	void print();
	
	template<typename X>
	friend std::ostream& operator<<(std::ostream&, Stack<X>*);
};