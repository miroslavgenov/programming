#include <iostream>
using namespace std;

const int NUMBER_TWO = 2;

class NaturalNumberController;

class NaturalNumber{
private:
	int number;
	friend NaturalNumberController;

public:
	NaturalNumber(int );

	friend std::ostream& operator<<(std::ostream&, const NaturalNumber&);
};

NaturalNumber::NaturalNumber(int number):number(number){}


std::ostream& operator<<(std::ostream& os ,const  NaturalNumber& naturalNumber){
	os<<naturalNumber.number;
	return os;
}

class NaturalNumberController{
public:
	static int getNaturaNumberNumber(NaturalNumber naturalNumberObject){
		return naturalNumberObject.number;
	}

	static int getNaturaNumberNumber(NaturalNumber* naturalNumberObject){
		return naturalNumberObject->number;
	}
};

class PrimeNumberChecker{
private:
	int* number;

public:
	PrimeNumberChecker(NaturalNumber* );
	
	PrimeNumberChecker(NaturalNumber );

	~PrimeNumberChecker();
		
	bool isNumberPrime(NaturalNumber );
	
	bool isNumberPrime(NaturalNumber *);
	 
	bool isNumberPrime();
		
private:
	bool isNumberNotNullAndGreaterThanTwo();

	bool isTheNumberSuitableToContinueTheAlgorithm();
	
	bool isNumberNullptr();
	
	bool isNumberGreatherThanTwo();
	
	bool isNumberDividable();
};

PrimeNumberChecker::PrimeNumberChecker(NaturalNumber* naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
}

PrimeNumberChecker::PrimeNumberChecker(NaturalNumber naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
}

PrimeNumberChecker::~PrimeNumberChecker(){
	delete this->number;
}

bool PrimeNumberChecker::isNumberPrime(NaturalNumber naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
	return isNumberPrime();
}

bool PrimeNumberChecker::isNumberPrime(NaturalNumber * naturalNumber){
	this->number = new int{NaturalNumberController::getNaturaNumberNumber(naturalNumber)};
	return isNumberPrime();
}

bool PrimeNumberChecker::isNumberPrime(){
	return isNumberNotNullAndGreaterThanTwo() && !isNumberDividable();
}

bool PrimeNumberChecker::isNumberNotNullAndGreaterThanTwo(){
		return isTheNumberSuitableToContinueTheAlgorithm();
	}

bool PrimeNumberChecker::isTheNumberSuitableToContinueTheAlgorithm(){
	return !isNumberNullptr() && isNumberGreatherThanTwo();
}

bool PrimeNumberChecker::isNumberNullptr(){
	return number == nullptr;
}

bool PrimeNumberChecker::isNumberGreatherThanTwo(){
	return *this->number > NUMBER_TWO;
}

bool PrimeNumberChecker::isNumberDividable(){
	for(int i = 2; i < *this->number; i++){
		 return *this->number%i == 0;	
	}
	return false;
}


int main(){	
	
	NaturalNumber *naturalNumber  = new NaturalNumber(5);
	PrimeNumberChecker *primeNumberChecker = new PrimeNumberChecker(naturalNumber);
	
	cout<<primeNumberChecker->isNumberPrime(naturalNumber)<<endl;


	
}























































