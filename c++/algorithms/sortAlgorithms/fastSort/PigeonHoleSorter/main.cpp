#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"


using namespace std;

class PigeonHoleSorter : NumberSorter{
	private:
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

	
	
	
private:

	void shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int *lesser){

	}	
	
public:
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
private:
	int getTheSuitablePigeonHoleIndexForTheCurrentNumber(int currentNumber){
		return currentNumber - getMinimumNumber();
	}

	int getMinimumNumber(){
		return minimumNumber;
	}

	void setMaximumNumber(){
		maximumNumber = NumberFinder::findMaximumNumberFromArray(numbers);
	}
	
	void setMinimumNumber(){
		minimumNumber = NumberFinder::findMinimumNumberFromArray(numbers);
	}
	
public:
	void printNumbers(){
		NumberSorter::printNumbers();
	}

};

int main(){
	srand(time(0));
		
	int numbersSize = 10; // = 2094901;
	int numbers[numbersSize] = {3, 11, 14, 10, 11, 11, 10, 2, 4, 8};
	// vector<int>  a ;
	
	// for(int i=0;i<numbersSize;i++){
	// 	a.push_back(numbers[i]);
	// }

	// cout<<NumberFinder::findMaximumNumberFromArray(a)<<endl;
	// cout<<NumberFinder::findMaximumNumberFromArray(numbers,numbersSize)<<endl;

	// for(int i=0;i<numbersSize;i++){
	// 	numbers[i] = rand()% 10001;
	// }

	// PigeonHoleSorter *p = new PigeonHoleSorter(numbers,numbersSize);
	// p->printNumbers();
	// p->sort();
	// p->printNumbers();
	
	

}


















