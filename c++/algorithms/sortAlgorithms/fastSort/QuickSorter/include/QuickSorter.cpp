#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/QuickSorter/src/QuickSorter.h"

QuickSorter::QuickSorter(int numbers[], size_t numbersSize):NumberSorter(numbers, numbersSize){        
}

void QuickSorter::sort(){  
    quickSort(0 , numbers.size()-1);
}

// don't know how to use with separe functions
void QuickSorter::quickSort(int left, int right){
    if(left > right){
        return;
    }

    int pivotValue = numbers[(left+right)/2] , i = left, j = right;

    // function1
    // find index of the first greater number than pivot from left
    while(numbers[i] < pivotValue){
        i++;
    }
    
    //function 2
    // find index of the first lesser number than pivot from right
    while(numbers[j] > pivotValue){
        j--;
    }

    //function 3
    // swap numbers 
    NumberSwapper::swapTwoNumbersValue(&numbers[i], &numbers[j]);
    
    // function 4
    //partition the array
    i++;
    j--;

    // repeat the step for the left part only
    quickSort(left,j);

    // then back track and repeat the step for the right part only
    quickSort(i,right);
}



void QuickSorter::shouldSwapTheGreaterNumberWithLesserNumber(int *greater, int *lesser){}

void QuickSorter::printNumbers(){
    NumberSorter::printNumbers();
}
