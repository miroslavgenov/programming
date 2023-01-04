#pragma once
//remove iostream && include
#include <iostream>
using namespace std;

#include <limits>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/DijkstraStackUtil.h"


class dijkstra{
    // int graphSize;// = 25;//7;
    int **graph=nullptr;
    int graphSize;
    Stack<vertexConnection*>* stack = nullptr;

    void fillVerticiesDistanceWithInfinity(){
        int infinity = std::numeric_limits<int>::max();
	
        for(int i= 0;i<graphSize;i++){
            verticiesDistance[i] = infinity;
        }
    }

public:
    int *verticiesDistance = nullptr;

    // the two dimension graph must be a square matrix
    dijkstra(int graphInSingleDimension[], int twoDimensionGraphSize){

        // initialize the begining        
        verticiesDistance = new int[twoDimensionGraphSize];
        fillVerticiesDistanceWithInfinity();

        graphSize = twoDimensionGraphSize;
        graph = new int*[twoDimensionGraphSize];
        
        // fill the outer arrays with inner arrays
        for(int i = 0; i < graphSize; i++){
            graph[i] = new int[twoDimensionGraphSize];
        }

        // transfer the single graph into two dimension
        int iterator = 0;
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                 graph[i][j]= graphInSingleDimension[iterator++];
            }
        }

        // init the stack
        stack = new Stack(new vertexConnection{-1,0,0});
        verticiesDistance[stack->getTop()->connectionToVertex] = 0;
        
    }

    // the starting vertex is  0
    void findPathToVertex(int destinationVertex){

    //    cout<<stack->getTop()->connectionFromVertex<<endl; 
    if(stack->isEmpty() == false){
    //     // cout<<"dijkstra stack is not empty"<<endl;
        
    //     //get the minvc and remove it
        vertexConnection* minvc =DijkstraStackUtil::findTheMinimumConnectionWeight(stack);
        
        DijkstraStackUtil::removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot,minvc);


        
    //     // is the current minvc weight lesser than the stored distance if yes then write the lesser 
        if(minvc->connectionWeight < verticiesDistance[minvc->connectionToVertex]){
            verticiesDistance[minvc->connectionToVertex] = minvc->connectionWeight;
        }

    //     //append the other connections if any
        int connectionWeight = 0;
        int currentVertexConnectionWeight = 0;

        // loop throug the connected verticies
        for(int i=0;i<graphSize;i++){
            currentVertexConnectionWeight = graph[minvc->connectionToVertex][i];
            // if the weight is not 0 and lesser than the written connection append to stack
            if(currentVertexConnectionWeight!=0){
                connectionWeight = minvc->connectionWeight + currentVertexConnectionWeight;
                if(verticiesDistance[i] > connectionWeight){
                    // cout<<"connection from: "<<minvc->connectionToVertex<<" to: "<<i<<" with weight: "<<connectionWeight<<endl;
                    stack->push(new vertexConnection{minvc->connectionToVertex,i,connectionWeight});
                }

            }
            
        }

        if(minvc->connectionToVertex == destinationVertex){
            return;
        }else{
            findPathToVertex(destinationVertex);
        }

    }

}

};
