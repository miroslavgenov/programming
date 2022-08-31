#include <iostream>
#include <vector>

using namespace std;

vector<int> vstack;

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





const int s = 6;

bool isEdgeInStack(int edgeNumber){
	stack* point = stackRoot;
	
	while(point->edge != edgeNumber ){
		if(point->next){
			point=point->next;
		}else{
			return 0;
		}
	}
	if(point->edge==edgeNumber){
		return 1;
	}
	return 0;
}

bool visitedNodes[s]{0};

void dfs(int g[][s],int i){
	if(visitedNodes[i] == 0){
		cout<<"edge: "<<i<<endl;
		visitedNodes[i]=1;
		appendStack(stackRoot,new stack{i,nullptr,nullptr});
//		vstack.push_back(i);
		
		for(int j =0; j<s; j++){
			if(g[i][j] == 1){
				if(visitedNodes[j]==0){
					appendStack(stackRoot,new stack{j,nullptr,nullptr});
//					vstack.push_back(j);
					cout<<i<<" ednge appended: "<<j<<endl;
					dfs(g,popStack(stackRoot)->edge);
//					dfs(g,vstack[vstack.size()-1]);
//					vstack.pop_back();
				}

			}
		}
	}
	
	
}

int main(){
	
	int g[s][s]={
		{0,1,1,0,1,0},
		{1,0,1,1,0,0},
		{1,1,0,0,0,0},
		{0,1,0,0,0,0},
		{1,0,0,0,0,1},
		{0,0,0,0,1,0}
	};
	
	dfs(g,2);

	
}
























































