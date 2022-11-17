#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/redesign/main.cpp"

template <typename T>
class Stack{
public:
	LinkedListHelper<T>* linkedListHelper = nullptr;
	
	Stack(){}
	
	Stack(T data){
		linkedListHelper = new LinkedListHelper(data);
	}
	
	void push(T data){
		if(linkedListHelper == nullptr){
			linkedListHelper = new LinkedListHelper(data);
		}else{
			linkedListHelper->appendAtEnd(data);
		}
		
	}

	T getTop(){
		return linkedListHelper->top();
	}
	
	T pop(){
		return linkedListHelper->deleteAtEnd();
	}

	int size(){
		return linkedListHelper->size();
	}

	bool isEmpty(){
		return linkedListHelper->isListEmpty();
	}

	void print(){
		linkedListHelper->print();
	}


	template<typename X>
	friend std::ostream& operator<<(std::ostream&, Stack<X>*);
};

template <typename X>
std::ostream& operator<<(std::ostream& os, Stack<X>* stack){
	stack->print();
	return os;
}
