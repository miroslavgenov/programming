#pragma once

class Prim:Graph{
    public:
    int **spanningTree = nullptr;
    int totalNumberOfVerticies;
    int numberOfConnectedVerticies;
    DFS* dfs  = nullptr;
    vertexConnection* minimumVertexConnection = nullptr;
    CycleDetector* cd = nullptr;

    Prim(int *, int );

    private:

    bool allVerticiesAreReachable();

    bool thereIsACycle();

    void findTheSpanningTree();

    public:
    int** getSpanningTree();

};