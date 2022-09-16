#include <iostream>
#include "perfectNumberChecker/PerfectNumberChecker.cpp"
#include "primeNumberChecker/PrimeNumberChecker.cpp"

using namespace std;

int main(){
    PerfectNumberChecker *perfectNumberChecker = new PerfectNumberChecker(6);
    cout<<perfectNumberChecker->isNumberPerfect()<<endl;

    PrimeNumberChecker *primeNumberChecker = new PrimeNumberChecker(5);
    cout<<primeNumberChecker->isNumberPrime()<<endl;


}