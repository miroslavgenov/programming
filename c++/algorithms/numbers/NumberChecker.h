#pragma once
#include "NullptrChecker.h"

class NumberChecker{
	static const int NUMBER_TWO = 2;
public:
	static bool isNumberAcceptableForPerfectNumberCheckerAlgorithm(int *number){
		return *number >= 6 || !NullptrChecker::isNumberNullptr(number);
	}
	static bool isNumberAcceptableForPrimeNumberCheckerAlgorithm(int *number){
		return !NullptrChecker::isNumberNullptr(number) && isNumberGreatherThanTwo(number);
	}
	
	static bool isNumberGreatherThanTwo(int *number){
		return isTheNumberGreaterThan(number, new int{NUMBER_TWO});
		
	}

	static bool isTheNumberGreaterThan(int *firstNumber, int* secondNumber){
		return *firstNumber > *secondNumber;
	}

	static bool isTheNumberGreaterOrEqual(int firstNumber, int secondNumber){
		return firstNumber >= secondNumber;
	}

	static bool isTheNumberLesserOrEqual(int firstNumber, int secondNumber){
		return firstNumber <= secondNumber;
	}

};