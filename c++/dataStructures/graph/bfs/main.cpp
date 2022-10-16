#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph/include/Graph.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Vertex.h"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/Queue/include/Queue.cpp"

using namespace std;

bool visitedVerticies[7]{};

void bfs(int** graph, int currentVertex, int size){
	visitedVerticies[currentVertex] = 1;
    Printer::printBooleans(visitedVerticies,7);
	
}

int main(){
    int GRAPH_SIZE = 7;
    Vertex* verticies[GRAPH_SIZE] = {
	    new Vertex {0, {1, 3}},
	    new Vertex {1, {0, 2, 4}},
	    new Vertex {2, {1, 3, 5}},
	    new Vertex {3, {0, 2, 5, 6}},
	    new Vertex {4, {1}},
	    new Vertex {5, {2, 3, 6}},
	    new Vertex {6, {3, 5}}
	};

	Graph *g = new Graph(verticies,GRAPH_SIZE);
    
    Queue<int> *q = new Queue(verticies[0]->vertexNumber);
    cout<<q<<endl;
    bfs(g->getGraph(), verticies[0]->vertexNumber,7);
    
}