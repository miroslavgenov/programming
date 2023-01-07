#pragma once

class DijkstraUtil{
    public:
    static void initializeVerticiesDistance(int** verticiesDistance, int graphSize){
        *verticiesDistance = new int[graphSize];
    }
    static void initializeTheGraphSize(int &sourceGraphSize, int destinationGraphSize){
        sourceGraphSize = destinationGraphSize;
    }

    static void initializeTheGraph(int ***graph, int graphSize){
        *graph = new int*[graphSize];
    }

    static void fillVerticiesDistanceWithInfinity(int** verticiesDistance, int graphSize){
     
    }

    static void initializeTheStackAndSetStartingVertex(Stack<vertexConnection*>** stack){
            *stack = new Stack(new vertexConnection{-1,0,0});
    }

    static void addWeightToTheVerticiesDistance(int **verticiesDistance, int vertexNumber, int weight){
        *verticiesDistance[vertexNumber] = weight;
    }
};