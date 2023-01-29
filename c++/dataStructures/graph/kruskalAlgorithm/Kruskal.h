#pragma once

class Kruskal{
    public:
    vertexConnection* minimumVertexConnection = nullptr;
    std::vector<int> stack;
    int minimumConnectionWeight;
    int graphSize;
    int **graph = nullptr;
    int **newGraph = nullptr;
    bool isCycle;
    bool *visitedVerticies = nullptr;
    


    //move into the util class
    void setMinimumVertexConnectionAndMinimumConnectionWeight(int i, int j){
        KruskalUtil::setMinimumConnectionWeight(minimumConnectionWeight,graph[i][j]);
        KruskalUtil::setMinimumVertexConnection(&minimumVertexConnection,i,j,minimumConnectionWeight);
    }



    bool isMinimumConnectionWeightNotInitialized(){
        return minimumConnectionWeight == 0;
    }

    bool isMinimumConnectionWeightGreaterThan(int i, int j){
        return minimumConnectionWeight > graph[i][j];
    }

    //move into the util class
    void findTheMinimumConnection(){
        KruskalUtil::clearMinimumVertexConnectionAndConnectionWeight(&minimumVertexConnection,minimumConnectionWeight);

        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
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

    void findPath(){
        while(KruskalUtil::areAllVerticiesVisited(visitedVerticies,graphSize) == false){
            findTheMinimumConnection();
            KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);

            isCycle = KruskalUtil::isThereACycle(newGraph,graphSize);
            
            if(isCycle == false){
                KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);
                KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
            }

            if(isCycle == true){
                KruskalUtil::removeWeightFromGraph(newGraph,minimumVertexConnection);
                KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
            }
            
            KruskalUtil::prepareStackAndClearVisitedVerticiesForDfs(stack,minimumVertexConnection,visitedVerticies,graphSize);
            dfs(newGraph);        

        }
        
        print(newGraph, graphSize);

    }

    //move in to the util class
    void dfs(int **graph){
        if(stack.empty() == false && visitedVerticies[stack.back()] == 0) {
            
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

            if(stack.empty() == false){
                dfs(graph);
            }
        }    
    }

    void prepareForKruskalAlgorithm(int **sourceGraph, int sourceGraphSize){
        KruskalUtil::setGraphSize(graphSize, sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::initializeGraph(&newGraph,graphSize);
        KruskalUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
    }

    Kruskal(int **sourceGraph, int sourceGraphSize){
        prepareForKruskalAlgorithm(sourceGraph, sourceGraphSize);
    }
    
    void print(int **graph,int graphSize){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
             std::cout<<graph[i][j]<<" ";
            }std::cout<<std::endl;
        }
    }

    void print(){
        print(graph,graphSize);
    }
};