#include <iostream>

using namespace std;

struct node{
	int num;
	node* left;
	node* right;
};

node *root = nullptr;

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

void dp(node* root, int num){
	
	if(root){
		if(root->num == num){
			cout<<"root is num: "<<num<<" found"<<endl;
		}else if(root->num > num){
			cout<<root->num<<" > "<<num<<endl;
			if(root->left->num == num){
				cout<<"TARGET FOUND"<<endl;
				cout<<"root->left == num"<<endl;
				if(root->left->left && root->left->right){
					cout<<"root->left have left and right childs"<<endl;
					cout<<"deleted abadoned"<<endl;
					cout<<"find max left or min right value"<<endl;
				}else if(root->left->left && !root->left->right){
					cout<<"root->left have only left child"<<endl;
					cout<<"target node is replaces with root->left->left"<<endl;
					root->left = root->left->left;

				}else if(!root->left->left && root->left->right){
					cout<<"root->left have only right child"<<endl;
					cout<<"target node is replacet whith root->left->right"<<endl;
					root->left = root->left->right;
//					cout<<"deleted abadoned"<<endl;
				}else if(!root->left->left && !root->left->right){
					cout<<"root->left don't have childs"<<endl;
					cout<<"deleting target left node"<<endl;
					root->left=nullptr;
				}
			}else{
				cout<<"TARGET IS NOT IN THIS ROOT check in root->left"<<endl;
				dp(root->left,num);
			}
		}else if(root->num < num){
			cout<<root->num<<" < "<<num<<endl;
			if(root->right->num == num){
				cout<<"TARGET FOUND"<<endl;
				cout<<"root->right == num"<<endl;
				if(root->right->left && root->right->right){
					cout<<"root->right have left and righ child"<<endl;
					cout<<"deleted abadoned"<<endl;
					
				}else if(root->right->left && !root->right->right){
					cout<<"root->right have only left child"<<endl;
					cout<<"root->right is replaced with root->right->left"<<endl;
					root->right = root->right->left;
				}else if(!root->right->left && root->right->right){
					cout<<"root->right have only right child"<<endl;
					cout<<"root->right is replaced with root->right->right"<<endl;
					root->right = root->right->right;
					
				}else if(!root->right->right && !root->right->right){
					cout<<"root->right don't have childs"<<endl;
					cout<<"deleting targeted node"<<endl;
					root->right=nullptr;
				}
			}else{
				cout<<"TARGET IS NOT IN THIS ROOT check in root->right"<<endl;
				dp(root->right, num);
			}
			
			
		}
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
	node *n9 = new node{9, nullptr,nullptr};
	
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
	
	dp(root,5);
	print(root);
	
	
	
	
	
	
	
	

	
}


































































