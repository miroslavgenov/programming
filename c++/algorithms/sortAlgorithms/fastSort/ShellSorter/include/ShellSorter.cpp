#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/ShellSorter/src/ShellSorter.h"


ShellSorter::ShellSorter(int numbers[],int numbersSize):NumberSorter(numbers,numbersSize){
    shellStep = this->numbers.size();
}

void ShellSorter::sort(){
    for(int i = shellStep; i >= 1; i = i/2){
        sortForwardAndBackwardsWithShellStep(i);            
    }
}


void ShellSorter::sortForwardAndBackwardsWithShellStep(int shellStep){
    for(int j = 0; j + shellStep < numbers.size(); j+= shellStep){
        if( NumberChecker::isTheNumberGreaterThan(&numbers[j], &numbers[j + shellStep])){
            NumberSwapper::swapTwoNumbersValue(&numbers[j], &numbers[j + shellStep]);
            sortBackwardsFromCurrentSwapIndexWithShellStep(j, shellStep);                  
        }   
    }
}

void ShellSorter::sortBackwardsFromCurrentSwapIndexWithShellStep(int currentSwapIndex, int currentShellStep){
    for(int z = currentSwapIndex; z - currentShellStep >= 0; z-=currentShellStep){
        shouldSwapTheGreaterNumberWithLesserNumber(&numbers[z-currentShellStep], &numbers[z]);
    }
}

void ShellSorter::shouldSwapTheGreaterNumberWithLesserNumber(int *greater, int* lesser){
    if(*greater > *lesser){
        NumberSwapper::swapTwoNumbersValue(greater, lesser);
    }
}