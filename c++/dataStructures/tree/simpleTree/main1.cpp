#include <iostream>
using namespace std;


//#TODO: refactor the code to make it readable beside clean code

struct node{
	int data;
	node * left;
	node * right;
};




int min_num=0;

int get_min_num(){
	return ::min_num;
}

void set_min_num(int val){
	::min_num=val;
}


int max_num=0;

int get_max_num(){
	return ::max_num;
}

void set_max_num(int val){
	::max_num=val;
}


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


void find_min_num_in_node(node *r){
		if(r){
			if(::min_num>r->data){
				set_min_num(r->data);
			}
			find_min_num_in_node(r->left);
			find_min_num_in_node(r->right);
		}
}


void fill_min_num_node(node *r , node * node_min){
	if(r){
		if(::get_min_num()<r->data){
			set_min_num(r->data);
			node_min->data=r->data;
			node_min->left=r->left;
			node_min->right=r->right;
		}
		fill_min_num_node(r->left,node_min);
		fill_min_num_node(r->right,node_min);
	}
}

void fill_max_num_num(node *r,node * node_max){
	if(r){
		if(::get_max_num()<r->data){
			::set_max_num(r->data);
			node_max->data=r->data;
			node_max->left=r->left;
			node_max->right=r->right;
		}
		fill_max_num_num(r->right,node_max);
		fill_max_num_num(r->left,node_max);
		
	}
	
}

void find_max_num_in_node(node *r){
	if(r){
		if(::get_max_num()<r->data){
			::set_max_num(r->data);
		}
		find_max_num_in_node(r->right);
		find_max_num_in_node(r->left);
	}
	
}

int count=0,count_max=0;

void walk(node *r , int c,int *c_m){
	
	if(r){
		
		if(c>*c_m){
			*c_m=c;
		}
		
		walk(r->left,c+1,c_m);
		walk(r->right,c+1,c_m);
	}
	
}

void prepare_walk(){
	int count=0,count_max=0;
}

void set_count_and_count_max(int val_count,int val_count_max){
	::count=val_count;
	::count_max=val_count_max;
}



int get_count_max(){
	return ::count_max;
}

void prepare_and_start_walk(node *root){
	prepare_walk();
	walk(root,count,&count_max);
}


void delete_s(node *r , int x){
		
}




int main(){
	node * root1=new node{5,nullptr,nullptr};
	node * root2=new node{8,nullptr,nullptr};

	

	node *p0 = new node{0};
	node * p1=new node{1};
	node * p2=new node{2};
	node * p3=new node{3};
	node * p4=new node{4};
	node * p5=new node{5};
	node * p6=new node{6};
	node * p7=new node{7};
	node * p8=new node{8};
	node * p9=new node{9};
	node * p10=new node{10};
	node * p11=new node{11};
	node * p12=new node{12};
	node * p13=new node{13};
	node * p14=new node{14};
	node * p15=new node{15};
	node * p16=new node{16};
	node * p17=new node{17};
	node * p18=new node{18};
	node * p19=new node{19};
	node * p20=new node{20};
	node * p21=new node{21};
	node * p22=new node{22};
	node * p23=new node{23};
	node * p24=new node{24};
	

	set_max_num(0);
	set_min_num(root2->data);
	
//	push(root2,p4);
//	push(root2,p12);
//	
//	push(root2,p2);
//	push(root2,p3);
//
//	push(root2,p1);
//	push(root2,p0);
//
//	push(root2,p6);
//	push(root2,p5);
//	push(root2,p7);
//	
//	push(root2,p10);
//	push(root2,p13);
//	
//	push(root2,p9);
//	push(root2,p11);
//	
//push(root2,p14);
//
//push(root2,p15);
//
//push(root2,p19);
//
//push(root2,p17);
//
//push(root2,p20);
//
//push(root2,p16);
//push(root2,p18);
//
//push(root2,p21);
//push(root2,p22);
	//!!!!!!!!!!!
	
	push(root2,p2);
	push(root2,p3);
	push(root2,p1);
	
	delete_s(root2,2);
	inorder(root2);
	
	
	
//delete_s(root2,1);




	
	
	
	
//	cout<<root2->left->left->data<<endl;
	//inorder(root2);
//	int count=0;
//	int count_max=0;
//	walk(root2,count,&count_max);
//	cout<<count_max<<endl;
	
//	find_max_num_in_node(root2->left->left);
//	cout<<get_max_num()<<endl;
//	find_min_num_in_node(root2->left->right);
//	cout<<get_min_num()<<endl;
	
//	delete_s(root2,4);
	
}








































































