#include <iostream>


void printNumbers(int [],int);
bool isPreviousNumberGreaterThanNext(int,int);
void swapNumber(int &, int &);
void insertionSort(int [],int );
    
int main(){
    constexpr int MAX_NUMBERS_SIZE = 7;
    int numbers[MAX_NUMBERS_SIZE]={12,82,43,56,8,6,9};

    insertionSort(numbers,MAX_NUMBERS_SIZE);

    printNumbers(numbers,MAX_NUMBERS_SIZE);

}
void printNumbers(int numbers[],int size){
    for(int value = 0;value <size;value++) 
        std::cout<< numbers[value]<<" ";
}
bool isPreviousNumberGreaterThanNext(int previousNumber,int nextNumber){
    return previousNumber>nextNumber;
}
    

void swapNumber(int &previousNumber , int &nextNumber){
    int temporaryNumber = nextNumber;
    nextNumber = previousNumber;
    previousNumber = temporaryNumber;

}


void insertionSort(int numbers[],int MAX_NUMBERS_SIZE ){
    for(int nextNumberValue=1,prevNumberValue=0;nextNumberValue<MAX_NUMBERS_SIZE;nextNumberValue++,prevNumberValue++){
        
        if(isPreviousNumberGreaterThanNext(numbers[prevNumberValue],numbers[nextNumberValue])){
            swapNumber(numbers[prevNumberValue],numbers[nextNumberValue]);

            for(int currentNumber=nextNumberValue,previousNumber=prevNumberValue;previousNumber>-1;previousNumber--,currentNumber--){
                if(!isPreviousNumberGreaterThanNext(numbers[currentNumber],numbers[previousNumber])){
                    swapNumber(numbers[currentNumber],numbers[previousNumber]);
                }
              
            }
            
        }
        
    }
}