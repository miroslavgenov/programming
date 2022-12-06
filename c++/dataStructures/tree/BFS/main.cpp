#include <iostream>
#include <queue>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"

using namespace std;

template <typename T>
class BFS{
	public:
	vector<T> thePathOfTheSearch;
	queue<T> queueForBfs;

	BFS(T root){
		// need to fix this if the user pass other than rootLeaf
		queueForBfs.push(root);
	}

	void bfs(){
		if(queueForBfs.empty() == false){
			cout<<*queueForBfs.front()->data<<endl;

			shouldAppendLeafToQueue(queueForBfs.front()->left);
			shouldAppendLeafToQueue(queueForBfs.front()->right);
			

			if(queueForBfs.empty() == false){
				queueForBfs.pop();
				bfs();
			}
		}
	}

	void shouldAppendLeafToQueue(T leaf){
		if(leaf){
			queueForBfs.push(leaf);
		}
	}


};


int main(){
	
	
	Tree<int*>* myt = new Tree(new int{3});
	

	myt->appendLeaf(new Leaf(new int{4}));
	myt->appendLeaf(new Leaf(new int{1}));
	myt->appendLeaf(new Leaf(new int{2}));
	myt->appendLeaf(new Leaf(new int{7}));
	

	BFS<Leaf<int*>*>* t = new BFS(myt->rootLeaf);
	
	t->bfs();
	
	

}















































