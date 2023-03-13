#include <iostream>

using namespace std;

struct item{
	int weight;
	int price;
};

const int bagSize = 7;
const size_t ITEMS_SIZE = 4;

item* items[ITEMS_SIZE] = {
	new item{4, 5},
	new item{3, 4},
	new item{2, 3},
	new item{1, 2},
};

int table[ITEMS_SIZE][bagSize]{};

void printTable(){
cout<<endl;
	for(int i=0;i<ITEMS_SIZE;i++){
		for(int j=0; j<bagSize; j++){
			cout<<table[i][j]<<"\t";
		}cout<<endl;
	}cout<<endl;
}

void knapsack(int i){
	if(i == ITEMS_SIZE){
		return;
	}
	else{
		int currentItemIndex = i;
		int pointer = 0;
		item* currentItem = items[currentItemIndex];
	
		for(int capacity = 0; capacity < bagSize; capacity++){		
			if(currentItemIndex == 0){
				if(currentItem->weight <= capacity){
					table[currentItemIndex][capacity] = currentItem->price;
				}
			}else{
				if(currentItem->weight <= capacity){
					cout<<"you can place: "<<currentItem->price<<" at: "<<capacity<<endl;
					cout<<"check if the item above price is greater than the sum of currentItem + price ant item above at pointer index "<<endl;
					if(table[currentItemIndex-1][pointer] + currentItem->price > table[currentItemIndex-1][capacity]){
						cout<<"the sum of pointer + currentItem is greater"<<endl;
						table[currentItemIndex][capacity] = table[currentItemIndex-1][pointer] + currentItem->price;
						pointer++;
					}else{
						cout<<"the sum of pointer + currentItem is lesser replace with the above price"<<endl;
						table[currentItemIndex][capacity] = table[currentItemIndex-1][capacity];
						
						if(pointer!=0){
							pointer++;
						}
					}
				}else{
					cout<<"you cant place get the above value: "<<table[currentItemIndex-1][capacity] <<endl;
					table[currentItemIndex][capacity] = table[currentItemIndex-1][capacity];
				}
			}
		}
	}
	knapsack(i+1);
}

int main(){
	knapsack(0);
	printTable();

}