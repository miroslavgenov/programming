#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include <ctime>
#include <cstdlib>

using namespace std;

size_t numbersSize = 10;

void print(int a[], int s){
    cout<<endl;
    for(int i=0;i<s;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
void fs(int l,int r ,int numbers[]){
    if(l<r){

    
    int left = l;
    int right = r;
    int mid = (left+right)/2;
    // cout<<left<<" "<<mid<<" "<<right<<endl;
    // print(numbers,r+1);

    // cout<<left<<" "<<mid<<" "<<right<<endl;
    // cout<<numbers[left]<<" "<<numbers[mid]<<" "<<numbers[right]<<endl;

    int i=left;
    int j = right;
    

    do{
    while(numbers[i] < numbers[mid]){
        i++;
    }
    
    while(numbers[j]>numbers[mid]){
        j--;
    }
    NumberSwapper::swapTwoNumbersValue(&numbers[i],&numbers[j]);
    
    }
    while(i<j);
    // print(numbers,numbersSize);
    // cout<<left<<" "<<mid<<" "<<right<<endl;
    
    
    
    

    }else{
        return;
    }
}

int main(){  
    srand(time(0));

    
    int numbers[numbersSize];
    
    for(int i=0; i<numbersSize;i++){
        numbers[i] = rand()% 100;
    }
    print(numbers,numbersSize);
    fs(0,numbersSize-1,numbers);
print(numbers,numbersSize);
    
    

    

    // print(numbers,numbersSize);

    

}
