#include "PrimeNumberChecker.h"

PrimeNumberChecker::PrimeNumberChecker(int number){
	this->number = new int{number};
}

PrimeNumberChecker::PrimeNumberChecker(int *number){
	this->number = new int{*number};
}

PrimeNumberChecker::~PrimeNumberChecker(){
	delete this->number;
}

bool PrimeNumberChecker::isNumberPrime(int number){
	this->number = new int{number};
	return isNumberPrime();
}

bool PrimeNumberChecker::isNumberPrime(){
	return NumberChecker::isNumberAcceptableForPrimeNumberCheckerAlgorithm(number) && !isNumberDividable();
}

bool PrimeNumberChecker::isNumberDividable(){
	for(int i = 2; i < *this->number; i++){
		 return *this->number%i == 0;	
	}
	return false;
}
