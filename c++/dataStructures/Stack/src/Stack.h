#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"

template <typename T>
class Stack{
private:
	T* top = nullptr;

public:
	LinkedList<T> *linkedList = nullptr;
	
	Stack(){}
	
	Stack(T );
	
	void push(T);

	T* getTop();
	
	T* pop();

	bool isEmpty();

	template<typename X>
	friend std::ostream& operator<<(std::ostream&, Stack<X>*);
};
