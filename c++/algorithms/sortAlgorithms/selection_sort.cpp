#include <iostream>
using namespace std;

void showNumbers(int [],int );

int getIndexOfMinumumNumberInNumbers(int numbers[],int NUMBERS_SIZE,int startPosition){
    int minimumNumberValue = numbers[startPosition];
    int minimumNumberIndex =startPosition;
    for(int i=startPosition;i<NUMBERS_SIZE;i++){
        
        if(minimumNumberValue>numbers[i])
        {
            minimumNumberValue = numbers[i];
            minimumNumberIndex=i;
        }

    }
    return minimumNumberIndex;

}

void swapNumber(int *greaterNumber , int *lesserNumber){
    int temporaryNumber = *lesserNumber;
    *lesserNumber=*greaterNumber;
    *greaterNumber = temporaryNumber;
}


int main(){
    constexpr int NUMBERS_SIZE = 7;
    int numbers[NUMBERS_SIZE] ={81,12,43,56,8,6,1} ;

    for(int i=0;i<NUMBERS_SIZE;i++){
        int minimumNumber = getIndexOfMinumumNumberInNumbers(numbers,NUMBERS_SIZE,i);
        int minimumNumberIndex = getIndexOfMinumumNumberInNumbers(numbers,NUMBERS_SIZE,i);
        if(numbers[i]>minimumNumber){
            swapNumber(&numbers[i],&numbers[minimumNumberIndex]);
        }
        
    }
    

    showNumbers(numbers,NUMBERS_SIZE);
}



void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";
}
