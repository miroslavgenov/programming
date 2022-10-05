#pragma once

#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberSearcher.h"

class LinearSearcher:NumberSearcher{
public:
	LinearSearcher(int [], size_t);
	
	LinearSearcher(int[], size_t, int);
	
	int linearSearchIndexOfFindThisNumberWithArrayShiftByOneToRightAndMakeTheFoundNumberFirst(int);

	int linearSearchIndexOfFindThisNumber();

	int linearSearchIndexOfFindThisNumberBackwards(int, int);
};