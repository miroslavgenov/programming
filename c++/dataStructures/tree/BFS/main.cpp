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

	BFS(T rootLeaf){
		// need to fix this if the user pass other than rootLeaf
		queueForBfs.push(rootLeaf);
	}

	void bfs(){
		if(queueForBfs.empty() == false){
			cout<<*queueForBfs.front()->data<<endl;
			thePathOfTheSearch.push_back(queueForBfs.front()->data);

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

	vector<T> getPath(){
		return thePathOfTheSearch;
	}


};


int main(){
	
	
	Tree<int*>* tree = new Tree(new int{3});
	

	tree->appendLeaf(new Leaf(new int{4}));
	tree->appendLeaf(new Leaf(new int{1}));
	tree->appendLeaf(new Leaf(new int{2}));
	tree->appendLeaf(new Leaf(new int{7}));
	

	BFS<Leaf<int*>*>* t = new BFS(tree->rootLeaf);
	
	t->bfs();
	vector<Leaf<int*>*> g  = t->getPath();


	

}















































