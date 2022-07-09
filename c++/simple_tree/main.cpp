#include <iostream>
using namespace std;

struct node{
	int number;
	node *left;
	node *right;
};

void push(node *r , node *p){
	if(r){
		if(r->number>p->number){
			if(!r->left){
				r->left=p;
			}else{
				push(r->left,p);
			}
			
		}
		else if(r->number<p->number){
			if(!r->right){
				r->right=p;
			}else{
				push(r->right,p);
			}
		}
	}
}

//void push(node *r,node *p){
//	if(r->number<p->number){
//		if(!r->right){
//			r->right=p;
//		}else{
//			//cout<<r->right->number<<" -- "<<p->number<<endl;
//			//if(r->right->number<)
//			push(r->right,p);
//			//cout<<"right is already in use"<<endl;
//			
//		}
//	}else if(r->number>p->number){
//		if(!r->left){
//			r->left=p;
//		}else{
//			push(r->left,p);
////			cout<<"left is already in use"<<endl;
//		}
//	}
//}

void show(node *r){
	if(r!=nullptr){
		cout<<r->number<<endl;
		cout<<"left: ";
		show(r->left);
		cout<<"right: ";
		show(r->right);
	}
}

void show_inorder(node *root){
	// shows the numbers as sorted
	if(root!=nullptr){
		show_inorder(root->left);
		cout<<root->number<<endl;
		show_inorder(root->right);
	}
}

node & search(node *r , int x){
	
	if(r){
		
		if(r->number==x){
			return *r;
		}else{
			if(r->number>x){
				search(r->left,x);
			}else if(r->number<x){
				search(r->right,x);
			}
		}
	}
	
}

void remove(node* root,int x){
	// need to be fixed
	node * r= &search(root,x);
	r=nullptr;
}


int main(){
	node * root = new node{5,nullptr,nullptr};
	node * r1 = new node{4,nullptr,nullptr};
	node * r2 = new node{3,nullptr,nullptr};
	node * r3 = new node{2,nullptr,nullptr};
	node * r4 = new node{1,nullptr,nullptr};
	node * r5 = new node{9,nullptr,nullptr};
	node * r6 = new node{8,nullptr,nullptr};
	node * r7 = new node{7,nullptr,nullptr};
	node * r8 = new node{6,nullptr,nullptr};
	
	
	node * list[]= {r1,r2,r3,r4,r5,r6,r7,r8};
	for(int i=0;i<8;i++){
		push(root,list[i]);
	}
	remove(root,1);
	cout<<r4->number<<endl;
	cout<<root->left->left->left->left->number<<endl;
//	show(root);
	
	
	
	
	
	
	
	
	
	


	

	
	
	
	
}







































