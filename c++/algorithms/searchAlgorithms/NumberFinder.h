#pragma once
#include <vector>

class NumberFinder{
    public:
    
    static int findMinimumNumberFromArray(std::vector<int> numbers){
        int minimumNumber = numbers[0];
        for(int i = 0; i < numbers.size();i++){
            if(minimumNumber > numbers[i]){
                minimumNumber = numbers[i];
            }
        }
        return minimumNumber;
    }

    static int findMinimumNumberFromArray(int numbers[], int numbersSize){
        int minimumNumber = numbers[0];
        for(int i = 0; i < numbersSize;i++){
            if(minimumNumber > numbers[i]){
                minimumNumber = numbers[i];
            }
        }
        return minimumNumber;
    }

    static int findMaximumNumberFromArray(std::vector<int> numbers){
        int maximumNumber = numbers[0];

        for(int i=0;i<numbers.size();i++){
            if(maximumNumber< numbers[i]){
                maximumNumber = numbers[i];
            }
        }
        return maximumNumber;
    }

    static int findMaximumNumberFromArray(int numbers[], int numbersSize){
        int maximumNumber = numbers[0];

        for(int i=0;i<numbersSize;i++){
            if(maximumNumber< numbers[i]){
                maximumNumber = numbers[i];
            }
        }
        return maximumNumber;
    }
};


