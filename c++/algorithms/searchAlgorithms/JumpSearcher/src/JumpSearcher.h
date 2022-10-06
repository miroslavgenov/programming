#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/LinearSearcher/include/LinearSearcher.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/ArrayChecker.cpp"
#include <iostream>
#include <cmath>

class JumpSearcher:NumberSearcher{
	int jumpSize;

public:
	JumpSearcher(int [], size_t, int);

	JumpSearcher(int [], size_t);

	bool canYouJumpSearch();

	int jumpSearch(int);
	
	int jumpSearch();
};
