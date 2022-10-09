#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"

using namespace std;

struct student{
string name;	
};

/*
	top: T

	push()
	pop()
	isEmpty()
	isFull()
	getMin()
	getMax()

*/
template <typename T>
class Stack{
	T* top = nullptr;
public:
	
	LinkedList<T> *linkedList = nullptr;
	

	Stack(){}
	
	Stack(T data){
		linkedList = new LinkedList(data);
	}


	
	void push(T data){
		if(linkedList == nullptr){
			linkedList = new LinkedList(data);
		}else{
			linkedList->appendAtEnd(data);
		}
		// cout<<linkedList<<endl;
		
	}

	T* getTop(){
		LinkedList<T>* iterator = linkedList;
		

		while(iterator->next){
			iterator = iterator->next;
		}

		top = new T{*iterator->data};
		return top;
	}
	
	T* pop(){
		return linkedList->deleteFromEnd();
	}

	template<typename X>
	friend ostream& operator<<(ostream& , Stack<X>* );

	// friend ostream& operator<<(ostream& , Stack<student>* );

};


template <typename X>
ostream& operator<<(ostream& os, Stack<X>* stack){
	os<<stack->linkedList;
	return os;
}

