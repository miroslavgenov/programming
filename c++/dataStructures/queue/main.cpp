#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"
using namespace std;


struct queue{
	string name;
	queue* next;
	queue *prev;
};


queue *firstInQueue=nullptr;
queue *lastInQueue= nullptr;


void initQueue(queue *);

void appendQueue(queue *);

queue* popQueue();

void printQueue();
bool isNull(queue * value){return value==nullptr;}

int main(){

	queue *n = new queue{"admin",nullptr,nullptr};
	initQueue(n);
	
	
	queue *n1 = new queue{"ivan",nullptr,nullptr};
	queue *n2 = new queue {"jojo", nullptr, nullptr};
	appendQueue(n1);
	appendQueue(n2);
	printQueue();
	popQueue();
	cout<<endl;
	printQueue();
	popQueue();
	cout<<endl;
	printQueue();
	cout<<endl;
	popQueue();
	printQueue();
	
}

queue *popQueue(){
	queue* poped=nullptr;
	
	if(isNull(firstInQueue->prev)){
		poped = new queue{firstInQueue->name,nullptr,nullptr};
		firstInQueue=nullptr;
		lastInQueue=nullptr;
		return poped;
	}else{
		poped = new queue{firstInQueue->name,nullptr,nullptr};
		firstInQueue=firstInQueue->prev;
		firstInQueue->next=nullptr;
		return poped;
	}
	
}

void initQueue(queue *root){
	lastInQueue=root;
	firstInQueue=root;
}

void appendQueue(queue *value){
	if(!firstInQueue && !lastInQueue){
		initQueue(value);
	}else{
		value->next=lastInQueue;
		lastInQueue->prev=value;
		value->prev=nullptr;
		lastInQueue=value;	
	}
	
}

void printQueue(){
	queue * point = lastInQueue;
	
	while(point){
		cout<<point->name<<"  ";
		point=point->next;
	}
}












































