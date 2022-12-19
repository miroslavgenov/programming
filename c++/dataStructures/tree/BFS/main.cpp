#include <iostream>
#include <queue>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/FirstSearchUtil.h"

using namespace std;

template <typename T>
class BFS{
public:
	queue<T> queueForBfs;

	BFS(T rootLeaf){
		queueForBfs.push(rootLeaf);
	}

	void bfs(){
		
		if(queueForBfs.empty() == false){
			cout<<*queueForBfs.front()->data<<endl;
			
			//NOTE: To edit the order of appending leafs in the container change the function algorithm.
			FirstSearchUtil::shouldAppendLeafsTo(queueForBfs.front(), queueForBfs);
			
			if(queueForBfs.empty() == false){
				queueForBfs.pop();
				bfs();
			}
		}
	}
};