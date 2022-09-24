#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;



void print(int a[], int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

    

void print(int numbers[],int from, int size){
    for(int i=from;i<size;i++){
        cout<<numbers[i]<<" ";
    }cout<<endl;
}




void fs(int numbers[],int left, int right){
    if(left>right){
        // cout<<"exit"<<endl;
        return;}


    int pivotIdx = (left+right) / 2;
    // cout<<endl<<"start fs"<<endl;
    int pivotValue = numbers[pivotIdx];
    int i = left, j = right;
    // cout<<"left: "<<left<<" pivotIdx: "<<pivotIdx <<" right: "<<right<<endl;
    // cout<<"i: "<<i<<" j: "<<j<<endl;
    // cout<<"pivotValue: "<<pivotValue<<endl;

    // cout<<" while numbers[i] < pivotValue "<<endl;
    while(numbers[i] < pivotValue){
        // cout<<numbers[i]<<" < "<<pivotValue<<endl;
        i++;
    }
    // cout<<"after while numbers[i] < pivotValue "<<endl;
    // cout<<numbers[i]<<" !< "<<pivotValue<<endl;

    // cout<<"while(numbers[j] > pivotValue"<<endl;
    while(numbers[j] > pivotValue){
        // cout<<numbers[j]<<" > "<<pivotValue<<endl;
        j--;
    }
    // cout<<"after while numbers[j] > pivotValue "<<endl;
    // cout<<numbers[j] <<" !> "<<pivotValue <<endl;
    // cout<<"after finding greater from left and lesser from right"<<endl;
    // cout<<"i: "<<i<<" j: "<<j<<endl;
    // cout<<"swaping the numbers"<<endl;
    NumberSwapper::swapTwoNumbersValue(&numbers[i],&numbers[j]);
    i++;
    j--;
    // cout<<"i: "<<i<<" j: "<<j<<endl;
    fs(numbers,left,j);
    // cout<<"back track"<<endl;
    // cout<<"i: "<<i<<" j: "<<j<<endl;
    // cout<<"sorting the right"<<endl;
    
    // if(i<right){
        fs(numbers,i,right);
    // }



}   

int main(){  
    srand(time(0));
    size_t numbersSize = rand() % 50;
    
    int numbers[numbersSize];
    
    for(int i=0; i<numbersSize;i++){
        numbers[i] = rand() % 200;
    }
    
    
    
    print(numbers,numbersSize);
    fs(numbers,0,numbersSize-1);
    print(numbers,numbersSize);

}
