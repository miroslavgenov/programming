#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"
#include <queue>

using namespace std;
	
template <typename T>
void bfs(queue<T> &queueWithData){
	if(queueWithData.size() > 0){

		cout<<queueWithData.front()->data<<endl;

		if(queueWithData.front()->left){
			queueWithData.push(queueWithData.front()->left);
		}

		if(queueWithData.front()->right){
			queueWithData.push(queueWithData.front()->right);
		}
		
		queueWithData.pop();
		bfs(queueWithData);
	}
}
	
int main(){
	
	
	Tree<int*>* rt = new Tree(new int{3});
	
	rt->appendLeaf(new Leaf(new int{4}));
	rt->appendLeaf(new Leaf(new int{1}));
	rt->appendLeaf(new Leaf(new int{2}));
	rt->appendLeaf(new Leaf(new int{7}));
	
	Printer::printTree(rt->rootLeaf);
	// cout<<endl;
	
	// queue<Leaf*> q;
	// q.push(rt->rootLeaf);
	// bfs(q);
	
	
	

}















































