#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/ItemHelper.h"

ItemHelper::ItemHelper(item** srcItems, int size){
    items = new item*[size];
    this->size = size;

    for(int i=0;i<size;i++){
        items[i] = new item{srcItems[i]->weight, srcItems[i]->price};
    }
}

int ItemHelper::getPrice(int index){
    return items[index]->price;
}

int ItemHelper::getWeight(int index){
    return items[index]->weight;
}

int ItemHelper::getSize(){
    return size;
}