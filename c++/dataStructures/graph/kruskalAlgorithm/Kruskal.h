#pragma once

class Kruskal:Graph{
    public:
        vertexConnection* minimumVertexConnection = nullptr;
        int totalNumberOfVerticies;

        std::vector<int> connectedVerticies;
        
        int **newGraph = nullptr;
        bool isCycle;
        CycleDetector *c = nullptr;
        DFS* dfsObj = nullptr;

        Kruskal(int **, int );
        
        void findPath();
        bool isThereACycle();
        void shouldAddWeightToTheNewGraphAndRemoveWeightFromTheOldGraph(bool );
        void shouldRemoveWeightFromBothGraphs(bool );

        std::vector<int> initializeDfsAndGetThePath();
};