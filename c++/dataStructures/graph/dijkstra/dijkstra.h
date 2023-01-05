#pragma once
#include <iostream>
#include <limits>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/DijkstraStackUtil.h"

//vertical, name refactor
class dijkstra{
    int **graph=nullptr;
    int graphSize;
    Stack<vertexConnection*>* stack = nullptr;

public:
    int *verticiesDistance = nullptr;

    dijkstra(int [], int );

private:
    void initializeAndFillVerticiesDistancesWithInfinity();
    void initializeVerticiesDistance();
    void fillVerticiesDistanceWithInfinity();

    void initializeTheGraphAndFillTheInnerArrays();
    void initializeTheGraph();
    void fillTheInnerArrayOfTheGraph();

public:
    void findTheSortestPathToAllVerticies();

    void showDistances();
};