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

int main(){
	
	
	int graph[GRAPH_SIZE][GRAPH_SIZE]={
		{0,1,1,0,1,0},
		{1,0,1,1,0,0},
		{1,1,0,0,0,0},
		{0,1,0,0,0,0},
		{1,0,0,0,0,1},
		{0,0,0,0,1,0}
	};

	int startFromThisVertex=  2;
	sStack = new Stack<int>();
	dfs(graph, startFromThisVertex);
	


	
}
























































