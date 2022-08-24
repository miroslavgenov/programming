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

void dp(int val){
	
	node* t= search(root,val);
	if(t){
		cout<<"found"<<endl;
		if(t->left && t->right){
			cout<<"have left and right child"<<endl;
		}else if(t->left && !t->right){
			cout<<"have only left child"<<endl;
		}else if(!t->left && t->right){
			cout<<"have only right child"<<endl;
		}else if(!t->left && !t->right){
			cout<<"dont have child"<<endl;
			cout<<t->num<<endl;
			
		}
	}else{
		cout<<"not found"<<endl;
	}
	

}

int main(){
	node *n1 = new node{3, nullptr, nullptr};	
	node *n2 = new node{5, nullptr, nullptr};
	node *n3 = new node{1, nullptr, nullptr};
	node *n4 = new node{2, nullptr, nullptr};
	node* n5 = new node{6, nullptr, nullptr};
	node* n6 = new node{7, nullptr, nullptr};
	
	init(4);
	append(root, n2);
	append(root, n1);
	append(root, n3);
	append(root, n4);
	append(root, n5);
	append(root, n6);
	dp(2);
	print(root);
	
	
	
//	search(root, 7);
//	dp(1);
	
	
}


































































