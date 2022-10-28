#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/PigeonSorter/src/PigeonSorter.h"

PigeonHoleSorter::PigeonHoleSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize) {
	
		setMaximumNumber();
		setMinimumNumber();
		totalPigeonHolesRange = (maximumNumber - minimumNumber) + 1;		

		for(int i=0;i< totalPigeonHolesRange;i++){
			pigeonHoles.push_back({});
		}

	}

	void PigeonHoleSorter::setMaximumNumber(){
		maximumNumber = NumberFinder::findMaximumNumberFromUnsortedVector(numbers);
	}
	
	void PigeonHoleSorter::setMinimumNumber(){
		minimumNumber = NumberFinder::findMinimumNumberFromUnsortedVector(numbers);
	}
	
	

	

	void PigeonHoleSorter::sort(){
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


	int PigeonHoleSorter::getTheSuitablePigeonHoleIndexForTheCurrentNumber(int currentNumber){
		return currentNumber - getMinimumNumber();
	}

	int PigeonHoleSorter::getMinimumNumber(){
		return minimumNumber;
	}
