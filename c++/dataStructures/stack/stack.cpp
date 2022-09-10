#include <iostream>

using namespace std;

struct stack{
	string name;
	stack* next;
	stack* prev;
};

stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* root,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		stackRoot = new stack{value->name,nullptr,nullptr};
		
	}else{
		point = root;
	while(point->next){
		point=point->next;
	}
	point->next = value;
	value->prev = point;	
	}
	
}

void printStack(stack* root){
	if(!isStackEmpty()){
		stack* point = root;
	while(point){
		cout<<point->name<<" ";
		point=point->next;
	}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){

	string stackName ="";

	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		stackName = stackRoot->name;
		stackRoot=nullptr;
		return new stack{stackName,nullptr,nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}

		stackName = stackPoint->name;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{stackName,nullptr,nullptr};
	}
	return stackRoot;
}

stack* getTheMaximumPricedItem(stack* stackRoot){
	stack* point = nullptr;
	string name;
	int *weight = nullptr;
	int *maximumPrice = nullptr;
	
	if(stackRoot){

		point = stackRoot;
		
		name = point->name;
		weight = new int{point->weight};
		maximumPrice = new int{point->price};

		while(point){
			if(*maximumPrice < point->price){
				name = point->name;
				weight = new int{point->weight};
				maximumPrice = new int{point->price};
			}
			point = point->next;
		}
		
	}
	return new stack{name,*weight,*maximumPrice,nullptr,nullptr};
}

void removeFromStack(string name, int price){
	stack* point = nullptr;
	if(stackRoot){
//		cout<<"stack root is not empty"<<endl;
//		cout<<"find value: name: "<<name<<" price: "<<price<<endl;
		point = stackRoot;
		while(point){
			if(point->name == name && point->price == price){
				cout<<point->name<<" "<<point->price<<endl;
//				cout<<"found"<<endl;
				break;
			}else{
				point= point->next;	
			}
			
		}

		if(point){
//			cout<<"found: "<<point->name<<"  weight: "<<point->price<<endl;
			if(!point->prev && !point->next){
//				cout<<"point dont have prev and next"<<endl;
				stackRoot = nullptr;
			}else{
//				cout<<"point have prev or next"<<endl;
				if(point->prev && point->next){
//					cout<<"point have prev and next"<<endl;
					point->prev->next = point->next;
					point->next->prev = point->prev;
				}else if(point->prev && !point->next){
//					cout<<"point have prev but don't have next"<<endl;
					point->prev->next=nullptr;
				}else if(!point->prev && point->next){
//					cout<<"point have next but don't have prev"<<endl;
					stackRoot = stackRoot->next;
					stackRoot->prev=nullptr;

				}
			}
		}else{
//			cout<<" don't found"<<endl;
		}
		
		
		
	}else{
		cout<<"stackRoot is empty"<<endl;
	}
}

int main(){
	
	


	
}

















































