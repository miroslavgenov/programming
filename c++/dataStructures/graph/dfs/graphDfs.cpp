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

};



int main(){
	int size = 4;
	

	edge* list[size] = {
		new edge{0,{1}},
		new edge{1,{0,2,3}},
		new edge{2,{1,3}},
		new edge{3,{1,2}}
	};
	int** g = new int*[size];

	int graph[size][size];
	// {0,1,0,0}
	// {1,0,1,1}
	// {0,1,0,1}
	// {0,1,1,0}
	
	int minEdge = list[0]->edgeNumber;
	int maxEdge = list[0]->edgeNumber;
	
	for(int i=0;i<size;i++){
		if(list[i]->edgeNumber < minEdge){
			minEdge = list[i]->edgeNumber;
		}
		if(list[i]->edgeNumber > maxEdge){
			maxEdge= list[i]->edgeNumber;
		}
	}

	// cout<<minEdge<<" "<<maxEdge<<endl;
	// graphCreater
	int iterator = 0;
	for(int i = minEdge; i<=maxEdge;i++){
		if(i == list[i]->edgeNumber){
			
			for(int j = 0;j<=maxEdge;j++){
				if(iterator < list[i]->edgeIsConnectedTo.size()){
					if(j == list[i]->edgeIsConnectedTo[iterator]){
						cout<<1<<" ";
						iterator++;
						graph[i][j] = 1;
						continue;
					}
				}
				cout<<0<<" ";
				graph[i][j] = 0;
			}cout<<endl;
			iterator = 0;

		}
		
	}
	
	cout<<endl;

	for(int i = 0 ; i <size;i++){
		for(int j = 0 ;j<size;j++){
			cout<<graph[i][j]<<" ";
		}cout<<endl;
	}
	


	
}
























































