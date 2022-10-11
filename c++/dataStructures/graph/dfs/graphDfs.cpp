#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/Stack.cpp"

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

struct edge{
	int edgeNumber;
	vector<int> edgeIsConnectedTo;
};

class Graph{
	int** graph = nullptr;
	int graphSize;

public:
	Graph(edge* edges[], int edgesSize){
		// set up the graph
		// set the graph capacite
		graph = new int*[edgesSize];
		// set the inner arrays capacity
		for(int i=0;i<edgesSize;i++){
			graph[i] = new int[edgesSize];
		}
		// set the graphSize
		graphSize = edgesSize;
		
		

		// NumberFinder::findTheMaximumNumberFromEdges
		// who is the minimum edge number
		// int minEdge = edges[0]->edgeNumber;
		
		// who is the maximum edge number
		int maxEdge = edges[0]->edgeNumber;
		

		// algorithm to find the minimum and maximum edge number
		for(int i=0;i<edgesSize;i++){

		// if(edges[i]->edgeNumber < minEdge){
		// 	minEdge = edges[i]->edgeNumber;
		// }
			if(edges[i]->edgeNumber > maxEdge){
				maxEdge= edges[i]->edgeNumber;
			}
		}
		// end 		NumberFinder::findTheMaximumNumberFromEdges


	
	// algorithm to fill the graph where there is connection
	int iterator = 0;
	for(int i = 0; i<=maxEdge;i++){
		
			
			for(int j = 0;j<=maxEdge;j++){

				// is the iterator lesser than the size of the connected edges
				if(iterator < edges[i]->edgeIsConnectedTo.size()){
					
					// if the j is equal to element from edgeIsConnectedTo[iterator]
					// make the connection in the graph
					// and continue
					// else add 0 
					if(j == edges[i]->edgeIsConnectedTo[iterator]){
						
						//increase the iterator
						iterator++;
						// write connection 
						graph[i][j] = 1;
						continue;
					}
				}
				// write there is no connection
				graph[i][j] = 0;
			}
			
			// prepare the iterator so the data about the next edge can ge written
			iterator = 0;

		
		
	}

	}

	~Graph(){
		for(int i =0;i<graphSize;i++){
			
				delete [] graph[i];
				delete [] graph;
			
		}
	}

	int** getGraph(){
		return graph;
	}
};

// todo: clear the graph clas
// test
// make test and make separe files

int main(){
	int size = 4;
	

	edge* list[size] = {
		new edge{0,{1}},
		new edge{1,{0,2,3}},
		new edge{2,{1,3}},
		new edge{3,{1,2}}
	};
	
	Graph* g  = new Graph(list, size);

	int**gg = g->getGraph();
	
	// Printer::printGraph
	for(int i=0;i<size;i++){
		for(int j = 0;j<size;j++){
			cout<<gg[i][j]<<" ";
		}cout<<endl;
	}

}
























































