#pragma once
#include "../../NumberSorter.cpp"

class ShakeSorter : public NumberSorter{
    private:
        bool isThereASwap;
    public:
        ShakeSorter(int [], int );

        void sort();

    private:
        void sortNumbersForwardAndShouldSetIsThereASwapToTrue();

        void sortNumbersBackwards();
    

};