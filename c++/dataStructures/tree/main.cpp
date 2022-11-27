// #pragma once
#include <iostream>
#include <vector>

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

// 	void appendLeaf(Leaf* parentLeaf, Leaf* leaf){
// 		if(!NullptrChecker::isLeafNullptr(leaf)){
// 			if(parentLeaf->data > leaf->data){
// 				shouldAppendALeftNode(parentLeaf,leaf);
// 			}else{
// 				shouldAppendARightNode(parentLeaf, leaf);
// 			}	
// 		}
// 	}

// private:
// 	void shouldAppendALeftNode(Leaf* parentLeaf, Leaf* leaf){
// 		if(parentLeaf->left){
// 			appendLeaf(parentLeaf->left, leaf);
// 		}else{
// 			parentLeaf->left=new Leaf{leaf->data,leaf->left,leaf->right};
// 			// listWithTheLeafValues->appendAtEnd(leaf->data);
// 		}
// 	}

// 	void shouldAppendARightNode(Leaf* parentLeaf, Leaf* leaf){
// 		if(parentLeaf->right){
// 			appendLeaf(parentLeaf->right, leaf);
// 		}else{
// 			parentLeaf->right=new Leaf{leaf->data,leaf->left,leaf->right};
// 			// listWithTheLeafValues->appendAtEnd(leaf->data);
// 		}
// 	}

// public:
// 	void deleteLeafByData(int targetLeafData){	
// 		if(isTreeAndLeafDataPresent(targetLeafData)){
// 			// listWithTheLeafValues->deleteByValue(targetLeafData);
// 			updateTree();
// 		}
// 	}
	
// 	bool isTreeAndLeafDataPresent(int targetLeafData){
// 		return !NullptrChecker::isLeafNullptr(rootLeaf) && 
// 			TreeFinderUtil::isLeafDataInTree(rootLeaf, targetLeafData);
// 	}

// private:
// 	void updateTree(){					
// 		// transferTheLeafValuesAndEmptyTheList(listWithTheLeafValues->size());
// 		appendTheRemainingLeafsToTheTree();

// 		leafValues.clear();
// 	}

// 	void transferTheLeafValuesAndEmptyTheList(int listWithLeafSize){
// 		for(size_t i = 0; i < listWithLeafSize; i++){
// 			// leafValues.push_back(*listWithTheLeafValues->deleteFromBegining());
// 		}
// 	}
// 	void appendTheRemainingLeafsToTheTree(){
// 		initializeRootLeaf(new Leaf{leafValues[0], nullptr, nullptr});

// 		for(size_t i = 1; i < leafValues.size(); i++){
// 			appendLeaf(rootLeaf, new Leaf{leafValues[i], nullptr, nullptr});
// 		}
// 	}

// 	void initializeRootLeaf(Leaf* sourceLeaf){
// 		rootLeaf->data = sourceLeaf->data;
// 		rootLeaf->left = sourceLeaf->left;
// 		rootLeaf->right = sourceLeaf->right;
// 	}

// public:
// 	int getTheDataFromLeaf(Leaf* leaf){
// 		return leaf->data;
// 	}

// template <typename X>
// 	friend ostream& operator<<(ostream&, const Tree<X>*);
};

// template <typename T>
// ostream& operator<<(ostream& os, const Tree<T>* tree){
// 	// os<<tree->listWithTheLeafValues;
// 	return os;
// }

int main(){

	Tree<int*> t(new int{4});
	// Leaf<int> *l1 = new Leaf{4};
	// Leaf<int> *l = new Leaf{3,l1};
	// cout<<l->left->data<<endl;
	
}