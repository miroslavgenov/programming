#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/BinarySearcher/src/BinarySearcher.h"

	BinarySearcher::BinarySearcher(int numbers[], size_t numbersSize):NumberSearcher(numbers, numbersSize){
			right = numbersSize - 1;
			mid = (left + right) / 2;
	}

	BinarySearcher::BinarySearcher(int numbers[], size_t numbersSize, int findThisNumber):NumberSearcher(numbers, numbersSize, findThisNumber){
			right = numbersSize - 1;
			mid = (left + right) / 2;
	}

	int BinarySearcher::search(int findThisNumber){
		setFindThisNumber(findThisNumber);
		return this->search();
	}

	int BinarySearcher::search(){
		if(ArrayChecker::areNumbersSorted(numbers, numbersSize)){
			 binarySearchIndexOfFindThisNumber(left, mid, right);	
			 
			 if(numbers[foundIndex] == findThisNumber){
			 	return foundIndex;	
			 }			 
		}
		else{
			std::cout<<"sort your first array"<<std::endl;
		}

		return -1;
	}
	

	void BinarySearcher::binarySearchIndexOfFindThisNumber(int left, int mid, int right){
	if(numbers[mid] == findThisNumber){
		foundIndex = mid;
		return ;
	}
	if(left >= right){
		return;
	}

	if(numbers[mid] < findThisNumber){
		binarySearchIndexOfFindThisNumber(mid + 1, (mid+1 + right) / 2, right);
	}else{
		binarySearchIndexOfFindThisNumber(left, ((mid - 1) + left) / 2, mid - 1);
	}
}