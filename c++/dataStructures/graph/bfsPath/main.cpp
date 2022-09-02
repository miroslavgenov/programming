#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int graphSize = 8;
bool visitedVerticies[graphSize]{0};
vector<int> verticiesPath;
queue<int> verticiesQueue;
bool isTargetFound = false;


void bfs(int graph[][graphSize] ,int vertex){
	if(visitedVerticies[vertex] == 0){
		visitedVerticies[vertex] = 1;
		
		

	}
}


void searchBfsPathFromVertextToVertextAndShow(int graph[][graphSize], int fromVertex, 
	int toVertext){
	
}

int main(){
	int graph[graphSize][graphSize] = {
		{0,	1,	1,	0,	0,	0,	0,	0},
		{1,	0,	1,	1,	0,	0,	0,	0},
		{1,	1,	0,	0,	1,	0,	0,	1},
		{0,	1,	0,	0,	1,	0,	0,	0},
		{0,	0,	1,	1,	0,	1,	0,	0},
		{0,	0,	0,	0,	1,	0,	1,	0},
		{0,	0,	0,	0,	0,	1,	0,	1},
		{0,	0,	1,	0,	0,	0,	1,	0}
	};


	bfs(graph, 0);


	

	
	


}