#include <iostream>
#include <vector>
#include <queue>

#include "/home/user/Desktop/programming/c++/dataStructures/graph/vertexConnection.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphFlags.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/Graph.cpp"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/vertexAndChilds.h"

using namespace std;

class BFS:Graph{
	public:

	std::queue<int> bfsQueue;
	std::vector<int> path;
	vertexAndChilds** history = nullptr;
	bool *visitedVerticies = nullptr;
	int *currentVertex = nullptr;

	BFS(int *srcGraph, int srcGraphSize):Graph(srcGraph,srcGraphSize){
		visitedVerticies  = new bool[graphSize];
	}

	void clearTheBasicVariables(){
		bfsQueue = std::queue<int>();
		path = std::vector<int>();
		visitedVerticies = new bool[graphSize];
		history = new vertexAndChilds*[graphSize];
		currentVertex = new int;
	}

	bool isChildVertexAlreadyInParentChilds(int childVertexNumber, vertexAndChilds** hs){
		for(int i=0;i<graphSize;i++){
			for(int j=0;j<hs[i]->child.size();j++){
				if(hs[i]->child[j] == childVertexNumber){
					return true;
				}
			}
		}
		return false;
	}

	void initializeHistory(){
		for(int i=0;i<graphSize;i++){
			history[i] = new vertexAndChilds{i,{}};
		}
	}

	std::vector<int> bfs(int startVertex, int *targetVertex = nullptr){	
		int vertexAppendedTheTg;

		clearTheBasicVariables();
		initializeHistory();	

		bfsQueue.push(startVertex);

		while(bfsQueue.empty() == false){

			*currentVertex = bfsQueue.front();

			if(visitedVerticies[*currentVertex] == 0){
				
				path.push_back(*currentVertex);

				visitedVerticies[*currentVertex] = 1;

				for(int i=0;i<graphSize;i++){

					if(graph[*currentVertex][i] != 0 && visitedVerticies[i] == 0){

						if(isChildVertexAlreadyInParentChilds(i,history) == false && targetVertex != nullptr){
							
							history[*currentVertex]->child.push_back(i);

							bfsQueue.push(i);

							if(i == *targetVertex ){
								
								path.push_back(i);

								vertexAppendedTheTg=*currentVertex;
								makeStartVertexPathToTargetVertexPathReadable(*targetVertex,history);
								return path;
							}
						}else{
							bfsQueue.push(i);							
						}

					}
				}
			}
			bfsQueue.pop();
		}

		return path;
	}

	int getTheParrentOfThatChildVertex(int childVertex, vertexAndChilds** hst){
		for(int i=0;i<graphSize;i++){
			for(int j=0;j<hst[i]->child.size();j++){
				if(childVertex == hst[i]->child[j]){
					return hst[i]->vertexParent;
				}
			}
		}

		return -1;
	}

	std::vector<int> getTheChildernsAndTheStartingParent(int tg, vertexAndChilds** hst){
		std::vector<int> pathBackwards;

		int tgv = tg;

		pathBackwards.push_back(tgv);
		while( (tgv = getTheParrentOfThatChildVertex(tgv,hst)) != -1){
			pathBackwards.push_back(tgv);
		}

		return pathBackwards;
	}

	std::vector<int> getThePathReversed(){
		vector<int> p;

		for(int i=path.size()-1;i>=0;i--){
			p.push_back(path[i]);
		}

		return p;
	}

	void makeStartVertexPathToTargetVertexPathReadable(int targetVertex, vertexAndChilds** hst){		
		path = getTheChildernsAndTheStartingParent(targetVertex,hst);

		path = getThePathReversed();

	}

	void printPath(std::vector<int> path){
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
	}
};


int main(){    
	const int graphSize = 8;
	int graph[graphSize][graphSize] = {
	//	0	1	2	3	4	5	6	7
		{0,	1,	1,	0,	0,	0,	0,	0}, //0
		{1,	0,	1,	1,	0,	0,	0,	0}, //1
		{1,	1,	0,	0,	1,	0,	0,	1}, //2
		{0,	1,	0,	0,	1,	0,	0,	0}, //3
		{0,	0,	1,	1,	0,	1,	0,	0}, //4
		{0,	0,	0,	0,	1,	0,	1,	0}, //5
		{0,	0,	0,	0,	0,	1,	0,	1}, //6
		{0,	0,	1,	0,	0,	0,	1,	0}  //7
	};

	BFS* bfs = new BFS((int *)graph,graphSize);

	bfs->printPath(bfs->bfs(0));
}