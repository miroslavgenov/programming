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
	
	// int *graphSize = nullptr;
	// int **graph = nullptr;
	// bool *visitedVerticies = nullptr;
	// queue<int> qw;
	// int targetVertex;
	// std::vector<int> path;

	BFS(int *srcGraph, int srcGraphSize):Graph(srcGraph,srcGraphSize){

	}

	std::vector<int> bfs(int sv){
		std::queue<int> bfsQueue = std::queue<int>();
		std::vector<int> path = std::vector<int>();
		bool visitedVerticies[graphSize]{};
		int currentVertex;


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

	//TODO: 
	void bfs(int st, int tg){	
		std::queue<int> qw;
		int cv;
		bool vs[graphSize]{0};

		vertexAndChild** hs =new vertexAndChild*[graphSize];

		for(int i=0;i<graphSize;i++){
			hs[i] = new vertexAndChild{i,{}}; 
		}

		qw.push(st);

		while(qw.empty() == false){
			cv = qw.front();

			if(vs[cv] == 0){
				for(int i=0;i<graphSize;i++){
					if(graph[cv][i] != 0 & vs[i] == 0 ){

						for(int j=0;j<graphSize;j++){
							// if(hs[j]->)
						}

					}
				}
			}
		}

	}

	void printPath(std::vector<int> path){
		for(int i=0;i<path.size();i++){
			cout<<path[i]<<" ";
		}
	}
};



const int graphSize = 8;
bool visitedVerticies[graphSize]{};
queue<int> mq;

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


vertexAndChild **history = nullptr ;
int vertexThatAppendTheTargetVertex;

bool isChildVertexNumberAlreadyInParenstList(int childNumber){
	for(int i=0;i<graphSize;i++){
		for(int j=0;j<history[i]->child.size();j++){
			if(history[i]->child[j] == childNumber){
				return true;
			}
		}
	}

	return false;
}

void bfs(int targetVertex){
	int currentVertex;

	if(mq.empty() == false){
		currentVertex = mq.front();

		if(visitedVerticies[currentVertex] == 0){

			visitedVerticies[currentVertex] = 1;

			for(int i=0;i<graphSize;i++){
				if( graph[currentVertex][i] != 0 && visitedVerticies[i] == 0){


					if(isChildVertexNumberAlreadyInParenstList(i)  == false){
						history[currentVertex]->child.push_back(i);
						mq.push(i);
					}
					


					if(targetVertex == i){
						vertexThatAppendTheTargetVertex = targetVertex;
						return;
					}
					
				}
			}
		
			
		}
		
		mq.pop();
		bfs(targetVertex);
		

	}
}


void printHistory(){
	for(int i=0;i<graphSize;i++){
		if(history[i]->child.size()!=0){
			cout<<"vertex: "<<history[i]->vertexParent<<" : ";

			for(int j=0;j<history[i]->child.size();j++){
				cout<<history[i]->child[j]<<" ";
			}
			cout<<endl;
		}
	}
}

int getTheVertexNumberWhichAppendedThatVertex(int thatVertex){
	
	for(int i=0;i<graphSize;i++){
		for(int j=0;j<history[i]->child.size();j++){
			if(history[i]->child[j] == thatVertex){
				return history[i]->vertexParent;		
			}
		}
	}

	return -1;
}

vector<int>reversePath;

void printThePath(int vertexNumber){
	int targetVertex = vertexNumber;
	while((vertexNumber = getTheVertexNumberWhichAppendedThatVertex(vertexNumber)) != -1){
		reversePath.push_back(vertexNumber);
	}

	for(int i = reversePath.size()-1;i>=0;i--){
		cout<<reversePath[i]<<' ';
	}
	cout<<targetVertex<<endl;

}

int main(){    

	// history = new vertexAndChild*[graphSize];

	// for(int i=0;i<graphSize;i++){
	// 	history[i] = new vertexAndChild{i,{}};
	// }

	// mq.push(0);
	
	// int targetVertex = 6;

    // bfs(targetVertex);

	// printHistory();

	// printThePath(targetVertex);


	BFS* bfs = new BFS((int *)graph,graphSize);

	// bfs->printPath(bfs->bfs(0));
	// cout<<endl;
	// bfs->printPath(bfs->bfs(7));



}