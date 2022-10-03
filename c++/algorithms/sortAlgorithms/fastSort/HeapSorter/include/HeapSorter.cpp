#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/HeapSorter/src/HeapSorter.h"

HeapSorter::HeapSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize){
    heapSize = this->numbers.size();
    theIndexOfTheMaximumParentValue = 0;
    theMaximumParentValue = numbers[theIndexOfTheMaximumParentValue];
}

void HeapSorter::sort(){
    heapSort();
}

void HeapSorter::heapSort(){
    while(heapSize>0){
        buildMaxHeap(0);
        
        theIndexOfTheMaximumParentValue = NumberFinder::findTheParentWithTheMaximumNumberFromAllParents (numbers,heapSize);
        theMaximumParentValue = numbers[theIndexOfTheMaximumParentValue];
    
        NumberSwapper::swapTwoNumbersValue(&numbers[0], &numbers[theIndexOfTheMaximumParentValue]);
        NumberSwapper::swapTwoNumbersValue(&numbers[heapSize-1], &numbers[0]);

        heapSize--;    
    }
}

void HeapSorter::buildMaxHeap(int parentIndex){
    if(parentIndex*2 + 1 >= heapSize){
        return;
    }

    int rightChildIndex = parentIndex*2+2;
    int leftChildIndex = parentIndex*2+1;

    if(rightChildIndex< heapSize){
        
        // pick the greates number from the child and place it as parent number and swap
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[rightChildIndex], &numbers[parentIndex]);        
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[leftChildIndex], &numbers[parentIndex]);
    }
    else if(leftChildIndex < heapSize){
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[leftChildIndex], &numbers[parentIndex]);   
    }

    buildMaxHeap(parentIndex+1);
    
}

void HeapSorter::shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int *lesser){
    if(*greater > *lesser){
        NumberSwapper::swapTwoNumbersValue(greater, lesser);
    }
}
    
void HeapSorter::printNumbers(){
    NumberSorter::printNumbers();
}