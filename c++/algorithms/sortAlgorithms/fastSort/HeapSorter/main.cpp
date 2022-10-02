#include <iostream>
// #include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberSwapper.h"

using namespace std;

void print(int numbers[], int numbersSize){
    for(int i=0;i<numbersSize;i++){
        cout<<numbers[i]<<" ";
    }cout<<endl;
}

bool isChildIndexInrangeOfHeapSize(int childIndex, int heapSize){
    return  childIndex < heapSize;
}

bool doParentHaveLeftChild(int parentIndex, int heapSize){
    return isChildIndexInrangeOfHeapSize(parentIndex*2+1,heapSize);
}



bool doParentHaveRightChild(int parentIndex, int heapSize){
    return isChildIndexInrangeOfHeapSize(parentIndex*2+2,heapSize);
}

bool canWeProceedToBuildMaxHeap(int childIndex,int heapSize){
    return childIndex<=heapSize;
}

bool isNumberGreaterThan(int numbers[], int firstNumber, int secondNumber){
    return firstNumber > secondNumber;
}

void shouldSwapParentNumberWithChildNumber(int numbers[],int parentIndex,int childIndex){
    if(
            numbers[childIndex] > numbers[parentIndex]
            
            ){
            NumberSwapper::swapTwoNumbersValue(&numbers[parentIndex], &numbers[childIndex]);
        }
}

void makeTheGreaterNumberFromSubTreeToBeRootOfTheSubTree(int numbers[],int parentIndex, int heapSize){
    
    int leftChildIndex;
    int rightChildIndex;

    
    if(doParentHaveRightChild(parentIndex,heapSize)){

        leftChildIndex = parentIndex*2+1;
        rightChildIndex = parentIndex*2+2;    
        
        shouldSwapParentNumberWithChildNumber(numbers,parentIndex,leftChildIndex);
        shouldSwapParentNumberWithChildNumber(numbers,parentIndex,rightChildIndex);

    
    }else if(doParentHaveLeftChild(parentIndex,heapSize)){
        
        leftChildIndex = parentIndex*2+1;
        
        shouldSwapParentNumberWithChildNumber(numbers,parentIndex,leftChildIndex);

    }    
}

void buildMaxHeap(int numbers[], int heapSize, int parentIndex){
    

    if(!canWeProceedToBuildMaxHeap(parentIndex*2+1,heapSize)){
        return;
    }
    makeTheGreaterNumberFromSubTreeToBeRootOfTheSubTree(numbers,parentIndex,heapSize);
    
    buildMaxHeap(numbers,heapSize, parentIndex*2+1);
    buildMaxHeap(numbers,heapSize, parentIndex*2+2);
    

}  

int findIndexOfTheMaximumParentValue(int numbers[], int heapSize){
    int theIndexOfTheMaximumParentValue = 0;

    for(int i= 0 ; i*2+1 < heapSize || i*2+2 < heapSize ; i++){
        if(i*2+1 < heapSize  && i*2+2 < heapSize){
            if(numbers[theIndexOfTheMaximumParentValue] < numbers[i]){
                theIndexOfTheMaximumParentValue = i;
            }
        }
        else if(i*2+1 < heapSize){
            if(numbers[theIndexOfTheMaximumParentValue] < numbers[i]){
                theIndexOfTheMaximumParentValue = i;
            }
        }
    }

    return theIndexOfTheMaximumParentValue;
}

int main(){
    int numbersSize = 10;
    int numbers[numbersSize] = {2,4,3,6,8,1,1,7,10,9};
    int heapSize = numbersSize;
    int theIndexOfTheMaximumParentValue;

    while(heapSize>0){
        buildMaxHeap(numbers, heapSize, 0);
        theIndexOfTheMaximumParentValue = findIndexOfTheMaximumParentValue(numbers,heapSize);
        NumberSwapper::swapTwoNumbersValue(&numbers[0], &numbers[theIndexOfTheMaximumParentValue]);
        NumberSwapper::swapTwoNumbersValue(&numbers[0], &numbers[heapSize-1]);    
        heapSize--;    
    }
    print(numbers,numbersSize);
    
    
}
