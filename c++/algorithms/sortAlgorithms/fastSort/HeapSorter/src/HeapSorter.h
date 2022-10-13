#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.h"

class HeapSorter:NumberSorter{
    int heapSize;
    int theIndexOfTheMaximumParentValue;
    int theMaximumParentValue;

public:
    HeapSorter(int [], size_t);

    void sort();

private:
    void heapSort();

    void buildMaxHeap(int );

    void shouldSwapTheGreaterNumberWithLesserNumber(int*, int *);

    std::vector<int> HeapSorter::getNumbers(){
    return NumberSorter::getNumbers();
}


};