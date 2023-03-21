#include <iostream>
#include <vector>

#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/item.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/tableCellCoordinates.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/itemPointer.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/ItemHelper.cpp"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/KnapSackHelper.cpp"

#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/KnapSack.cpp"

using namespace std;

int main(){

    int bagSize = 7;
    int itemSize = 4;   

    item** items = new item*[itemSize]{
        new item{4,5},
        new item{3,4},
        new item{2,3},
        new item{1,2},

    };

    KnapSack *kp = new KnapSack(items,itemSize,bagSize);

    kp->knapsack();

	KnapSackHelper::printTable(kp->table,bagSize,itemSize);

}