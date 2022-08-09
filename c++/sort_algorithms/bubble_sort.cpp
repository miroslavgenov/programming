#include <iostream>
using namespace std;

void swapNumber(int *, int *);
void showNumbers(int [],int );
bool isNumberGreater(int *,int *);
void bubbleSortNumbers(int [],int );

int main(){
    constexpr int NUMBERS_SIZE = 7;
    int numbers[NUMBERS_SIZE] ={81,12,43,56,8,6,1} ;

    bubbleSortNumbers(numbers,NUMBERS_SIZE);

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

void bubbleSortNumbers(int numbers[],int NUMBERS_SIZE)
{
    for(int i=NUMBERS_SIZE;i>0;i--)
        for(int j=1;j<i;j++)
            if(isNumberGreater(&numbers[j-1],&numbers[j]))
                swapNumber(&numbers[j-1],&numbers[j]);
}


void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";
}



















