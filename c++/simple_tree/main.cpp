#include <iostream>
using namespace std;

struct node{
	int number;
	node *left;
	node *right;
};


void push(node *r,node *p){
	if(r->number<p->number){
		if(!r->right){
			r->right=p;
		}else{
			//cout<<r->right->number<<" -- "<<p->number<<endl;
			//if(r->right->number<)
			push(r->right,p);
			//cout<<"right is already in use"<<endl;
			
		}
	}else if(r->number>p->number){
		if(!r->left){
			r->left=p;
		}else{
			push(r->left,p);
//			cout<<"left is already in use"<<endl;
		}
	}
}

void show(node *r){
	if(r!=nullptr){
		cout<<r->number<<endl;
		cout<<"left: ";
		show(r->left);
		cout<<"right: ";
		show(r->right);
	}
}





int main(){
	node * root = new node{5,nullptr,nullptr};
	int number;	
	while(cin>>number){
		if(cin.good()){
			push(root,new node{number,nullptr,nullptr});
		}
		cout<<"Type \'Y\' to exit"<<endl;
		
	}
	show(root);
	
	
	
	


	

	
	
	
	
}

















