#include <iostream>

using namespace std;

constexpr size_t GRAPH_SIZE = 6;
constexpr int GRAPH[GRAPH_SIZE][GRAPH_SIZE] = {
	{0, 1, 1, 0, 1, 0},
	{1, 0, 1, 1, 0, 0},
	{1, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 1, 0}
};
bool visitedVerticies[GRAPH_SIZE]{0};

void dfs(int);

int main(){
	dfs(0);	
}

void dfs(const int currentVertex){
	cout<<currentVertex<<endl;
	visitedVerticies[currentVertex] = 1;
	
	for(int i = 0; i < GRAPH_SIZE; i++){
		if(GRAPH[currentVertex][i] == 1 && visitedVerticies[i] == 0){
			dfs(i);
		}
	}
}
























































