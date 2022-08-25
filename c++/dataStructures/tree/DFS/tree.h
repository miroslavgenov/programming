#pragma once


struct treeNode{
	int num;
	treeNode* left;
	treeNode* right;
};

void clearTreeNodeRoot(treeNode*);
void clearTreeNodeLeft(treeNode*);
void clearTreeNodeRight(treeNode*);
void deleteTreeNode(treeNode* ,int);
void initTree(int);
void appendTreeNode(treeNode * rootTree ,treeNode *value);
void printTree(treeNode *rootTree);
treeNode* search(treeNode *rootTree, int num);
void minNode(treeNode *rootTree,int &min);
void maxNode(treeNode* rootTree,int &max);
void clearTreeNodeRoot(treeNode* rootTree);
void deleteTreeNode(treeNode* rootTree, int num);
void clearTreeNodeLeft(treeNode *rootTree);
void clearTreeNodeRight(treeNode* rootTree);
