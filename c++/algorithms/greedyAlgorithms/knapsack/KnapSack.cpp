#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/KnapSack.h"

KnapSack::KnapSack(item** srcItems,int srcItemSize,int srcBagSize):bagSize(srcBagSize){  
    knpsh = new KnapSackHelper(srcItems, srcItemSize, &currentItem);
        
    table = new int*[srcItemSize];
    
    for(int i=0;i<srcItemSize;i++){
        table[i] = new int[srcBagSize];
    }

    KnapSackHelper::initializeItemPointers({&prevItemPointerIt,&prevItem,&currentItem});
}

void KnapSack::setRowAndColumnForBothItemPointers(int row){
    knpsh->setRowAndColumn(&prevItemPointerIt, row-1, prevItemPointerIt);
    knpsh->setRowAndColumn(&prevItem, row-1, prevItem);
}

void KnapSack::knapsack(){
    knpsh->initializeKnapSackTable(&table,bagSize);

    int sumOfPrice;

    for(int row = 1; row <knpsh->ith->getSize(); row++){

        knpsh->setItemPointerWeightAndPrice(&currentItem,row);
        knpsh->setTheSameRowButDifferentColumnToItemPointers({&prevItemPointerIt,&prevItem},row-1);

        for(int j = KnapSackHelper::getWeight(currentItem) + 1; j < bagSize; j++){
            
            knpsh->setItemPointersWeightAndPrice({&prevItemPointerIt,&prevItem},table);

            if(KnapSackHelper::isTheCellWeightCompatableWithTheItemWeight(j, KnapSackHelper::getSumOfWeight(currentItem,prevItem))){
                
                sumOfPrice = KnapSackHelper::getSumOfPrice(currentItem,prevItem);

                if(KnapSackHelper::isCurrentPriceGreaterOrEqualToThatPrice(sumOfPrice, KnapSackHelper::getPrice(prevItemPointerIt))){
                    
                    KnapSackHelper::setTableCellPrice(&table,new tableCellCoordinates{row,j}, (sumOfPrice));

                    KnapSackHelper::incrementColumn({&prevItem,&prevItemPointerIt});
                }

            }else{
                KnapSackHelper::setTableCellPriceAndIncrementItemPointerColumn(&table,new tableCellCoordinates{row,j}, &prevItemPointerIt);
            }
        }
    }
}