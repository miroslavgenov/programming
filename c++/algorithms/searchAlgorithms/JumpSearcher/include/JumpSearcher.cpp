#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/JumpSearcher/src/JumpSearcher.h"





JumpSearcher::JumpSearcher(int numbers[], size_t numbersSize):NumberSearcher(numbers, numbersSize){
	jumpSize = sqrt(this->numbersSize);	
}

bool JumpSearcher::canYouJumpSearch(){
	return ArrayChecker::areNumbersSorted(numbers, numbersSize);
}

int JumpSearcher::jumpSearch(int findThisNumber){
	if(canYouJumpSearch()){
		
		for(int i = 0; i < numbersSize; i+=jumpSize){
			if(numbers[i] == findThisNumber){
				return i;
			}else{
				if(findThisNumber < numbers[i]){
					return LinearSearcher(numbers, numbersSize, findThisNumber).linearSearchIndexOfFindThisNumberBackwards(i, i-jumpSize);
				}
			}

		}


	}else{
		std::cout<<"firstSort your array"<<std::endl;

	}

	return indexIsNotFound;
}


