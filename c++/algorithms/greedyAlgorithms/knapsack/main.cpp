/*
	GREADY APROACH NOT giving the correct
	answer
*/

#include <iostream>

using namespace std;

struct item{
	string name;
	int weight;
	int price;
};
int bagSize = 1200;

struct stack{
	string name;
	int weight;
	int price;
	stack* next;
	stack* prev;
};



stack* stackRoot=nullptr;

bool isStackEmpty(){
	return ::stackRoot==nullptr;
}

void appendStack(stack* stackRoot,stack* value){
	stack* point = nullptr;
	if(isStackEmpty()){
		
		::stackRoot = new stack{value->name,value->weight, value->price, nullptr, nullptr};
		
	}else{
		point = stackRoot;
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
			cout<<point->name<<" "<<point->weight<<" "<<point->price<<endl;
			point=point->next;
		}	
	}
	else
	{
		cout<<"STACK IS EMPTY"<<endl;	
	}
	
	
}

stack* popStack(stack* root){

	string name;
	int weight;
	int price;


	if(!root){
		return stackRoot;
	}
	else if(!root->prev && !root->next){
		name = stackRoot->name;
		weight = stackRoot->weight;
		price = stackRoot->price;
		stackRoot=nullptr;
		return new stack{name, weight, price,nullptr, nullptr};
	}else{
		stack* stackPoint = root;
		while(stackPoint->next){
			stackPoint=stackPoint->next;
		}
		name = stackRoot->name;
		weight= stackPoint->weight;
		price = stackRoot->price;
		
		stackPoint->prev->next=nullptr;
		stackPoint=nullptr;
		return new stack{name, weight, price,nullptr,nullptr};
	}
	return stackRoot;
}

bool isVertexInStack(string name){
	stack* point = stackRoot;
	
	while(point->name != name ){
		if(point->next){
			point=point->next;
		}else{
			return 0;
		}
	}
	if(point->name == name){
		return 1;
	}
	return 0;
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




item* getTheMaximumPricedItem(item *items[], size_t size){
	 item* maximumPricedItem = items[0];
	for(int i=0; i < size; i++){
		if(maximumPricedItem->price < items[i]->price){
			maximumPricedItem ->price= items[i]->price;
		}
	}
	return maximumPricedItem;
}

int currentBagSize=0;
int maxPrice = 0;

void knapsack(){
	cout<<"bag size: "<<bagSize<<endl;
	cout<<"currentBagSize: "<<currentBagSize<<endl;
	cout<<"maxPrice: "<<maxPrice<<endl;

	if(stackRoot){
		stack *maximumPricedItem = getTheMaximumPricedItem(stackRoot);
		cout<<"current item weight: "<<maximumPricedItem->weight<<" ";
		
		if(currentBagSize+maximumPricedItem->weight <= bagSize){
			removeFromStack(maximumPricedItem->name, maximumPricedItem->price);
			cout<<"you can add the: "<<maximumPricedItem->name<<endl;
			currentBagSize+= maximumPricedItem->weight;
			maxPrice+= maximumPricedItem->price;
			cout<<"currentBagSize: "<<currentBagSize<<endl;
		}else{
			cout<<"check if there is other item that can fit "<<endl;
			cout<<"if there is not other item that can fit bag is full"<<endl;
			removeFromStack(maximumPricedItem->name, maximumPricedItem->price);
		}
		knapsack();
	}else{
		cout<<"bag is ready!"<<endl;
	}
	
}

int main(){
	// item *book = new item{"Book", 142, 17};
	// item *sandwich = new item{"Sandwich", 250, 8};
	// item *phone = new item{"Phone", 140, 208};
	// item *fragrance = new item{"Fragrance",100, 80};
	// item *water = new item{"Water" , 1000, 2};
	// item *shoes = new item{"Shoes", 800 , 50};

	
	appendStack(stackRoot, new stack{"Book", 142, 17});
	appendStack(stackRoot, new stack{"Sandwich", 250, 8});
	appendStack(stackRoot, new stack{"Phone", 140, 208});
	appendStack(stackRoot, new stack{"Fragrance",100, 80});
	appendStack(stackRoot, new stack{"Water" , 1000, 2});
	appendStack(stackRoot, new stack{"Shoes", 800 , 50});
		
	knapsack();
	cout<<endl;
	
}
