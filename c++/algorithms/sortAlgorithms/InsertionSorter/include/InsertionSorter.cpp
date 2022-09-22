#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/InsertionSorter/src/InsertionSorter.h"

InsertionSorter::InsertionSorter(int numbers[], 
    size_t numbersSize):NumberSorter(numbers, numbersSize){}

void InsertionSorter::sort(){
    int currentSwap;
    for(int i=1;i<numbers.size();i++){
        currentSwap = i;
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[i-1], &numbers[i]);
        loopBackWardsFromTheCurrentSwapAndShouldSwapGreaterNumberWithLesserNumber(currentSwap);
    }
}

void InsertionSorter::shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser){
    if(NumberChecker::isTheNumberGreaterThan(greater,lesser)){
        NumberSwapper::swapTwoNumbersValue(greater,lesser);
    }
}

void InsertionSorter::loopBackWardsFromTheCurrentSwapAndShouldSwapGreaterNumberWithLesserNumber(int loopBackFromThisIndex){
    for(int j = loopBackFromThisIndex; j - 1 >= 0; j--){
            shouldSwapTheGreaterNumberWithLesserNumber(&numbers[j-1],&numbers[j]);
        }
}



void InsertionSorter::printNumbers(){
    NumberSorter::printNumbers();
}    
