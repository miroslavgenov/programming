// #pragma once
#include <iostream>

#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/include/LinkedListHelper.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NullptrChecker.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/TreeFinderUtil.cpp"

using namespace std;

template <typename T>
class TreeHelper{
	public:
	Leaf<T>* rootLeaf = nullptr;
};

template <typename T>
class Tree{

public:
	Leaf<T>* rootLeaf = nullptr;
	LinkedListHelper<T>* listWithTheLeafValues= nullptr; 
	vector<int> leafValues;

	Tree(T data){
		initializeRootLeaf(data);
		initializeListWithTheLeafValues(data);
	}

	void initializeRootLeaf(T data){
		rootLeaf = new Leaf(data);
	}

	void initializeListWithTheLeafValues(T data){
		listWithTheLeafValues = new LinkedListHelper(data);
	}

	void appendLeaf(Leaf<T>* leaf){
		appendLeaf(rootLeaf,leaf);
	}
	
	void appendLeaf(Leaf<T>* rootLeaf,Leaf<T>*leaf){
		if(listWithTheLeafValues->size() == 0){
			rootLeaf->data = new int{*leaf->data};
		}else{
			shouldAppend(rootLeaf, leaf);
			// shouldAppendLeftLeaf(rootLeaf,leaf);
			// shouldAppendRightLeaf(rootLeaf,leaf);
		}
	}

	

	void shouldAppend(Leaf<T>* rootLeaf, Leaf<T>* leaf){
		
		if(*rootLeaf->data > *leaf->data){
			if(canAppendLeaf(rootLeaf->left)){
				rootLeaf->left = leaf;
			}
	}
	}
	

	bool canAppendLeaf(Leaf<T>* leaf){
		return leaf == nullptr;
	}


//TO DO: clear this duplication
	// void shouldAppendRightLeaf(Leaf<T>* rootLeaf, Leaf<T>* leaf){
	// 	if(*rootLeaf->data < *leaf->data){
	// 		if(rootLeaf->right == nullptr){		
	// 			rootLeaf->right = leaf;
	// 			listWithTheLeafValues->appendAtEnd(leaf->data);
	// 		}
	// 		else{
	// 			appendLeaf(rootLeaf->right,leaf);
	// 		}
	// 	}
	// }
	// void shouldAppendLeftLeaf(Leaf<T>* rootLeaf, Leaf<T>* leaf){
	// 	if(*rootLeaf->data > *leaf->data){
	// 		if(rootLeaf->left == nullptr){
	// 			rootLeaf->left = leaf;
	// 			listWithTheLeafValues->appendAtEnd(leaf->data);				
	// 		}else{
	// 			appendLeaf(rootLeaf->left,leaf);
	// 		}
	// 	}
	// }

	

template <typename X>
	friend ostream& operator<<(ostream&, const Tree<X>*);

template <typename X>
	friend ostream& operator<<(ostream&, const Tree<X>&);
};

template <typename T>
ostream& operator<<(ostream& os, const Tree<T>* tree){
	tree->listWithTheLeafValues->print();
	return os;
}

template <typename T>
ostream& operator<<(ostream& os, const Tree<T>& tree){
	tree.listWithTheLeafValues->print();
	return os;
}

int main(){
	Tree<int*> *t  = new Tree(new int{5});
	t->appendLeaf(new Leaf(new int{3}));
	// t->appendLeaf(new Leaf(new int{4}));
	Printer::printTree(t->rootLeaf);
}