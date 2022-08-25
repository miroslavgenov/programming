#include "tree.h"
#include <iostream>
using namespace std;


treeNode* rootTree=nullptr;



void initTree(int value){
	rootTree = new treeNode{value, nullptr, nullptr};
}

void appendTreeNode(treeNode * rootTree ,treeNode *value){
	
	if(rootTree->num>value->num){

		if(rootTree->left){


			appendTreeNode(rootTree->left,value);
		}else{

			rootTree->left=value;
		}
	}else{

		if(rootTree->right){


			appendTreeNode(rootTree->right, value);
			
		}else{

			rootTree->right = value;
		}
	}

}

void printTree(treeNode *rootTree){
	if(!rootTree){
		return;
	}
	
	printTree(rootTree->left);
	cout<<rootTree->num<<" ";
	printTree(rootTree->right);
	
}

treeNode* search(treeNode *rootTree, int num){
	
	if(!rootTree){

		return rootTree;
	}else{
		if(rootTree->num==num){
			

			return rootTree;
		}else if(rootTree->num>num){
			
			
			search(rootTree->left, num);
		}else if(rootTree->num < num){
			
			
			search(rootTree->right,num);
		}
	}
	
}

void minNode(treeNode *rootTree,int &min){
	if(rootTree){
		if(min > rootTree->num){
			
			min = rootTree->num;
			
		}
		minNode(rootTree->left,min);
	}
	
}
void maxNode(treeNode* rootTree,int &max){
	
	if(rootTree){
		if(max < rootTree->num){
			
			max=rootTree->num;
			
		}
		maxNode(rootTree->right,max);
	}
}

void clearTreeNodeRoot(treeNode* rootTree){
	
	if(rootTree->left && rootTree->right){
		
		int max=rootTree->left->num;
		maxNode(rootTree->left,max);
		deleteTreeNode(::rootTree,max);
		rootTree->num=max;
		
	}else if(rootTree->left && !rootTree->right){
		
		rootTree->num = rootTree->left->num;
		rootTree->left=nullptr;
	}else if(!rootTree->left && rootTree->right){
		
		rootTree->num = rootTree->right->num;
		rootTree->right=nullptr;
	}
	else if(!rootTree->left && !rootTree->left)
	{
		
		::rootTree= nullptr;
	}
}

void deleteTreeNode(treeNode* rootTree, int num){
	
	if(rootTree){
		if(rootTree->num == num){
			
			clearTreeNodeRoot(rootTree);
		}else if(rootTree->num > num){
			
			if(rootTree->left){
				if(rootTree->left->num == num){
				
				clearTreeNodeLeft(rootTree);
			}else{
				
				deleteTreeNode(rootTree->left,num);
			}
			}else{
				
			}
		}else if(rootTree->num < num){
			
			if(rootTree->right){
				if(rootTree->right->num == num){
				
				clearTreeNodeRight(rootTree);
			}else{
				
				
					deleteTreeNode(rootTree->right, num);	
				}	
			
			}
			
		}
	}

}



void clearTreeNodeLeft(treeNode *rootTree){
	
	if(rootTree->left->left && rootTree->left->right){
		
		
		int max = rootTree->left->right->num;
		maxNode(rootTree->left->right,max);
		
		deleteTreeNode(::rootTree, max);
		rootTree->left->num = max;

	}else if(rootTree->left->left && !rootTree->left->right){
		
		
		rootTree->left = rootTree->left->left;
		
	}else if(!rootTree->left->left && rootTree->left->right){
		
		
		rootTree->left = rootTree->left->right;	
	}else if(!rootTree->left->left && !rootTree->left->right){
		
		
		rootTree->left=nullptr;
	}
}

void clearTreeNodeRight(treeNode* rootTree){
	if(rootTree->right->left && rootTree->right->right){
		
		
		int min=rootTree->right->num;
		minNode(rootTree->right,min);
		
		deleteTreeNode(::rootTree,min);
		rootTree->right->num = min;
	}else if(rootTree->right->left && !rootTree->right->right){
		
		
		rootTree->right = rootTree->right->left;
		
	}else if(!rootTree->right->left && rootTree->right->right){
		
		
		rootTree->right = rootTree->right->right;	
	}else if(!rootTree->right->left && !rootTree->right->right){
		
		
		rootTree->right=nullptr;
	}
	
}

