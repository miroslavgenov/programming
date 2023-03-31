#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/GraphSearcher.h"

GraphSearcher::GraphSearcher(int *srcGraph, int srcGraphSize):Graph(srcGraph, srcGraphSize){
    visitedVerticies  = new bool[graphSize];
}

void GraphSearcher::clearTheBasicVariables(){
    path = std::vector<int>();
    visitedVerticies = new bool[graphSize];
}