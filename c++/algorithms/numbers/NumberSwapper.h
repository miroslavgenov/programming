#pragma once

class NumberSwapper{
public:
	static void swapTwoNumbersValue(int* firstNumber,int *secondNumber){
		int *temporarayNumberValue = new int{*firstNumber};
		*firstNumber = *secondNumber;
		*secondNumber = *temporarayNumberValue;
		
		delete temporarayNumberValue;
	}
};