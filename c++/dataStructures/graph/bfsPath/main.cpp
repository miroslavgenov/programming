#include <iostream>
#include <vector>

using namespace std;

const int graphSize = 8;
bool visitedVerticies[graphSize]{0};


bool isTargetFound = false;


struct queue{
	int edge;
	queue* next;
	queue *prev;
};


queue *firstInQueue=nullptr;
queue *lastInQueue= nullptr;

queue *popQueue(){
	queue* poped=nullptr;
	
	if(!firstInQueue->prev){
		poped = new queue{firstInQueue->edge,nullptr,nullptr};
		firstInQueue=nullptr;
		lastInQueue=nullptr;
		return poped;
	}else{
		poped = new queue{firstInQueue->edge,nullptr,nullptr};
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
		cout<<point->edge<<"  ";
		point=point->next;
	}
}

vector<int> path;

void bfs(int graph[][graphSize] ,int vertex,int target){
	
		if(visitedVerticies[vertex] == 0){
		visitedVerticies[vertex] = 1;
		path.push_back(vertex);
		
		
		
		for(int i=0;i<graphSize;i++){
			if(graph[vertex][i] !=0 && visitedVerticies[i] == 0){
//				cout<<"vertex: "<<vertex<<" append: "<<i<<endl;
				if(target == i){
					path.push_back(i);
					isTargetFound= true;
					return;
				}
				appendQueue(new queue{i,nullptr,nullptr});
			}
		}
		
		
	}
	
	if(lastInQueue){
//		int p  = popQueue()->edge;
//		cout<<"poped from Queue: "<<p<<endl;
		bfs(graph,popQueue()->edge,target);		
	}
	
	
	
}


void searchBfsPathFromVertextToVertextAndShow(int graph[][graphSize], int fromVertex, 
	int toVertext){
	
}

int main(){
	int graph[graphSize][graphSize] = {

{0,	0,	0,	1,	0,	1,	0},
{0,	0,	1,	1,	0,	0,	0},
{0,	1,	0,	0,	0,	0,	0},
{1,	1,	0,	0,	1,	0,	1},
{0,	0,	0,	1,	0,	1,	0},
{1,	0,	0,	0,	1,	0,	0},
{0,	0,	0,	1,	0,	0,	0}
	};

	
	bfs(graph, 1,6);
	bool pointToNext[path.size()]{0};
	int count = 0;

	for(int i = 1 ; i<path.size();i++){

		if(graph[path[i-1]][path[i]]== 1){
			pointToNext[count] = 1;
		}else{
			
		}
			
		if(i == path.size()-1){
			if(graph[path[i]][path[i-1]]){
				count++;
				pointToNext[i] =1;
			}
		}
		count++;
	}
		
	for(int i= 0;i<path.size();i++){
		if(path[i]!=-1)
			cout<<path[i]<<" ";

	}

}


































