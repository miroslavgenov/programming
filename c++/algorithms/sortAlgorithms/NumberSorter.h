#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberSwapper.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class NumberSorter{
    protected:
    std::vector<int> numbers;

    void setNumbers(int [], int );

    public:
    NumberSorter(int [],size_t );

    void printNumbers();

    virtual void sort() = 0;
    private:
    virtual void sortAllNumbers() = 0;
    
    virtual void sortNumber() = 0;
    
    virtual void shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser) = 0;
    
};

