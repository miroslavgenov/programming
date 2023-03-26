#pragma once

// #include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/GraphFlags.h"
// #include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
// #include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/vertexConnections.h"
// #include "/home/home/Desktop/programming/c++/algorithms/Printer.h"

class GraphUtil{
    public:

    static bool areAllVerticiesNotVisited(bool *visitedVerticies, int graphSize){
        for(int i=0;i<graphSize;i++){
            if(visitedVerticies[i] == 1){
                return false;
            } 
        }
        return true;
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

    static vertexConnection* getFirstValidConnection(int **graph, int graphSize){
        vertexConnection* firstValidConnection = nullptr;
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0 ){
                    return firstValidConnection = new vertexConnection{i,j,graph[i][j]};
                }
            }
        }
        return firstValidConnection;
    } 

    // maybe MinimumConnectionFinder
    static vertexConnection* findMinimumVertexConnection(int **graph,int graphSize){
        vertexConnection* minimumVertexConnection = getFirstValidConnection(graph,graphSize);

        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0){
                    if(minimumVertexConnection->connectionWeight > graph[i][j]){
                        minimumVertexConnection = new vertexConnection{i,j,graph[i][j]};
                    }
                }
            }
        }
        


        return minimumVertexConnection;
    }

    static void copyTheWeightsFromSourceGraph(int ***destinationGraph,int *sourceGraph,int graphSize){
        int iterator =0;
    
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                *(*(*destinationGraph+j)+i) = *(sourceGraph+iterator);
                iterator++;
            }
        }
    }

    static bool areAllVerticiesVisited(bool *visitedVerticies, int graphSize){
        for(int i=0;i<graphSize;i++){
                if(isCurrentVertexNotVisited(visitedVerticies[i])){
                    return GraphFlags::allVerticiesAreNotVisited;
                }
        }
        return GraphFlags::allVerticiesAreVisited;
    }

    static bool isCurrentVertexNotVisited(bool currentVertexStatus){
        return !isCurrentVertexVisited(currentVertexStatus);
    }

    static bool isCurrentVertexVisited(bool currentVertexStatus){
        return currentVertexStatus == 1;
    }
    
    static bool isConnectionValid(int weight){
        return weight != 0;
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

    static void clearVisitedVerticies(bool *visitedVerticies,int graphSize){
        clearVisitedVerticies(&visitedVerticies,graphSize);
    }

    static void clearVisitedVerticies(bool **visitedVerticies, int graphSize){
        for(int i=0;i<graphSize;i++){
            *(*visitedVerticies+i) = 0;
        }
    }

    static void printGraph(int **graph, int graphSize){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                std::cout<<graph[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
};
