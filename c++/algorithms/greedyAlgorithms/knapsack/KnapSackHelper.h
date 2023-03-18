#pragma once

class KnapSackHelper{
    public:
    ItemHelper* ith = nullptr;
    itemPointer* currentItem = nullptr;
    itemPointer** itemPointerHelper = nullptr;

    KnapSackHelper(item** srcItems, int size, itemPointer** srcCurrentItem){
        ith = new ItemHelper(srcItems,size);

        itemPointer* currentItem = *srcCurrentItem;
    }

    void setItemPointerWeightAndPrice(itemPointer** p, int itemIndex){
        itemPointer* itemP = *p;
        itemP->itemData->weight = ith->getWeight(itemIndex);
        itemP->itemData->price = ith->getPrice(itemIndex);
    }

    void setItemPointerWeightAndPrice(itemPointer** p, int **table){
        itemPointer* i = *p;
        i->itemData->weight = i->cellData->column;
        i->itemData->price = table[i->cellData->row][i->cellData->column];

    }

    static int getSumOfWeight(itemPointer* fitem, itemPointer* sitem){
        return fitem->itemData->weight + sitem->itemData->weight;
    }

    static int getSumOfPrice(itemPointer* fitem, itemPointer* sitem){
        return fitem->itemData->price + sitem->itemData->price;
    }

    static void incrementColumns(itemPointer** fitem, itemPointer** sitem){
        incrementColumn(fitem);
        incrementColumn(sitem);
    }

    static void incrementColumn(itemPointer** item){
        itemPointer* p = *item;
        p->cellData->column = p->cellData->column + 1;
    }

    void setRowAndColumn(itemPointer** item, int row, itemPointer* itemColumnData){
        itemPointer* p = *item;
        p->cellData->row = row;
        setColumn(item,itemColumnData);
    }

    void setColumn(itemPointer** item, itemPointer* itemIndex){
        itemPointer* p = *item;

        p->cellData->column = ith->getWeight(itemIndex->cellData->row);
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

    // static void initializeTheFirstRowOfTheTable(int ***table, int bagSize,int itemWeight){
    //     constexpr int firstItem = 0;

    //     for(int i = 0; i <= firstItem; i++){
    //         for(int currentCapacityWeight = 0; currentCapacityWeight < bagSize; currentCapacityWeight++){
    //             if(currentCapacityWeight >= itemWeight){
    //                 table[firstItem][currentCapacityWeight] = knpsh->ith->getPrice(firstItem);
    //             }
    //         }
    //     }
    // }

};