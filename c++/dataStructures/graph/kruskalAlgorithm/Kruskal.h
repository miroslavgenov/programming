#pragma once

#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/KruskalUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.cpp"

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

        Kruskal(int **, int );
        void prepareForKruskalAlgorithm(int **, int );
        
        void findPath();
        void findTheMinimumConnection();
        bool isMinimumConnectionWeightNotInitialized();
        void setMinimumVertexConnectionAndMinimumConnectionWeight(int , int );
        bool isMinimumConnectionWeightGreaterThan(int , int );
        bool isThereACycle();
        void shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool );
        void shouldRemoveWeightFromBothGraphs(bool );

        void dfs(int **);        
};