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
		return *number > NUMBER_TWO;
	}
};