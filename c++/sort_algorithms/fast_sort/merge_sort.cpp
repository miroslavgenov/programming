#include <iostream>
#include <vector>
using namespace std;



void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";

    cout<<endl;
}

void swapNumber(int &greaterNumber , int &lesserNumber){
    int temporaryNumber = lesserNumber;
    lesserNumber = greaterNumber;
    greaterNumber = temporaryNumber;

}

void mergeSort(int numbers[],int left,int right,int a[],int b[]){
    
    
    int mid = (left+right)/2;
    if(left<right){
        cout<<numbers[mid]<<" mid: "<<mid<<" left: "<<left<<" right:"<<right<<endl;
        mergeSort(numbers,left,mid,a,b);
        
    }
    
}

  
int main(){
    int size=8;
    int numbers[size]{11,10,2,13,9,7,6,4};
    int a[size/2];
    int b[size/2];
    showNumbers(numbers,size);
    mergeSort(numbers,0,size-1,a,b);
    
    

    
    
    

    
    
    

}