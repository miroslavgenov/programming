#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/dijkstra.h"

dijkstra::dijkstra(int graphInSingleDimension[], int twoDimensionGraphSize){
    DijkstraUtil::initializeTheGraphSize(graphSize, twoDimensionGraphSize);
   
    initializeAndFillVerticiesDistancesWithInfinity();
    
    DijkstraUtil::initializeTheGraph(&graph, graphSize);
    
    fillTheGraphWithVerticies();

    transferTheSingleGraphIntoTwoDimensional(graphInSingleDimension);

    DijkstraUtil::initializeTheStackAndSetStartingVertex(&stack);
    
    DijkstraUtil::addWeightToTheVerticiesDistance(&verticiesDistance, stack->getTop()->connectionWeight, 0);
}   

void dijkstra::transferTheSingleGraphIntoTwoDimensional(int singleDimensionalGraph[]){
    int iterator = 0;
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
                graph[i][j]= singleDimensionalGraph[iterator++];
        }
    }
}

void dijkstra::fillTheGraphWithVerticies(){
    for(int i = 0; i < graphSize; i++){
        graph[i] = new int[graphSize];
    }
}

void dijkstra::initializeAndFillVerticiesDistancesWithInfinity(){
    //NOTE: don't change the order of the function calls
    DijkstraUtil::initializeVerticiesDistance(&verticiesDistance, graphSize);
    fillVerticiesDistanceWithInfinity();
}

void dijkstra::fillVerticiesDistanceWithInfinity(){
    int infinity = std::numeric_limits<int>::max();

    for(int i= 0;i<graphSize;i++){
        verticiesDistance[i] = infinity;
    }
}

bool dijkstra::isThereAConnectionFromAVertexToAVertex(int fromVertexNumber, int toVertexNumber){
    return graph[fromVertexNumber][toVertexNumber] != 0;
}

void dijkstra::findTheSortestPathToAllVerticies(){

    if(stack->isEmpty() == false){
        minimumVertexConnection = DijkstraStackUtil::findTheMinimumConnectionWeight(stack);
        DijkstraStackUtil::removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot, minimumVertexConnection);
        
        int pathWeight=0;
        for(int i=0;i<graphSize;i++){
            if(isThereAConnectionFromAVertexToAVertex(minimumVertexConnection->connectionToVertex, i)){
                pathWeight = verticiesDistance[minimumVertexConnection->connectionToVertex] + graph[minimumVertexConnection->connectionToVertex][i];

                if(verticiesDistance[i] > pathWeight){
                    verticiesDistance[i] = pathWeight;
                    stack->push(new vertexConnection{minimumVertexConnection->connectionToVertex,i,pathWeight});
                }
            }
        }
        findTheSortestPathToAllVerticies();
    }
}

void dijkstra::showDistances(){
    for(int i=0;i<graphSize;i++){
        std::cout<<verticiesDistance[i]<<" ";
    }
}