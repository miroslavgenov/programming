#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"

using namespace std;

bool visitedVerticies[6]{};
enum GraphFlags : bool {empty = true, notEmpty = false, visited = true, notVisited = false};


//find the minimum connection

vertexConnection* findTheMinimumConnection(int **graph, int graphSize){
    //! only if the graph is not empty !
    vertexConnection *vt  = nullptr;

    int min = 0;
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            // only check if the weight is different than 0
            if(graph[i][j] !=0 ){
                //initialize the minWeight
                if(min == 0){
                    min = graph[i][j];
                    vt = new vertexConnection{i,j,graph[i][j]};
                }
                //if the minWeight is initialized
                else{
                    // check if the graphWeight is lesser then the min weight
                    if(min > graph[i][j]){
                        // store the data
                        min = graph[i][j];
                        vt = new vertexConnection{i,j,graph[i][j]};
                    }
                }
            }
        }
    }
    
    return vt;
}

bool isVertexVisited(int vertexNumber){
    return visitedVerticies[vertexNumber] == GraphFlags::visited;
}

bool isBothVerticiesVisited(int firstVertex, int secondVertex){
    return isVertexVisited(firstVertex) && isVertexVisited(secondVertex);
}


// if they are not visited mark them as visited
void markVertexAsVisited(int vertexNumber){
    visitedVerticies[vertexNumber] = 1;
}

void markBothVerticiesAsVisited(int vertexNumbers[]){
    markVertexAsVisited(vertexNumbers[0]);
    markVertexAsVisited(vertexNumbers[1]);
}


// add the connection to a new graph
// void addTheConnectionToNewGraph()
void addTheConnectionsToTheNewGraph(int **newGraph, vertexConnection* vt){
    newGraph[vt->connectionFromVertex][vt->connectionToVertex] = vt->connectionWeight;
    newGraph[vt->connectionToVertex][vt->connectionFromVertex]  = vt->connectionWeight;
}

// remove the connection from the old graph
void removeTheConnectionsFromTheOldGraph(int **graph, vertexConnection* vt){
    graph[vt->connectionFromVertex][vt->connectionToVertex] =0;
    graph[vt->connectionToVertex][vt->connectionFromVertex] =0;
}

// if only one vertex is visted add the new connection to the new graph
// if(isBothVerticiesVisited == true) check whether one of them are visited or not
// remove the connection from the old graph

//if the verticies are visited don't add the connection to the new graph
//remove the connection

//the algorithm will end if the old graph is empty
// if(isGraphEmpty(oldGraph) == true){
    // finish
// }


bool isGraphEmpty(int **graph, int graphSize){
    
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){

            if(graph[i][j] != 0 ){
                return GraphFlags::notEmpty;
            }
        }
    }


    return GraphFlags::empty;
}

void print(int** graph, int graphSize){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            cout<<graph[i][j]<<" ";
        }cout<<endl;
    }
}

void kruskal(int **graph, int graphSize, int **newGraph){
    if(isGraphEmpty(graph,graphSize) == false){
        vertexConnection* vt = findTheMinimumConnection(graph, graphSize);
        
        if(isBothVerticiesVisited(vt->connectionFromVertex, vt->connectionToVertex) == false){

        }else{

        }
    }
}

int main(){
    int graphSize = 6;
    
    int graphCp[graphSize][graphSize] = {
        //  0 1 2 3 4 5
        {0,1,2,6,0,0},
        {1,0,0,1,0,2},
        {2,0,0,3,0,0},
        {0,1,3,0,2,3},
        {0,0,0,2,0,0},
        {0,2,0,3,0,0}
	};

    int **graph = new int*[graphSize];
    // make this function
    for(int i=0;i<graphSize;i++){
            graph[i] = new int[graphSize];
    }
    // make this function
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            graph[i][j] = graphCp[i][j];
            // cout<<graph[i][j]<<" ";
        }
    }

    int **newGraph = new int*[graphSize];
    for(int i=0;i<graphSize;i++){
        newGraph[i] = new int[graphSize];
    }

    kruskal(graph, graphSize, newGraph);

    // isGraphEmpty(graph, graphSize);
    


    
    
    

}