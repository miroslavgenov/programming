#pragma once

#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/include/LinkedListHelper.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NullptrChecker.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/TreeFinderUtil.cpp"

using namespace std;

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
		appendLeaf(&rootLeaf,leaf);
	}
	
	private:
	void appendLeaf(Leaf<T>** rootLeaf, Leaf<T>* leaf){
		if(canAppendLeaf(*rootLeaf)){			
			*rootLeaf = leaf;
		}
		else{
			shouldAppendLeftOrRightLeaf(*rootLeaf, leaf);
		}
	}

	void shouldAppendLeftOrRightLeaf(Leaf<T>* rootLeaf,Leaf<T>*leaf){
		if(*rootLeaf->data > *leaf->data){	
			appendLeaf(&rootLeaf->left,leaf);
		}
		else{
			appendLeaf(&rootLeaf->right,leaf);
		}
	}


	bool canAppendLeaf(Leaf<T>* leaf){
		return leaf == nullptr;
	}


template <typename X>
	friend std::ostream& operator<<(std::ostream&, const Tree<X>*);

template <typename X>
	friend std::ostream& operator<<(std::ostream&, const Tree<X>&);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>* tree){
	tree->listWithTheLeafValues->print();
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree){
	tree.listWithTheLeafValues->print();
	return os;
}
