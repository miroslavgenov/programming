#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"


class CountSorter : public NumberSorter {
    int *countedNumbers;
    size_t countedNumbersSize;
public:
    CountSorter(int numbers[], size_t numbersSize);
private:
    void countNumbers();
    
    public:
    void sort();
     
};