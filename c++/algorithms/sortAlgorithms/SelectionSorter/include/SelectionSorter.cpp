#include "../src/SelectionSorter.h"

SelectionSorter::SelectionSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize){}

void SelectionSorter::sort(){
    int theMinimumNumberIndexInUnsortedPart;
    int starOfTheUnsortedPartOfArray;

    for(int i=0;i<numbers.size();i++){
        starOfTheUnsortedPartOfArray = i;
        NumberSwapper::swapTwoNumbersValue(&numbers[i], &numbers[getTheIndexOfTheNumberThatIsLessThanTheCurrentNumberAndIsInTheUnsortedPartOfTheArray(numbers[i], starOfTheUnsortedPartOfArray)]);
    }
}

int SelectionSorter::getTheIndexOfTheNumberThatIsLessThanTheCurrentNumberAndIsInTheUnsortedPartOfTheArray(int currentNumber, int startOfUnsortedPartOfTheArray){
    int *minimumNumber = new int{currentNumber};
    int theIndexOfTheMinimumNumber = startOfUnsortedPartOfTheArray;

    for(int i = startOfUnsortedPartOfTheArray; i < numbers.size(); i++){
        if(NumberChecker::isTheNumberGreaterThan(minimumNumber,&numbers[i])){
            *minimumNumber = numbers[i];
            theIndexOfTheMinimumNumber = i;
        }
    }
    
    delete minimumNumber;
    return theIndexOfTheMinimumNumber;
}

void SelectionSorter::printNumbers(){
    NumberSorter::printNumbers();
}
