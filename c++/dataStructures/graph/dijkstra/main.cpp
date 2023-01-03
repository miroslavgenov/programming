#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/dijkstra.h"

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

// void print(vertexConnection* connection){
//     cout<<"connectionFromVertex: "<<connection->connectionFromVertex<<"\nConnectionToVertex: "<<connection->connectionToVertex<<"\nConnectionWeight: "<<connection->connectionWeight<<endl;
// }


// template <typename T>
// void print(Stack<T>* stack){
//     if(stack->isEmpty() == false){
//         linkedListStruct<T> * point = stack->linkedListHelper->linkedListRoot;

//         while(point){
//             cout<<point->data->connectionWeight<<endl;
//             point = point->next;
//         }
//     }
// }


// template <typename T>
// void dijkstra(Stack<T>* stack, int graph[][graphSize], int endVertexLocation){
//     if(stack->isEmpty() == false){
//         // cout<<"dijkstra stack is not empty"<<endl;
        
//         //get the minvc and remove it
//         vertexConnection* minvc =DijkstraStackUtil::findTheMinimumConnectionWeight(stack);
//         DijkstraStackUtil::removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot,minvc);

        
//         // is the current minvc weight lesser than the stored distance if yes then write the lesser 
//         if(minvc->connectionWeight < verticiesDistance[minvc->connectionToVertex]){
//             verticiesDistance[minvc->connectionToVertex] = minvc->connectionWeight;
//         }

//         //append the other connections if any
//         int connectionWeight = 0;
//         int currentVertexConnectionWeight = 0;

//         // loop throug the connected verticies
//         for(int i=0;i<graphSize;i++){
//             currentVertexConnectionWeight = graph[minvc->connectionToVertex][i];
//             // if the weight is not 0 and lesser than the written connection append to stack
//             if(currentVertexConnectionWeight!=0){
//                 connectionWeight = minvc->connectionWeight + currentVertexConnectionWeight;
//                 if(verticiesDistance[i] > connectionWeight){
//                     // cout<<"connection from: "<<minvc->connectionToVertex<<" to: "<<i<<" with weight: "<<connectionWeight<<endl;
//                     stack->push(new vertexConnection{minvc->connectionToVertex,i,connectionWeight});
//                 }

//             }
            
//         }

//         if(minvc->connectionToVertex == endVertexLocation){
//             return;
//         }else{
//             dijkstra(stack,graph,endVertexLocation);
//         }

//     }

// }






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
    
    dijkstra<vertexConnection*>* dijk = new dijkstra(graph, graphSize);
    
	// fillVerticiesDistanceWithInfinity();

    //init the staring vertex weight
    // vertexConnection* startingVertex = new vertexConnection{-1,0,0};
    // verticiesDistance[startingVertex->connectionToVertex] = 0;

    // Stack<vertexConnection*> *stack = new Stack(startingVertex);
    
    // dijkstra(stack, graph, 24);
    // for(int i: verticiesDistance){
    //     cout<<i<<", ";
    // }
}