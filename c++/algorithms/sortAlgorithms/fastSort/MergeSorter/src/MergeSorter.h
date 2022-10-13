#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

//TODO: MERGE SORTER IS NOT CLEAN

class MergeSorter : NumberSorter{
    private:
        int *arrayToStoreSortedNumbers = nullptr;
    
    public:    
        MergeSorter(int [], size_t);

        void sort();
        
    private:
        void merge(int left,int right);

        void splitAndMerge(int left, int right);
        
        void shouldAppendTheRemainingNumbersInSortedNumbersFromIndexToRange(int index, int range,int storeSortedNumbersIterator){
            while(isIndexInRange(index, range)){
                arrayToStoreSortedNumbers[storeSortedNumbersIterator] = numbers[index];
                storeSortedNumbersIterator++;
                index++;
            }
        }
        void replaceUnsortedNumbersWithSortedNumbersInOriginalArrayFromIndexToRange(int left, int right){
            for(int i = left ; i<=right;i++){
                numbers[i] = arrayToStoreSortedNumbers[i];
            }
        }

        bool isIndexInRange(int index, int range){
            return NumberChecker::isTheNumberLesserOrEqual(index,range);
        }


        

        void shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser){}

    public:
        std::vector<int> MergeSorter::getNumbers(){
    return NumberSorter::getNumbers();
}

    
};