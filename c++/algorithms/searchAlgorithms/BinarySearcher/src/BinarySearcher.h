#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/ArrayChecker.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberSearcher.h"


class BinarySearcher: NumberSearcher{
	int left = 0;
	int right;
	int mid;

public:
	BinarySearcher(int [], size_t);

	BinarySearcher(int [], size_t, int);

	int search(int);

	int search();
	
private:
	void binarySearchIndexOfFindThisNumber(int, int, int);
};