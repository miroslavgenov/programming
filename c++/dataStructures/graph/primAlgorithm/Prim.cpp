#include "/home/home/Desktop/programming/c++/dataStructures/graph/primAlgorithm/Prim.h"


Prim::Prim(int *sourceGraph, int sourceGraphSize):Graph(sourceGraph,sourceGraphSize){
    totalNumberOfVerticies = graphSize;

    GraphUtil::initializeGraph(&spanningTree,graphSize);

    
    dfs = new DFS(graph,graphSize);
    cd = new CycleDetector(spanningTree,graphSize);

    //throw GraphException 
    if(dfs->getPath().size() != graphSize){
        std::cout<<" not all verticies are connected"<<std::endl;
        std::cout<<"call destructur"<<std::endl;
        delete this;
    }else{
        this->findTheSpanningTree();
    }
}


bool Prim::allVerticiesAreReachable(){
    dfs = new DFS(spanningTree,graphSize);
    numberOfConnectedVerticies = dfs->getPath().size();
    return numberOfConnectedVerticies == totalNumberOfVerticies;
}

bool Prim::thereIsACycle(){
    cd =  new CycleDetector(spanningTree,graphSize);
    return cd->isThereACycle();
}

void Prim::findTheSpanningTree(){
    if(allVerticiesAreReachable() == false){
        minimumVertexConnection = GraphUtil::findMinimumVertexConnection(graph, graphSize);

        GraphUtil::addWeightToGraph(spanningTree, minimumVertexConnection);
        GraphUtil::removeWeightFromGraph(graph, minimumVertexConnection);

        if(thereIsACycle()){
            GraphUtil::removeWeightFromGraph(spanningTree, minimumVertexConnection);
        }

        findTheSpanningTree();
        
    }
}

int** Prim::getSpanningTree(){
    return spanningTree;
}

