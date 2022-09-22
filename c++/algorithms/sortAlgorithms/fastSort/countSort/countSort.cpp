#include <iostream>

using namespace std;

int getMinNumberFromArray(int a[], int size){
	int minNumber = a[0];
	
	for(int i=0; i < size; i++){
		if(minNumber > a[i]){
			minNumber = a[i];
		}
	}
	return minNumber;
}

int getMaxNumberFromArray(int a[],int size){
	int maxNumber = a[0];
	
	for(int i=0; i < size; i++){
		if(maxNumber < a[i]){
			maxNumber = a[i];
		}
	}
	return maxNumber;
}

int main(){

    int size = 10;
    int numbers[size] = {2, 9, 6, 3, 4, 4, 8, 10, 1, 1};

    int minNumber = getMinNumberFromArray(numbers, size);
    int maxNumber = getMaxNumberFromArray(numbers ,size);
	
	cout<<minNumber<<endl;
	cout<<maxNumber<<endl;
	
	
	int numbersS[size]{0};
	int index=0;
	for(int i=0;i<=size;i++){
		for(int j=0;j<size;j++){
			if(i==numbers[j]){
				numbersS[index]=i;
			}
		}
	}
    
    
    
    
}






























































