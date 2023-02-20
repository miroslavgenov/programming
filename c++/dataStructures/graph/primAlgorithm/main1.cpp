#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/DFS.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/primAlgorithm/Prim.cpp"

using namespace std;

int main(){
    int graphSize = 5;
    int graph[graphSize][graphSize] = {      
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };

    Prim* p = new Prim((int*)graph, graphSize);
    
    Printer::printGraph(p->getSpanningTree(),graphSize);
}