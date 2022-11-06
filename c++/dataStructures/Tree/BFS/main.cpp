#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/Tree/main.cpp"
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

	Tree* rt = new Tree(3);
	rt->appendLeaf(rt->root,new Leaf{4,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{1,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{2,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{7,nullptr,nullptr});
	
	Printer::printTree(rt->root);
	cout<<endl;
	
	queue<Leaf*> q;
	q.push(rt->root);
	bfs(q);
	
	
	

}















































