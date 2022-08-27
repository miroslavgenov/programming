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


struct queue{
	treeNode* node;
	queue* next;
	queue* prev;
};


queue *firstInQueue=nullptr;
queue *lastInQueue= nullptr;

void initQueue(queue *);
bool isQueueEmpty();
void appendQueue(queue *);
queue* popQueue();
void printQueue();
bool isNull(queue * value){return value==nullptr;}


void bfs(){
	if(firstInQueue && lastInQueue){
		
		queue *f = popQueue();
		cout<<f->node->num<<" ";
		
		if(f->node->left){
			appendQueue(new queue{f->node->left,nullptr,nullptr});
		}
		if(f->node->right){
			appendQueue(new queue{f->node->right,nullptr,nullptr});
		}

		bfs();
			
		
	}
	
	
	
	
}

int main(){

	initTree(3);
	treeNode *t1 = new treeNode{1,nullptr,nullptr};
	treeNode *t2 = new treeNode{5,nullptr,nullptr};
	
	
	appendTreeNode(rootTree,t1);
	appendTreeNode(rootTree,t2);


	
//	printTree(rootTree);
	initQueue(new queue{rootTree,nullptr,nullptr});
	
	bfs();
	cout<<endl;

    
    
	
}



queue *popQueue(){
	queue* poped=nullptr;
	if(firstInQueue){
			if(isNull(firstInQueue->prev)){
		poped = new queue{firstInQueue->node,nullptr,nullptr};
		firstInQueue=nullptr;
		lastInQueue=nullptr;
		return poped;
	}else{
		poped = new queue{firstInQueue->node,nullptr,nullptr};
		firstInQueue=firstInQueue->prev;
		firstInQueue->next=nullptr;
		return poped;
	}		
	}

	return poped;
	
}

void initQueue(queue *root){
	lastInQueue=root;
	firstInQueue=root;
}

void appendQueue(queue *value){
    if(!::firstInQueue && !::lastInQueue){
        initQueue(value);
    }else{
        value->next=lastInQueue;
	    lastInQueue->prev=value;
	    value->prev=nullptr;
	    lastInQueue=value;	
    }
	
}

void printQueue(){
	queue * point = nullptr;
	if(lastInQueue){
		point = lastInQueue;
		
		while(point){
		cout<<point->node->num<<"  ";
		point=point->next;
	}
	}
	
}












































