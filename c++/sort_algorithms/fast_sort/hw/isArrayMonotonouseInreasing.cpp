#include <iostream>

using namespace std;

bool isNumbersEqual(int , int );
bool isArrayMonotonouseIncreasing(int [], int );

int main(){
	int size=10;
	int a[size]={2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	
	cout<<isArrayMonotonouseIncreasing(a, size);
}

bool isArrayMonotonouseIncreasing(int a[], int size){
	for(int i=0, j=a[0]; i < size; i++ ,j++){
		if(!isNumbersEqual(a[i], j)){
			return 0;
		}
	}
	return 1;
}
 
bool isNumbersEqual(int numberOne, int numberSecond){
	return numberOne == numberSecond;
}





























































