#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"


class QuickSorter : NumberSorter{
    
    public:
        QuickSorter(int [], size_t );
        
        void sort();

    private:    
        void quickSort(int , int );

    
        void shouldSwapTheGreaterNumberWithLesserNumber(int *, int *);

    public:
        void printNumbers();


    
};
