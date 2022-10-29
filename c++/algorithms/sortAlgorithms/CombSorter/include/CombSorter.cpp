#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/CombSorter/src/CombSorter.h"

CombSorter::CombSorter(int numbers[], size_t numbersSize):NumberSorter(numbers, numbersSize){
    initializeGap();
    areNumbersSorted = ArrayChecker::areNumbersSorted(this->numbers);
}

void CombSorter::initializeGap(){
    this->gap = this->numbers.size();
}

void CombSorter::sort(){
    while(areNumbersSorted == false){       
        setAndDecreaseGapIfGreaterThanOne();

        for(int i = 0 , j = gap ; j < numbers.size() ; i++, j++){
            shouldSwapTheGreaterNumberWithLesserNumber(&numbers[i], &numbers[j]);
        }

        areNumbersSorted = ArrayChecker::areNumbersSorted(this->numbers);
    }
}

void CombSorter::setAndDecreaseGapIfGreaterThanOne(){
    if(isGapDevidedByGapShrinkFactorGreaterThanOne()){
        int newGapValue = devideGapByGapShrinkValue();
        setGap(newGapValue);
    }
}

bool CombSorter::isGapDevidedByGapShrinkFactorGreaterThanOne(){
    return gap/gapShrinkFactor > 1;
}

int CombSorter::devideGapByGapShrinkValue(){
    return gap / gapShrinkFactor;
}

void CombSorter::setGap(int newDecreasedGap){
    gap = newDecreasedGap;
}

