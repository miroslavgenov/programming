#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class InsertionSorter : public NumberSorter{
    public:
    InsertionSorter(int [], size_t );

    void sort();

    void loopBackWardsFromTheCurrentSwapAndShouldSwapGreaterNumberWithLesserNumber(int );

    private:



    void sortAllNumbers(){}
    
    void sortNumber(){}
    
    
};
