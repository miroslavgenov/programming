#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/CountSorter/src/CountSorter.h"


    CountSorter::CountSorter(int numbers[], size_t numbersSize){
        countedNumbersSize= NumberFinder::findMaximumNumberFromUnsortedArray(numbers,numbersSize)+1;
        setNumbers(numbers,numbersSize);
        countedNumbers=new int[countedNumbersSize];
        

        countNumbers();

        
    }

    void CountSorter::countNumbers(){
        for(int i=0;i < this->numbers.size();i++){
            countedNumbers[numbers[i]]+=1;
        }
    }
    
    
    void CountSorter::sort(){
        this->numbers.clear();

        for(int i=0;i < countedNumbersSize;i++)
        {
            for(int j=0;j < countedNumbers[i];j++)
            {
                this->numbers.push_back(i);
         
            }
        }
    }