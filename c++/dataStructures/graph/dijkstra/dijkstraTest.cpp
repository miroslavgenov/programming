#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int graphSize = 7;
int verticiesDistance[graphSize]{0};
bool visitedVerticies[graphSize]{0};


struct stack{
	int prevVertex;
	int vertexNumber;
	int edgeWeight;
	stack* next;
	stack* prev;
};

struct vertex{
	int vertexNumber;
	vector<int> childs;
};

stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* stackRoot,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		
		::stackRoot = new stack{value->prevVertex,value->vertexNumber, value->edgeWeight, nullptr, nullptr};
		
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
			cout<<point->prevVertex<<" "<<point->vertexNumber<<" "<<point->edgeWeight<<endl;
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){

	int prevVertex;
	int vertexNumber;
	int edgeWeight;

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		prevVertex = stackRoot->prevVertex;
		vertexNumber = stackRoot->vertexNumber;
		edgeWeight = stackRoot->edgeWeight;
		stackRoot=nullptr;
		return new stack{prevVertex,vertexNumber, edgeWeight,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}
		prevVertex = stackRoot->prevVertex;
		vertexNumber= stackPoint->vertexNumber;
		edgeWeight = stackRoot->edgeWeight;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{prevVertex, vertexNumber, edgeWeight,nullptr,nullptr};
	}
	return stackRoot;
}

bool isVertexInStack(int vertexNumber){
	stack* point = stackRoot;
	
	while(point->vertexNumber != vertexNumber ){
		if(point->next){
			point=point->next;
		}else{
			return 0;
		}
	}
	if(point->vertexNumber==vertexNumber){
		return 1;
	}
	return 0;
}

stack* findMinWeight(stack* stackRoot){
	stack* point = nullptr;
	int prevVertex;
	int *edgeMinWeight = nullptr;
	int *vertexNumber = nullptr;
	
	if(stackRoot){

		point = stackRoot;
		
		prevVertex = point->prevVertex;
		vertexNumber = new int{point->vertexNumber};
		edgeMinWeight = new int{point->edgeWeight};

		while(point){
			if(*edgeMinWeight > point->edgeWeight){
				prevVertex = point->prevVertex;
				edgeMinWeight = new int{point->edgeWeight};
				vertexNumber = new int{point->vertexNumber};
			}
			point = point->next;
		}
		
	}
	return new stack{prevVertex,*vertexNumber,*edgeMinWeight,nullptr,nullptr};
}

void removeFromStack(int vertexNumber, int edgeWeight){
	stack* point = nullptr;
	if(stackRoot){
//		cout<<"stack root is not empty"<<endl;
//		cout<<"find value: vertexNumber: "<<vertexNumber<<" edgeWeight: "<<edgeWeight<<endl;
		point = stackRoot;
		while(point){
			if(point->vertexNumber == vertexNumber && point->edgeWeight == edgeWeight){
				cout<<point->vertexNumber<<" "<<point->edgeWeight<<endl;
//				cout<<"found"<<endl;
				break;
			}else{
				point= point->next;	
			}
			
		}

		if(point){
//			cout<<"found: "<<point->vertexNumber<<"  weight: "<<point->edgeWeight<<endl;
			if(!point->prev && !point->next){
//				cout<<"point dont have prev and next"<<endl;
				stackRoot = nullptr;
			}else{
//				cout<<"point have prev or next"<<endl;
				if(point->prev && point->next){
//					cout<<"point have prev and next"<<endl;
					point->prev->next = point->next;
					point->next->prev = point->prev;
				}else if(point->prev && !point->next){
//					cout<<"point have prev but don't have next"<<endl;
					point->prev->next=nullptr;
				}else if(!point->prev && point->next){
//					cout<<"point have next but don't have prev"<<endl;
					stackRoot = stackRoot->next;
					stackRoot->prev=nullptr;

				}
			}
		}else{
//			cout<<" don't found"<<endl;
		}
		
		
		
	}else{
		cout<<"stackRoot is empty"<<endl;
	}
}

bool isVerticiesDistanceEmpty(){
	for(int i=0;i<graphSize;i++){
		if(verticiesDistance[i] != 0){
			return false;
		}
	}
	return true;
}

template <typename T>
void print(T array[], size_t size){
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}

void fillVerticiesDistanceWithInfinity(){
	int infinity = std::numeric_limits<int>::max();
	
	for(int i= 0;i<graphSize;i++){
		verticiesDistance[i] = infinity;
	}
}

template <typename T>
void print(vector<T> list){
	for(int i=0;i<list.size();i++){
		cout<<list[i]<<" ";
	}
}



vector<int> path;
void dijkstra(int graph[][graphSize], int startVertex, int targetVertex) {
	
	
	
	if(stackRoot){
		stack* s =  nullptr;
	s = findMinWeight(stackRoot);
	removeFromStack(s->vertexNumber,s->edgeWeight);
	
		if(visitedVerticies[s->vertexNumber] == true){
		cout<<"vertex: "<<s->vertexNumber<<" is visited visited"<<endl;
		cout<<"check if the weight is less!"<<endl;
	}else{
		cout<<"vertex: "<<s->vertexNumber<<" is not visited"<<endl;
		
		cout<<s->edgeWeight<<endl;
		verticiesDistance[s->vertexNumber] = s->edgeWeight;
		cout<<"append the neighbours of: "<<s->vertexNumber<<endl;

		for (int i = 0; i < graphSize; ++i)
		{
			if(graph[s->vertexNumber][i] != 0 && visitedVerticies[i] == 0){
				cout<<graph[s->vertexNumber][i]<<" ";
				appendStack(stackRoot, new stack{s->vertexNumber,i,verticiesDistance[s->vertexNumber]+graph[s->vertexNumber][i],nullptr,nullptr});
			}else if(graph[s->vertexNumber][i] != 0 && visitedVerticies[i] == 1){
				cout<<"vertext: "<<i<<" is "<<endl;
			}
			
		}

	}	
	}
	
	
	

	
	


}







int main(){
	int graph[graphSize][graphSize]={
		{0,	1,	4,	0,	0,	0,	0,},
		{1,	0,	1,	2,	1,	0,	0,},
		{4,	1,	0,	0,	2,	4,	0,},
		{0,	2,	0,	0,	0,	0,	0,},
		{0,	1,	2,	0,	0,	0,	2,},
		{0,	0,	4,	0,	0,	0,	3,},
		{0,	0,	0,	0,	2,	3,	0,}

	};

	fillVerticiesDistanceWithInfinity();
	verticiesDistance[0] = 0;
	appendStack(stackRoot, new stack{-1,0,verticiesDistance[0],nullptr, nullptr});
	dijkstra(graph,0,6);
	dijkstra(graph,0,6);


	

	

	


	// for(int i=0;i<graphSize;i++){
	// 	cout<<verticiesDistance[i]<<" ";
	// }
	// printStack(stackRoot);
	
	// for(int i=0;i<path.size();i++){
	// 	cout<<path[i]<<" ";
 //  	}

}




































