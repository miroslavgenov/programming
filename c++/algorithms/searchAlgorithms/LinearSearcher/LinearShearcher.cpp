#include <iostream>


using namespace std;

class LinearSearcher{
	int *numbers = nullptr;
	int numbersSize;
	int givenNumber;
public:
	LinearSearcher(int numbers[], int numbersSize,int givenNumber){
		this->numbersSize = numbersSize;
		this->numbers = numbers;
		this->givenNumber = givenNumber;
		
	}

	bool areNumbersEqual(int firstNumber, int secondNumber){
		return firstNumber == secondNumber;
	}

	

	int search(){
		for(int i=0;i<numbersSize;i++){
			if(areNumbersEqual(numbers[i],givenNumber)){
				return i;
			}
		}
		return -1;
	}

};

	const int numbersSize = 10;
	int numbers[numbersSize] = {9,1,2,4,6,5,8,7,3,4};

int searchedNumber = 1;

bool linearSearch(){
	for(int i=0;i<numbersSize;i++){
		if(numbers[i] == searchedNumber){
			return true;
		}
	}
	return false;
}

int main(){
	
	LinearSearcher*l= new LinearSearcher(numbers,numbersSize,1);
	cout<<l->search()<<endl;
	
}