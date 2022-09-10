/**
 * @file sequentiallyEqualNumbers.cpp
 * @author Miroslav Genov
 * @brief Program that check if there is one equation of one
 * sequentionally equal numbers
 * @version 0.1
 * @date 2022-08-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

bool isThereSequantinallNumberWhitSameValue(int [], int );

int main(){
    int size=10;
    int a[size]={9,7,5,3,4,3,3,2,8,6};
	
	cout<<isThereSequantinallNumberWhitSameValue(a,size)<<endl;
}

bool isThereSequantinallNumberWhitSameValue(int a[], int size){
	for(int i = 1; i < size; i++)    {
		if(a[i-1] == a[i]){
			return 1;
		}
	}return 0;
}


























