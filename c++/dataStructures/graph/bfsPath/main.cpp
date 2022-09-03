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

bool isInQueue(int value){
	queue* point = lastInQueue;

	if(point){
		while(point){
			if(point->edge==value){
				// cout<<" found: "<<point->edge<<endl;
				return true;
			}
			point = point->next;
		}
		// cout<<"not found"<<endl;
	}
	return false;
}


struct parent{
	int parentNumber;
	vector<int> childs;
};

vector<parent*> parents;

std::vector<int> path;
void bfs(int graph[][graphSize] ,int vertex,int target){
	
		if(visitedVerticies[vertex] == 0){
		visitedVerticies[vertex] = 1;
		path.push_back(vertex);
		
		parents.push_back(new parent{vertex});
		cout<<"!!! parent: "<<parents[parents.size()-1]->parentNumber<<endl;
		
		for(int i=0;i<graphSize;i++){
			if(graph[vertex][i] !=0 && visitedVerticies[i] == 0){
				cout<<"parent: "<<vertex<<" will append: "<<endl;
				if(lastInQueue){
					cout<<"queue is not empty"<<endl;
					cout<<"edge to be appende: "<<i<<endl;
					cout<<"check if: "<<i<<" is in the queue"<<endl;
					if(isInQueue(i)){
						cout<<"edge: "<<i<<" is in the queue! Don't add it"<<endl;
					}else{
						cout<<"edge: "<<i<<" is not in the queue"<<endl;
						parents[parents.size()-1]->childs.push_back(i);
						appendQueue(new queue{i,nullptr,nullptr});
					}
				}else if(!lastInQueue){
					cout<<"queue is empty"<<endl;
					cout<<"appende edge is: "<<i<<endl;
					parents[parents.size()-1]->childs.push_back(i);
					appendQueue(new queue{i,nullptr,nullptr});
				}
				
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

bool isNumberInVector(int number,vector<int> numbers){
	for(int i=0;i<numbers.size();i++){
		if(number == numbers[i]){
			return true;
		}
	}
	return false;
}

int main(){
	int graph[graphSize][graphSize] = {


{0,	1,	1,	0,	0,	0,	0,	0},
{1,	0,	1,	1,	0,	0,	0,	0},
{1,	1,	0,	0,	1,	0,	0,	1},
{0,	1,	0,	0,	1,	0,	0,	0},
{0,	0,	1,	1,	0,	1,	0,	0},
{0,	0,	0,	0,	1,	0,	1,	0},
{0,	0,	0,	0,	0,	1,	0,	1},
{0,	0,	1,	0,	0,	0,	1,	0}
	};

	
	bfs(graph, 0,6);
	vector<parent*> reverseParents;
	for(int i=parents.size()-1;i>=0;i--){
		reverseParents.push_back(parents[i]);
	}

	for(int i=0;i<reverseParents.size();i++)cout<<reverseParents[i]->parentNumber<<' ';
	cout<<" is num: "<<isNumberInVector(reverseParents[0]->parentNumber,reverseParents[2]->childs)<<endl;
	cout<<reverseParents[0]->parentNumber<<endl;
	cout<<reverseParents[2]->parentNumber<<endl;
	
	


	
	



}


































