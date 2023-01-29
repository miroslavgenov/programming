#pragma once

class KruskalUtil{
    public:

    static int cycleDeterminationNumber;

    static bool cycleAuthentication(int repeatedConnections){
        return repeatedConnections >= cycleDeterminationNumber;
    }

    static void initializeGraph(int ***graph, int graphSize){
        *graph = new int*[graphSize];

        for(int i=0;i<graphSize;i++){
            *(*graph+i) = new int[graphSize];
        }
    }

    static void initializeVisitedVerticies(bool **visitedVerticies, int graphSize){
        *visitedVerticies = new bool[graphSize];
    }

    static void setGraphSize(int &destinationGraphSize, int sourceGraphSize){
        destinationGraphSize = sourceGraphSize;
    }

    static void copyTheWeightsFromSourceGraph(int ***destinationGraph, int **sourceGraph, int graphSize){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                *(*(*destinationGraph+j)+i) = sourceGraph[i][j];
            }
        }        
    }

    static bool areAllVerticiesVisited(bool *visitedVerticies, int graphSize){
        bool allVerticiesAreVisited = true;
        bool notAllVerticiesAreVisited = false;
        bool isCurrentVertexVisited;

        for(int i=0;i<graphSize;i++){
            isCurrentVertexVisited = visitedVerticies[i];
                if(isCurrentVertexVisited == 0){
                    return notAllVerticiesAreVisited;
                }
        }
        return allVerticiesAreVisited;
    }

    static void clearVisitedVerticies(bool **visitedVerticies, int graphSize){
        for(int i=0;i<graphSize;i++){
            *(*visitedVerticies+i) = 0;
        }
    }

    static void pushAllVerticiesNumber(int graphSize,std::vector<vertexConnections*>& container){
        for(int vertexNumber = 0; vertexNumber < graphSize; vertexNumber++){
            container.push_back(new vertexConnections{vertexNumber});
        }
    }

    static bool isConnectionValid(int weight){
        return weight != 0;
    }

    static void pushAllValidVertexConnections(int** graph,int graphSize,std::vector<vertexConnections*>& listWithVertexConnections){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(isConnectionValid(graph[i][j])){
                    listWithVertexConnections[i]->connections.push_back(j);
                }
            }
        }
    }

    static std::vector<vertexConnections*> getOnlyTheVerticiesWithMoreThanOneConnections(std::vector<vertexConnections*> listWithVertexConnections){
        std::vector<vertexConnections*> potentialLoopVerticies; 
        for(int i = 0 ;i< listWithVertexConnections.size();i++){
            if(listWithVertexConnections[i]->connections.size()>=2){
            potentialLoopVerticies.push_back(listWithVertexConnections[i]);
            }
        }

        return potentialLoopVerticies;

    }

static bool isThereACycle(int **graph, int graphSize){
    //get the connections
    std::vector<vertexConnections*> listWithVertexConnections;
    pushAllVerticiesNumber(graphSize, listWithVertexConnections);
    pushAllValidVertexConnections(graph,graphSize,listWithVertexConnections);
    
    std::vector<vertexConnections*> potentialLoopVerticies = getOnlyTheVerticiesWithMoreThanOneConnections(listWithVertexConnections);
   
    //loop detector
    int repeatedConnections = 0;

    // loop each vertex
    for(int i=0;i<potentialLoopVerticies.size();i++){
        // cout<<"current vertex: "<<potentialLoopVerticies[i]->vertexNumber<<endl;
        
        // loop each vertex connections
        // loop and see if the connection from the current vertex occur in the other
        for(int j=0;j<potentialLoopVerticies[i]->connections.size();j++){
            // cout<<"connection: "<<potentialLoopVerticies[i]->connections[j]<<endl; // connection from the current vertex
            // cout<<"checking if that connection occur in the other verticies"<<endl;

            //loop all verticies
            // loop throug all verticies except the current vertex to check for similar connections
            for(int z=0;z<potentialLoopVerticies.size();z++){
                //show all verticies except the current one
                // all other verticies except the current vertex
                if(potentialLoopVerticies[i]->vertexNumber != potentialLoopVerticies[z]->vertexNumber){
                    // cout<<"vertex: "<<potentialLoopVerticies[z]->vertexNumber<<" : ";

                    //loop the connections from the verticies and check for similar
                    //looping throught the other verticies connections and checking for repeted connections
                    for(int y =0 ; y< potentialLoopVerticies[z]->connections.size();y++){
                        // cout<<potentialLoopVerticies[z]->connections[y]<<" ";
                        if(potentialLoopVerticies[i]->connections[j] == potentialLoopVerticies[z]->connections[y]){
                            // cout<<"connection : "<<potentialLoopVerticies[i]->connections[j]<<" occur !!"<<endl;
                            repeatedConnections++;
                        }
                    }
                    // cout<<endl;
                }
            }

        }
        // cout<<endl;       
    }
    
    return cycleAuthentication(repeatedConnections);
}
    static void removeWeightFromGraph(int **graph,vertexConnection* mv){
        mv->connectionWeight = 0;
        addWeightToGraph(graph,mv);
    }
    
    static void addWeightToGraph(int **graph, vertexConnection* mv){
        graph[mv->connectionFromVertex][mv->connectionToVertex] = mv->connectionWeight;
        graph[mv->connectionToVertex][mv->connectionFromVertex] = mv->connectionWeight;
    }

    static void clearMinimumVertexConnectionAndConnectionWeight(vertexConnection** mV, int &mCW){
        *mV = nullptr;
        mCW = 0;
    }

    static void setMinimumConnectionWeight(int &minimumConnectionWeight, int sourceValue){
        minimumConnectionWeight = sourceValue;
    }

    static void setMinimumVertexConnection(vertexConnection** mv,int i, int j, int weight){
        *mv = new vertexConnection{i,j,weight};
    }

    static void prepareStackAndClearVisitedVerticiesForDfs(std::vector<int> &stack, vertexConnection* minimumVertexConnection, bool *visitedVerticies, int graphSize){
        stack.clear();
        stack.push_back(minimumVertexConnection->connectionFromVertex);
        clearVisitedVerticies(&visitedVerticies, graphSize);
    }
};

int KruskalUtil::cycleDeterminationNumber = 6;