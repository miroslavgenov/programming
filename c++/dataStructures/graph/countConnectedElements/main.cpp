#include <iostream>
#include <vector>

using namespace std;

const int s=7;
bool visitedEdges[s]{0};
vector <int> edgesVisited;

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

stack* createNewStack(int number){
  return new stack{number, nullptr, nullptr};
}

void dfs(int g[][s], int i){
  if(visitedEdges[i] == 0){
	visitedEdges[i] = 1;
    appendStack(stackRoot, createNewStack(i));
    edgesVisited.push_back(i);
    
    for(int j = 0; j<s; j++){
      if(g[i][j] == 1 && visitedEdges[j] == 0){
          appendStack(stackRoot, createNewStack(j));
          dfs(g,popStack(stackRoot)->edge);
      }
    }
  }
}

int countConnectedEdges(int g[][s]){
  int countSubGraph = 0;
  for(int i = 0; i<s; i++){
    if(visitedEdges[i] == 0){
    	dfs(g, i);
    	if(edgesVisited.size() > 1){
    		countSubGraph++;
    		edgesVisited.clear();
		}
	}
	edgesVisited.clear();
  }
  return countSubGraph;
}


int main(){
  int g[][s]={
    {0,1,0,0},
    {1,0,0,0},
    {0,0,0,1},
    {0,0,1,0}
  };
}