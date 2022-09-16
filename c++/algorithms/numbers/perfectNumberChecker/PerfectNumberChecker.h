#pragma once
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/numbers/NumberChecker.h"

class PerfectNumberChecker{
private:
	std::vector<int> numbersThatDevidesThePotetialPerfectNumber;
	int *potentialPerfectNumber = nullptr;

public:	
	PerfectNumberChecker(int );

	~PerfectNumberChecker();

	bool isNumberPerfect();
	
private:
	void appendToVectorOnlyTheNumbersThatDevidesPotetialPerfectNumber();

	int getTheSumOfTheNumbersThatDevidesPotentialPerfectNumber();
};
