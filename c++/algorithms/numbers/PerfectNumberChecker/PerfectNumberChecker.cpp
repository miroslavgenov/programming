#include "PerfectNumberChecker.h"

PerfectNumberChecker::PerfectNumberChecker(int number){
    this->potentialPerfectNumber = new int{number};
}

PerfectNumberChecker::~PerfectNumberChecker(){
    numbersThatDevidesThePotetialPerfectNumber.clear();
    delete potentialPerfectNumber;
}

bool PerfectNumberChecker::isNumberPerfect(){
	if(!NumberChecker::isNumberAcceptableForPerfectNumberCheckerAlgorithm(potentialPerfectNumber)){
		return false;
	}else{
		appendToVectorOnlyTheNumbersThatDevidesPotetialPerfectNumber();
	}
	return *potentialPerfectNumber == getTheSumOfTheNumbersThatDevidesPotentialPerfectNumber();
}


void PerfectNumberChecker::appendToVectorOnlyTheNumbersThatDevidesPotetialPerfectNumber(){
	for(int number = 1 ;number < *potentialPerfectNumber; number++)	{
		if(*potentialPerfectNumber%number == 0){
			numbersThatDevidesThePotetialPerfectNumber.push_back(number);
		}
	}
}

int PerfectNumberChecker::getTheSumOfTheNumbersThatDevidesPotentialPerfectNumber(){
	int sumOfTheNumbersThatDevidesPotentialPerfectNumber = 0;
	for(int i = 0; i < numbersThatDevidesThePotetialPerfectNumber.size(); i++){
		sumOfTheNumbersThatDevidesPotentialPerfectNumber += numbersThatDevidesThePotetialPerfectNumber[i];
	}
	return sumOfTheNumbersThatDevidesPotentialPerfectNumber;
}
