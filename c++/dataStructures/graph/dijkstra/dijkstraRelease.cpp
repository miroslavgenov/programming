#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int graphSize = 25;//7;
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
	}cout<<endl;
}



void printMinEdgeInfo(stack* mv){
	cout<<"the min Edge is from parent: "<<mv->prevVertex<<" to child: "<<mv->vertexNumber<<" distance: "<<mv->edgeWeight<<endl;
}

vector<stack*> path;

void dijkstra(int graph[][graphSize], int startVertex, int targetVertex) {
	
	
	if(stackRoot){
		cout<<"stack is not empty"<<endl;
		stack* mv = findMinWeight(stackRoot);
		removeFromStack(mv->vertexNumber,mv->edgeWeight);
		printMinEdgeInfo(mv);
		if(visitedVerticies[mv->vertexNumber] == 0){
			if(mv->prevVertex!=-1){
				verticiesDistance[mv->vertexNumber] = mv->edgeWeight;
				visitedVerticies[mv->vertexNumber] = 1;
				path.push_back(mv);

			}else{
				verticiesDistance[mv->vertexNumber] = 0;
				path.push_back(mv);
				visitedVerticies[mv->vertexNumber] = 1;
			}
			cout<<"vertex: "<<mv->vertexNumber<<" is not visited"<<endl;
			cout<<"you can look all of his child's"<<endl;
			
			for(int i=0;i<graphSize;i++){
				if(graph[mv->vertexNumber][i] != 0){
					cout<<"vertext: "<<mv->vertexNumber<<" to child : "<<i<<" distance is: "<<verticiesDistance[mv->vertexNumber] + graph[mv->vertexNumber][i]<<endl;
					appendStack(stackRoot, new stack{mv->vertexNumber, i, verticiesDistance[mv->vertexNumber] + graph[mv->vertexNumber][i]});
				}	
			}cout<<endl;
					
		}else{
			// if next min vertex is visited
			cout<<"vertex: "<<mv->vertexNumber<<" is visited check if the distance is less than current distance!"<<endl;
			cout<<"current weight distance to: "<<mv->vertexNumber<<" is: "<<verticiesDistance[mv->vertexNumber]<<" new weight distance is: "<<mv->edgeWeight <<endl;
			cout<<"check if new distance is less than current weight distance!"<<endl;
			if(verticiesDistance[mv->vertexNumber] > mv->edgeWeight){
				cout<<"current edge weight: "<<verticiesDistance[mv->vertexNumber]<<" on: "<<mv->vertexNumber<<" is greater than new: "<<mv->edgeWeight<<" from vertex: "<<mv->prevVertex<<" update!"<<endl;
				verticiesDistance[mv->vertexNumber] = mv->edgeWeight;
				cout<<"!!!!!!!!!!!!!! UPDATE THE PATH !!!!!!!!!!!!!!!!!!!"<<endl;
				cout<<"!!!!!!!!!!!!!! find the previous weight and remove it !!!!!!!!!!!!!!!!!!!"<<endl;
			}else{
				cout<<"current edge weight: "<<verticiesDistance[mv->vertexNumber]<<" on: "<<mv->vertexNumber<<" is lesser than new: "<<mv->edgeWeight<<" from vertex: "<<mv->prevVertex<<" don't update"<<endl;
			}

		}
		if(mv->vertexNumber == targetVertex){
			cout<<"targetVertex: "<<mv->vertexNumber<<" is found tha min path is: "<<verticiesDistance[mv->vertexNumber]<<endl;
			return;
		}else{
			dijkstra(graph, mv->vertexNumber, targetVertex);
		}
		
		
	}
	
	
	
	

	
	


}







int main(){
	int graph[graphSize][graphSize]={
		// {0,	1,	4,	0,	0,	0,	0,},
		// {1,	0,	1,	2,	1,	0,	0,},
		// {4,	1,	0,	0,	2,	4,	0,},
		// {0,	2,	0,	0,	0,	0,	0,},
		// {0,	1,	2,	0,	0,	0,	2,},
		// {0,	0,	4,	0,	0,	0,	3,},
		// {0,	0,	0,	0,	2,	3,	0,}
        
        //{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        //{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        //{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        //{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        //{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        //{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        //{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        //{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        //{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
{0 , 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{20 , 0 , 53 , 38 , 55 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 53 , 0 , 0 , 0 , 0 , 48 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 38, 0, 0, 0, 52, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 55, 0, 0, 0, 54, 47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 52, 54, 0, 0, 33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 48, 0, 47, 0, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 33, 0, 0, 0, 0, 72, 0, 92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 46, 0, 0, 42, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 46, 0, 67, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 72, 0, 67, 0, 0, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 92, 0, 0, 46, 74, 0, 54, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 36, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0, 0, 34, 88, 0, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 20, 0, 0, 87, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34, 20, 0, 0, 87, 0, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 88, 0, 0, 0, 34, 0, 43, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87, 34, 0, 17, 0, 0, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 87, 0, 0, 17, 0, 0, 111, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 43, 0, 0, 0, 78, 0, 0}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111, 78, 0, 47, 100}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 47, 0, 92}, 
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 92, 0}, 

	};

	fillVerticiesDistanceWithInfinity();
	
	appendStack(stackRoot, new stack{-1,0,verticiesDistance[0],nullptr, nullptr});
	dijkstra(graph,0,24);
	
	for(int i=0;i<graphSize;i++){
		cout<<verticiesDistance[i]<<" ";
	}
	

	cout<<endl;
	// for(int i=0;i<path.size();i++){
	// 	cout<<path[i]->prevVertex<<" "<<path[i]->vertexNumber<<endl;
 //  	}

	
  	vector<stack*> reversePath;
  	for(int i=path.size()-1; i>=0; i--){
  		reversePath.push_back(path[i]);
  	}cout<<endl;
  	
  	// filter path
  	int vertexParent ;
  	vector<int> reverseFilteredPath;
  	for(int i=0;i<reversePath.size();i++){
		if(i == 0){
			vertexParent = reversePath[i]->prevVertex;
			cout<<reversePath[i]->vertexNumber<<" ";
			reverseFilteredPath.push_back(reversePath[i]->vertexNumber);
		}else{
			if(vertexParent == reversePath[i]->vertexNumber){
			cout<<reversePath[i]->vertexNumber<<" ";
			// cout<<reversePath[i]->prevVertex<<" "<<reversePath[i]->vertexNumber<<endl;	
			vertexParent = reversePath[i]->prevVertex;
			reverseFilteredPath.push_back(reversePath[i]->vertexNumber);
			if(vertexParent == -1){
				break;
			}
		}	
		}	
	}	
	
	// final Path
	vector<int> finalPath;
	for(int i= reverseFilteredPath.size()-1; i>=0;i--){
		finalPath.push_back(reverseFilteredPath[i]);
	}

	cout<<endl;
  	for(int i=0;i<finalPath.size(); i++){
  		cout<<finalPath[i]<<" ";
  	}


}




































