#pragma once
#include "../../NumberSorter.cpp"

class ShakeSorter : NumberSorter{
    private:
        bool isThereASwap;
    public:
        ShakeSorter(int [], int );

        void sort();

    private:
        void sortNumbersForwardAndShouldSetIsThereASwapToTrue();

        void sortNumbersBackwards();
    
        void shouldSwapTheGreaterNumberWithLesserNumber(int* ,int *);
    
    public:
        std::vector<int> getNumbers();

};