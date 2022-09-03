#include <iostream>
#include <vector>

using namespace std;

const int graphSize = 9;
int verticiesDistance[graphSize]{0};


struct stack{
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
		
		::stackRoot = new stack{value->vertexNumber, value->edgeWeight, nullptr, nullptr};
		
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
			cout<<point->vertexNumber<<" "<<point->edgeWeight<<endl;
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){

	int vertexNumber;
	int edgeWeight;

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		vertexNumber = stackRoot->vertexNumber;
		edgeWeight = stackRoot->edgeWeight;
		stackRoot=nullptr;
		return new stack{vertexNumber, edgeWeight,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		vertexNumber= stackPoint->vertexNumber;
		edgeWeight = stackRoot->edgeWeight;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{vertexNumber, edgeWeight,nullptr,nullptr};
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
	int *edgeMinWeight = nullptr;
	int *vertexNumber = nullptr;
	
	if(stackRoot){

		point = stackRoot;
		
		vertexNumber = new int{point->vertexNumber};
		edgeMinWeight = new int{point->edgeWeight};

		while(point){
			if(*edgeMinWeight > point->edgeWeight){
				edgeMinWeight = new int{point->edgeWeight};
				vertexNumber = new int{point->vertexNumber};
			}
			point = point->next;
		}
	}
	return new stack{*vertexNumber,*edgeMinWeight,nullptr,nullptr};
}

void removeFromStack(int vertexNumber, int edgeWeight){
	stack* point = nullptr;
	if(stackRoot){
		cout<<"stack root is not empty"<<endl;
		cout<<"find value: vertexNumber: "<<vertexNumber<<" edgeWeight: "<<edgeWeight<<endl;
		point = stackRoot;
		while(point){
			if(point->vertexNumber == vertexNumber && point->edgeWeight == edgeWeight){
				cout<<point->vertexNumber<<" "<<point->edgeWeight<<endl;
				cout<<"found"<<endl;
				break;
			}else{
				point= point->next;	
			}
			
		}

		if(point){
			cout<<"found: "<<point->vertexNumber<<"  weight: "<<point->edgeWeight<<endl;
			if(!point->prev && !point->next){
				cout<<"point dont have prev and next"<<endl;
				stackRoot = nullptr;
			}else{
				cout<<"point have prev or next"<<endl;
				if(point->prev && point->next){
					cout<<"point have prev and next"<<endl;
					point->prev->next = point->next;
					point->next->prev = point->prev;
				}else if(point->prev && !point->next){
					cout<<"point have prev but don't have next"<<endl;
					point->prev->next=nullptr;
				}else if(!point->prev && point->next){
					cout<<"point have next but don't have prev"<<endl;
					stackRoot = stackRoot->next;
					stackRoot->prev=nullptr;

				}
			}
		}else{
			cout<<" don't found"<<endl;
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
vector<int> path;
void dijkstra(int graph[][graphSize], int startVertex, int targetVertex) {

    if (isVerticiesDistanceEmpty()) {
        cout << "verticiesDistance is empty" << endl;
        verticiesDistance[startVertex] = 1;
        path.push_back(startVertex);

        cout << "parent: " << startVertex << " childs: ";
        for (int i = 0; i < graphSize; i++) {
            if (graph[startVertex][i] != 0) {
                cout << "from parent: " << startVertex << " to child: " << i << " weight: " << (verticiesDistance[startVertex] + graph[startVertex][i]) << endl;
                if (verticiesDistance[i] == 0) {
                    cout << "child: " << i << " don't have distance from: " << startVertex << endl;
                    verticiesDistance[i] = verticiesDistance[startVertex] + graph[startVertex][i];
                    appendStack(stackRoot, new stack {
                        i,
                        verticiesDistance[i],
                        nullptr,
                        nullptr
                    });
                } else {
                    cout << "child: " << i << " already have weight compare and update if new value is less" << endl;
                }

            }

        }

        dijkstra(graph, startVertex, targetVertex);

    } else {
    	
        cout << "verticiesDistance is not empty" << endl;
        stack * minEdge = findMinWeight(stackRoot);
        path.push_back(minEdge->vertexNumber);
        
        if(minEdge->vertexNumber == targetVertex){
        	cout<<" found"<<endl;
        	return;
        }

        removeFromStack(minEdge -> vertexNumber, minEdge -> edgeWeight);
        // printStack(stackRoot);
        cout << "startVertex: " << minEdge -> vertexNumber << endl;
        for (int i = 0; i < graphSize; i++) {
            if (graph[minEdge -> vertexNumber][i] != 0) {
                if (verticiesDistance[i] != 0) {
                    cout << i << " have distance of" << verticiesDistance[i] << endl;
                    cout << "check if vertex: " << minEdge -> vertexNumber << " edge distance" << (minEdge -> edgeWeight + graph[minEdge -> vertexNumber][i]) << " to: " << i << " is less distance from: " << verticiesDistance[i] << endl;
                    if ((minEdge -> edgeWeight + graph[minEdge -> vertexNumber][i]) < verticiesDistance[i]) {
                        cout << " yes it's less distance" << endl;
                    } else {
                        cout << " not it's not less distance" << endl;
                    }
                } else {
                    cout << "from: " << minEdge -> vertexNumber << " to: " << i << " don't have distance" << endl;
                    cout << "the distance will be: " << (minEdge -> edgeWeight + graph[minEdge -> vertexNumber][i]) << endl;
                    verticiesDistance[i] = minEdge -> edgeWeight + graph[minEdge -> vertexNumber][i];
                    appendStack(stackRoot, new stack {
                        i,
                        verticiesDistance[i],
                        nullptr,
                        nullptr
                    });
                }
            }
        }
        if (stackRoot) {
            dijkstra(graph, startVertex, targetVertex);
        } else {
            return;
        }
    }

}


int main(){
	int graph[graphSize][graphSize]={
		{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	dijkstra(graph,0,4);

	// for(int i=0;i<graphSize;i++){
	// 	cout<<verticiesDistance[i]<<" ";
	// }
	// printStack(stackRoot);
	for(int i=0;i<path.size();i++){
		cout<<path[i]<<" ";
	}

}
