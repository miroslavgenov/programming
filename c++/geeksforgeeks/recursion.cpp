#include <iostream>

using namespace std;

void printNos(int );
bool isNumberZero(int );
void rec(int );

int main(){
	printNos(10);
}

void printNos(int number){
	if(number>0){
		printNos(number-1);
		cout<<number<<" ";
	}	
}

void rec(int number){
	if(number>=1 && number<=100000){
		
		if(isNumberZero(number)){
			return;
		}

		rec(--number);
		cout<<number+1<<" ";
	}
}
bool isNumberZero(int number){
	return number==0;
}
