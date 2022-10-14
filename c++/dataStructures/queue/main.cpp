#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"
using namespace std;

template <typename T>
class Queue{
	LinkedList<T>* linkedList = nullptr;
public:
	
	Queue(T data){
		linkedList = new LinkedList(data);
	}
	
	void push(T data){
		linkedList->appendAtBeggining(data);
	}
	
	T* pop(){
		return linkedList->deleteFromEnd();
	}

	T* getTop(){
		return linkedList->getTop();
	}

	bool isEmpty(){
		return linkedList->isEmpty();
	}

	template <typename X>
	friend ostream& operator<<(ostream& , Queue<X>*);
};



template <typename X>
ostream& operator<<(ostream& os, Queue<X>* queue){
	os<<queue->linkedList;
	return os;
}


int main(){
	Queue<int> *q = new Queue(3);
	q->push(4);
	cout<<q<<endl;
	cout<<*q->pop();
	cout<<"top: "<<*q->getTop()<<endl;
	cout<<q<<endl;
	q->pop();
	cout<<q->isEmpty()<<endl;

	
}