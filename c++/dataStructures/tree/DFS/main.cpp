#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/main.cpp"
#include <vector>

using namespace std;

template <typename T>
void myDfs(vector<T> &stack){
	
		
		if(!stack.empty()){
			Leaf* currentLeaf = stack[stack.size()-1];
			stack.pop_back();
			cout<<currentLeaf->data<<endl;

			if(currentLeaf->right){
				stack.push_back(currentLeaf->right);
			}

			if(currentLeaf->left){
				stack.push_back(currentLeaf->left);
			}
			myDfs(stack);

		}
		

	

}

int main(){
	
	Tree* rt = new Tree(2);
	rt->appendLeaf(rt->root,new Leaf{1,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{3,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{0,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{5,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{4,nullptr,nullptr});
	rt->appendLeaf(rt->root,new Leaf{6,nullptr,nullptr});
	// Printer::printTree(rt->root);
	vector<Leaf*> stack;
	stack.push_back(rt->root);
	myDfs(stack);

}