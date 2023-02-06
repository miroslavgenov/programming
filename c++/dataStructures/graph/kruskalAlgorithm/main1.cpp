// lenght before 587
#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/KruskalUtil.h"
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
    KruskalUtil::initializeGraph(&graph,graphSize);
    KruskalUtil::copyTheWeightsFromSourceGraph(&graph,(int *) sourceGraph, graphSize);
    
    int **newGraph = nullptr;
    KruskalUtil::initializeGraph(&newGraph, graphSize);
    
    Kruskal* k = new Kruskal(graph, graphSize);
    k->findPath();
}