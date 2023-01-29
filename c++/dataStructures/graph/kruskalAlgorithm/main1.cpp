// lenght before 587
#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/GraphFlags.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/vertexConnections.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/KruskalUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.h"

using namespace std;


int main(){
    int  graphSize = 4;
    int graphCp[graphSize][graphSize] = {
       //0 1 2 3
        {0,10,6,5}, //0
        {10,0,0,15}, //1
        {6,0,0,4}, //2
        {5,15,4,0}  //3
	};
    
    int **graph = new int*[graphSize];
    // make this function
    for(int i=0; i<graphSize;i++){
        graph[i] = new int[graphSize];
    }

    //graph converted to int** graph
    // make this function
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            graph[i][j] = graphCp[i][j];
            // cout<<graph[i][j]<<" ";
        }
    }

    // new graph to store the kruskal path
    int **newGraph = new int*[graphSize];
    for(int i=0;i<graphSize;i++){
        newGraph[i] = new int[graphSize];
    }

    
    Kruskal* k = new Kruskal(graph, graphSize);
    k->findPath();
}