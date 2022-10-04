#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/ArrayChecker.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/CountSorter/include/CountSorter.cpp"
#include <cmath>

using namespace std;

class LinearSearcher{
private:
	int *numbers=nullptr;
	size_t numbersSize;
	int findThisNumber;
	int foundNumber;
	int foundIndex;
	int jumpSize;

public:
	LinearSearcher(int numbers[], size_t numbersSize, int findThisNumber):numbersSize(numbersSize),findThisNumber(findThisNumber){
		this->numbers = new int[this->numbersSize];
		this->numbers = numbers;
		this->findThisNumber = findThisNumber;
		jumpSize = sqrt(this->numbersSize);
		
		
	}

	~LinearSearcher(){
		delete [] numbers;
	}
	void jumpSearch(){
		
		if(ArrayChecker::areNumbersSorter(numbers,numbersSize)){
			
			for(int i=0; i<numbersSize; i+=jumpSize){
				if(numbers[i] == findThisNumber){
					cout<<findThisNumber<<" found at index: "<<i<<endl;
					break;	
				}else{

					if(findThisNumber < numbers[i]){
						
						for(int j = i-1; j >= i - jumpSize ; j--){
							if(numbers[j] == findThisNumber){
								cout<<findThisNumber<<" found at index: "<<j<<endl;
								break;
							}
						}
						

					}
					
				}
				
			}

		}else{
			cout<<"to use jumpSort() first sort your array in DESC order"<<endl;
		}
	
	}

	void linearSearch(){
		foundIndex = NumberFinder::findTheIndexOfNumberFromArray(numbers,numbersSize,findThisNumber);
		if(foundIndex != -1){
			cout<<findThisNumber<<" is at index: "<<foundIndex<<endl;			
		}else{
			cout<<findThisNumber<<" is not in the array"<<endl;
		}
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
	// int findThisNumber = 5	;
	CountSorter* c = new CountSorter(numbers,numbersSize);
	c->sort();
	vector<int> sortedNumbers = c->getNumbers();
	
	for(int i = 0; i<sortedNumbers.size(); i++){
		numbers[i] = sortedNumbers[i];
	}
	Printer::printNumbers(numbers,numbersSize);
	
	LinearSearcher* l = nullptr;
	cout<<endl;
	for(int i = 1; i<=10;i++){
		l= new LinearSearcher(numbers,numbersSize,i);
	l->jumpSearch();	
	}
	delete l;

	



}
