#pragma once
#include <vector>

class ArrayChecker{
    public:

    static bool areNumbersSorted(std::vector<int> numbers){
        for(int i = 1; i < numbers.size(); i++){
            if(numbers[i-1] > numbers[i]){
                return false;
            }
        }
        return true;
    }
        
    static bool areNumbersSorted(int numbers[], int numbersSize){
        for(int i=1;i<numbersSize;i++){
            if(numbers[i-1]>numbers[i]){
                return false;
            }
        }
        return true;
    }
};