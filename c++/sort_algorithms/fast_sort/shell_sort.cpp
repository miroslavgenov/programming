#include <iostream>
using namespace std;

void printNumbers(int [],int);
bool isNumberGreaterThan(int,int);
void swapNumber(int &, int &);
void insertionSort(int [],int );
    
void swapNumberIfGreater(int &geraterNumber,int &lesserNumber){
    if(isNumberGreaterThan(geraterNumber,lesserNumber)){
        swapNumber(geraterNumber,lesserNumber);
    }                   
}


void sortBackWardWithStep(int i,int step,int numbers[]){

    for(int j=i;j>0;j-=step){
        if(j-step>=0){
            swapNumberIfGreater(numbers[j-step],numbers[j]);
        }
    }
}

void shellSort(int numbers[],int MAX_NUMBERS_SIZE,int step){
    while(step>0){
        
        for(int i=0;i<MAX_NUMBERS_SIZE;i++){
            if(i+step<MAX_NUMBERS_SIZE){
                if(numbers[i]>numbers[i+step]){
                    swapNumber(numbers[i],numbers[i+step]);
                    sortBackWardWithStep(i,step,numbers);                
                }
            }    
        }
        step=step/2;
    }
}

int main(){
    constexpr int MAX_NUMBERS_SIZE = 7;
    int numbers[MAX_NUMBERS_SIZE]={12,82,43,56,8,6,9};
    cout<<(int)MAX_NUMBERS_SIZE/2<<endl;
    int step = MAX_NUMBERS_SIZE/2;
    
    shellSort(numbers,MAX_NUMBERS_SIZE,step);
        
    
    


    printNumbers(numbers,MAX_NUMBERS_SIZE);

}
void printNumbers(int numbers[],int size){
    for(int value = 0;value <size;value++) 
        std::cout<< numbers[value]<<" ";
}
bool isNumberGreaterThan(int previousNumber,int nextNumber){
    return previousNumber>nextNumber;
}
    

void swapNumber(int &greaterNumber , int &lesserNumber){
    int temporaryNumber = lesserNumber;
    lesserNumber = greaterNumber;
    greaterNumber = temporaryNumber;

}


void insertionSort(int numbers[],int MAX_NUMBERS_SIZE ){

    for(int nextNumberValue=1,prevNumberValue=0;nextNumberValue<MAX_NUMBERS_SIZE;nextNumberValue++,prevNumberValue++){
        
        if(isNumberGreaterThan(numbers[prevNumberValue],numbers[nextNumberValue])){
            swapNumber(numbers[prevNumberValue],numbers[nextNumberValue]);

            for(int currentNumber=nextNumberValue,previousNumber=prevNumberValue;previousNumber>-1;previousNumber--,currentNumber--){
                if(!isNumberGreaterThan(numbers[currentNumber],numbers[previousNumber])){
                    swapNumber(numbers[currentNumber],numbers[previousNumber]);
                }
              
            }
            
        }
        
    }
}


















































