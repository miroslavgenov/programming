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
	int maximumLeafValueFromRight;

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

	void prepareFindAndSetTheMaximumLeafValueFromRight(){
		Leaf* pointer = root;
		maximumLeafValueFromRight = pointer->data;

		findAndSetTheMaxiumumLeafValueFromLeft(pointer);
	}

	int getTheMaximumLeafValueFromRight(){
		return maximumLeafValueFromRight;
	}	

private:
	void findAndSetTheMaxiumumLeafValueFromLeft(Leaf* currentLeaf){
		if(currentLeaf != nullptr){
			if(maximumLeafValueFromRight < currentLeaf->data){
				maximumLeafValueFromRight = currentLeaf->data;
			}

			findAndSetTheMaxiumumLeafValueFromLeft(currentLeaf->right);
		}
	}

public:


	void prepareFindAndSetTheMinimumLeafValueFromLeft(){
		Leaf* pointer = root;
		minimumLeafValueFromLeft = pointer->data;
		
		findAndSetTheMinumumLeafValueFromLeft(pointer);
	}

	int getTheMinimumLeafValueFromLeft(){
		return minimumLeafValueFromLeft;
	}	

private:
	void findAndSetTheMinumumLeafValueFromLeft(Leaf* currentLeaf){
		if(currentLeaf){
			if(minimumLeafValueFromLeft > currentLeaf->data){
				minimumLeafValueFromLeft = currentLeaf->data;
			}

			findAndSetTheMinumumLeafValueFromLeft(currentLeaf->left);
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

public:
// Leaf* deleteLeafPointer=root;

void deleteLeafWithValue(Leaf* rootPointer, int value){
	if(rootPointer)	
	{	
		// check if the parent have no child and delete the parent

		// check if parent have two child and check their values
		// left and right
		if(doParentLeafHaveTwoChilds(rootPointer)){
			cout<<"parentLeaf have left and right child"<<endl;
		}
		// check if parent have one child and check his value
		// left or right
		else if(doParentLeafHaveOneChild(rootPointer)){
			cout<<"parentChild have left or right child"<<endl;
			if(rootPointer->left != nullptr && rootPointer->left->data == value){
				cout<<"data found: "<<rootPointer->left->data<<endl;
				rootPointer->left=nullptr;
				// check if the target leaf have childs
			}else if(rootPointer->right != nullptr && rootPointer->right->data == value){
				cout<<"data found: "<<rootPointer->right->data<<endl;
				rootPointer->right=nullptr;
				// check if the target leaf have child
			}
		}



		// search for the value
		deleteLeafWithValue(rootPointer->left,value);
		deleteLeafWithValue(rootPointer->right,value);
	}
}



bool doParentLeafHaveTwoChilds(Leaf* parentLeaf){
return parentLeaf->left != nullptr && parentLeaf->right != nullptr;
}

bool doParentLeafHaveOneChild(Leaf* parentLeaf){
return parentLeaf->left != nullptr || parentLeaf->right != nullptr;
}


bool doParentLeafHaveAnyChilds(Leaf* parentLeaf){
	return doParentLeafHaveOneChild(parentLeaf);
}


};




int main(){
	Tree* t = new Tree(5);
	
	t->appendLeaf(t->root,new Leaf{3, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{2, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{4, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{1, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{0, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{7, nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{8, nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{10, nullptr,nullptr});
	t->appendLeaf(t->root,new Leaf{9, nullptr, nullptr});
	t->appendLeaf(t->root,new Leaf{6, nullptr, nullptr});
	

	t->prepareFindAndSetTheMinimumLeafValueFromLeft();
	cout<<"minimum Leaf value is: "<<t->getTheMinimumLeafValueFromLeft()<<endl;
	
	// t->prepareFindAndSetTheMaximumLeafValueFromRight();
	// cout<<t->getTheMaximumLeafValueFromRight()<<endl;
	t->deleteLeafWithValue(t->root, 0);
	
	Printer::printTree(t->root);

}

