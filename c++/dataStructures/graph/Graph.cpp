#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph.h"

Graph::Graph(int *sourceGraph,int sourceGraphSize){
    setGraphSizeAndInitializeTheGraph(sourceGraphSize);
    GraphUtil::copyTheWeightsFromSourceGraph(&graph,(int* )sourceGraph,graphSize);
}

Graph::Graph(int **sourceGraph, int sourceGraphSize){
    setGraphSizeAndInitializeTheGraph(sourceGraphSize);
    GraphUtil::copyTheWeightsFromSourceGraph(&graph,sourceGraph,graphSize);
}

void Graph::setGraphSizeAndInitializeTheGraph(int sourceGraphSize){
    GraphUtil::setGraphSize(graphSize,sourceGraphSize);
    GraphUtil::initializeGraph(&graph,graphSize);
}
