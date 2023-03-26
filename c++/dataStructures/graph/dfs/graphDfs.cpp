#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph/include/Graph.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"

using namespace std;

const size_t GRAPH_SIZE = 6;
bool visitedVerticies[GRAPH_SIZE]{};
Stack<int>* sStack = nullptr;

void dfs(int graph[][GRAPH_SIZE], int vertex){
	visitedVerticies[vertex] = 1;
	std::cout<<vertex<<std::endl;

	for(int i=0;i<GRAPH_SIZE;i++){
		if(graph[vertex][i] == 1 && visitedVerticies[i] == 0){
			sStack->push(i);
			dfs(graph,*sStack->pop());
		}
	}
}

int main(){
	int size = 4;
	

	Vertex* list[size] = {
		new Vertex{0,{1}},
		new Vertex{1,{0,2,3}},
		new Vertex{2,{1,3}},
		new Vertex{3,{1,2}}
	};
	
	Graph* g  = new Graph(list, size);

	Printer::printGraph(g->getGraph(),size);

}
