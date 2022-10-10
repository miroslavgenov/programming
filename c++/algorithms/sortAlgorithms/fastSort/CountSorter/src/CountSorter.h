#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"

class CountSorter : NumberSorter{
private:
    int maximumNumberFromUnsortedArray;
    int* countOfNumbersRepeated = nullptr;
    int countOfNumbersRepeatedSize;

public:
    CountSorter(int [], size_t );

private:
    void setCountOfNumbersRepeatedSize();

    int getAGreaterNumberThanMaximumNumberByOne();

public:
    ~CountSorter();

    void sort();

private:
    void loopTheUnsortedNumbersAndAddOneToHisValue();

    void useCurrentNumberAsKeyToAddOneToHisValue(int );

    bool isNumberRepeated(int );

    void replaceUnsortedNumberThatTimesHowMuchNumberRepeats(int ,int ,int &);

public:
    std::vector<int> getNumbers(){ return NumberSorter::getNumbers();}
    void printNumbers();

private:
    void shouldSwapTheGreaterNumberWithLesserNumber(int* , int* );
        
};