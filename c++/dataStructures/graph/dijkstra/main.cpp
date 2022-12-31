#include <iostream>
#include <vector>
#include <limits>

#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"

using namespace std;

const int graphSize = 25;//7;
int verticiesDistance[graphSize]{0};
bool visitedVerticies[graphSize]{0};

void fillVerticiesDistanceWithInfinity(){
	int infinity = std::numeric_limits<int>::max();
	
	for(int i= 0;i<graphSize;i++){
		verticiesDistance[i] = infinity;
	}
}


struct vertexConnection{
    int connectionFromVertex;
    int connectionToVertex;
    int connectionWeight;
};


// isVertexConnectionMinimum(weight: int): bool
// setTheMinimumVertexConnection(srcData, dstData: srcVertexConnection,vertexConnection**): void

bool isTheNewConnectionWeightLessThan(int currentConnectionWeight, int prevConnectionWeight){
    return prevConnectionWeight > currentConnectionWeight;
}

template <typename T>
vertexConnection* findTheMinimumConnectionWeight(Stack<T>* stack){
    vertexConnection* minimumConnection = nullptr;
    
    if(stack->isEmpty() == false){
        
        linkedListStruct<T>* point =  stack->linkedListHelper->linkedListRoot;

        int minimumConnectionWeight = point->data->connectionWeight; 

        minimumConnection = new vertexConnection{
                    point->data->connectionFromVertex,
                    point->data->connectionToVertex,
                    point->data->connectionWeight
                };

        while(point){
            if(minimumConnectionWeight > point->data->connectionWeight ){                
                // print(point->data);
                
                minimumConnection = new vertexConnection{
                    point->data->connectionFromVertex,
                    point->data->connectionToVertex,
                    point->data->connectionWeight
                };
            }
            
            
            point = point->next;
        }

        
    }

    return minimumConnection;
}

void print(vertexConnection* connection){
    cout<<"connectionFromVertex: "<<connection->connectionFromVertex<<"\nConnectionToVertex: "<<connection->connectionToVertex<<"\nConnectionWeight: "<<connection->connectionWeight<<endl;
}

bool isVertexConnectionsEqual(vertexConnection* first, vertexConnection* sec){
     if(first != nullptr && sec != nullptr){
        if(first->connectionFromVertex == sec->connectionFromVertex & first->connectionToVertex == sec->connectionToVertex & first->connectionWeight == sec->connectionWeight){
            return true;
        }
     }
        

     return false;
}

template <typename T>
void removeFromStackByVertexConnection(Stack<T>* stack,linkedListStruct<T>** linkedListRoot, vertexConnection* target){
    if(stack->isEmpty() == false){
        linkedListStruct<T>* linkedListRootPointer = *linkedListRoot;
        // if the target is first in stack
        if(isVertexConnectionsEqual(linkedListRootPointer->data, target)){
            stack->linkedListHelper->deleteAtBegining();
        }
        // if target is not first in stack
        else{
            cout<<"the target is not first in stack"<<endl;
            while(linkedListRootPointer->next){
                if(isVertexConnectionsEqual(linkedListRootPointer->next->data, target)){
                    // print(linkedListRootPointer->data);
                    // print(linkedListRootPointer->next->data);

                    // if next don't have next do this ...
                    if(linkedListRootPointer->next->next == nullptr){
                        cout<<"next  dont have next"<<endl;
                        stack->linkedListHelper->deleteAtEnd();
                        
                    }
                    // if the next have next->next do this ...
                    else if(linkedListRootPointer->next->next != nullptr){
                        cout<<"next has next"<<endl;
                        linkedListRootPointer->next = linkedListRootPointer->next->next;
                        stack->linkedListHelper->decrementSize();

                    }

                    break;
                }
                
                linkedListRootPointer = linkedListRootPointer->next;
            }

        }
    }

    
}

template <typename T>
void print(Stack<T>* stack){
    if(stack->isEmpty() == false){
        linkedListStruct<T> * point = stack->linkedListHelper->linkedListRoot;

        while(point){
            cout<<point->data->connectionWeight<<endl;
            point = point->next;
        }
    }
}

// int main(){
//     Stack<vertexConnection*> * stack  = new Stack(new vertexConnection{1,1,1});
//     stack->push(new vertexConnection{4,4,2});
//     stack->push(new vertexConnection{1,2,0});

//     vertexConnection* target = findTheMinimumConnectionWeight(stack);
    
//     removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot,target);
// }

void dijkstra(){}






int main(){
	//is it worth to make this into graph class ?
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

    Stack<vertexConnection*> *stack = new Stack(new vertexConnection{-1,0,verticiesDistance[0]});

	// dijkstra(stack, graph, 0, 24);
	

}