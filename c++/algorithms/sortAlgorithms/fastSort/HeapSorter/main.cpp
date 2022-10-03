#include <iostream>
// #include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberSwapper.h"
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"


using namespace std;

void print(int numbers[], int numbersSize){
    for(int i=0;i<numbersSize;i++){
        cout<<numbers[i]<<" ";
    }cout<<endl;
}

class HeapSorter:NumberSorter{
    int heapSize;
    int theIndexOfTheMaximumParentValue;
    int theMaximumParentValue;

public:
    HeapSorter(int numbers[], int numbersSize):NumberSorter(numbers,numbersSize){
        heapSize = this->numbers.size();
        theIndexOfTheMaximumParentValue = 0;
        theMaximumParentValue = this->numbers[theIndexOfTheMaximumParentValue];
    }

    void sort(){}
    void shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser){}



    int findIndexOfTheMaximumParentValue(){
        // to clean
        int val = numbers[0];
        int index = 0;
        for(int i=0; i*2+1 < heapSize || i*2+2 < heapSize; i++){
        if(val < numbers[i]){
            val = numbers[i];
            index = i;
         
        }    
        
    }
    return index;
}

void buildMaxHeap(int parentIndex){
    if(parentIndex*2+1>=heapSize){return;}
    
    if(parentIndex*2+2 < heapSize){
        if(numbers[parentIndex] < numbers[parentIndex*2+2]){
            NumberSwapper::swapTwoNumbersValue(&numbers[parentIndex], &numbers[parentIndex*2+2]);
        }

        if(numbers[parentIndex] < numbers[parentIndex*2+1]){
            NumberSwapper::swapTwoNumbersValue(&numbers[parentIndex], &numbers[parentIndex*2+1]);
        }    
    }
        else if(parentIndex*2+1<heapSize){
        if(numbers[parentIndex] < numbers[parentIndex*2+1]){
        NumberSwapper::swapTwoNumbersValue(&numbers[parentIndex], &numbers[parentIndex*2+1]);
    }       
        }
        buildMaxHeap(parentIndex+1);
        
}

void heapSort(){
    
    while(heapSize>0){
        buildMaxHeap(0);
        theIndexOfTheMaximumParentValue = findIndexOfTheMaximumParentValue();
        theMaximumParentValue = numbers[theIndexOfTheMaximumParentValue];
    
        NumberSwapper::swapTwoNumbersValue(&numbers[0], &numbers[theIndexOfTheMaximumParentValue]);
        NumberSwapper::swapTwoNumbersValue(&numbers[heapSize-1], &numbers[0]);
        heapSize--;    
    }

}
    void printNumbers(){
        NumberSorter::printNumbers();
    }
};



int main(){
    int numbersSize = 5;
    int numbers[numbersSize] = {2,4,3,6,8};//,1,1,7,10,9};
    HeapSorter* h = new HeapSorter(numbers,numbersSize);
    h->heapSort();
    
    
    
}
