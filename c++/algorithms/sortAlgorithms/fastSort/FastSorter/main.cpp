#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

size_t numbersSize = 10;

void print(int a[], int s){
    for(int i=0;i<s;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}

    vector<int> lesserNumbers;
    vector<int> greaterNumbers;

bool isLeftSotered = false;

void print(int numbers[],int from, int size){
    for(int i=from;i<size;i++){
        cout<<numbers[i]<<" ";
    }cout<<endl;
}

void fs(int l,int r ,int numbers[]){
    lesserNumbers.clear();
    greaterNumbers.clear();
    int left =l;
    int right = r;
    int mid = (left+right)/2;
    int midNumberValue = numbers[mid];
    // cout<<"leftIdx: "<<left<<" midIdx: "<<mid<<" rightIdx: "<<right<<endl;
    
    int i=left,j=right;
    // do{
        while(numbers[i]<midNumberValue){
            i++;
        }
        while(numbers[j]>midNumberValue){
            j--;
        }
        cout<<numbers[i]<<" "<<numbers[mid]<<" "<<numbers[j]<<endl;
        // NumberSwapper::swapTwoNumbersValue(&numbers[i],numbers[j]);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    // }while(i<j);
    

    // move lesser numbers than mid value in lesserNumbers and greater in greaterNumbers
    // for(int i=0;i<right;i++){
    //     if(numbers[i]<numbers[mid]){
    //         lesserNumbers.push_back(numbers[i]);
    //     }
    //     else if(numbers[i]> numbers[mid]){
    //         if(mid != i){
    //             greaterNumbers.push_back(numbers[i]);
    //         }
            
    //     }
    // }


    // update the new array
    // for(int i=0;i<lesserNumbers.size();i++){
    
    //     numbers[i] = lesserNumbers[i];
    // }
    
    // numbers[lesserNumbers.size()] = midNumberValue;
    
    // for(int i=0, j = lesserNumbers.size()+1;i<greaterNumbers.size();i++,j++){
    //     numbers[j] = greaterNumbers[i];
    // }
    // cout<<l<<" "<<r<<endl;
    // print(numbers,left,right);

    // if(left < right){
        // fs(left,(left+right)/2,numbers);
    // }
    
    // if(mid < r-1){
        // fs(mid,r,numbers);
    // }    
}

int main(){  
    srand(time(0));

    
    int numbers[numbersSize] = {25,35,81,83,99,75,96,39,1,28};
    
    // for(int i=0; i<numbersSize;i++){
    //     numbers[i] = rand()% 100;
    // }
    
    print(numbers,numbersSize);
    fs(0,numbersSize,numbers);
    print(numbers,numbersSize);
    
    // if(ns == 1){
    //     cout<<"ns == 1 can't compare only one number.Left part is done"<<endl; 
    // }
    

    // returning
    


    
    

    

}
