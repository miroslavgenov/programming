#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/QuickSorter/src/QuickSorter.h"

QuickSorter::QuickSorter(int numbers[], size_t numbersSize):NumberSorter(numbers, numbersSize){        
}

void QuickSorter::sort(){  
    quickSort(0 , numbers.size()-1);
}

// don't know how to use with separe functions
void QuickSorter::quickSort(int left, int right){
    if(left>=right){return;}
    int l = left ;
    int r = right;
    int pivot = numbers[(l+r)/2];
    
    
    int i  = l;
    int j = r;

    while(i<j){
        while(numbers[i] < pivot){  
            i++;
        }
        while(numbers[j] > pivot){
            j--;
        }
        
        if(i<=j){
            NumberSwapper::swapTwoNumbersValue(&numbers[i], &numbers[j]);    
            i++;
            j--;
        }
        
    }
    
    quickSort(l,j);
    quickSort(i,r);
}



void QuickSorter::shouldSwapTheGreaterNumberWithLesserNumber(int *greater, int *lesser){}
