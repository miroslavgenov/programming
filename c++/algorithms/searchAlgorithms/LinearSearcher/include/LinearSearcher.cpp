#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/LinearSearcher/src/LinearSearcher.h"

LinearSearcher::LinearSearcher(int numbers[], size_t numbersSize):NumberSearcher(numbers, numbersSize){
}

LinearSearcher::LinearSearcher(int numbers[], size_t numbersSize, int findThisNumber):NumberSearcher(numbers, numbersSize, findThisNumber){
}

	
int LinearSearcher::linearSearchIndexOfFindThisNumberWithArrayShiftByOneToRightAndMakeTheFoundNumberFirst(int findThisNumber){

	foundIndex = this->linearSearchIndexOfFindThisNumber();
	if(foundIndex != indexIsNotFound){
		
		for(int i = foundIndex; i-1 >= 0; i--){
			numbers[i] = numbers[i-1];
		}

		numbers[0] = findThisNumber;
		return 0;	
	}

	return indexIsNotFound;
	
}

int LinearSearcher::linearSearchIndexOfFindThisNumber(int findThisNumber){
	setFindThisNumber(findThisNumber);
	return this->linearSearchIndexOfFindThisNumber();
}

int LinearSearcher::linearSearchIndexOfFindThisNumber(){
	for(int i = 0; i < numbersSize; i++){
		if(numbers[i] == findThisNumber){
			return i;
		}
	}
	return indexIsNotFound;
}

int LinearSearcher::linearSearchIndexOfFindThisNumberBackwards(int startIndex, int endIndex){
	for(int i = startIndex-1; i >= endIndex; i--){
		if(numbers[i] == findThisNumber){
			return i;
		}
	}

	return indexIsNotFound;
}
