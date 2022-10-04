#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"
using namespace std;

class LinearSearcher{
private:
	int *numbers=nullptr;
	size_t numbersSize;
	int findThisNumber;
	int foundNumber;
	int foundIndex;

public:
	LinearSearcher(int numbers[], size_t numbersSize, int findThisNumber):numbersSize(numbersSize),findThisNumber(findThisNumber){
		this->numbers = new int[this->numbersSize];
		this->numbers = numbers;
		this->findThisNumber = findThisNumber;
		
	}

	~LinearSearcher(){
		delete [] numbers;
	}


	void linearSearchWithArrayShiftByOneToRightAndMakeTheFoundNumberFirst(){
		foundIndex = NumberFinder::findTheIndexOfNumberFromArray(numbers,numbersSize,findThisNumber);
		if(foundIndex != NumberFinder::theNumberIndexIsNotFound){
			foundNumber = numbers[foundIndex];
			
			shiftTheArrayByOneToTheFoundIndex();
			setTheFirstNumberOfTheArrayToBeTheFoundedNumber();
			
			cout<<foundNumber<<" is found and at index 0"<<endl;

		}else{
			cout<<findThisNumber<<"is not found"<<endl;
		}
	}

private:
	void shiftTheArrayByOneToTheFoundIndex(){
		for(int i = foundIndex; i-1 >= 0; i--){
			numbers[i] = numbers[i-1];
		}
	}
	void setTheFirstNumberOfTheArrayToBeTheFoundedNumber(){
		numbers[0] = foundNumber;
	}


};




int main(){
	int numbersSize = 10;
	int numbers[numbersSize] = {8,5,4,6,2,1,9,7,3,10};
	int findThisNumber = 10	;
	LinearSearcher* l = new LinearSearcher(numbers,numbersSize,10);
	l->linearSearchWithArrayShiftByOneToRightAndMakeTheFoundNumberFirst();

	



}
