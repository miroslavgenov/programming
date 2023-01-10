#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"

using namespace std;

//find the minimum connection
// void findTheMinimumVertexConnection
void findTheMinimumConnection(int **graph, int graphSize){
    //TO DO: there is some error and can't find the fromVertex,toVertex
    // if the graph is not empty then you can find the minimum connection

// int    minimumWeight = 0, fromVertex = 0 , toVertex = 0;
// vertexConnection* m = nullptr;
//     for(int i = 0; i < graphSize; i++){
//         for(int j = 0; j < graphSize; j++){
//             if(graph[i][j] != 0){
//                 //initialize the minimumconnection
//                 if(minimumWeight == 0){
//                     minimumWeight = graph[i][j];
//                     cout<<minimumWeight<<endl;
//                 }else{
                    
                    
//                     if(minimumWeight > graph[i][j]){
//                         //add the wast visited, maybe make structure that store the data
//                         //about the connected verticies
//                         minimumWeight = graph[i][j];
//                         // m = new vertexConnection{i,j,graph[i][j]};
//                         // cout<<m->connectionWeight<<endl;
//                         cout<<i<<j<<endl;
//                         fromVertex = i;
//                         toVertex = j;

//                     }
//                 }   
//                 // cout<<"there is a connection ";
//                 // cout<<"from: "<<i<<" to: "<<j<<" with Weight of: "<<graph[i][j]<<endl;
//             }
//         }
//     }
//     cout<<"the minimum weight is: "<<minimumWeight<<endl;
//     cout<<fromVertex<<" "<<toVertex<<" "<<minimumWeight<<endl;
//     // cout<<m->connectionFromVertex<<" "<<m->connectionToVertex<<" "<<m->connectionWeight<<endl;
//     // cout<<m->connectionWeight<<endl;
    
}

// check if both verticies are visited
// bool isBothVerticiesVisited(int firstVertex, int secondVertex){
    // return isisVertexVisited(firstVertex) && isVertexVisited(secondVertex);
// }

// bool isVertexVisited(int vertexNumber){
    // return 
// }

// if they are not visited mark them as visited
// void markVerticiesAsVisited()

// add the connection to a new graph
// void addTheConnectionToNewGraph()

// remove the connection from the old graph
//void removeTheConnectionFromTheOldGraph()

// if only one vertex is visted add the new connection to the new graph
// if(isBothVerticiesVisited == true) check whether one of them are visited or not
// remove the connection from the old graph

//if the verticies are visited don't add the connection to the new graph
//remove the connection

//the algorithm will end if the old graph is empty
// if(isGraphEmpty(oldGraph) == true){
    // finish
// }

enum GraphEmpty : bool {empty = true, notEmpty = false};

bool isGraphEmpty(int **graph, int graphSize){
    
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){

            if(graph[i][j] != 0 ){
                return GraphEmpty::notEmpty;
            }
        }
    }


    return GraphEmpty::empty;
}


bool visitedVerticies[6]{};

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

    // isGraphEmpty(graph, graphSize);
    findTheMinimumConnection(graph, graphSize);

    
    
    

}