#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.h"

Kruskal::Kruskal(int **sourceGraph, int sourceGraphSize){
    prepareForKruskalAlgorithm(sourceGraph, sourceGraphSize);

}

void Kruskal::prepareForKruskalAlgorithm(int **sourceGraph, int sourceGraphSize){
    KruskalUtil::setGraphSize(graphSize, sourceGraphSize);
    KruskalUtil::initializeGraph(&graph,graphSize);
    KruskalUtil::initializeGraph(&newGraph,graphSize);
    KruskalUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
    KruskalUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
}

void Kruskal::findPath(){
    while(KruskalUtil::areAllVerticiesVisited(visitedVerticies,graphSize) == GraphFlags::notVisited){
        findTheMinimumConnection();
        KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);

        isCycle = isThereACycle();
        
        shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(isCycle);        
        
        shouldRemoveWeightFromBothGraphs(isCycle);
        
        KruskalUtil::prepareStackAndClearVisitedVerticiesForDfs(stack,minimumVertexConnection,visitedVerticies,graphSize);
        dfs(newGraph);        

    }
    Printer::printGraph(newGraph,graphSize);
}

//move into the util class
void Kruskal::findTheMinimumConnection(){
    KruskalUtil::clearMinimumVertexConnectionAndConnectionWeight(&minimumVertexConnection,minimumConnectionWeight);

    for(int i = 0; i < graphSize; i++){
        for(int j = 0; j < graphSize; j++){
            if(KruskalUtil::isConnectionValid(graph[i][j])){
                if(isMinimumConnectionWeightNotInitialized()){
                    setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
                }

                if(isMinimumConnectionWeightGreaterThan(i,j)){
                    setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
                }
                
            }
        }
    }
} 

bool Kruskal::isMinimumConnectionWeightNotInitialized(){
    return minimumConnectionWeight == 0;
}

void Kruskal::setMinimumVertexConnectionAndMinimumConnectionWeight(int i, int j){
    KruskalUtil::setMinimumConnectionWeight(minimumConnectionWeight,graph[i][j]);
    KruskalUtil::setMinimumVertexConnection(&minimumVertexConnection,i,j,minimumConnectionWeight);
}

bool Kruskal::isMinimumConnectionWeightGreaterThan(int i, int j){
    return minimumConnectionWeight > graph[i][j];
}

bool Kruskal::isThereACycle(){
    c = new CycleDetector(newGraph,graphSize);
    return c->isThereACycle();
}

void Kruskal::shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool isCycle){
    if(isCycle == GraphFlags::hasNoCycle){
        KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);
        KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
    }
}

void Kruskal::shouldRemoveWeightFromBothGraphs(bool isCycle){
    if(isCycle == GraphFlags::hasACycle){
        KruskalUtil::removeWeightFromGraph(newGraph,minimumVertexConnection);
        KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
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