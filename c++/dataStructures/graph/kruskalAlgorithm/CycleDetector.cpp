#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.h"

int CycleDetector::cycleDeterminationNumber = 6;

CycleDetector::CycleDetector(int **sourceGraph, int sourceGraphSize):Graph(sourceGraph,sourceGraphSize){
    pushAllVerticiesNumber();
    pushAllValidVertexConnections();
    setOnlyTheVerticiesWithMoreThanOneConnection();

    countForConnectionRepetitions();
}

void CycleDetector::pushAllVerticiesNumber(){
    for(int vertexNumber = 0; vertexNumber < graphSize; vertexNumber++){
        pushNewVertexNumber(vertexNumber);
    }
}
void CycleDetector::pushNewVertexNumber(int vertexNumber){
    listWithVertexConnections.push_back(new vertexConnections{vertexNumber});
}

void CycleDetector::pushAllValidVertexConnections(){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            if(graph[i][j] !=0){
                listWithVertexConnections[i]->connections.push_back(j);
            }
        }
    }
}

void CycleDetector::setOnlyTheVerticiesWithMoreThanOneConnection(){
    for(int i=0;i<listWithVertexConnections.size();i++){
        if(listWithVertexConnections[i]->connections.size() >= 2){
            verticiesWithMoreThanOneConnection.push_back(listWithVertexConnections[i]);
        }
    }
}

void CycleDetector::countForConnectionRepetitions(){
    int currentVertexNumber;
    int aVertexNumber;
        for(int i = 0; i < verticiesWithMoreThanOneConnection.size(); i++){
        for(int j = 0; j < verticiesWithMoreThanOneConnection[i]->connections.size(); j++){
            currentVertexNumber = verticiesWithMoreThanOneConnection[i]->vertexNumber;
            aVertexNumber = verticiesWithMoreThanOneConnection[i]->connections[j];
            countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(currentVertexNumber,aVertexNumber);
        } 
    }
}
void CycleDetector::countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(int currentVertexNumber,int aVertexNumber){
    std::vector<int> connections;
    for(int i = 0 ; i < verticiesWithMoreThanOneConnection.size(); i++){
        if(currentVertexNumber != verticiesWithMoreThanOneConnection[i]->vertexNumber){
            connections = verticiesWithMoreThanOneConnection[i]->connections;
            countHowMuchTimeAVertexNumberAppearsInVertexConnections(aVertexNumber, connections);        
        }
    }
}
void CycleDetector::countHowMuchTimeAVertexNumberAppearsInVertexConnections(int vertexNumber, std::vector<int> connections){
    for(int i=0;i<connections.size();i++){
        if(vertexNumber == connections[i]){
            repeatedConnections++;
        }
    }
}

bool CycleDetector::isThereACycle(){
    return repeatedConnections >= cycleDeterminationNumber;
}