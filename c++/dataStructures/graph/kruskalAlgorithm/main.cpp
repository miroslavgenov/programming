#include <iostream>
#include <vector>

using namespace std;

const int s = 4;
vector<int> vstack;

void printGraph(int g[][s]);


struct edgeConnection{
	//TODO: rename fromEdgeNumber to fromVertexNumber
	int fromEdgeNumber;
		//TODO: rename fromEdgeNumber to toVertexNumber
	int toEdgeNumber;
	int value;
};

struct stack{
	edgeConnection* edgeConnection;
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
		
		::stackRoot = new stack{value->edgeConnection,nullptr,nullptr};
		
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
			cout<<point->edgeConnection->value<<" ";
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){

	int fromEdge,toEdge,value;

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		fromEdge = stackRoot->edgeConnection->fromEdgeNumber;
		toEdge = stackRoot->edgeConnection->toEdgeNumber;
		value = stackRoot->edgeConnection->value;
		stackRoot=nullptr;
		return new stack{new edgeConnection{fromEdge,toEdge,value} ,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		fromEdge = stackPoint->edgeConnection->fromEdgeNumber;
		toEdge = stackPoint->edgeConnection->toEdgeNumber;
		value = stackPoint->edgeConnection->value;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{new edgeConnection{fromEdge,toEdge,value},nullptr,nullptr};
	}
	return stackRoot;
}






int totalVerticies=0;

int span[s][s]{0}; // contains the minimum path
int gCon[s][s]{0};


stack* createNewStack(int fromEdge, int toEdge, int value){
  return new stack{new edgeConnection{fromEdge,toEdge,value}, nullptr, nullptr};
  
}

stack* getStackElement(int index){
	stack* point = stackRoot;
	int count = 0;

	while(point){
		if(count == index){
			return point;
		}
		count++;
		point = point->next;
	}
	return nullptr;
	
	
}

edgeConnection* getShortesConnectionAndIncrementTotalConnections(int g[][s]){
	cout<<endl<<"getShortesConnection"<<endl;
	int *min = nullptr;
	int *edgeNumber = nullptr;
	int *fromEdge = nullptr;
  	
	
		
		for(int i = 0; i < s; i++){
			for(int j=0; j<s; j++){
				if(g[i][j] != 0){
					if(min == nullptr){
						min = new int{g[i][j]};
						edgeNumber = new int{j};
						fromEdge = new int{i};
					}else{
						if(*min > g[i][j]){
							min = new int{g[i][j]};
							fromEdge = new int{i};
							edgeNumber = new int{j};
						}
					}
				}
			} 
		}
		::totalVerticies++;
		appendStack(stackRoot, createNewStack(*fromEdge,*edgeNumber,*min));
		return new edgeConnection{*fromEdge, *edgeNumber, *min};
}

void printShortesConnectionInGraph(int g[][s]){
  int *min = nullptr;
  int *edgeNumber = nullptr;
  int *fromEdge = nullptr;
  
  for(int i = 0; i < s; i++){
    for(int j=0; j<s; j++){
      if(g[i][j] != 0){
    	if(min == nullptr){
        min = new int{g[i][j]};
        edgeNumber = new int{j};
        fromEdge = new int{i};
      }else{
        if(*min > g[i][j]){
          min = new int{g[i][j]};
          fromEdge = new int{i};
          edgeNumber = new int{j};
        }
      }
    }
    }
    
  }
  cout<<"from: "<<*fromEdge<<" to: "<<*edgeNumber<<" is: "<<*min<<endl;
  
  delete fromEdge;
  delete edgeNumber;
  delete min;
  
}

bool isSpanEmpty(int span[][s]){
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			if(span[i][j] !=0){
				return false;
			}
		}
	}
	return true;
}



void appendToSpan(int span[][s], int fromEdge , int toEdge, int value){
	span[fromEdge][toEdge] = value;
	span[toEdge][fromEdge] = value;
}



void clearConnection(int [][s], edgeConnection*);



bool visitedEdges[s]{0};
void clearVisitedEdges(){
	for(int i=0;i<s;i++){
		visitedEdges[i]=0;
	}
}
vector<int> edgeVisited;

void dfs(int gr[][s],int i){
	if(visitedEdges[i] == 0){
		cout<<"edge: "<<i<<endl;
		visitedEdges[i]=1;

		vstack.push_back(i);
		edgeVisited.push_back(i);
		
		for(int j =0; j<s; j++){
			if(gr[i][j] != 0){
				if(visitedEdges[j]==0){

					vstack.push_back(j);
					cout<<i<<" ednge appended: "<<j<<endl;
					
					dfs(gr,vstack[vstack.size()-1]);
					vstack.pop_back();
				}

			}
		}
	}
	
	
}

bool isEdgeInTheSameGraphInSpan(vector<int> edgeVisited,int e){
	for(int i=0;i<edgeVisited.size();i++){
		if(edgeVisited[i] == e){
			return true;
		}
	}
	return false;
	
}

// TODO EDIT this function
void kruskal(int g[][s], int span[][s]){
	cout<<endl<<"kruskal"<<endl;
	edgeConnection *ed = nullptr;
	
	if(totalVerticies == s-1){
		cout<<"done"<<endl;
	}else{
		if(isSpanEmpty(span)){
			
			cout<<"span is empty"<<endl;
			cout<<"totalVeriticies are: "<<totalVerticies<<endl;
			ed = getShortesConnectionAndIncrementTotalConnections(::gCon);
			cout<<ed->fromEdgeNumber<<" "<<ed->toEdgeNumber<<" "<<ed->value<<endl;
			appendToSpan(span, ed->fromEdgeNumber,ed->toEdgeNumber,ed->value);
			printGraph(span);
			cout<<"edge visited"<<endl;
			for(int i=0;i<edgeVisited.size();i++)cout<<edgeVisited[i]<<" ";
			clearVisitedEdges();
						
//			cout<<"gCon"<<endl;
			clearConnection(gCon,ed);
			printGraph(gCon);
			cout<<"totalVeriticies are: "<<totalVerticies<<endl;
      		kruskal(g,span);
			
			
		}else{
			cout<<endl<<"span is not empty"<<endl;
			cout<<"totalVeriticies are: "<<totalVerticies<<endl;
			//TOTO check if the edge is part of existing group if it is then find next
			ed = getShortesConnectionAndIncrementTotalConnections(gCon);
			cout<<ed->fromEdgeNumber<<" "<<ed->toEdgeNumber<<" "<<ed->value<<endl;
			dfs(span,ed->fromEdgeNumber);
			if(edgeVisited.size()==1){
				cout<<"size==1"<<endl;
				clearVisitedEdges();
				edgeVisited.clear();
				clearConnection(gCon,ed);
				appendToSpan(span,ed->fromEdgeNumber,ed->toEdgeNumber,ed->value);
				printGraph(span);
				printGraph(gCon);
				
			}else{
				cout<<"size> 1"<<endl;
				cout<<ed->fromEdgeNumber<<" "<<ed->toEdgeNumber<<" "<<ed->value<<endl;

				if(isEdgeInTheSameGraphInSpan(edgeVisited,ed->fromEdgeNumber) && isEdgeInTheSameGraphInSpan(edgeVisited,ed->toEdgeNumber)){
					cout<<"there is looop"<<endl;
					totalVerticies--;
					edgeVisited.clear();
					clearVisitedEdges();
					clearConnection(gCon,ed);
					printGraph(gCon);
				}else{
					cout<<"totalVeriticies are: "<<totalVerticies<<endl;
					cout<<"you can add it"<<endl;
					edgeVisited.clear();
					clearVisitedEdges();
					clearConnection(gCon,ed);
					appendToSpan(span,ed->fromEdgeNumber,ed->toEdgeNumber,ed->value);
				}
			
			}

			kruskal(g,span);
			
		}
		
	}
	
}

vector<int> ssteck;
int spanWeight=0;
void dfsPr(int span[][s],int i){
  if(visitedEdges[i] == 0){
    visitedEdges[i] = 1;
    ssteck.push_back(i);
    
    
    for(int j=0;j<s;j++){
      if(span[i][j] !=0 && visitedEdges[j] == 0)
      {
        cout<<"from: "<<i<<" to: "<<j<<" = "<<span[i][j]<<endl;
        spanWeight += span[i][j];
		ssteck.push_back(j);
      dfsPr(span,ssteck[ssteck.size()-1]);
      ssteck.pop_back();
      }
    }
    
  }
}

int main(){
	int g[s][s] = {
			{0,10,6,5},
			{10,0,0,15},
			{6,0,0,4},
			{5,15,4,0}


	};
	
  // copyGraph(int src[][s], int dst[][s]);
  for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			::gCon[i][j] = g[i][j];
			
		}
	}
	

	kruskal(g,span);
	

	dfsPr(span,0);
	cout<<spanWeight<<endl;
	
	
	
	
}

void clearConnection(int gCon[][s], edgeConnection* ed){
  gCon[ed->fromEdgeNumber][ed->toEdgeNumber] = 0;
      		gCon[ed->toEdgeNumber][ed->fromEdgeNumber] = 0;
}

void printGraph(int g[][s]){
  cout<<endl;
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      cout<<g[i][j]<<" ";
    }cout<<endl;
  }
  cout<<endl;
}



















































