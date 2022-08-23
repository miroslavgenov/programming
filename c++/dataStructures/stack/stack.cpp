#include <iostream>

using namespace std;

class MyException{
	string msg;
	public:
		MyException(string msg):msg(msg){}
		string what(){return msg;}
};


struct node{
	string name;
	node * next;
};

node *root;

void init(){root=new node{"admin",nullptr};}

void push(node * value){
	node * point = root;
	while(point->next){
		point=point->next;
	}
	
	point->next = value;
	
}

void print(){
	node *point = root;
	while(point){
		cout<<point->name<<" ";
		point=point->next; 
	}
}

node* get(){
	node *point  = root;
	
	node *target = nullptr;
	
	if(root->next == nullptr && point){
cout<<"!"<<endl;
		target = new node{root->name,nullptr};
		root=nullptr;
		return target;

		
	}
	
	while(point->next->next){
		point=point->next;
		
	}
	target=point->next;

	point->next=nullptr;
	return target;
}

bool isEmpty(){
	return root==nullptr;
}

int main(){
	init();

	node * n = new node{"ivan",nullptr};
	node *n1 = new node{"alex",nullptr};
	push(n);
	push(n1);
	
get();get();get();
print();
cout<<isEmpty()<<endl;

	


	
}













































