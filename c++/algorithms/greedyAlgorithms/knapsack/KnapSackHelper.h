#pragma once

class KnapSackHelper{
    public:
    ItemHelper* ith = nullptr;
    itemPointer* currentItem = nullptr;
    itemPointer** itemPointerHelper = nullptr;

    KnapSackHelper(item** , int , itemPointer** );

    void initializeKnapSackTable(int ***, int );

    void initializeTheFirstRowOfTheTable(int ***, int );

    void initializeTheRowsThatAreNotInitialized(int ***, int );

    void setItemPointersWeightAndPrice(std::vector<itemPointer**> , int **);

    void setRowAndColumn(itemPointer** , int );

    void setColumn(itemPointer** , int );

    void setColumn(itemPointer** , itemPointer* );

    void setRowAndColumn(itemPointer** , int , itemPointer* );

    void setTheSameRowButDifferentColumnToItemPointers(std::vector<itemPointer**> , int );

    void setItemPointerWeightAndPrice(itemPointer** , int );

    void setItemPointerWeightAndPrice(itemPointer** , int **);
    
    static bool isTheCellWeightCompatableWithTheItemWeight(int currentWeight, int thatWeight){
        return currentWeight >= thatWeight;
    }

    static bool isCurrentPriceGreaterOrEqualToThatPrice(int currentPrice, int thatPrice){
        return currentPrice >= thatPrice;
    }    

    static int getSumOfWeight(itemPointer* fitem, itemPointer* sitem){
        return fitem->itemData->weight + sitem->itemData->weight;
    }

    static int getSumOfPrice(itemPointer* fitem, itemPointer* sitem){
        return fitem->itemData->price + sitem->itemData->price;
    }

    static void incrementColumn(std::vector<itemPointer**> list){
        for(int i=0;i<list.size();i++){
            incrementColumn(list[i]);
        }
    }

    static void incrementColumn(itemPointer** item){
        itemPointer* p = *item;
        p->cellData->column = p->cellData->column + 1;
    }

    static void setTableCellPriceAndIncrementItemPointerColumn(int*** table, tableCellCoordinates* coordinates, itemPointer** item){
        KnapSackHelper::setTableCellPrice(table,coordinates, KnapSackHelper::getPrice(*item));
        KnapSackHelper::incrementColumn(item);
    }

	static void initializeItemPointer(itemPointer** p){
        *p= new itemPointer;

        itemPointer* pointer = *p;

        pointer->itemData = new item;
        pointer->cellData = new tableCellCoordinates;
    }

    static void printTable(int **table, int bagSize, int itemSize){
        for(int i=0;i<bagSize;i++){
            if(i == 0){
                std::cout<<"   ";
            }
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;

        for(int i=0;i<itemSize;i++){
            std::cout<<i<<": ";
            for(int j=0;j<bagSize;j++){
                std::cout<<table[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    static int getPrice(itemPointer* p){
        return p->itemData->price;
    }

    static int getWeight(itemPointer* p){
        return p->itemData->weight;
    }

	static void initializeItemPointers(std::vector<itemPointer**> list){
		for(int i=0;i<list.size();i++){
            KnapSackHelper::initializeItemPointer(list[i]);
        }
	}

    static void setTableCellPrice(int ***table,tableCellCoordinates* coordinates, int price){
        // table[coordinates->row][coordinates->column] = price;
        *(*(*table+coordinates->row)+coordinates->column) = price;
    }

    static int getSumOfPrice(std::vector<itemPointer*> list){
        int sum = 0;

        for(int i=0;i<list.size();i++){
            if(list[i] != nullptr){
                if(list[i]->itemData != nullptr){
                    sum += list[i]->itemData->price;
                }
            }
        }
        return sum;
    }

    static int getSumOfWeight(std::vector<itemPointer*> list){
        int sum = 0;
        
        for(int i=0;i<list.size();i++){
            if(list[i] != nullptr){
                if(list[i]->itemData != nullptr){
                    sum += list[i]->itemData->weight;
                }
            }
        }
        return sum;
    }

};