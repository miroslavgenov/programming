#include <iostream>

using namespace std;

struct treeNode{
	int num;
	treeNode* left;
	treeNode* right;
};

void initTree(int );
void appendTreeNode(treeNode * ,treeNode *);
void printTree(treeNode *);
treeNode* search(treeNode *, int );
void minNode(treeNode *,int &);
void maxNode(treeNode* ,int &);
void clearTreeNodeRoot(treeNode* );
void deleteTreeNode(treeNode* , int );
void clearTreeNodeLeft(treeNode *);
void clearTreeNodeRight(treeNode* );




treeNode* rootTree=nullptr;



void initTree(int value){
	rootTree = new treeNode{value, nullptr, nullptr};
}

void shouldAppendALeftNode(treeNode* rootTree, treeNode* value){
	if(rootTree->left){
			appendTreeNode(rootTree->left,value);
		}else{

			rootTree->left=value;
		}	
}


void shouldAppendARightNode(treeNode* rootTree, treeNode* value){
	if(rootTree->right){
			appendTreeNode(rootTree->right,value);
		}else{
			rootTree->right=value;
		}	
}



void appendTreeNode(treeNode * rootTree ,treeNode *value){
	
	if(rootTree->num>value->num){
		shouldAppendALeftNode(rootTree,value);

	}else{
		shouldAppendARightNode(rootTree,value);
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
	return rootTree;
	
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



int main(){
	treeNode *n1 = new treeNode{3, nullptr, nullptr};	
	treeNode *n2 = new treeNode{2, nullptr, nullptr};
	treeNode *n3 = new treeNode{4, nullptr, nullptr};
	treeNode *n4 = new treeNode{1, nullptr, nullptr};
	treeNode *n5 = new treeNode{0, nullptr, nullptr};
	treeNode *n6 = new treeNode{7, nullptr,nullptr};
	treeNode *n7 = new treeNode{8, nullptr,nullptr};
	treeNode *n8 = new treeNode{10, nullptr,nullptr};
	treeNode *n9 = new treeNode{9, nullptr, nullptr};
	treeNode *n10 = new treeNode{6, nullptr, nullptr};
	
	initTree(5);
	
	appendTreeNode(rootTree, n1);
	appendTreeNode(rootTree, n2);
	appendTreeNode(rootTree, n3);
	appendTreeNode(rootTree, n4);
	appendTreeNode(rootTree, n5);
	appendTreeNode(rootTree, n6);
	appendTreeNode(rootTree, n7);
	appendTreeNode(rootTree, n8);
	appendTreeNode(rootTree, n9);
	appendTreeNode(rootTree, n10);
	
	cout<<search(rootTree,5)->num<<endl;

	deleteTreeNode(rootTree,7);

	printTree(rootTree);	
}


































































