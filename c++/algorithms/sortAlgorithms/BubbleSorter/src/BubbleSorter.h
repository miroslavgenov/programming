#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class BubbleSorter : NumberSorter{
    public:

    BubbleSorter(int [],int );

    void sort();

    void sortAllNumbers();

    void sortNumber();

    std::vector<int> getNumbers(){return NumberSorter::getNumbers();}

};