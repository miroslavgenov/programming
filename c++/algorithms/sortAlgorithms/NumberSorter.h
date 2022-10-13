#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberSwapper.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class NumberSorter{
protected:
    std::vector<int> numbers;

public:
    NumberSorter(int [],size_t );

private:
    void setNumbers(int [], int );

public:
    virtual void sort() = 0;

    std::vector<int> getNumbers(){return numbers;}

private:
    virtual void shouldSwapTheGreaterNumberWithLesserNumber(int* , int *) = 0;
    
};

