#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NaturalNumber.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NullptrChecker.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class PrimeNumberChecker{
private:
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
	bool isNumberDividable();
};

