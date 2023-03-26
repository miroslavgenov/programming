#include <iostream>

using namespace std;

bool isVertexNotVisitedAndConnectedToCurrentVertex(int , int );
bool isCurrentVertexConnectedToThatVertex(int , int );
void dfs(int );
bool isVertexVisited(int );
void printVertex(int );
void markVertexAsVisited(int );
void printVertexAndMarkItAsVisited(int );

constexpr size_t GRAPH_SIZE = 6;
constexpr int GRAPH[GRAPH_SIZE][GRAPH_SIZE] = {
	{0, 1, 1, 0, 1, 0},
	{1, 0, 1, 1, 0, 0},
	{1, 1, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 1},
	{0, 0, 0, 0, 1, 0}
};
bool visitedVerticies[GRAPH_SIZE] = { 0 };

int main(){
	dfs(0);	
}

void dfs(const int currentVertex){
	printVertexAndMarkItAsVisited(currentVertex);
	
	for(int vertex = 0; vertex < GRAPH_SIZE; vertex++){
		if(isVertexNotVisitedAndConnectedToCurrentVertex(vertex, currentVertex)){
			dfs(vertex);
		}
	}
}

void printVertexAndMarkItAsVisited(int vertex){
	printVertex(vertex);
	markVertexAsVisited(vertex);
}

void printVertex(int vertex){
	cout<<vertex<<endl;
}

void markVertexAsVisited(int vertex){
	visitedVerticies[vertex] = 1;
}

bool isVertexNotVisitedAndConnectedToCurrentVertex(int connectedVertex, int currentVertex){
	return isCurrentVertexConnectedToThatVertex(currentVertex, connectedVertex) && !isVertexVisited(connectedVertex);
}

bool isCurrentVertexConnectedToThatVertex(int currentVertex, int thatVertex){
	return GRAPH[currentVertex][thatVertex] == 1;
}

bool isVertexVisited(int vertex){
	return visitedVerticies[vertex] == 1;
}
