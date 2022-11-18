// #pragma once
#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"
#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/LinkedList.cpp"
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
	LinkedList<int>* listWithTheLeafValues = nullptr;
	vector<int> leafValues;

	Tree(int data){
		initializeRootLeaf(data);
		initializeListWithTheLeafValues(data);
	}

	void initializeRootLeaf(int data){
		rootLeaf = new Leaf{data, nullptr, nullptr};
	}

	void initializeListWithTheLeafValues(int data){
		listWithTheLeafValues = new LinkedList(data);
	}

	void appendLeaf(Leaf* parentLeaf, Leaf* leaf){
		if(!NullptrChecker::isLeafNullptr(leaf)){
			if(parentLeaf->data > leaf->data){
				shouldAppendALeftNode(parentLeaf,leaf);
			}else{
				shouldAppendARightNode(parentLeaf, leaf);
			}	
		}
	}

private:
	void shouldAppendALeftNode(Leaf* parentLeaf, Leaf* leaf){
		if(parentLeaf->left){
			appendLeaf(parentLeaf->left, leaf);
		}else{
			parentLeaf->left=new Leaf{leaf->data,leaf->left,leaf->right};
			listWithTheLeafValues->appendAtEnd(leaf->data);
		}
	}

	void shouldAppendARightNode(Leaf* parentLeaf, Leaf* leaf){
		if(parentLeaf->right){
			appendLeaf(parentLeaf->right, leaf);
		}else{
			parentLeaf->right=new Leaf{leaf->data,leaf->left,leaf->right};
			listWithTheLeafValues->appendAtEnd(leaf->data);
		}
	}

public:
	void deleteLeafByData(int targetLeafData){	
		if(isTreeAndLeafDataPresent(targetLeafData)){
			listWithTheLeafValues->deleteByValue(targetLeafData);
			updateTree();
		}
	}
	
	bool isTreeAndLeafDataPresent(int targetLeafData){
		return !NullptrChecker::isLeafNullptr(rootLeaf) && 
			TreeFinderUtil::isLeafDataInTree(rootLeaf, targetLeafData);
	}

private:
	void updateTree(){					
		transferTheLeafValuesAndEmptyTheList(listWithTheLeafValues->size());
		appendTheRemainingLeafsToTheTree();

		leafValues.clear();
	}

	void transferTheLeafValuesAndEmptyTheList(int listWithLeafSize){
		for(size_t i = 0; i < listWithLeafSize; i++){
			leafValues.push_back(*listWithTheLeafValues->deleteFromBegining());
		}
	}
	void appendTheRemainingLeafsToTheTree(){
		initializeRootLeaf(new Leaf{leafValues[0], nullptr, nullptr});

		for(size_t i = 1; i < leafValues.size(); i++){
			appendLeaf(rootLeaf, new Leaf{leafValues[i], nullptr, nullptr});
		}
	}

	void initializeRootLeaf(Leaf* sourceLeaf){
		rootLeaf->data = sourceLeaf->data;
		rootLeaf->left = sourceLeaf->left;
		rootLeaf->right = sourceLeaf->right;
	}

public:
	int getTheDataFromLeaf(Leaf* leaf){
		return leaf->data;
	}

	friend ostream& operator<<(ostream&, const Tree*);
};

ostream& operator<<(ostream& os, const Tree* tree){
	os<<tree->listWithTheLeafValues;
	return os;
}
