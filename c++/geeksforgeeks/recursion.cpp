#include <iostream>
using namespace std;

void printNos(int N){
	if(N>0){
		printNos(N-1);
		cout<<N<<" ";
	}	
}

void rec(int N){
	if(N>=1 && N<=100000){
		if(N==0){
			return;
		}
		rec(--N);
		cout<<N+1<<" ";
	}
}
int main(){
	printNos(10);
}
