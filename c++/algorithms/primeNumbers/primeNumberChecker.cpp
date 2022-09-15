#include "primeNumberChecker.h"

PrimeNumberChecker::PrimeNumberChecker(int number){
	this->number = new int{number};
}

PrimeNumberChecker::PrimeNumberChecker(NaturalNumber* naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
}

PrimeNumberChecker::PrimeNumberChecker(NaturalNumber naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
}

PrimeNumberChecker::~PrimeNumberChecker(){
	delete this->number;
}

bool PrimeNumberChecker::isNumberPrime(int number){
	this->number = new int{number};
	return isNumberPrime();

}

bool PrimeNumberChecker::isNumberPrime(NaturalNumber naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
	return isNumberPrime();
}

bool PrimeNumberChecker::isNumberPrime(NaturalNumber * naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
	return isNumberPrime();
}

bool PrimeNumberChecker::isNumberPrime(){
	return isNumberNotNullAndGreaterThanTwo() && !isNumberDividable();
}

bool PrimeNumberChecker::isNumberNotNullAndGreaterThanTwo(){
		return isTheNumberSuitableToContinueTheAlgorithm();
	}

bool PrimeNumberChecker::isTheNumberSuitableToContinueTheAlgorithm(){
	return !NullptrChecker::isNumberNullptr(this->number) && isNumberGreatherThanTwo();
}

bool PrimeNumberChecker::isNumberGreatherThanTwo(){
	return *this->number > NUMBER_TWO;
}

bool PrimeNumberChecker::isNumberDividable(){
	for(int i = 2; i < *this->number; i++){
		 return *this->number%i == 0;	
	}
	return false;
}