#pragma once
#include <iostream>
#include <limits>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/DijkstraStackUtil.h"


class dijkstra{
    int **graph=nullptr;
    int graphSize;
    Stack<vertexConnection*>* stack = nullptr;

public:
    int *verticiesDistance = nullptr;
    bool* verticiesVisited = nullptr;

    dijkstra(int [], int );

private:
    void fillVerticiesDistanceWithInfinity();

public:
    void findTheSortestPathToAllVerticies();

    void showDistances();
};