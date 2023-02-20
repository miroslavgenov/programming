#include "/home/home/Desktop/programming/c++/dataStructures/graph/DFS.h"

DFS::DFS(int **scrGraph, int scrGraphSize):Graph(scrGraph,scrGraphSize){
    GraphUtil::initializeVisitedVerticies(&visitedVerticies,graphSize);
}

void DFS::dfs(){
    int currentVertex;
    if(stack.empty() == false){
        currentVertex = stack.back();
        stack.pop_back();
        path.push_back(currentVertex);
        visitedVerticies[currentVertex] = 1;

        for(int i=0;i<graphSize;i++){
            if(graph[currentVertex][i] !=0 && visitedVerticies[i] == 0){
                stack.push_back(i);
                dfs();
            }
        }
    }
}

int DFS::getFirstValidVertex(){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            if(graph[i][j] !=0){
                return i;
            }
        }
    }

    return notValidVertex;
}

std::vector<int> DFS::getPath(){

    GraphUtil::clearVisitedVerticies(&visitedVerticies,graphSize);
    stack.clear();
    path.clear();
    validVertex = getFirstValidVertex();

    if(validVertex == notValidVertex){
        return path;
    }else{
        stack.push_back(validVertex);
        dfs();
    }
    return path;
}