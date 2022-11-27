#pragma once
#include "Leaf.h"

class TreeFinderUtil{
    public:

    static bool isLeafFound;


	template <typename T>
	static bool isLeafDataInTree(Leaf<T>* rootLeaf, int dataToBeSearched){
		TreeFinderUtil::searchLeafByData(rootLeaf,dataToBeSearched);
		return TreeFinderUtil::isLeafFound;
	}

	template <typename T>
    static void searchLeafByData(Leaf<T>* parentLeaf, int data){
		if(parentLeaf){
			if(parentLeaf->data == data){
				isLeafFound = true;
				return ;
			}else if(parentLeaf->data > data){
				searchLeafByData(parentLeaf->left, data);
			}else if(parentLeaf->data < data){
				searchLeafByData(parentLeaf->right, data);
			}
		}
	}
};

bool TreeFinderUtil::isLeafFound = false;
