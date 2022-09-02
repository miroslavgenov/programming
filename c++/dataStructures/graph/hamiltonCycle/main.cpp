/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			THIS ALGORITHM IS NOT OPTIMIZE
 * 			IF YOU START FROM VERTEX DIVERENT
 * 			THAN 0 WILL NOT VISIT THE CORRECT
 * 			VERTEXT ONLY ONCE
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * 
 * @version 0.1
 * @date 2022-09-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

const int graphSize = 7;
bool visitedVerticies[graphSize]{0};

void printGraph(int graph[][graphSize], int size){
	cout<<endl;
	for(int i=0;i<size;i++){
		for(int j=0; j<size;j++){
			cout<<graph[i][j]<<' ';
		}cout<<endl;
	}
	cout<<endl;
}
void clearEdgesOfVertex(int graph[][graphSize], int vertex){
	for(int i=0;i<graphSize;i++){
		graph[vertex][i] = 0;
	}
}

vector<int> visitedVerticiesHistory;
vector<int> currentVertex;
void dfs(int graph[][graphSize], int vertex){
	if(visitedVerticies[vertex] == 0){
		visitedVerticies[vertex] = 1;
		
		currentVertex.push_back(vertex);
		visitedVerticiesHistory.push_back(vertex);
		

		for(int i=0;i<graphSize; i++){
			if(graph[vertex][i] !=0 && visitedVerticies[i] == 0){

				currentVertex.push_back(i);
				cout<<"from: "<<vertex<<" to: "<<i<<endl;
				clearEdgesOfVertex(graph,vertex);
//				printGraph(graph,graphSize);
				dfs(graph,currentVertex[currentVertex.size()-1]);
				currentVertex.pop_back();
			}
		}

	}
}

bool isHamiltonCycle(int graph[][graphSize], int startVertex){
	return graph[visitedVerticiesHistory[visitedVerticiesHistory.size()-1]][startVertex];
}

int main(){
	int graph[graphSize][graphSize] = {
		   { 0, 3, 0, 0, 0, 5, 2 },
  { 3, 0, 2, 0, 7, 0, 1 },
 
  { 0, 2, 0, 3, 6, 0, 0 },
 
  { 0, 0, 3, 0, 4, 0, 0 },
  
  { 0, 7, 6, 4, 0, 4, 0 },
  
  { 5, 0, 0, 0, 4, 0, 3 },
  
  { 2, 1, 0, 0, 0, 3, 0 }
	};
	//TODO if not all verticies are visited print to start with startVertext of 0
	int startVertex = 0;
	dfs(graph,startVertex);
	printGraph(graph,graphSize);
	cout<<isHamiltonCycle(graph,startVertex);
	
	
	
	
}





































