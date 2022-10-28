#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class InsertionSorter : NumberSorter{
    public:
    InsertionSorter(int [], size_t );

    void sort();

    void loopBackWardsFromTheCurrentSwapAndShouldSwapGreaterNumberWithLesserNumber(int );

    private:



    void sortAllNumbers(){}
    
    void sortNumber(){}
    
    
    public:    
    std::vector<int> getNumbers(){
        return NumberSorter::getNumbers();
    }

};
