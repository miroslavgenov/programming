#include <iostream>

using namespace std;



struct node{
	int num;
	node* left;
	node* right;
};

node *root = nullptr;

void clearNodeRoot(node*);
void clearNodeLeft(node*);
void clearNodeRight(node*);
void dp(node* ,int);

void init(int value){
	root = new node{value, nullptr, nullptr};
}

void append(node * root ,node *value){
	
	if(root->num>value->num){
//		cout<<root->num<<" > "<<value->num<<endl;
		if(root->left){
//			cout<<"left not empty: "<< root->left->num<<endl;
//			cout<<"append(root->left, value);"<<endl;
			append(root->left,value);
		}else{
//			cout<<"left is empty"<<endl;
			root->left=value;
		}
	}else{
//		cout<<root->num<<" < "<<value->num<<endl;
		if(root->right){
//			cout<<"right not empty: "<< root->right->num<<endl;
//			cout<<"append(root->right, value);"<<endl;
			append(root->right, value);
			
		}else{
//			cout<<"right empty"<<endl;
			root->right = value;
		}
	}
//	cout<<endl;
}

void print(node *root){
	if(!root){
		return;
	}
	
	print(root->left);
	cout<<root->num<<" ";
	print(root->right);
	
}

node* search(node *root, int num){
	
	if(!root){
//		cout<<num<<" not found"<<endl;
		return root;
	}else{
		if(root->num==num){
			cout<<root->num<<" == "<<num<<endl;
//			cout<<"found"<<endl;
			return root;
		}else if(root->num>num){
			cout<<root->num<<" > "<<num<<endl;
			cout<<"search(root->left,num)"<<endl;
			search(root->left, num);
		}else if(root->num < num){
			cout<<root->num<<" < "<<num<<endl;
			cout<<"search(root->right,num)"<<endl;
			search(root->right,num);
		}
	}
	
}

void minNode(node *root,int &min){
	if(root){
		if(min > root->num){
			cout<<"prev min: "<<min<<" ";
			min = root->num;
			cout<<"new min: "<<min<<endl;
		}
		minNode(root->left,min);
	}
	
}
void maxNode(node* root,int &max){
	cout<<"MAX NODE"<<endl;
	if(root){
		if(max < root->num){
			cout<<"prev max: "<<max<<" ";
			max=root->num;
			cout<<"new max: "<<max<<endl;
		}
		maxNode(root->right,max);
	}
}

void clearNodeRoot(node* root){
	
	if(root->left && root->right){
		cout<<"root have two child's "<<endl;
		int max=root->left->num;
		maxNode(root->left,max);
		dp(::root,max);
		root->num=max;
		
	}else if(root->left && !root->right){
		cout<<"root have only left child"<<endl;
		root->num = root->left->num;
		root->left=nullptr;
	}else if(!root->left && root->right){
		cout<<"root have only right child"<<endl;
		root->num = root->right->num;
		root->right=nullptr;
	}
	else if(!root->left && !root->left)
	{
		cout<<"node->left have no childs"<<endl;
		::root= nullptr;
	}
}

void dp(node* root, int num){
	
	if(root){
		if(root->num == num){
			cout<<"root is num: "<<num<<" found"<<endl;
			clearNodeRoot(root);
		}else if(root->num > num){
			cout<<root->num<<" > "<<num<<endl;
			if(root->left){
				if(root->left->num == num){
				cout<<"TARGET FOUND"<<endl;
				clearNodeLeft(root);
			}else{
				cout<<"TARGET IS NOT IN THIS ROOT check in root->left"<<endl;
				dp(root->left,num);
			}
			}else{
				cout<<"TARGET NOT FOUND"<<endl;
			}
		}else if(root->num < num){
			cout<<root->num<<" < "<<num<<endl;
			if(root->right){
				if(root->right->num == num){
				cout<<"TARGET FOUND"<<endl;
				clearNodeRight(root);
			}else{
				cout<<"TARGET IS NOT IN THIS ROOT check in root->right"<<endl;	
				
					dp(root->right, num);	
				}	
			}else{cout<<"TARGET NOT FOUND"<<endl;
			}
			
		}
	}

}



void clearNodeLeft(node *root){
	cout<<"CLEAR NODE LEFT"<<endl;
	if(root->left->left && root->left->right){
		cout<<"root->left have two childrend's "<<endl;
		cout<<"PREPARE TO FIND MAX NODE"<<endl;
		int max = root->left->right->num;
		maxNode(root->left->right,max);
		cout<<"MAX NODE FOUND: "<<max<<endl;
		dp(::root, max);
		root->left->num = max;

	}else if(root->left->left && !root->left->right){
		cout<<"root->left have only left child"<<endl;
		cout<<"root->left is replaced "<<endl;
		root->left = root->left->left;
		
	}else if(!root->left->left && root->left->right){
		cout<<"root->left have only right childrend"<<endl;
		cout<<"root->left replaced with root->left->right"<<endl;
		root->left = root->left->right;	
	}else if(!root->left->left && !root->left->right){
		cout<<"root->left have no childrens"<<endl;
		cout<<"root->left deleted"<<endl;
		root->left=nullptr;
	}
}

void clearNodeRight(node* root){
	if(root->right->left && root->right->right){
		cout<<"root->right have two childrend's "<<endl;
		cout<<"PREPARE TO FIND MIN NODE"<<endl;
		int min=root->right->num;
		minNode(root->right,min);
		cout<<"MIN NODE FOUND: "<<min<<endl;
		dp(::root,min);
		root->right->num = min;
	}else if(root->right->left && !root->right->right){
		cout<<"root->right have only left child"<<endl;
		cout<<"root->right is replaced "<<endl;
		root->right = root->right->left;
		
	}else if(!root->right->left && root->right->right){
		cout<<"root->right have only right childrend"<<endl;
		cout<<"root->right replaced with root->left->right"<<endl;
		root->right = root->right->right;	
	}else if(!root->right->left && !root->right->right){
		cout<<"root->right have no childrens"<<endl;
		cout<<"root->right deleted"<<endl;
		root->right=nullptr;
	}
	
}



int main(){
	node *n1 = new node{3, nullptr, nullptr};	
	node *n2 = new node{2, nullptr, nullptr};
	node *n3 = new node{4, nullptr, nullptr};
	node *n4 = new node{1, nullptr, nullptr};
	node *n5 = new node{0, nullptr, nullptr};
	node *n6 = new node{7, nullptr,nullptr};
	node *n7 = new node{8, nullptr,nullptr};
	node *n8 = new node{10, nullptr,nullptr};
	node *n9 = new node{9, nullptr, nullptr};
	node *n10 = new node{6, nullptr, nullptr};
	
	init(5);
	
	append(root, n1);
	append(root, n2);
	append(root, n3);
	append(root, n4);
	append(root, n5);
	append(root, n6);
	append(root, n7);
	append(root, n8);
	append(root, n9);
	append(root, n10);
	
	dp(root,7);
	print(root);
	
	
		

	
	
	
	
	
	
	
	

	
}


































































