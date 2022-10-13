#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class SelectionSorter:NumberSorter{
    public:
    SelectionSorter(int [], size_t );
    
    void sort();
    
    private:
    // TODO: implement binary search instead of linear search
    int getTheIndexOfTheNumberThatIsLessThanTheCurrentNumberAndIsInTheUnsortedPartOfTheArray(int , int );

    void shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int* lesser){}
    public:
        std::vector<int> getNumbers();
    
};