#include <iostream>

using namespace std;


constexpr size_t GRAPH_SIZE=8;
bool visitedEdges[GRAPH_SIZE]{0};

struct queue{
	int vertexNumber;
	queue* next;
	queue *prev;
};


queue *firstInQueue=nullptr;
queue *lastInQueue= nullptr;


void initQueue(queue *);

void appendQueue(queue *);

queue* popQueue();

void printQueue();
bool isNull(queue * value){return value == nullptr;}


bool isCurrentVertextConnectedToThisVertex(const int GRAPH[][GRAPH_SIZE], const int vertex, const int thisVertex){
	return GRAPH[vertex][thisVertex];
}

void bfs(const int GRAPH[][GRAPH_SIZE],const int currentVertex){
	if(visitedEdges[currentVertex] == 0){
		visitedEdges[currentVertex] = 1;
        
        cout<<"currentVertex: "<<currentVertex<<endl;
        for(int vertex = 0; vertex < GRAPH_SIZE; vertex++){
            if(isCurrentVertextConnectedToThisVertex(GRAPH, currentVertex, vertex) && visitedEdges[vertex] == 0){
                appendQueue(new queue{vertex, nullptr, nullptr});
            }
        }
       
    }
     if(firstInQueue){
     	bfs(GRAPH, popQueue()->vertexNumber);	
     }
     
}

int main(){
	constexpr int GRAPH[GRAPH_SIZE][GRAPH_SIZE]={
		{0,	1,	1,	0,	0,	0,	0,	0},
		{1,	0,	1,	1,	0,	0,	0,	0},
		{1,	1,	0,	0,	1,	0,	0,	1},
		{0,	1,	0,	0,	1,	0,	0,	0},
		{0,	0,	1,	1,	0,	1,	0,	0},
		{0,	0,	0,	0,	1,	0,	1,	0},
		{0,	0,	0,	0,	0,	1,	0,	1},
		{0,	0,	1,	0,	0,	0,	1,	0}
	};

	bfs(GRAPH,0);
}

queue *popQueue(){
	queue* poped=nullptr;
	
	if(isNull(firstInQueue->prev)){
		poped = new queue{firstInQueue->vertexNumber,nullptr,nullptr};
		firstInQueue=nullptr;
		lastInQueue=nullptr;
	}else{
		poped = new queue{firstInQueue->vertexNumber,nullptr,nullptr};
		firstInQueue=firstInQueue->prev;
		firstInQueue->next=nullptr;
	}
	return poped;
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
		cout<<point->vertexNumber<<"  ";
		point=point->next;
	}
}











































