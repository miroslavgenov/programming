#include <iostream>
#include <vector>
#include <queue>

#include "/home/user/Desktop/programming/c++/dataStructures/graph/vertexConnection.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphFlags.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/Graph.cpp"

using namespace std;

struct vertexAndChild{
	int vertexParent;
	std::vector<int> child;
};

// main BFS basic bfs function and advanced bfs funtion that shows the shortes path
class BFS:Graph{
	public:

	std::queue<int> bfsQueue;
	std::vector<int> path;
	bool *visitedVerticies = nullptr;
	int currentVertex;
	int targetVertex;

	BFS(int *srcGraph, int srcGraphSize):Graph(srcGraph,srcGraphSize){
		visitedVerticies  = new bool[graphSize];
	}

	void emptyQueueStackAndVisitedVerticies(){
		bfsQueue = std::queue<int>();
		path = std::vector<int>();
		visitedVerticies = new bool[graphSize];
	}

	std::vector<int> bfs(int sv){
		emptyQueueStackAndVisitedVerticies();

		bfsQueue.push(sv);

		while(bfsQueue.empty() == false){
			currentVertex = bfsQueue.front();

			if(visitedVerticies[currentVertex] == 0){
				
				path.push_back(currentVertex);
				visitedVerticies[currentVertex] = 1;

				for(int i=0;i<graphSize;i++){
					if(graph[currentVertex][i] != 0 && visitedVerticies[i] == 0){
						bfsQueue.push(i);
					}
				}
			}

			bfsQueue.pop();
		}
		return path;
	}

	bool isChildVertexAlreadyInParentChilds(int childVertexNumber, vertexAndChild** hs){
		for(int i=0;i<graphSize;i++){
			for(int j=0;j<hs[i]->child.size();j++){
				if(hs[i]->child[j] == childVertexNumber){
					return true;
				}
			}
		}
		return false;
	}

	void bfs(int st, int tg){	
		std::queue<int> qw;
		int cv;
		bool vs[graphSize]{0};
		vertexAndChild** hst =new vertexAndChild*[graphSize]; 
		int vertexAppendedTheTg;


		for(int i=0;i<graphSize;i++){
			hst[i] = new vertexAndChild{i,{}};
		}


		qw.push(st);

		while(qw.empty() == false){

			cv = qw.front();

			if(vs[cv] == 0){

				vs[cv] = 1;

				for(int i=0;i<graphSize;i++){
					if(graph[cv][i] != 0 && vs[i] == 0){
						if(isChildVertexAlreadyInParentChilds(i,hst) == false){
							hst[cv]->child.push_back(i);
							qw.push(i);

							if(i == tg){
								vertexAppendedTheTg=cv;
								makeStartVertexPathToTargetVertexPathReadable(tg,vertexAppendedTheTg,hst);
								return;
							}
						}

					}
				}
			}

			qw.pop();

		}
	}

	int getTheParrentOfThatChildVertex(int childVertex, vertexAndChild** hst){
		for(int i=0;i<graphSize;i++){
			for(int j=0;j<hst[i]->child.size();j++){
				if(childVertex == hst[i]->child[j]){
					return hst[i]->vertexParent;
				}
			}
		}

		return -1;
	}

	std::vector<int> getThePath(int tg, vertexAndChild** hst){
		std::vector<int> pathBackwards;

		int tgv = tg;

		pathBackwards.push_back(tgv);
		while( (tgv = getTheParrentOfThatChildVertex(tgv,hst)) != -1){
			pathBackwards.push_back(tgv);
		}

		return pathBackwards;

	}

	std::vector<int> getTheReversePath(std::vector<int> path){

		vector<int> p;
		for(int i=path.size()-1;i>=0;i--){
			p.push_back(path[i]);
		}

		return p;
	}

	void makeStartVertexPathToTargetVertexPathReadable(int targetVertex, int vertexThatAppendedTargetVertex, vertexAndChild** hst){		
		std::vector<int> pathBackwards = getThePath(targetVertex,hst);

		pathBackwards = getTheReversePath(pathBackwards);

		printPath(pathBackwards);
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