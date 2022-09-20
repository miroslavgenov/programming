#include "../src/ShakeSorter.h"

ShakeSorter::ShakeSorter(int numbers[],int numbersSize):NumberSorter(numbers,numbersSize){
    isThereASwap = false;
}

void ShakeSorter::sort(){
    do{
        sortNumbersForwardAndShouldSetIsThereASwapToTrue();
        sortNumbersBackwards();
    }while(isThereASwap);
}


void ShakeSorter::sortNumbersForwardAndShouldSetIsThereASwapToTrue(){
    isThereASwap = false;
    for(int i = 1; i < numbers.size(); i++){
        if(numbers[i-1] > numbers[i]){
            NumberSwapper::swapTwoNumbersValue(&numbers[i-1],&numbers[i]);
            isThereASwap = true;
        }
    }
}

void ShakeSorter::sortNumbersBackwards(){
    for(int i = numbers.size() - 1 ; i-1 >= 0 ; i--){
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[i-1] , &numbers[i]);
    }
}    

void ShakeSorter::shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser){
    if(*greater > * lesser){
        NumberSwapper::swapTwoNumbersValue(greater,lesser);
    }
}

void ShakeSorter::printNumbers(){
    NumberSorter::printNumbers();
}
