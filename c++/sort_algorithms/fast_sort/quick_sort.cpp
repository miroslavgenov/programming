#include <iostream>
#include <vector>
using namespace std;



int search(vector<int> list,int value){
    for(int i=0;i<list.size();i++){
        if(list[i] == value){
            return i;
        }
    }
    return -1;
}

int size=13;

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

void quickSort(int numbers[],int left,int right){
    int pivot = numbers[(left+right)/2];
    int midIdx=(left+right)/2;


    int i=left,j=right;
    do{ 
        showNumbers(numbers,size);   
    while(numbers[i]<pivot){
        i++;
    }
    while(numbers[j]>pivot){
        j--;
    }
    if(i<=j){
        swapNumber(numbers[i],numbers[j]);
        i++;
        j--;
    }}while(i<=j);
    
    cout<<"i: "<<i<<" j: "<<j<<endl;
    if(j>left){
        quickSort(numbers,left,j);
    }
    cout<<"out rect1 j: "<<j<<" left: "<<left<<endl;
    cout<<"i: "<<i<<" j: "<<j<<endl;
    cout<<endl;
    if(i<right){
        quickSort(numbers,i,right);
    }
   
    
}


    

    
    
    
    


int main(){
    
    int numbers[size]{10,11,2,13,9,7,6,4,8,14,17,0,1};
    showNumbers(numbers,size);
    quickSort(numbers,0,::size-1);
    showNumbers(numbers,size);

    
    
    

    
    
    

}