#include <iostream>
#include "tree.cpp"

int main(){
	initTree(5);
	treeNode *n1 = new treeNode{4,nullptr,nullptr};
	appendTreeNode(::rootTree, n1);
	printTree(::rootTree);
}

