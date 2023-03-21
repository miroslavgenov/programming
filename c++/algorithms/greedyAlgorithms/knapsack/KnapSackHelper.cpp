#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/KnapSackHelper.h"

KnapSackHelper::KnapSackHelper(item** srcItems, int size, itemPointer** srcCurrentItem){
    ith = new ItemHelper(srcItems,size);

    itemPointer* currentItem = *srcCurrentItem;
}

void KnapSackHelper::setItemPointerWeightAndPrice(itemPointer** p, int itemIndex){
    itemPointer* itemP = *p;
    itemP->itemData->weight = ith->getWeight(itemIndex);
    itemP->itemData->price = ith->getPrice(itemIndex);
}

void KnapSackHelper::setItemPointerWeightAndPrice(itemPointer** p, int **table){
    itemPointer* i = *p;
    i->itemData->weight = i->cellData->column;
    i->itemData->price = table[i->cellData->row][i->cellData->column];

}

void KnapSackHelper::setRowAndColumn(itemPointer** item, int row, itemPointer* itemColumnData){
    itemPointer* p = *item;
    p->cellData->row = row;
    setColumn(item,itemColumnData);
}

void KnapSackHelper::setTheSameRowButDifferentColumnToItemPointers(std::vector<itemPointer**> list, int row){
    itemPointer* p = nullptr;

    for(int i=0;i<list.size();i++){
        setRowAndColumn(list[i], row);            
    }
}

void KnapSackHelper::setRowAndColumn(itemPointer** item, int row){
    itemPointer* p = *item;

    p->cellData->row = row;

    setColumn(item,row);
}

void KnapSackHelper::setColumn(itemPointer** item, int row){
    itemPointer* p = *item;
    p->cellData->column = ith->getWeight(row);
}

void KnapSackHelper::setColumn(itemPointer** item, itemPointer* itemIndex){
    itemPointer* p = *item;

    p->cellData->column = ith->getWeight(itemIndex->cellData->row);
}

void KnapSackHelper::setItemPointersWeightAndPrice(std::vector<itemPointer**> list, int **table){
    for(int i=0;i<list.size();i++){
        setItemPointerWeightAndPrice(list[i],table);
    }
}

void KnapSackHelper::initializeKnapSackTable(int ***table, int bagSize){
    initializeTheFirstRowOfTheTable(table, bagSize);
    initializeTheRowsThatAreNotInitialized(table,bagSize);
}

void KnapSackHelper::initializeTheFirstRowOfTheTable(int ***table, int bagSize){
    constexpr int firstItem = 0;
    
    for(int itemRow=0;itemRow<=firstItem;itemRow++){
        for(int currentCapacityWeight=0;currentCapacityWeight<bagSize;currentCapacityWeight++){
            if(currentCapacityWeight >= ith->getWeight(firstItem)){
                *(*(*table+itemRow)+currentCapacityWeight) = ith->getPrice(firstItem);
            }
        }
    }
} 

void KnapSackHelper::initializeTheRowsThatAreNotInitialized(int ***table, int bagSize){
    int currentItemWeight;
    
    for(int i = 1; i < ith->getSize(); i++){
        for(int currentCapacityWeight = 0; currentCapacityWeight < bagSize; currentCapacityWeight++){
            currentItemWeight = ith->getWeight(i);

            if(currentCapacityWeight == currentItemWeight){
                *(*(*table+i)+currentCapacityWeight) = ith->getPrice(i);
            }
        }
    }
}