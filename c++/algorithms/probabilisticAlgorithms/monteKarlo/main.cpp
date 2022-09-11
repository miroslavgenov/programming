#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

bool isNumberPrime=false;

void checkIfNumberIsPrimeAndSetIsNumberPrime(int number, int i){
	if(number == i){
		isNumberPrime = true;
		return;
	}else{
		if(number % i == 0){
			isNumberPrime = false;
			return ;
		}
		checkIfNumberIsPrimeAndSetIsNumberPrime(number,i+1);
	}
}

void printIsRandomGeneratedNumberAPrime(int number){
	if(isNumberPrime == true){
		cout<<"Yes the number: "<<number<<" is prime"<<endl;
		return;
	}
	cout<<"No the number: "<<number<<" is not prime"<<endl;
}

void monteKarlo(){
	srand(time(0));
	int randomGeneratedNumber = rand();
	checkIfNumberIsPrimeAndSetIsNumberPrime(randomGeneratedNumber, 2);
	printIsRandomGeneratedNumberAPrime(randomGeneratedNumber);
}

int main(){
	monteKarlo();

}
