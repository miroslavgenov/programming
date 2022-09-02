#include <iostream>
#include <vector>

using namespace std;

const int graphSize = 4;
bool visitedVertex[graphSize]{0};
int verticiesThatCanGoBackCount = 0;


bool isVertexVisited(int vertex){
	return visitedVertex[vertex];
}

bool canVertexGoBackToThatVertex(int graph[][graphSize], int vertex, int thatVertex){
	return graph[vertex][thatVertex];
}

vector<int> currentVertex;
void dfs(int graph[][graphSize], int vertex){
	if(!isVertexVisited(vertex)){	
		visitedVertex[vertex] = 1;
		currentVertex.push_back(vertex);
		for(int i=0;i<graphSize;i++){
			if(graph[vertex][i] != 0 && !isVertexVisited(i)){
				cout<<"vertex: "<<vertex<<" can visit: "<<i<<endl;
				cout<<"can: "<<i<<" go back to: "<<vertex<<" ? ";
				currentVertex.push_back(i);
				
				if(canVertexGoBackToThatVertex(graph,i,vertex)==true){
					cout<<"yes"<<endl;
					verticiesThatCanGoBackCount++;
				}
				else{
					cout<<" no"<<endl;
				}

				dfs(graph,currentVertex[currentVertex.size()-1]);
				currentVertex.pop_back();
			}
		}
	}
}

bool isGraphEulerCycle(int graph[][graphSize],int startVertex){
	dfs(graph,startVertex);
	return verticiesThatCanGoBackCount == graphSize-1;
}


int main(){
	int graph[graphSize][graphSize] = {
		{0,1,0,0},
		{1,0,1,0},
		{0,1,0,1},
		{0,1,1,0},
	};


	cout<<isGraphEulerCycle(graph, 1)<<endl;
	
	
	


	
	
}