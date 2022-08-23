#include <iostream>

using namespace std;
struct node{
	string name;
	node* next;
	node* prev;
};

node* first=nullptr;
node* last=nullptr;

void init(node* value){
	first=value;
	last=value;
}

void get(){
	if(!first->prev){
		first=nullptr;
		last=nullptr;
	}
	else{
		first=first->prev;
		first->next=nullptr;
	}
}

void append(node* value){
	value->next=last;
	last->prev=value;
	last=value;
}

void appendLeft(node * value){
	last->prev = value;
	value->next=last;
	last=value;
}

void print(){
	node* point = last;
	while(point){
		cout<<point->name<<"  ";
		point=point->next;
	}cout<<endl;
}
void appendRight(node* value){
	first->next=value;
	value->prev=first;
	first=value;
	value->next=nullptr;
}

void getLeft(){
	if(first == nullptr){
		first = nullptr;
		last = nullptr;
	}
	else{
		last=last->next;
		last->prev=nullptr;
	}
}

int main(){
	node *n1=new node{"admin",nullptr,nullptr};
	init(n1);
	node *n2=new node{"ivan",nullptr,nullptr};
	node* n3 = new node{"alex", nullptr, nullptr};
	append(n2);
	append(n3);
	node* n4 = new node{"jojo", nullptr, nullptr};
	appendLeft(n4);
	node* n5 = new node{"dio", nullptr, nullptr};
	appendRight(n5);
	getLeft();
	get();

	node * n6 = new node{"jotaro", nullptr, nullptr};
	appendRight(n6);
	print();
}


















































