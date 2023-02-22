#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/GraphFlags.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"


#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/vertexConnections.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.cpp"

#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"

#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.cpp"


using namespace std;

int main(){
    int  graphSize = 4;
    int sourceGraph[graphSize][graphSize] = {
       //0 1 2 3
        
        {0,10,6,5}, //0
        {10,0,0,15}, //1
        {6,0,0,4}, //2
        {5,15,4,0}  //3
	};


    int **graph = nullptr; 
    GraphUtil::initializeGraph(&graph,graphSize);
    GraphUtil::copyTheWeightsFromSourceGraph(&graph,(int *) sourceGraph, graphSize);
    
    int **newGraph = nullptr;
    GraphUtil::initializeGraph(&newGraph, graphSize);
    
    Kruskal* k = new Kruskal(graph, graphSize);
    k->findPath();
}