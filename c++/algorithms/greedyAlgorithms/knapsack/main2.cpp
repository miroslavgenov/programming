#include <iostream>

using namespace std;

struct item{
    int weight;
    int price;
};

struct tableCellCoordinates{
    int row;
    int column;
};

struct itemPointer{
    item *itemData = nullptr;
    tableCellCoordinates* cellData = nullptr;
};

class ItemHelper{
    public:

    int size;
    item** items = nullptr;

    ItemHelper(item** srcItems, int size){
        items = new item*[size];
        this->size = size;

        for(int i=0;i<size;i++){
            items[i] = new item{srcItems[i]->weight, srcItems[i]->price};
        }
    }

    int getPrice(int index){
        return items[index]->price;
    }

    int getWeight(int index){
        return items[index]->weight;
    }

    int getSize(){
        return size;
    }

};

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


};

class KnapSack{
    public:

    int bagSize;
    int itemSize;
    int** table = nullptr;

    itemPointer* prevItemPointerIt = nullptr;
    itemPointer* prevItem = nullptr;
    itemPointer* currentItem = nullptr;

    itemPointer* itemPointerHelper = nullptr;

    KnapSackHelper* knpsh = nullptr;


    //util
    void initializeItemPointer(itemPointer** p){
        *p = new itemPointer;

        itemPointerHelper = *p;
        itemPointerHelper->itemData = new item;

        itemPointerHelper->cellData = new tableCellCoordinates;


        itemPointerHelper = nullptr;
    }

    KnapSack(item** srcItems,int srcItemSize,int srcBagSize):itemSize(srcItemSize),bagSize(srcBagSize){
                
        knpsh = new KnapSackHelper(srcItems, srcItemSize, &currentItem);
        
        int itemSize = knpsh->ith->getSize(); 

        table = new int*[itemSize];
        
        for(int i=0;i<itemSize;i++){
            table[i] = new int[bagSize];
        }

        initializeItemPointer(&prevItemPointerIt);
        initializeItemPointer(&prevItem);
        initializeItemPointer(&currentItem);

        this->knapsack();
    }


    void printTable(){
        for(int i=0;i<bagSize;i++){
            if(i == 0){
                cout<<"   ";
            }
            cout<<i<<" ";
        }
        cout<<endl;

        for(int i=0;i<knpsh->ith->getSize();i++){
            cout<<i<<": ";
            for(int j=0;j<bagSize;j++){
                cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    void setTableCellPrice(tableCellCoordinates* coordinates, int price){
        table[coordinates->row][coordinates->column] = price;
    }

    int getItemPointerPrice(itemPointer *p){
        return p->itemData->price;
    }

    int getItemPointerColumn(itemPointer* p){
        return p->cellData->column;
    }

    bool isTheCellWeightCompatableWithTheItem(int currentWeight, int thatWeight){
        return currentWeight >= thatWeight;
    }

    bool isCurrentPriceGreaterOrEqualToThatPrice(int currentPrice, int thatPrice){
        return isTheCellWeightCompatableWithTheItem(currentPrice, thatPrice);
    }

    int getColumn(itemPointer* p){
        return p->cellData->column;
    }
    int getRow(itemPointer* p){
        return p->cellData->row;
    }

    int getPrice(itemPointer* p){
        return p->itemData->price;
    }

    int getWeight(itemPointer* p){
        return p->itemData->weight;
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
            sum+=getWeight(p[i]);
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
            sum+=getPrice(p[i]);
        }
        // cout<<sum<<endl;
        return sum;
    }


    void initializeKnapSackTable(){
        initializeTheFirstRowOfTheTable();
        initializeTheRowsThatAreNotInitialized();
    }

    void knapsack(){
        initializeKnapSackTable();

        int sumOfPrice;

        for(int row = 1; row <knpsh->ith->getSize(); row++){

            knpsh->setItemPointerWeightAndPrice(&currentItem,row);
                        
            knpsh->setRowAndColumn(&prevItemPointerIt, row-1, prevItemPointerIt);

            knpsh->setRowAndColumn(&prevItem, row-1, prevItem);

            for(int j = getWeight(currentItem) + 1; j < bagSize; j++){
                
                knpsh->setItemPointerWeightAndPrice(&prevItemPointerIt,table);

                knpsh->setItemPointerWeightAndPrice(&prevItem,table);

                if(isTheCellWeightCompatableWithTheItem(j, KnapSackHelper::getSumOfWeight(currentItem,prevItem))){

                    sumOfPrice = KnapSackHelper::getSumOfPrice(currentItem,prevItem);
                    if(isCurrentPriceGreaterOrEqualToThatPrice(sumOfPrice, getPrice(prevItemPointerIt))){
                        
                        setTableCellPrice(new tableCellCoordinates{row,j}, (sumOfPrice));

                        KnapSackHelper::incrementColumns(&prevItem,&prevItemPointerIt);
                    }

                }else{
                    setTableCellPrice(new tableCellCoordinates{row,j}, getPrice(prevItemPointerIt));
                    KnapSackHelper::incrementColumn(&prevItemPointerIt);
                }
            }
        }
    }


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

    kp->printTable();
}