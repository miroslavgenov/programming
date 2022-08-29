#include <iostream>

using namespace std;


struct queue{
	int edgeNumber;
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

const int s=5;
bool visitedEdges[s]{0};

void bfs(int g[][s],int i){
	if(visitedEdges[i]==0){
		visitedEdges[i]=1;
        
        cout<<"edge: "<<i<<endl;
        for(int j = 0; j<s; j++){
            if(g[i][j] == 1 && visitedEdges[j]==0){
                appendQueue(new queue{j,nullptr,nullptr});
            }
        }
        bfs(g,popQueue()->edgeNumber);
    }
    
}

int main(){
	
	int g[s][s]={
		{0,1,0,0,1},
		{1,0,1,1,0},
		{0,1,0,1,0},
		{0,1,1,0,0},
		{1,0,0,0,0},


		
	};
	bfs(g,0);
	
}

queue *popQueue(){
	queue* poped=nullptr;
	
	if(isNull(firstInQueue->prev)){
		poped = new queue{firstInQueue->edgeNumber,nullptr,nullptr};
		firstInQueue=nullptr;
		lastInQueue=nullptr;
		return poped;
	}else{
		poped = new queue{firstInQueue->edgeNumber,nullptr,nullptr};
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
		cout<<point->edgeNumber<<"  ";
		point=point->next;
	}
}











































