#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NullptrChecker.h"
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class PrimeNumberChecker{
private:
	int* number;

public:
	PrimeNumberChecker(int number);
	PrimeNumberChecker(int *number);
	~PrimeNumberChecker();
		
private:
	bool isNumberPrime(int number);

public:
	bool isNumberPrime();

private:
	bool isNumberDividable();
};

