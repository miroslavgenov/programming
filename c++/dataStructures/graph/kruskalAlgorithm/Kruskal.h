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
    CycleDetector *c = nullptr;

    Kruskal(int **sourceGraph, int sourceGraphSize){
        prepareForKruskalAlgorithm(sourceGraph, sourceGraphSize);
    }
    
    void prepareForKruskalAlgorithm(int **sourceGraph, int sourceGraphSize){
        KruskalUtil::setGraphSize(graphSize, sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::initializeGraph(&newGraph,graphSize);
        KruskalUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
    }
	
	bool 	isThereACycle(){
		// TODO: instead of using the constructur
		// try to use example: 
		// in the constructur of Kruskal
		//CycleDetector* c = new CycleDetector();
		//
		//in this function
		//c->detectCycle(newGraph,graphSize)
		// return c->isThereACycle();
		c = new CycleDetector(newGraph,graphSize);
		return c->isThereACycle();
	}
	    
    void findPath(){
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
    void findTheMinimumConnection(){
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

    bool isMinimumConnectionWeightNotInitialized(){
        return minimumConnectionWeight == 0;
    }

    void setMinimumVertexConnectionAndMinimumConnectionWeight(int i, int j){
        KruskalUtil::setMinimumConnectionWeight(minimumConnectionWeight,graph[i][j]);
        KruskalUtil::setMinimumVertexConnection(&minimumVertexConnection,i,j,minimumConnectionWeight);
    }

    bool isMinimumConnectionWeightGreaterThan(int i, int j){
        return minimumConnectionWeight > graph[i][j];
    }

    void shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool isCycle){
        if(isCycle == GraphFlags::hasNoCycle){
            KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);
            KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
        }
    }

    void shouldRemoveWeightFromBothGraphs(bool isCycle){
        if(isCycle == GraphFlags::hasACycle){
            KruskalUtil::removeWeightFromGraph(newGraph,minimumVertexConnection);
            KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
        }
    }

    //move in to the util class
    void dfs(int **graph){
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
};
