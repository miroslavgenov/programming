#include <iostream>
#include <vector>

using namespace std;

struct fraction{
	int nomerator;
	int denominator;
};

int maximumDenominator = 2;
vector<fraction*> usedFractions;

double getFractionToDecimal(fraction* sourceFraction){
	double fractionToDecimal = (double)sourceFraction->nomerator / (double)sourceFraction->denominator;
	return fractionToDecimal;
}


bool isMaximumUnitFractionAcceptable(fraction* maximumUnitFraction, fraction* targetFraction){
	double maximumUniFractionDecimal = getFractionToDecimal(maximumUnitFraction);
	double targetFractionDecimal = getFractionToDecimal(targetFraction);
	return maximumUniFractionDecimal <= targetFractionDecimal;
}

void printFraction(fraction* value){
	cout<<endl<<value->nomerator<<"/"<<value->denominator<<endl;
}

bool isMaximumDenominatorUsed(){
	for(int i=0;i<usedFractions.size();i++)	{
		if(maximumDenominator == usedFractions[i]->denominator){
			return 1;
		}
	}
	return 0;
}

void updateTargetFraction(fraction* targetFraction, fraction* lesserFraction){
	// cout<<"subtractFromFraction"<<endl;
	fraction * newGreaterFraction = new fraction{targetFraction->nomerator * lesserFraction->denominator , targetFraction->denominator * lesserFraction->denominator};
	fraction* newLesserFraction = new fraction{lesserFraction->nomerator * targetFraction->denominator, lesserFraction->denominator * targetFraction->denominator};
	// printFraction(newGreaterFraction);
	// printFraction(newLesserFraction);
	int newNomeratorForTargetFraction = newGreaterFraction->nomerator - newLesserFraction->nomerator;
	int newDenominatorForTargetFraction = newGreaterFraction->denominator;
	if(newDenominatorForTargetFraction % newNomeratorForTargetFraction == 0){
		newDenominatorForTargetFraction = newDenominatorForTargetFraction / newNomeratorForTargetFraction;
		newNomeratorForTargetFraction = 1;
	}
	targetFraction->nomerator = newNomeratorForTargetFraction;
	targetFraction->denominator = newDenominatorForTargetFraction;
	// printFraction(targetFraction);
}	
void printUsedFractions(){
	for(int i=0; i<usedFractions.size();i++){
		if(i<usedFractions.size()-1){
			cout<<usedFractions[i]->nomerator<<"/"<<usedFractions[i]->denominator<<" + ";		
		}else if(i == usedFractions.size()-1){
			cout<<usedFractions[i]->nomerator<<"/"<<usedFractions[i]->denominator<<endl;					
		}
	}
}

fraction* rootFraction = new fraction{65, 67};


void egyptianFraction(fraction * targetFraction){
	if(targetFraction->nomerator == 1){
		cout<<"egymptianFraction is found"<<endl;
		usedFractions.push_back(targetFraction);
		
		cout<<rootFraction->nomerator<<"/"<<rootFraction->denominator<<" = ";
		printUsedFractions();
		return;
	}else{
		fraction* maximumUnitFraction = new fraction {1,::maximumDenominator};
		
		if(isMaximumUnitFractionAcceptable(maximumUnitFraction, targetFraction)){
			// cout<<"the maximumUnitFraction: "<<maximumUnitFraction->nomerator<<"/"<<maximumUnitFraction->denominator<<" is accpetable"<<endl;
			updateTargetFraction(targetFraction, maximumUnitFraction);
			usedFractions.push_back(maximumUnitFraction);
			maximumDenominator++;
			egyptianFraction(targetFraction);
			
		}
		else{
			// cout<<"the maximumUnitFraction: "<<maximumUnitFraction->nomerator<<"/"<<maximumUnitFraction->denominator<<" is not accpetable"<<endl;
			// cout<<"maximumUniFraction is not acceptable find new one"<<endl;
			maximumDenominator++;
			egyptianFraction(targetFraction);
		}
		
	}
}


int main(){
	int nomerator = rootFraction->nomerator;
	int denominator = rootFraction->denominator;
	fraction *targetFraction = new fraction{nomerator, denominator};

	egyptianFraction(targetFraction);



}
