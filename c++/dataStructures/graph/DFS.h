#pragma once

class DFS:Graph{
    
    bool *visitedVerticies = nullptr;
    std::vector<int> stack;
    std::vector<int> path;
    int notValidVertex = -1;
    int validVertex;

    public:

    DFS(int **, int );

    void dfs();

    int getFirstValidVertex();

    std::vector<int> getPath();
};