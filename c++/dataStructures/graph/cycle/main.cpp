#include <iostream>
#include <vector>

using namespace std;

struct stack{
	int edgeNumber;
	stack* next;
	stack* prev;
};

stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* root,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		stackRoot = new stack{value->edgeNumber,nullptr,nullptr};
		
	}else{
		point = root;
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
		cout<<point->edgeNumber<<" ";
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
		edgeNumber = stackRoot->edgeNumber;
		stackRoot=nullptr;
		return new stack{edgeNumber,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		edgeNumber = stackPoint->edgeNumber;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{edgeNumber,nullptr,nullptr};
	}
	return stackRoot;
}



template<typename T>
void printSingleDimensionArray(T a[],int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}





const int s=6;
bool visitedEdges[s]{0};
vector<int> h;


void isThereLoop(int g[][s] ,int i){
	for(int j=0; j<i ; j++){
		if(g[i][j] == 1 && visitedEdges[j] == 1){
			if(j!=h[h.size()-1]){
				if(visitedEdges[j] == 1){
					cout<<endl<<"there  is loop from: "<<i<<" to: "<<j<<endl;
				}
			}
		}
	}
}

void dfs(int g[][s], int i){
	
	if(visitedEdges[i] == 0){
		
		visitedEdges[i]	= 1;
		appendStack(stackRoot,new stack{i,nullptr,nullptr});
		
		cout<<i<<" ";
		isThereLoop(g,i);
		
		for(int j=0; j<s;j++){
			if(g[i][j] == 1 && visitedEdges[j] == 0){
				h.push_back(i);
				appendStack(stackRoot,new stack{j,nullptr,nullptr});
				dfs(g,popStack(stackRoot)->edgeNumber);
			}
		}		
	}
}

int main(){
    int g[s][s]{
        {0,1,0,0,0,1},
        {1,0,1,0,0,1},
        {0,1,0,1,0,0},
        {0,0,1,0,1,0},
        {0,0,0,1,0,1},
        {1,1,0,0,1,0}
    };
    
    dfs(g,0);
}