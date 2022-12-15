#include <iostream>
#include <queue>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"

#include "/home/home/Desktop/programming/c++/dataStructures/tree/FirstSearchUtil.h"

using namespace std;

template <typename T>
class BFS{
	public:
	queue<T> queueForBfs;

	BFS(T rootLeaf){
		// need to fix this if the user pass other than rootLeaf
		queueForBfs.push(rootLeaf);
	}

	void bfs(){
		if(queueForBfs.empty() == false){
			cout<<*queueForBfs.front()->data<<endl;
			
			// FirstSearchUtil::shouldAppendLeafTo(queueForBfs.front()->left,queueForBfs);
			// FirstSearchUtil::shouldAppendLeafTo(queueForBfs.front()->right, queueForBfs);
			// cout<<*queueForBfs.front()->data<<endl;
			queueForBfs.push(queueForBfs.front()->right);
			queueForBfs.pop();
			queueForBfs.push(queueForBfs.front()->left);
			cout<<queueForBfs.size()<<endl;
			queueForBfs.pop();

			cout<<*queueForBfs.front()->data<<endl;
			// shouldAppendLeafToQueue(queueForBfs.front()->right);
			// shouldAppendLeafToQueue(queueForBfs.front()->left);

			

			if(queueForBfs.empty() == false){
				queueForBfs.pop();
				// bfs();
			}
			
			// cout<<*queueForBfs.front()->data<<endl;
		}
	}

	void shouldAppendLeafToQueue(T leaf){
		if(leaf){
			queueForBfs.push(leaf);
		}
	}



};


int main(){
	
	
	Tree<int*>* tree = new Tree(new int{3});
	
	tree->appendLeaf(new Leaf(new int{5}));
	tree->appendLeaf(new Leaf(new int{4}));
	tree->appendLeaf(new Leaf(new int{1}));
	tree->appendLeaf(new Leaf(new int{2}));
	tree->appendLeaf(new Leaf(new int{7}));
	tree->appendLeaf(new Leaf(new int{6}));

	

	BFS<Leaf<int*>*>* t = new BFS(tree->rootLeaf);
	
	t->bfs();


	

}















































