#pragma once

class Kruskal{
    public:
        vertexConnection* minimumVertexConnection = nullptr;
        
        //remove
        std::vector<int> stack;
        //remove
        bool *visitedVerticies = nullptr;
        
        //remove use Graph class
        int graphSize;
        int **graph = nullptr;

        int **newGraph = nullptr;
        bool isCycle;
        CycleDetector *c = nullptr;

        Kruskal(int **, int );
        void prepareForKruskalAlgorithm(int **, int );
        
        void findPath();
        bool isThereACycle();
        void shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool );
        void shouldRemoveWeightFromBothGraphs(bool );

        //remove use DFS class
        void dfs(int **);        
};