// #pragma once
#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"


using namespace std;


class Tree{
	
public:
	Leaf* root=nullptr;
	bool isLeafFound=false;
	int minimumLeafValueFromLeft;

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
private:
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
public:
	bool isLeafInTree(Leaf* startLeaf, int data){
		search(startLeaf,data);
		return isLeafFound;
	}

	void prepareFindAndSetTheMinimumLeafValueFromLeft(){
		Leaf* pointer=root;
		minimumLeafValueFromLeft = pointer->data;
		
		findAndSetTheMinumumLeafValueFromLeft(pointer);
	}

	int getTheMinimumLeafValueFromLeft(){
		return minimumLeafValueFromLeft;
	}	

private:
	void findAndSetTheMinumumLeafValueFromLeft(Leaf* startLeaf){
		if(startLeaf){
			if(minimumLeafValueFromLeft > startLeaf->data){
				minimumLeafValueFromLeft = startLeaf->data;
			}
			findAndSetTheMinumumLeafValueFromLeft(startLeaf->left);
		}
	}

private:
	void search(Leaf* startLeaf, int data){
		isLeafFound=false;
		if(startLeaf){
			if(startLeaf->data == data){
				isLeafFound=true;
				return ;
			}else if(startLeaf->data > data){
				search(startLeaf->left,data);
			}else if(startLeaf->data < data){
				search(startLeaf->right,data);
			}
		}

	}

};

int main(){
	Tree* t = new Tree(1);
	
	t->appendLeaf(t->root,new Leaf{-1,nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{2,nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{4,nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{3,nullptr,nullptr});	

	t->prepareFindAndSetTheMinimumLeafValueFromLeft();
	cout<<t->getTheMinimumLeafValueFromLeft()<<endl;
	
	

}

