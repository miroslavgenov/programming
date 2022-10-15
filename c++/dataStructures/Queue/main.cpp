#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/Queue/include/Queue.cpp"
using namespace std;

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