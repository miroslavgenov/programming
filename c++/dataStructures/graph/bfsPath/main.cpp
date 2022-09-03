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

bool isVertexInQueue(int vertextNumber){
	queue* point = lastInQueue;

	if(point){
		while(point){
			if(point->edge==vertextNumber){		
				return true;
			}
			point = point->next;
		}
	}
	return false;
}


struct parentVertex{
	int parentVertexNumber;
	vector<int> childs;
};

vector<parentVertex*> parentVerticiesUsedToVindTarget;
void bfs(int graph[][graphSize] ,int vertex,int target){
	
	if(visitedVerticies[vertex] == 0){
		visitedVerticies[vertex] = 1;
	
	
		parentVerticiesUsedToVindTarget.push_back(new parentVertex{vertex});
		cout<<"!!! parentVertex: "<<parentVerticiesUsedToVindTarget[parentVerticiesUsedToVindTarget.size()-1]->parentVertexNumber<<endl;
	
		for(int i=0;i<graphSize;i++){
			if(graph[vertex][i] !=0 && visitedVerticies[i] == 0){
				cout<<"parentVertex: "<<vertex<<" will append: "<<endl;
				if(lastInQueue){
					cout<<"queue is not empty"<<endl;
					cout<<"edge to be appende: "<<i<<endl;
					cout<<"check if: "<<i<<" is in the queue"<<endl;
					if(isVertexInQueue(i)){
						cout<<"edge: "<<i<<" is in the queue! Don't add it"<<endl;
					}
					else{
						cout<<"edge: "<<i<<" is not in the queue"<<endl;
						parentVerticiesUsedToVindTarget[parentVerticiesUsedToVindTarget.size()-1]->childs.push_back(i);
						appendQueue(new queue{i,nullptr,nullptr});
					}
				}else if(!lastInQueue){
					cout<<"queue is empty"<<endl;
					cout<<"appende edge is: "<<i<<endl;
					parentVerticiesUsedToVindTarget[parentVerticiesUsedToVindTarget.size()-1]->childs.push_back(i);
					appendQueue(new queue{i,nullptr,nullptr});
				}
				
			}
		}		
	}
	
	if(lastInQueue){
		bfs(graph,popQueue()->edge,target);		
	}
}


bool isThisVertextChildInThatParent(int thisVertext,vector<int> parentChilds){
	for(int i=0;i<parentChilds.size();i++){
		if(thisVertext == parentChilds[i]){
			return true;
		}
	}
	return false;
}



void showParentChilds(vector<parentVertex*> list){
	for(int i=0;i<list.size();i++){
		cout<<"parentVertex: "<<list[i]->parentVertexNumber<<" childs: ";
		if(list[i]->childs.size()>0){
			for(int j=0;j<list[i]->childs.size();j++){
				cout<<list[i]->childs[j]<<" ";
			}cout<<endl;	
		}else{
			cout<<" don't have childs."<<endl;
		}
	}
	cout<<endl;
}

void filterPathAndPrint(vector<parentVertex*> list){
	vector<int> newPath;
	int childVertexIndex = 0;
	int parentVertexIndex = 1;
	int currentChildVertext;
	showParentChilds(list);
	
	while(parentVertexIndex<list.size()){
		currentChildVertext = list[childVertexIndex]->parentVertexNumber;
		if(isThisVertextChildInThatParent(currentChildVertext,list[parentVertexIndex]->childs)){
			cout<<"currentChildVertex:"<<list[childVertexIndex]->parentVertexNumber<<" is in parentVertex: "<<list[parentVertexIndex]->parentVertexNumber<<endl;
			newPath.push_back(list[childVertexIndex]->parentVertexNumber);
			if(parentVertexIndex == list.size()-1){
				newPath.push_back(list[parentVertexIndex]->parentVertexNumber);
			}
			childVertexIndex = parentVertexIndex;
			parentVertexIndex++;	
		}else{
			cout<<"child:"<<list[childVertexIndex]->parentVertexNumber<<" is not in parentVertex: "<<list[parentVertexIndex]->parentVertexNumber<<endl;
			parentVertexIndex++;	
		}
	}

	vector<int> reversPath;
	for(int i = newPath.size()-1; i>=0; i--) reversPath.push_back(newPath[i])		;	
	for (int i = 0; i < reversPath.size(); ++i)	cout<<reversPath[i]<<" "			;
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
	
	//PATH MUST BE REVERSED !!
	vector<parentVertex*> reverseparentVerticiesUsedToVindTarget;
	for(int i=parentVerticiesUsedToVindTarget.size()-1;i>=0;i--){
		reverseparentVerticiesUsedToVindTarget.push_back(parentVerticiesUsedToVindTarget[i]);
	}
	filterPathAndPrint(reverseparentVerticiesUsedToVindTarget);
	
	
	


	
	



}


































