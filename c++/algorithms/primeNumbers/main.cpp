#include <iostream>
#include "primeNumberChecker.cpp"

using namespace std;

int main(){	
	
	NaturalNumber *naturalNumber  = new NaturalNumber(5);
	
	PrimeNumberChecker *primeNumberChecker = new PrimeNumberChecker(naturalNumber);
	PrimeNumberChecker *primeNumberChecker1 = new PrimeNumberChecker(4);
	
	cout<<primeNumberChecker->isNumberPrime()<<endl;
	cout<<primeNumberChecker1->isNumberPrime()<<endl;

	delete primeNumberChecker;
	delete primeNumberChecker1;

}























































