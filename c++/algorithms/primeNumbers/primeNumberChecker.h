#pragma once
#include "nullptrChecker.h"
#include "naturalNumber.cpp"



class PrimeNumberChecker{
private:
	const int NUMBER_TWO = 2;
	int* number;

public:
	PrimeNumberChecker(int number);

	PrimeNumberChecker(NaturalNumber* );

	PrimeNumberChecker(NaturalNumber );

	~PrimeNumberChecker();
		
private:
	bool isNumberPrime(int number);

	bool isNumberPrime(NaturalNumber );
	
	bool isNumberPrime(NaturalNumber *);

public:
	bool isNumberPrime();

private:
	bool isNumberNotNullAndGreaterThanTwo();

	bool isTheNumberSuitableToContinueTheAlgorithm();
	
	bool isNumberGreatherThanTwo();
	
	bool isNumberDividable();
};

