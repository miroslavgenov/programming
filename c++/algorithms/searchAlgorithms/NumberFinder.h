#pragma once
#include <vector>

class NumberFinder{
public:
    static constexpr int theNumberIndexIsNotFound = -1;

    static int findTheIndexOfNumberFromArrayInReverseOrder(int numbers[], int numbersSize, int startIndex, int stopIndex, int findThisNumber){
        for(int i = startIndex; i>= stopIndex; i--){
            if(numbers[i] == findThisNumber){
                return i;
            }
        }
        return -1;
    }

    static int findTheIndexOfNumberFromArray(int numbers[], int numbersSize, int findThisNumber){
        
        int foundIndex;

        for(int i = 0; i<numbersSize; i++){
            if(numbers[i] == findThisNumber){
                foundIndex = i;
                return foundIndex;
            }
        }
        return theNumberIndexIsNotFound;

    }
    
    static int findTheParentWithTheMaximumNumberFromAllParents(std::vector<int> numbers, int heapSize){
        // to clean
        int currentMaximumParentIndex = 0;
        int currentMaximumParentNumber = numbers[currentMaximumParentIndex];
        
        for(int i=0; i*2+1 < heapSize || i*2+2 < heapSize; i++){
        if(currentMaximumParentNumber < numbers[i]){
            currentMaximumParentNumber = numbers[i];
            currentMaximumParentIndex = i;
         
        }    
        
    }
    return currentMaximumParentIndex;
}



    static int findMinimumNumberFromUnsortedVector(std::vector<int> numbers){
        int minimumNumber = numbers[0];
        for(int i = 0; i < numbers.size();i++){
            if(minimumNumber > numbers[i]){
                minimumNumber = numbers[i];
            }
        }
        return minimumNumber;
    }

    static int findMinimumNumberFromUnsortedArray(int numbers[], int numbersSize){
        int minimumNumber = numbers[0];
        for(int i = 0; i < numbersSize;i++){
            if(minimumNumber > numbers[i]){
                minimumNumber = numbers[i];
            }
        }
        return minimumNumber;
    }

    static int findMaximumNumberFromUnsortedVector(std::vector<int> numbers){
        int maximumNumber = numbers[0];

        for(int i=0;i<numbers.size();i++){
            if(maximumNumber< numbers[i]){
                maximumNumber = numbers[i];
            }
        }
        return maximumNumber;
    }

    static int findMaximumNumberFromUnsortedArray(int numbers[], int numbersSize){
        int maximumNumber = numbers[0];

        for(int i=0;i<numbersSize;i++){
            if(maximumNumber< numbers[i]){
                maximumNumber = numbers[i];
            }
        }
        return maximumNumber;
    }
};

