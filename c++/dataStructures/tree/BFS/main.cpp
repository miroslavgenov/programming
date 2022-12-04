#include <iostream>
// #include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/Queue/include/Queue.cpp"

using namespace std;
	
// template <typename T>
// void bfs(queue<T> &queueWithData){
// 	if(queueWithData.size() > 0){

// 		cout<<queueWithData.front()->data<<endl;

// 		if(queueWithData.front()->left){
// 			queueWithData.push(queueWithData.front()->left);
// 		}

// 		if(queueWithData.front()->right){
// 			queueWithData.push(queueWithData.front()->right);
// 		}
		
// 		queueWithData.pop();
// 		bfs(queueWithData);
// 	}
// }

// template <typename T>
// class BFS{
// 	public:
// 	Tree<T> *tree = nullptr;

// };

// template <typename T>
// void BFS(Tree<T> tree){

// }


int main(){
	
	
	// Tree<int*>* myt = new Tree(new int{3});
	
	// myt->appendLeaf(new Leaf(new int{4}));
	// myt->appendLeaf(new Leaf(new int{1}));
	// myt->appendLeaf(new Leaf(new int{2}));
	// myt->appendLeaf(new Leaf(new int{7}));
	
	Queue<int*> *q = new Queue(new int{4});
	q->push(new int{5});
	q->pop();
	// Printer::printTree(rt->rootLeaf);
	// cout<<endl;
	
	// queue<Leaf*> q;
	// q.push(rt->rootLeaf);
	// bfs(q);
	
	
	

}















































