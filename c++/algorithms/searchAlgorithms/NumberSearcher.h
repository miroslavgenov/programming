#pragma once

class NumberSearcher{
protected:
	int *numbers;
	size_t numbersSize;
	int findThisNumber;
	int foundNumber;
	int foundIndex;
	int indexIsNotFound = -1;

public:
	
	NumberSearcher(int numbers[], size_t numbersSize){
		this->numbersSize = numbersSize;
		this->numbers = new int[numbersSize];
		this->numbers = numbers;
	}

	NumberSearcher(int numbers[], size_t numbersSize, int findThisNumber):NumberSearcher(numbers, numbersSize){
		this->findThisNumber = findThisNumber;
	}
};