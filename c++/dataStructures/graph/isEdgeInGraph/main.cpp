#include <iostream>
#include <vector>

using namespace std;

const int s=4;
bool visitedEdges[s]{0};

struct stack{
	int edge;
	stack* next;
	stack* prev;
};

stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* stackRoot,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		
		::stackRoot = new stack{value->edge,nullptr,nullptr};
		
	}else{
		point = stackRoot;
	while(point->next){
		point=point->next;
	}
	point->next = value;
	value->prev = point;	
	}
}

void printStack(stack* root){
	if(!isStackEmpty()){
		stack* point = root;
		while(point){
			cout<<point->edge<<" ";
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
}

stack* popStack(stack* root){

	int edgeNumber;

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		edgeNumber= stackRoot->edge;
		stackRoot=nullptr;
		return new stack{edgeNumber,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		edgeNumber= stackPoint->edge;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{edgeNumber,nullptr,nullptr};
	}
	return stackRoot;
}

vector<int> edgesVisited;

bool isEdgeInGraph(vector<int> graphEdges, int edgeNumber){
	for(int i=0; i<graphEdges.size(); i++){
		if(graphEdges[i] == edgeNumber){
			graphEdges.clear();
			return true;
		}
	}
	graphEdges.clear();
	return false;
}

bool isEdgeVisited(int edgeNumber){
	return visitedEdges[edgeNumber] == 1;
}
void setWhichEdgeWasVisited(int visitedEdgeNumber){
	visitedEdges[visitedEdgeNumber] = 1;
}
stack* createNewStack(int number){
	return new stack{number, nullptr, nullptr};
}

bool isThisEdgeConnectedToThatEdge(int g[][s], int rootEdge, int connectedEdge){
	return g[rootEdge][connectedEdge] == 1;
}

bool isEdgeAcceptable(int g[][s], int i ,int j){
	return isThisEdgeConnectedToThatEdge(g,i,j) && !isEdgeVisited(j);
}

void dfs(int g[][s], int i, int e){
	if(!isEdgeVisited(i)){
		setWhichEdgeWasVisited(i);
		appendStack(stackRoot,createNewStack(i));
		edgesVisited.push_back(i);
		
		for(int j=0; j<s; j++){	
			if(isEdgeAcceptable(g,i,j)){
					appendStack(stackRoot,createNewStack(j));
					dfs(g,popStack(stackRoot)->edge,e);
			}
		}
	}
}

int main(){
	int g[s][s] = {
		{0, 1, 0, 1},
		{1, 0, 0, 1},
		{0, 0, 0, 0},
		{1, 1, 0, 0}
	};
    dfs(g,0,0);
    
    cout<<isEdgeInGraph(edgesVisited,2);
	
	
}






































































