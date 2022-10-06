#include <iostream>

using namespace std;
struct node{
  string name;
  node *next,*prev;
};

void printNode(node * root){
  if(root){
  	while(root){
    cout<<root->name<<" "<<endl;
    root=root->next;
  }	
  }
  
  
}

void append(node *root,node *nodeToBeAppended){
  
  node *point=root;
  while(point->next && point->name!=""){
  	point=point->next;
  }
  point->next=nodeToBeAppended;
  nodeToBeAppended->prev=point;
}


node *getItem(node* root,string targetNodeName){
	
	node * point=root;
	
	while(point->name!=targetNodeName){
  		
	  	point=point->next;
	  	
  	}
  	
	
	node* nextNode = point->next;
	node* prevNode = point->prev;
	
	if(!prevNode && nextNode){
		root->name=nextNode->name;
		root->next=nextNode->next;		
		return point;
	}else if(nextNode && prevNode){
		prevNode->next=nextNode;
		nextNode->prev=prevNode;
		point->next=nullptr;
		point->prev=nullptr;
		return point;
	}else if(prevNode && !nextNode){
		prevNode->next=nullptr;
		point->prev=nullptr;
		return point;
	}else if(!prevNode && !nextNode){
		node *newNode=new node{root->name,nullptr,nullptr};
		root->name="";
		root->next=nullptr;
		root->prev=nullptr;
		return newNode;
		
	}

}

int main(){
  node * root = new node{"admin",nullptr,nullptr};
  node *n1 = new node{"ivan",nullptr,nullptr};
  node *n2 = new node{"jojo",nullptr,nullptr};
  append(root,n1);
  append(root,n2);
  
  
  
  
	
	getItem(root,"jojo");
	getItem(root,"admin");
	getItem(root,"ivan");
    printNode(root);
  
//  printNode(root);
  
  
  
  
  
}

















































