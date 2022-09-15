#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/primeNumbers/nullptrChecker.h"

using namespace std;

class NumberChecker{
public:
	static bool isNumberAcceptableForPerfectNumberCheckerAlgorithm(int *number_source){
		return *number_source >= 6 || !NullptrChecker::isNumberNullptr(number_source);
	}
};

class PerfectNumberChecker{
private:
	vector<int> numbersThatDevidesThePotetialPerfectNumber;
	int *potentialPerfectNumber = nullptr;
public:	
	~PerfectNumberChecker(){
		numbersThatDevidesThePotetialPerfectNumber.clear();
		delete potentialPerfectNumber;
	}
};

vector<int> numbersThatDevidesThePotetialPerfectNumber;
int *potentialPerfectNumber = nullptr;

bool isNumberAcceptableForPerfectNumberCheckerAlgorithm(int *number_source){
		return *number_source >= 6 || !NullptrChecker::isNumberNullptr(number_source);
}

void appendOnlyTheNumbersThatDevidesPotetialPerfectNumberToVector(){
	for(int number = 1 ;number < *potentialPerfectNumber; number++)	{
			if(*potentialPerfectNumber%number == 0)
				numbersThatDevidesThePotetialPerfectNumber.push_back(number);
		}
}

int getTheSumOfTheNumbersThatDevidesPotentialPerfectNumber(){
	int sumOfTheNumbersThatDevidesPotentialPerfectNumber = 0;
	for(int i = 0; i < numbersThatDevidesThePotetialPerfectNumber.size(); i++){
		sumOfTheNumbersThatDevidesPotentialPerfectNumber += numbersThatDevidesThePotetialPerfectNumber[i];
	}
	return sumOfTheNumbersThatDevidesPotentialPerfectNumber;
}

bool is_number_perfect(int number){
	potentialPerfectNumber = new int{number};
	if(!isNumberAcceptableForPerfectNumberCheckerAlgorithm(potentialPerfectNumber)){
		return false;
	}else{
		appendOnlyTheNumbersThatDevidesPotetialPerfectNumberToVector();
	}
	return *potentialPerfectNumber == getTheSumOfTheNumbersThatDevidesPotentialPerfectNumber();
}


int main(){
	
	int *number1=new int(6);
	
	cout<<is_number_perfect(*number1);
}






































