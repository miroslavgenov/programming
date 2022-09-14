#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

struct number{
	int number;
	int range;
	// float fitness;
};

void bubbleSortOneDimentionArrayAscendingOrder(number* currentPopulation[], size_t currentPopulationSize){
	for(int i=0;i<currentPopulationSize;i++){
		for(int j=1;j<currentPopulationSize;j++){
			if(currentPopulation[j-1]->number > currentPopulation[j]->number){
				number* temp = nullptr;
				temp = new number{currentPopulation[j-1]->number,currentPopulation[j-1]->range};
				currentPopulation[j-1]  = new number{currentPopulation[j]->number,currentPopulation[j]->range};
				currentPopulation[j] = new number{temp->number,temp->range};
			}
		}
	}
}

void printGeneration(number* population[], size_t populationSize,int generationNumber,int rageToBePrinted){
	cout<<endl<<"Generation Number: "<<generationNumber<<endl;
	cout<<"top: "<<rageToBePrinted<<endl;
	for(int i=0;i<rageToBePrinted;i++){
		cout<<"child: "<<population[i]->number<<"  parent: "<<population[i]->range<<endl;
	}
}

void fillChildPopulationWithChildsFromHalfOfTheCurrentPopulation(number *childPopulation[], number* currentPopulation[], size_t currentPopulationSize){
	int childId=0;
	for(int i=0;i < currentPopulationSize/2 ;i++){	
		childPopulation[childId] = new number{rand()%+currentPopulation[i]->number, currentPopulation[i]->number};
		childId++;
		childPopulation[childId] = new number{rand()%+currentPopulation[i]->number, currentPopulation[i]->number};
		childId++;
	}	
}

void fillTheFirstGeneration(number* firstGeneration[],size_t generationSize){
	for(int i=0;i<generationSize;i++){
		firstGeneration[i] = new number;
		firstGeneration[i]->range = rand();
		firstGeneration[i]->number = rand()% firstGeneration[i]->range;
	}
	// fillTheFirstGeneration(currentPopulation,currentPopulationSize);
}
void sortGenerationAscendingOrder(number* generation[],size_t generationSize){
	bubbleSortOneDimentionArrayAscendingOrder(generation,generationSize);
}

void freeUpCurrentPopulation(number* currentPopulation[], size_t currentPopulationSize){
	for(int i=0;i<currentPopulationSize;i++) {
		delete currentPopulation[i];
		currentPopulation[i] = nullptr;
	}
}

void fillCurrentPopulationWithTheChilds(number* currentPopulation[], number* childPopulation[], size_t currentPopulationSize){
	for(int i=0;i<currentPopulationSize;i++){
		currentPopulation[i] = new number{childPopulation[i]->number,childPopulation[i]->range};
	}
}


void geneticNumberAlgorithmToFindTheZero(){
	srand(time(0));
	size_t currentPopulationSize = 9000;
	number *currentPopulation[currentPopulationSize];
	number* childPopulation[currentPopulationSize];
	int generationNumber = 0 ;
	int rageToBePrinted = 10;
	fillTheFirstGeneration(currentPopulation,currentPopulationSize);

	while(currentPopulation[0]->number != 0){
		sortGenerationAscendingOrder(currentPopulation,currentPopulationSize);
		generationNumber++;
		
		
		printGeneration(currentPopulation,currentPopulationSize,generationNumber,rageToBePrinted);
	
		
		fillChildPopulationWithChildsFromHalfOfTheCurrentPopulation(childPopulation,currentPopulation, currentPopulationSize);
		sortGenerationAscendingOrder(childPopulation,currentPopulationSize);
		
		// freeUpCurrentPopulation(currentPopulation,currentPopulationSize);
		for(int i=0;i<currentPopulationSize;i++) {
			delete currentPopulation[i]; 
			currentPopulation[i] = nullptr;
		}

		fillCurrentPopulationWithTheChilds(currentPopulation,childPopulation,currentPopulationSize);
		// freeUpCurrentPopulation(childPopulation, currentPopulationSize);	
		for(int i=0;i<currentPopulationSize;i++) {
			delete childPopulation[i]; 
			childPopulation[i] = nullptr;
		}

	}
	
	cout<<endl;
	printGeneration(currentPopulation,currentPopulationSize,++generationNumber,rageToBePrinted);

	for(int i=0;i<currentPopulationSize;i++) {
			delete currentPopulation[i]; 
			currentPopulation[i] = nullptr;
		}
for(int i=0;i<currentPopulationSize;i++) {
			delete childPopulation[i]; 
			childPopulation[i] = nullptr;
		}	
	
}


int main(){
geneticNumberAlgorithmToFindTheZero();
	

	
}
