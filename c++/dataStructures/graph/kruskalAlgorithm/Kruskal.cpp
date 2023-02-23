#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.h"

Kruskal::Kruskal(int **sourceGraph, int sourceGraphSize):Graph(sourceGraph,sourceGraphSize){
    GraphUtil::initializeGraph(&newGraph,graphSize);
    totalNumberOfVerticies = graphSize;
    connectedVerticies = initializeDfsAndGetThePath();
}

void Kruskal::findPath(){
    while(connectedVerticies.size() != totalNumberOfVerticies){

        minimumVertexConnection = GraphUtil::findMinimumVertexConnection(graph, graphSize);

        GraphUtil::addWeightToGraph(newGraph, minimumVertexConnection);

        isCycle = isThereACycle();
        
        shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(isCycle);        
        
        shouldRemoveWeightFromBothGraphs(isCycle);
        
        connectedVerticies = initializeDfsAndGetThePath();
    }

    Printer::printGraph(newGraph,graphSize);
}

std::vector<int> Kruskal::initializeDfsAndGetThePath(){
    dfsObj = new DFS(newGraph,graphSize);
    return dfsObj->getPath();
}

bool Kruskal::isThereACycle(){
    c = new CycleDetector(newGraph,graphSize);
    return c->isThereACycle();
}

void Kruskal::shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool isCycle){
    if(isCycle == GraphFlags::hasNoCycle){
        GraphUtil::addWeightToGraph(newGraph,minimumVertexConnection);
        GraphUtil::removeWeightFromGraph(graph,minimumVertexConnection);
    }
}

void Kruskal::shouldRemoveWeightFromBothGraphs(bool isCycle){
    if(isCycle == GraphFlags::hasACycle){
        GraphUtil::removeWeightFromGraph(newGraph,minimumVertexConnection);
        GraphUtil::removeWeightFromGraph(graph,minimumVertexConnection);
    }
}