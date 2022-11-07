#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph/include/Graph.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Vertex.h"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include <queue>

using namespace std;

bool visitedVerticies[7]{};

void bfs(Vertex** verticies , queue<Vertex*>& q,int graphSize){
	if(q.size()>0){
			if(visitedVerticies[q.front()->vertexNumber]==0){
				Vertex* currentVertex = q.front();
				cout<<"-> "<<currentVertex->vertexNumber<<endl;
				q.pop();

				visitedVerticies[currentVertex->vertexNumber]=1;

		
				for(int i=0;i<currentVertex->connectedVerticies.size();i++){

					if(visitedVerticies[currentVertex->connectedVerticies[i]] == 0){
						q.push(verticies[currentVertex->connectedVerticies[i]]);
					}
	
				}

				bfs(verticies,q,graphSize);

		}
	}
	
}

int main(){
    int GRAPH_SIZE = 7;
    Vertex* verticies[GRAPH_SIZE] = {
	    new Vertex {0, {1, 3}},
	    new Vertex {1, {0, 2, 4}},
	    new Vertex {2, {1, 3, 5}},
	    new Vertex {3, {0, 2, 5, 6}},
	    new Vertex {4, {1}},
	    new Vertex {5, {2, 3, 6}},
	    new Vertex {6, {3, 5}}
	};

	Graph *g = new Graph(verticies,GRAPH_SIZE);
    
    queue<Vertex*> q;
	q.push(verticies[0]);
    
	
    bfs(verticies, q, GRAPH_SIZE);

	
    
}