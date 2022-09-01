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

const int graphSize = 4;
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
				graph[vertex][i] = 0;
				graph[i][vertex] = 0;
				cout<<"from: "<<vertex<<" to: "<<i<<endl;
				printGraph(graph,graphSize);
				dfs(graph,currentVertex[currentVertex.size()-1]);
				currentVertex.pop_back();
			}
		}

	}
}

bool isHamiltonCycle(int graph[][graphSize], int startVertext){
	return graph[startVertext][visitedVerticiesHistory[visitedVerticiesHistory.size()-1]] &&
		graph[visitedVerticiesHistory[visitedVerticiesHistory.size()-1]][startVertext];
}

int main(){
	int graph[graphSize][graphSize] = {
		{0,1,1,1},
		{1,0,1,0},
		{1,1,0,1},
		{1,0,1,0}
	};
	int startVertex = 0;
	dfs(graph,startVertex);
	
	cout<<isHamiltonCycle(graph,startVertex);
	
}





































