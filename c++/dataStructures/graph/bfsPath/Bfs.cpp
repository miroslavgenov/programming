#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/Bfs.h"

//NOTE: This class is not cleaned

Bfs::Bfs(int *srcGraph, int srcGraphSize):GraphSearcher(srcGraph,srcGraphSize){
}

void Bfs::clearTheBasicVariables(){
    GraphSearcher::clearTheBasicVariables();

    bfsQueue = std::queue<int>();
    history = new vertexAndChilds*[graphSize];
    currentVertex = new int;
}

bool Bfs::isChildVertexAlreadyInParentChilds(int childVertexNumber, vertexAndChilds** hs){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<hs[i]->child.size();j++){
            if(hs[i]->child[j] == childVertexNumber){
                return true;
            }
        }
    }
    return false;
}

void Bfs::initializeHistory(){
    for(int i=0;i<graphSize;i++){
        history[i] = new vertexAndChilds{i,{}};
    }
}


std::vector<int> Bfs::getPath(){
    return path;
}

void Bfs::printPath(std::vector<int> path){
    for(int i=0;i<path.size();i++){
        std::cout<<path[i]<<" ";
    }
}


int Bfs::getTheParrentOfThatChildVertex(int childVertex, vertexAndChilds** hst){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<hst[i]->child.size();j++){
            if(childVertex == hst[i]->child[j]){
                return hst[i]->vertexParent;
            }
        }
    }

    return -1;
}

std::vector<int> Bfs::getTheChildernsAndTheStartingParent(int tg, vertexAndChilds** hst){
    std::vector<int> pathBackwards;

    int tgv = tg;

    pathBackwards.push_back(tgv);
    while( (tgv = getTheParrentOfThatChildVertex(tgv,hst)) != -1){
        pathBackwards.push_back(tgv);
    }

    return pathBackwards;
}

std::vector<int> Bfs::getThePathReversed(){
    std::vector<int> p;

    for(int i=path.size()-1;i>=0;i--){
        p.push_back(path[i]);
    }

    return p;
}

void Bfs::makeStartVertexPathToTargetVertexPathReadable(int targetVertex, vertexAndChilds** hst){		
    path = getTheChildernsAndTheStartingParent(targetVertex,hst);

    path = getThePathReversed();

}