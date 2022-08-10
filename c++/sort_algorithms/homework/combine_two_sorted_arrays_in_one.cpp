#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void swapNumber(int *, int *);
void showNumbers(int [],int );
bool isNumberGreater(int *,int *);
void bubbleSortNumbers(int [],int );

bool isIndexLessThenArraySize(int index , int arraySize){
    return index<arraySize;
}

bool isNumberGreaterAndIndexSizeLessThanArraySize(int *greaterNumber , int *lesserNumber,int index,int arraySize){
    return isNumberGreater(greaterNumber,lesserNumber) && isIndexLessThenArraySize(index,arraySize);
}


void combineTwoArraysAndSortTheCombinedArrayInAscendingOrder(
    int firstArray[],int secondArray[],
    int firstArraySize,int secondArraySize,
    int combinedArray[],int combinedArraySize
){
    
    int firstArrayValue=0,secondArrayValue=0;
    
    for(int z=0;z<combinedArraySize;z++){
        if(isNumberGreaterAndIndexSizeLessThanArraySize(&secondArray[secondArrayValue],&firstArray[firstArrayValue],firstArrayValue,firstArraySize)){
            combinedArray[z]=firstArray[firstArrayValue];
            firstArrayValue++;
        }
        else if(
            isNumberGreaterAndIndexSizeLessThanArraySize(&firstArray[firstArrayValue],&secondArray[secondArrayValue],secondArrayValue,secondArraySize)){
            combinedArray[z]=secondArray[secondArrayValue];
            secondArrayValue++;
        }
    }
}

int main(){
    
    int firstArray[]={1,3,5,6,7};
    int secondArray[]={2,4,8};
    int firstArraySize = sizeof(firstArray)/sizeof(*firstArray);
    int secondArraySize =sizeof(secondArray)/sizeof(*secondArray);
    int combinedArraySize = (firstArraySize+secondArraySize);
    int combinedArray[combinedArraySize]{};

    
    combineTwoArraysAndSortTheCombinedArrayInAscendingOrder(
        firstArray,secondArray,firstArraySize,secondArraySize
        ,combinedArray,combinedArraySize
    );

    showNumbers(combinedArray,combinedArraySize);
   
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
}





























































