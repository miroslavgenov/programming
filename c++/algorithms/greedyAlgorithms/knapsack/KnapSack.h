#pragma once

class KnapSack{
    public:
    int bagSize;
    int** table = nullptr;
    itemPointer* prevItemPointerIt = nullptr;
    itemPointer* prevItem = nullptr;
    itemPointer* currentItem = nullptr;
    KnapSackHelper* knpsh = nullptr;
	
    KnapSack(item** ,int ,int );

    void setRowAndColumnForBothItemPointers(int );

    void knapsack();
};