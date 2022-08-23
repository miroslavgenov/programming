#include <iostream>

using namespace std;


struct node{
	string name;
	node* next;
	node *prev;
};


node *first=nullptr;
node *last= nullptr;


void init(node *);

void append(node *);

node* pop();

void print();
bool isNull(node * value){return value==nullptr;}

int main(){

	node *n = new node{"admin",nullptr,nullptr};
	init(n);
	
	
	node *n1 = new node{"ivan",nullptr,nullptr};
	node *n2 = new node {"jojo", nullptr, nullptr};
	append(n1);
	append(n2);
	print();
	pop();
	cout<<endl;
	print();
	pop();
	cout<<endl;
	print();
	cout<<endl;
	pop();
	print();
	
}

node *pop(){
	node* poped=nullptr;
	
	if(isNull(first->prev)){
		poped = new node{first->name,nullptr,nullptr};
		first=nullptr;
		last=nullptr;
		return poped;
	}else{
		poped = new node{first->name,nullptr,nullptr};
		first=first->prev;
		first->next=nullptr;
		return poped;
	}
	
}

void init(node *root){
	last=root;
	first=root;
}

void append(node *value){
	value->next=last;
	last->prev=value;
	value->prev=nullptr;
	last=value;	
}

void print(){
	node * point = last;
	
	while(point){
		cout<<point->name<<"  ";
		point=point->next;
	}
}












































