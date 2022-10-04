#pragma once
#include <iostream>

class Printer{
public:
	static void printNumbers(int numbers[], int numbersSize){
		for(int i = 0; i<numbersSize;i++){
			std::cout<<numbers[i]<<" ";
		}std::cout<<std::endl;
	}
};
