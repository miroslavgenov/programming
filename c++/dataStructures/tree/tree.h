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

	Tree(T );

	void initializeRootLeaf(T );

	void initializeListWithTheLeafValues(T );

	void appendLeaf(Leaf<T>* );
	
private:
	void appendLeaf(Leaf<T>** , Leaf<T>* );

	void shouldAppendLeftOrRightLeaf(Leaf<T>*, Leaf<T>*);

	bool isLeafNullptr(Leaf<T>* );

template <typename X>
	friend std::ostream& operator<<(std::ostream&, const Tree<X>*);

template <typename X>
	friend std::ostream& operator<<(std::ostream&, const Tree<X>&);
};
