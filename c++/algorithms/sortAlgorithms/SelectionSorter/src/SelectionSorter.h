#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class SelectionSorter: public NumberSorter{
    public: public NumberSorter
    SelectionSorter(int [], size_t );
    
    void sort();
    
    private:
    // TODO: public NumberSorter implement binary search instead of linear search
    int getTheIndexOfTheNumberThatIsLessThanTheCurrentNumberAndIsInTheUnsortedPartOfTheArray(int , int );
    
};