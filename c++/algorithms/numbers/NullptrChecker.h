#pragma once
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"

class NullptrChecker{
public:	
	static Leaf* nullptrLeaf;

	static bool isNumberNullptr(int* number){
		return number == nullptr;
	}

	static bool isLeafNullptr(Leaf* targetLeaf){
		return targetLeaf == nullptrLeaf;
	}

};

Leaf* NullptrChecker::nullptrLeaf = nullptr;

