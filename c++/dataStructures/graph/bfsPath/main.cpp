#include <iostream>
#include <vector>
#include <queue>

#include "/home/user/Desktop/programming/c++/dataStructures/graph/vertexConnection.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphFlags.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/Graph.cpp"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/vertexAndChilds.h"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/GraphSearcher.cpp"
#include "/home/user/Desktop/programming/c++/dataStructures/graph/bfsPath/Bfs.cpp"

using namespace std;




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

	Bfs* bfs = new Bfs((int *)graph,graphSize);

	bfs->printPath(bfs->bfs(0));
}