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
		cout<<root->num<<" > "<<value->num<<endl;
		if(root->left){
			cout<<"left not empty: "<< root->left->num<<endl;
			cout<<"append(root->left, value);"<<endl;
			append(root->left,value);
		}else{
			cout<<"left is empty"<<endl;
			root->left=value;
		}
	}else{
		cout<<root->num<<" < "<<value->num<<endl;
		if(root->right){
			cout<<"right not empty: "<< root->right->num<<endl;
			cout<<"append(root->right, value);"<<endl;
			append(root->right, value);
			
		}else{
			cout<<"right empty"<<endl;
			root->right = value;
		}
	}cout<<endl;
}

void print(node *root){
	if(!root){
		return;
	}
	
	print(root->left);
	cout<<root->num<<" ";
	print(root->right);
	
}

void search(node *root, int num){
	
}


int main(){
	node *n1 = new node{3, nullptr, nullptr};	
	node *n2 = new node{5, nullptr, nullptr};
	node *n3 = new node{1, nullptr, nullptr};
	node *n4 = new node{2, nullptr, nullptr};
	node* n5 = new node{6, nullptr, nullptr};
	
	init(4);
	append(root, n2);
	append(root, n1);
	append(root, n3);
	append(root, n4);
	append(root, n5);
	
	print(root);
	
	
}
































