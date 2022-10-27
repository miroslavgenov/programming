#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/BubbleSorter/src/BubbleSorter.h"

BubbleSorter::BubbleSorter(int numbers[],int numberSize):NumberSorter(numbers,numberSize){}

void BubbleSorter::sort(){
    sortAllNumbers();
}

void BubbleSorter::sortAllNumbers(){
    for(int i=1;i<numbers.size();i++){
        sortNumber();
    }
}    

void BubbleSorter::sortNumber(){
    for(int i=1;i<numbers.size();i++){
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[i-1],&numbers[i]);
    }
}