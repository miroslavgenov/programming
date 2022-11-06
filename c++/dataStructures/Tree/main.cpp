#pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/Tree/Leaf.h"


using namespace std;


class Tree{
	
public:
	Leaf* root=nullptr;
	// Leaf* rootPointer=nullptr;

	Tree(int data){
		root=new Leaf{data,nullptr,nullptr};
	}


	void appendLeaf(Leaf* startLeaf, Leaf* leaf){
		if(startLeaf->data > leaf->data){
			shouldAppendALeftNode(startLeaf,leaf);
		}else{
			shouldAppendARightNode(startLeaf, leaf);
		}	
	}

	void shouldAppendARightNode(Leaf* startLeaf, Leaf* leaf){
		if(startLeaf->right){
				appendLeaf(startLeaf->right, leaf);
			}else{
				startLeaf->right=new Leaf{leaf->data,leaf->left,leaf->right};
			}
	}

	void shouldAppendALeftNode(Leaf* startLeaf, Leaf* leaf){
		if(startLeaf->left){
				appendLeaf(startLeaf->left, leaf);
			}else{
				startLeaf->left=new Leaf{leaf->data,leaf->left,leaf->right};

			}
	}

	

	bool search(Leaf* startLeaf, int data){
		if(startLeaf){
			if(startLeaf->data == data){
				return true;
			}else if(startLeaf->data > data){
				search(startLeaf->left,data);
			}else if(startLeaf->data < data){
				search(startLeaf->right,data);
			}
		}else{
			return false;	
		}	
	}

};


// int main(){
// 	Tree* t = new Tree(1);
	
// 	t->appendLeaf(t->root,new Leaf{-1,nullptr,nullptr});
// 	t->appendLeaf(t->root,new Leaf{2,nullptr,nullptr});
// 	t->appendLeaf(t->root,new Leaf{4,nullptr,nullptr});
// 	t->appendLeaf(t->root,new Leaf{3,nullptr,nullptr});	
	
// }

