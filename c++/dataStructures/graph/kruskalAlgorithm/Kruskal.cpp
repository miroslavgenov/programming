#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.h"

Kruskal::Kruskal(int **sourceGraph, int sourceGraphSize){
    prepareForKruskalAlgorithm(sourceGraph, sourceGraphSize);

}

void Kruskal::prepareForKruskalAlgorithm(int **sourceGraph, int sourceGraphSize){
    GraphUtil::setGraphSize(graphSize, sourceGraphSize);
    GraphUtil::initializeGraph(&graph,graphSize);
    GraphUtil::initializeGraph(&newGraph,graphSize);
    GraphUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
    GraphUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
}

void Kruskal::findPath(){
    // get the path from DFS class. Then check if the path.size() == graphSize( the graphSize is == total number of verticies)
    while(
        GraphUtil::areAllVerticiesVisited(visitedVerticies,graphSize) == GraphFlags::notVisited
        ){

        minimumVertexConnection = GraphUtil::findMinimumVertexConnection(graph,graphSize);

        GraphUtil::addWeightToGraph(newGraph,minimumVertexConnection);

        isCycle = isThereACycle();
        
        shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(isCycle);        
        
        shouldRemoveWeightFromBothGraphs(isCycle);
        
        GraphUtil::prepareStackAndClearVisitedVerticiesForDfs(stack,minimumVertexConnection,visitedVerticies,graphSize);
        dfs(newGraph);        

    }
    Printer::printGraph(newGraph,graphSize);
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

//move in to the util class
void Kruskal::dfs(int **graph){
    if(stack.empty() == GraphFlags::notEmpty && visitedVerticies[stack.back()] == 0) {
        
        int currentVertex = stack.back();
        stack.pop_back();
        visitedVerticies[currentVertex] = 1;
        
        for(int i=0;i<graphSize;i++){
            if(graph[currentVertex][i] != 0){
                if(visitedVerticies[i]==0){

                    stack.push_back(i);
                }
            }
        }

        if(stack.empty() == GraphFlags::notEmpty){
            dfs(graph);
        }
    }    
}