#pragma once

class Graph{
    public:
    int **graph = nullptr;
    int graphSize;

    Graph(int *,int );

    Graph(int **, int );

    void setGraphSizeAndInitializeTheGraph(int );
};