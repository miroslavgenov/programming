#pragma once
#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"

class NullptrChecker{
public:	
	

	static bool isNumberNullptr(int* number){
		return number == nullptr;
	}

	template <typename T>
	static bool isLeafNullptr(Leaf<T>* targetLeaf){
		return targetLeaf == nullptr;
	}

};


