#include <iostream>
#include <queue>

using namespace std;

constexpr size_t GRAPH_SIZE = 4;
constexpr int GRAPH[GRAPH_SIZE][GRAPH_SIZE] = {
	{},
	{},
	{},
	{}
};
bool visitedVerticies[GRAPH_SIZE]{0};

void bfs();

int main(){
	bfs();
}
