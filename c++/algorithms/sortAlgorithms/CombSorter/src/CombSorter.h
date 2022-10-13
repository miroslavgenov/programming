#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/ArrayChecker.cpp"

class CombSorter : NumberSorter{
    private:
        const double gapShrinkFactor = 1.3;
        int gap;
        bool areNumbersSorted;

    public:
        CombSorter(int [], size_t );
private:
        void initializeGap();
public:
        void sort();
private:
        void setAndDecreaseGapIfGreaterThanOne();

        bool isGapDevidedByGapShrinkFactorGreaterThanOne();

        int devideGapByGapShrinkValue();

        void setGap(int);

        void shouldSwapTheGreaterNumberWithLesserNumber(int *, int*);

public:
    std::vector<int> getNumbers();
};