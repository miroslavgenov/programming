#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberSwapper.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class NumberSorter{
protected:
    std::vector<int> numbers;

public:
    NumberSorter(int [],size_t );
    NumberSorter(){}



public:
    virtual void sort(){}

    std::vector<int> getNumbers(){return numbers;}

protected:
    void setNumbers(int [], int );

    void shouldSwapTheGreaterNumberWithLesserNumber(int* greaterNumber,int *lesserNumber){
    if(NumberChecker::isTheNumberGreaterThan(greaterNumber,lesserNumber)){
            NumberSwapper::swapTwoNumbersValue(greaterNumber,lesserNumber);
        }
    }
};