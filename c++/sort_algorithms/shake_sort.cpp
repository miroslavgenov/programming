#include <iostream>
using namespace std;

void swapNumber(int *, int *);
void showNumbers(int [],int );
bool isNumberGreater(int *,int *);


void shakeSort(int numbers[],int NUMBERS_SIZE){
    int lastSwapIndex =0;
    int countSwap =0;
    int sizeNumbers = NUMBERS_SIZE;
    int reverseSize =-1;

    do{
        countSwap=0;

    
    for(int i=1;i<sizeNumbers;i++){
        if(numbers[i-1]>numbers[i]){
            swapNumber(&numbers[i-1],&numbers[i]);
            lastSwapIndex=i;
            countSwap++;
        }
    }
    
    sizeNumbers--;
    if(countSwap==0)break;

    for(int i=lastSwapIndex-1,j=i-1;j>reverseSize;i--,j--,reverseSize++){
    
        if(numbers[i]<numbers[j]){
            swapNumber(&numbers[j],&numbers[i]);
            countSwap++;
        }

    }
    
        if(countSwap==0)break;
    
    }while(countSwap!=0);
}

int main(){
    constexpr int NUMBERS_SIZE = 7;
    int numbers[NUMBERS_SIZE] ={81,12,43,56,8,6,1} ;


    shakeSort(numbers,NUMBERS_SIZE);
    
    showNumbers(numbers,NUMBERS_SIZE);
}
    


bool isNumberGreater(int *greaterNumber,int *lesserNumber){
    return *greaterNumber>*lesserNumber;
}

void swapNumber(int *greaterNumber , int *lesserNumber){
    int temporaryNumber = *lesserNumber;
    *lesserNumber=*greaterNumber;
    *greaterNumber = temporaryNumber;
}



void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";

    cout<<endl;
}



















