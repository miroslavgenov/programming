#pragma once
#include <iostream>
#include <limits>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/DijkstraStackUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/DijkstraUtil.h"

class dijkstra{
    int **graph=nullptr;
    int graphSize;
    Stack<vertexConnection*>* stack = nullptr;
    int *verticiesDistance = nullptr;
    vertexConnection* minimumVertexConnection = nullptr;

public:
    dijkstra(int [], int );

private:
    void transferTheSingleGraphIntoTwoDimensional(int []);

    void fillTheGraphWithVerticies();

    void initializeAndFillVerticiesDistancesWithInfinity();

    void fillVerticiesDistanceWithInfinity();

    bool isThereAConnectionFromAVertexToAVertex(int , int );

public:
    void showDistances();
    void findTheSortestPathToAllVerticies();
};