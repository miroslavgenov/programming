#include <iostream>
using namespace std;

struct node{
	int data;
	node * left;
	node * right;
};



void push(node * r,node *p){
	if(r){
		if(r->data>p->data){
			if(!r->left){
				r->left=p;
			}else if(r->left){
				push(r->left,p);
			}
		}else if(r->data<p->data){
			if(!r->right){
				r->right=p;
			}else if(r->right){
				push(r->right,p);
			}
		}
	}
}

void push_s(node *r , node *p){
	node *z=r;
	
	if(r->data==p->data){
		return;
	}
	
	while(1){
		
		if(z->data>p->data){
			if(!z->left){
				z->left=p;
				break;	
			}else if(z->left){
				z=z->left;
				continue;
			}
			
		}else if(z->data<p->data){
			if(!z->right){
				z->right=p;
				break;
			}else if(z->right){
				z=z->right;
				continue;
			}
		}
	}
}

void inorder(node *r){
	if(r){
		inorder(r->left);
		cout<<r->data<<endl;
		inorder(r->right);
	}
}

bool search_s(node *r,int x){
	node *z=r;
	while(1){
		if(z){
			if(z->data==x){
				return true;
			}else if(z->data>x){
				z=z->left;
				continue;
			}else if(z->data<x){
				z=z->right;
				continue;
			}
		}else{
			return 0;
		}
		
	}
	return 0;
	
}

void delete_s(node *r , int x){
	if(r){
		if(r->data>x){
			if(r->left->data==x){
				r->left=nullptr;
			}else if(r->left->data!=x){
				delete_s(r->left,x);
			}
		}
	}
}

int main(){
	node * root1=new node{5,nullptr,nullptr};
	node * root2=new node{5,nullptr,nullptr};
	
	node * p1=new node{4};
	node * p2=new node{3};
	node * p3=new node{2};
	node * p4=new node{1};
	node * p5=new node{5};
	node * p6=new node{6};
	node * p7=new node{7};
	node * p8=new node{8};
	node * p9=new node{9};
	node * p10=new node{10};
	node * p11=new node{11};
	push_s(root2,p1);
	push_s(root2,p2);
	push_s(root2,p3);
	push_s(root2,p4);
	push_s(root2,p11);
	push_s(root2,p10);
	push_s(root2,p5);
	push_s(root2,p6);
	push_s(root2,p8);
	push_s(root2,p7);
	push_s(root2,p9);
	
//	inorder(root2);
//	cout<<search_s(root2,0);
//delete_s(root2,1);
//cout<<root2->left->left->left->left->data;
	inorder(root2);
	
}








































































