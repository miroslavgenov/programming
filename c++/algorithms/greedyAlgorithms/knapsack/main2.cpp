#include <iostream>

using namespace std;

struct item{
    int weight;
    int price;
};

struct itemPointer{
    item *itemData = new item;
    int rowIterator;
    int columnIterator;
};

const int bagsize = 7;
const int itemsize = 4;

item items[itemsize] = {
    {4,5},
    {3,4},
    {2,3},
    {1,2}
};

int table[itemsize][bagsize] = {0};

void printTable(){
    for(int i=0;i<bagsize;i++){
        if(i == 0){
            cout<<"   ";
        }
        cout<<i<<" ";
    }
    cout<<endl;

    for(int i=0;i<itemsize;i++){
        cout<<i<<": ";
        for(int j=0;j<bagsize;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}

void initializeTheFirstRowOfTheTable(){
    constexpr int firstItem = 0;
    for(int i=0;i<=firstItem;i++){
        for(int currentCapacityWeight=0; currentCapacityWeight<bagsize;currentCapacityWeight++){
            if(currentCapacityWeight >= items[firstItem].weight){
                table[firstItem][currentCapacityWeight] = items[firstItem].price;
            }
        }
    }
} 

void initializeTheRowsThatAreNotInitialized(){
    int currentItemWeight;
    
    for(int i=1;i<itemsize;i++){
        for(int currentCapacityWeight=0;currentCapacityWeight<bagsize;currentCapacityWeight++){
            currentItemWeight = items[i].weight;
            if(currentCapacityWeight == currentItemWeight){
                table[i][currentCapacityWeight] = items[i].price;
            }
        }
    }
}

void initializeItemPointer(itemPointer** pointer){
    // cout<<pointer<<endl;
    itemPointer** p =pointer;
    
}


void knapsak(){
    initializeTheFirstRowOfTheTable();
    initializeTheRowsThatAreNotInitialized();

    itemPointer* prevItem = new itemPointer;
    prevItem->itemData = new item;

    // initializeItemPointer(&prevItem);

    int currentItemPrice, currentItemWeight;
    
    itemPointer* prevItemPointer = new itemPointer;
    prevItemPointer->itemData = new item;
    
    for(int i = 1; i<itemsize;i++){

        
        prevItem->rowIterator = i-1;
        prevItem->columnIterator = items[prevItem->rowIterator].weight;


        prevItemPointer->rowIterator = i-1;
        prevItemPointer->columnIterator = items[prevItemPointer->rowIterator].weight;

        currentItemPrice = items[i].price;
        currentItemWeight = items[i].weight;

        for(int j = items[i].weight+1; j<bagsize;j++){

            
            prevItem->itemData->price = table[prevItem->rowIterator][prevItem->columnIterator];
            prevItem->itemData->weight = prevItem->columnIterator;

            prevItemPointer->itemData->price = table[prevItemPointer->rowIterator][prevItemPointer->columnIterator];
            prevItemPointer->itemData->weight = prevItemPointer->columnIterator;

            if( j >= currentItemWeight+ prevItemPointer->itemData->weight){
                if(currentItemPrice + prevItemPointer->itemData->price>= prevItem->itemData->price){
                    table[i][j] = currentItemPrice+ prevItemPointer->itemData->price;
                    prevItemPointer->columnIterator = prevItemPointer->columnIterator+1;

                    prevItem->columnIterator = prevItem->columnIterator+1;
                }
            }else{

                table[i][j] = prevItem->itemData->price;

                prevItem->columnIterator = prevItem->columnIterator+1;

            }


        }


    }

}

class KnapSak{
    public:

    int bagSize;
    int itemSize;
    

};

int main(){



    knapsak();



    printTable();
}