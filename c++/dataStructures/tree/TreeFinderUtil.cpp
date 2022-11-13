#pragma once
#include "Leaf.h"

class TreeFinderUtil{
    public:

    static bool isLeafFound;

	static bool isLeafDataInTree(Leaf* rootLeaf, int dataToBeSearched){
		TreeFinderUtil::searchLeafByData(rootLeaf,dataToBeSearched);
		return TreeFinderUtil::isLeafFound;
	}

    static void searchLeafByData(Leaf* parentLeaf, int data){
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
