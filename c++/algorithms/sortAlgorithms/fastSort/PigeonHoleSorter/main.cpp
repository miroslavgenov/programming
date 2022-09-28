#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

using namespace std;

void print(int numbers[], int numbersSize){
	for(int i=0;i<numbersSize;i++){
	cout<<numbers[i]<<" ";
	}cout<<endl;
}
class PigeonHoleSorter : NumberSorter{
	vector<vector<int>> pigeonHoles;
	int minimumNumber;
	int maximumNumber;
	int totalPigeonHolesRange ;


public:

	PigeonHoleSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize) {
	
		setMaximumNumber();
		setMinimumNumber();
		totalPigeonHolesRange = (maximumNumber - minimumNumber) + 1;		

		for(int i=0;i< totalPigeonHolesRange;i++){
			pigeonHoles.push_back({});
		}

	}

	
	
	void shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int *lesser){

	}

	int findMinimumNumberFromArray(){
		minimumNumber = numbers[0];
		
		for(int i =0 ;i<numbers.size();i++){
			if(minimumNumber > numbers[i]){
				minimumNumber = numbers[i];
			}
		}
		return minimumNumber;
	}

	int findMaximumNumberFromArray(){
		maximumNumber = numbers[0];
		
		for(int i=0;i<numbers.size();i++){
			if(maximumNumber < numbers[i]){
				maximumNumber = numbers[i];
			}
		}
		return maximumNumber;
	}
	

	void sort(){
		for(int i=0;i<numbers.size();i++){
			pigeonHoles[getTheSuitablePigeonHoleIndexForTheCurrentNumber(numbers[i])].push_back(numbers[i]);
		}

		int numbersIterator = 0;
		
		for(int i=0;i<pigeonHoles.size();i++){
			for(int j =0; j<pigeonHoles[i].size() ; j++){
				// cout<<pigeonHoles[i][j]<<" ";
				numbers[numbersIterator] = pigeonHoles[i][j];
				numbersIterator++;
			}
		}
	}

	int getTheSuitablePigeonHoleIndexForTheCurrentNumber(int currentNumber){
		return currentNumber - getMinimumNumber();
	}

	int getMinimumNumber(){
		return minimumNumber;
	}

	void setMaximumNumber(){maximumNumber = findMaximumNumberFromArray();}
	void setMinimumNumber(){minimumNumber = findMinimumNumberFromArray();}
	
	void printNumbers(){
		NumberSorter::printNumbers();
	}

};

int main(){
	srand(time(0));
		
	int numbersSize = 2094901;
	int numbers[numbersSize];// = {3, 11, 14, 10, 11, 11, 10, 2, 4, 8};
	
	for(int i=0;i<numbersSize;i++){
		numbers[i] = rand()% 10001;
	}

	PigeonHoleSorter *p = new PigeonHoleSorter(numbers,numbersSize);
	p->printNumbers();
	p->sort();
	p->printNumbers();
	
	

}


















