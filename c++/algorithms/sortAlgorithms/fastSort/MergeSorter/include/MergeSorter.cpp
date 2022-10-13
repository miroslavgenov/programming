#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/MergeSorter/src/MergeSorter.h"

// TODO: MERGE SORTER IS NOT CLEAN

MergeSorter::MergeSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize){
    this->arrayToStoreSortedNumbers = new int[numbersSize];
}

void MergeSorter::sort(){
    splitAndMerge(0,numbers.size()-1);
}

void MergeSorter::splitAndMerge(int left, int right){

    if(left == right){
        return;
    }

    int mid = (left+right)/2;
    
    splitAndMerge(left,mid);
    splitAndMerge(mid+1,right);
    merge(left,right);
}

void MergeSorter::merge(int left,int right){
    // this functions is not clean
    int i = left;
    int mid = (left+right)/2;
    int j = mid + 1;
    
    // moving from the left to save the correct number position for
    // arrayToStoreSortedNumbers
    int arrayToStoreSortedNumbersIterator = left;

    // clean
    while(i<=mid && j<=right){

        if(NumberChecker::isTheNumberGreaterOrEqual(numbers[i], numbers[j])
            
        ){
            arrayToStoreSortedNumbers[arrayToStoreSortedNumbersIterator] = numbers[j];
            arrayToStoreSortedNumbersIterator++;
            j++;
        }

        if(
            NumberChecker::isTheNumberGreaterOrEqual(numbers[j], numbers[i])
            
            ){

            arrayToStoreSortedNumbers[arrayToStoreSortedNumbersIterator] = numbers[i];
            arrayToStoreSortedNumbersIterator++;
            i++;
        }
    }
    
    
    shouldAppendTheRemainingNumbersInSortedNumbersFromIndexToRange(i,mid,arrayToStoreSortedNumbersIterator);
    
    shouldAppendTheRemainingNumbersInSortedNumbersFromIndexToRange(j,right,arrayToStoreSortedNumbersIterator);
    
    replaceUnsortedNumbersWithSortedNumbersInOriginalArrayFromIndexToRange(left,right);
    
    
}
 