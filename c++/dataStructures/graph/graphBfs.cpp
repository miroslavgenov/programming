#include <iostream>

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

const int s=2;

void bfs(int g[][s],int i){

}

int main(){
	
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











































