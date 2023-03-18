#include <iostream>

#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/item.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/tableCellCoordinates.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/itemPointer.h"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/ItemHelper.cpp"
#include "/home/user/Desktop/programming/c++/algorithms/greedyAlgorithms/knapsack/KnapSackHelper.h"

using namespace std;


class KnapSack{
    public:

    int bagSize;
    int** table = nullptr;

    itemPointer* prevItemPointerIt = nullptr;
    itemPointer* prevItem = nullptr;
    itemPointer* currentItem = nullptr;

    itemPointer* itemPointerHelper = nullptr;

    KnapSackHelper* knpsh = nullptr;
	

    KnapSack(item** srcItems,int srcItemSize,int srcBagSize):bagSize(srcBagSize){
                
        knpsh = new KnapSackHelper(srcItems, srcItemSize, &currentItem);
         

        table = new int*[srcItemSize];
        
        for(int i=0;i<srcItemSize;i++){
            table[i] = new int[srcBagSize];
        }
        
        initializeItemPointers();
	
        this->knapsack();
    }

	void initializeItemPointers(){
		KnapSackHelper::initializeItemPointer(&prevItemPointerIt);
		KnapSackHelper::initializeItemPointer(&prevItem);
		KnapSackHelper::initializeItemPointer(&currentItem);
	}

    void setTableCellPrice(tableCellCoordinates* coordinates, int price){
        table[coordinates->row][coordinates->column] = price;
    }

    bool isTheCellWeightCompatableWithTheItem(int currentWeight, int thatWeight){
        return currentWeight >= thatWeight;
    }

    bool isCurrentPriceGreaterOrEqualToThatPrice(int currentPrice, int thatPrice){
        return isTheCellWeightCompatableWithTheItem(currentPrice, thatPrice);
    }

    /// @brief NOTE each element of the array must be initialized with parameters. Example p[0] = new itemPointer{new item{3,3}, new tableCellCoordinates{1,1}};
    // else will give you arror
    //  MAKE CLASS FOR EXCEPTIONS
    // HOW TO CALL: getSumOfWeight(new itemPointer*[]{currentItem,prevItem});
    /// @param array with itemPointer 
    int getSumOfWeight(itemPointer** p){
        int size = 0;

        for(int i=0;;i++){
            if(p[i] == nullptr){
                break;
            }
            // if you don't want error pass fully initialized variables or
            // make else if( p[i]->cellData == nullptr) break;
            // else if(p[i]->itemData == nullptr) break; 
            // etc

            size++;
        }

    int sum = 0;
        // cout<<size<<endl;
        for(int i=0;i<size;i++){
            sum+=KnapSackHelper::getWeight(p[i]);
        }
        // cout<<sum<<endl;
        return sum;
    }


    /// @brief NOTE each element of the array must be initialized with parameters. Example p[0] = new itemPointer{new item{3,3}, new tableCellCoordinates{1,1}};
    // else will give you arror
    //  MAKE CLASS FOR EXCEPTIONS
    // HOW TO CALL:  getSumOfPrice(new itemPointer*[]{currentItem,prevItem});
    /// @param array with itemPointer 
    int getSumOfPrice(itemPointer** p){
        int size = 0;

        for(int i=0;;i++){
            if(p[i] == nullptr){
                break;
            }
            // if you don't want error pass fully initialized variables or
            // make else if( p[i]->cellData == nullptr) break;
            // else if(p[i]->itemData == nullptr) break; 
            // etc

            size++;
        }

    int sum = 0;
        // cout<<size<<endl;
        for(int i=0;i<size;i++){
            sum+=KnapSackHelper::getPrice(p[i]);
        }
        // cout<<sum<<endl;
        return sum;
    }

    void knapsack(){
        initializeKnapSackTable();

        int sumOfPrice;

        for(int row = 1; row <knpsh->ith->getSize(); row++){

            knpsh->setItemPointerWeightAndPrice(&currentItem,row);
                        
            knpsh->setRowAndColumn(&prevItemPointerIt, row-1, prevItemPointerIt);

            knpsh->setRowAndColumn(&prevItem, row-1, prevItem);

            for(int j = KnapSackHelper::getWeight(currentItem) + 1; j < bagSize; j++){
                
                knpsh->setItemPointerWeightAndPrice(&prevItemPointerIt,table);

                knpsh->setItemPointerWeightAndPrice(&prevItem,table);

                if(isTheCellWeightCompatableWithTheItem(j, KnapSackHelper::getSumOfWeight(currentItem,prevItem))){

                    sumOfPrice = KnapSackHelper::getSumOfPrice(currentItem,prevItem);
                    if(isCurrentPriceGreaterOrEqualToThatPrice(sumOfPrice, KnapSackHelper::getPrice(prevItemPointerIt))){
                        
                        setTableCellPrice(new tableCellCoordinates{row,j}, (sumOfPrice));

                        KnapSackHelper::incrementColumns(&prevItem,&prevItemPointerIt);
                    }

                }else{
                    setTableCellPrice(new tableCellCoordinates{row,j}, KnapSackHelper::getPrice(prevItemPointerIt));
                    KnapSackHelper::incrementColumn(&prevItemPointerIt);
                }
            }
        }
    }

    void initializeKnapSackTable(){
        initializeTheFirstRowOfTheTable();
        initializeTheRowsThatAreNotInitialized();
    }

    //TODO: in the util class
    void initializeTheFirstRowOfTheTable(){
        constexpr int firstItem = 0;

        for(int i = 0; i <= firstItem; i++){
            for(int currentCapacityWeight = 0; currentCapacityWeight < bagSize; currentCapacityWeight++){
                if(currentCapacityWeight >= knpsh->ith->getWeight(firstItem)){
                    table[firstItem][currentCapacityWeight] = knpsh->ith->getPrice(firstItem);
                }
            }
        }
    } 

//todo: in util class
    void initializeTheRowsThatAreNotInitialized(){
        int currentItemWeight;
        
        for(int i = 1; i < knpsh->ith->getSize(); i++){
            for(int currentCapacityWeight = 0; currentCapacityWeight < bagSize; currentCapacityWeight++){
                currentItemWeight = knpsh->ith->getWeight(i);
                if(currentCapacityWeight == currentItemWeight){
                    table[i][currentCapacityWeight] =knpsh->ith->getPrice(i);
                }
            }
        }
    }

};

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

	KnapSackHelper::printTable(kp->table,bagSize,itemSize);
}