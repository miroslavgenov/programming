/**
 	!! not my aproach !!
 
 */


#include <iostream>
#include <vector>

using namespace std;

struct Fraction{
	int p;
	int q;
};

Fraction* createMaximumFractionFrom(Fraction *currentFraction){
	int maximumDenominator = ((double)(currentFraction->q+currentFraction->p)/(double)currentFraction->p);
	
	return new Fraction{1, maximumDenominator};
}

void makeNewFractionUsingCurrentFractionAndMaxFration(Fraction* currentFraction, Fraction *maximumFraction){
	
	currentFraction->p = currentFraction->p * maximumFraction->q - currentFraction->q;
	currentFraction->q = currentFraction->q * maximumFraction->q;
		
	if(currentFraction->q % currentFraction->p == 0){
		currentFraction->q = currentFraction->q / currentFraction->p;
		currentFraction->p = 1;
	}
	
}

vector<Fraction*>usedFractions;

bool isNumeratorOfCurrentFractionEqualsToOne(Fraction* currentFraction){
	return currentFraction->p == 1;
}

vector<Fraction*> findEgyptianFraction(Fraction* currentFraction){
	Fraction* maxFraction=nullptr;

	while(!isNumeratorOfCurrentFractionEqualsToOne(currentFraction)){
		maxFraction = createMaximumFractionFrom(currentFraction);
		usedFractions.push_back(maxFraction);
		makeNewFractionUsingCurrentFractionAndMaxFration(currentFraction,maxFraction);
	}

	usedFractions.push_back(currentFraction);

	return usedFractions;
}

int main(){	
	Fraction* currentFraction = new Fraction{7,8};
	
	findEgyptianFraction(currentFraction);
	
	for(int i=0;i<usedFractions.size();i++){
		cout<<usedFractions[i]->p<<" "<<usedFractions[i]->q<<endl;
	}
	


	
}
