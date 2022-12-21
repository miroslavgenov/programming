#include "/home/home/Desktop/programming/c++/dataStructures/tree/BFS/bfs.h"


template <typename T>
	BFS<T>::BFS(T rootLeaf){
		queueForBfs.push(rootLeaf);
	}
    
template <typename T>
	void BFS<T>::bfs(){
		
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
