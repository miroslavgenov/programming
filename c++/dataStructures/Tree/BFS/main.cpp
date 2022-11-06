#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/Tree/main.cpp"
#include <queue>

using namespace std;
	
template <typename T>
void bfs(queue<T> &q){
	if(q.size()>0){
		cout<<q.front()->data<<endl;
		if(q.front()->left){
			q.push(q.front()->left);
		}
		if(q.front()->right){
			q.push(q.front()->right);
		}
		q.pop();
	bfs(q);
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















































