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


struct stack{
	treeNode* node;
	stack* next;
	stack* prev;
};

stack* rootStack=nullptr;

bool isStackEmpty(){
	return ::rootStack==nullptr;
}

void appendStack(stack* root,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		rootStack = new stack{value->node,nullptr,nullptr};
		
	}else{
		point = root;
	while(point->next){
		point=point->next;
	}
	point->next = value;
	value->prev = point;	
	}
	
}

void printStack(stack* root){
	if(!isStackEmpty()){
		stack* point = root;
	while(point){
		cout<<point->node->num<<" ";
		point=point->next;
	}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){
	int treeNum;
	treeNode* left=nullptr;
	treeNode* right= nullptr;

	if(!root){
		return rootStack;
	}
	else if(!root->prev && !root->next){
		treeNum = rootStack->node->num;
		left = rootStack->node->left;
		right = rootStack->node->right;
		rootStack=nullptr;
		return new stack{new treeNode{treeNum,left,right},nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		treeNum = stackPoint->node->num;
		left = stackPoint->node->left;
		right = stackPoint->node->right;
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{new treeNode{treeNum,left,right},nullptr,nullptr};
	}
	return rootStack;
}

void dfs(){
	if(!isStackEmpty()){
//		cout<<rootStack->node->right->num<<endl;
		stack* s1= popStack(rootStack);
		cout<<s1->node->right->num;
		//TODO DFS
		
		
	}else{cout<<"stack empty"<<endl;
	}
	
}

int main(){
	
	
	initTree(10);
	treeNode *t1 = new treeNode{5,nullptr,nullptr};
	treeNode *t2 = new treeNode{1,nullptr,nullptr};
	treeNode *t3 = new treeNode{2,nullptr,nullptr};
	treeNode *t4 = new treeNode{4,nullptr,nullptr};
	treeNode *t5 = new treeNode{7,nullptr,nullptr};
	treeNode *t6 = new treeNode{6,nullptr,nullptr};
	treeNode *t7 = new treeNode{8,nullptr,nullptr};
	treeNode *t8 = new treeNode{9,nullptr,nullptr};
	treeNode *t9 = new treeNode{15,nullptr,nullptr};
	treeNode *t10 = new treeNode{11,nullptr,nullptr};
	treeNode *t11 = new treeNode{17,nullptr,nullptr};
	treeNode *t12 = new treeNode{12,nullptr,nullptr};
	treeNode *t13 = new treeNode{14,nullptr,nullptr};
	treeNode *t14 = new treeNode{13,nullptr,nullptr};
	treeNode *t15 = new treeNode{18,nullptr,nullptr};
	
	appendTreeNode(rootTree,t1);
	appendTreeNode(rootTree,t2);
	appendTreeNode(rootTree,t3);
	appendTreeNode(rootTree,t4);
	appendTreeNode(rootTree,t5);
	appendTreeNode(rootTree,t6);
	appendTreeNode(rootTree,t7);
	appendTreeNode(rootTree,t8);
	appendTreeNode(rootTree,t9);
	appendTreeNode(rootTree,t10);
	appendTreeNode(rootTree,t11);
	appendTreeNode(rootTree,t12);
	appendTreeNode(rootTree,t13);
	appendTreeNode(rootTree,t14);
	appendTreeNode(rootTree,t15);

	

	appendStack(rootStack , new stack{rootTree,nullptr,nullptr});
	
	dfs();
	
	
	

	

	
	
	
	
	
	
	
	
	

	
		
}
















