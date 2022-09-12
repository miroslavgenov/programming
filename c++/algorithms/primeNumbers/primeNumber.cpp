#include <iostream>

const int NUMBER_TWO = 2;

bool isNumberPrime(int *source_number);
bool isNumberNotNullAndGreaterThanTwo(int *source_number);
bool isTheNumberSuitableToContinue(int *number);
bool isNumberNullptr(int *source_number);
bool isNumberGreatherThanTwo(int *source_number);
bool isNumberDividable(int source_number);

int main(){	
	int *number=new int(11);
	std::cout<<isNumberPrime(number);
}

bool isNumberPrime(int *source_number){
	return isNumberNotNullAndGreaterThanTwo(source_number) && !isNumberDividable(*source_number);
}

bool isNumberNotNullAndGreaterThanTwo(int *source_number){
	return isTheNumberSuitableToContinue(source_number);
}

bool isTheNumberSuitableToContinue(int *number){
	return !isNumberNullptr(number) && isNumberGreatherThanTwo(number);
}

bool isNumberNullptr(int *source_number){
	return source_number == nullptr;
}

bool isNumberGreatherThanTwo(int *source_number){
	return *source_number > NUMBER_TWO;
}

bool isNumberDividable(int source_number){
	for(int i = 2; i < source_number; i++){
		if(source_number%i == 0){
			 return true;	
		}
	}
	return false;
}





















































