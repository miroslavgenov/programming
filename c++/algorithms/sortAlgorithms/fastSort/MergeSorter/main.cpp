#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;



void print(int n[], int s){
    for(int i=0;i<s;i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
}


  void merge(int numbers[],int b[], int left,int right){
    int i = left;
    int mid = (left+right)/2;
    int j = mid + 1;
    int k = left;

    while(i<=mid && j<=right){
        if(numbers[i]>= numbers[j]){
            b[k] = numbers[j];
            k++;
            // cout<<numbers[j]<<" ";
            j++;
        }
        if(numbers[j] >= numbers[i]){
            // cout<<numbers[i]<<" ";
            b[k] = numbers[i];
            k++;
            i++;
        }
    }

    while(i<=mid){
        // cout<<numbers[i]<<" ";
        b[k] = numbers[i];
        k++;
        i++;
    }
    while(j<=right){
        // cout<<numbers[j]<<" ";
        b[k] = numbers[j];
        k++;
        j++;
    }
    // cout<<endl;
    for(int i = left ; i<=right;i++){
        numbers[i] = b[i];
    }

	

}
    


void split(int numbers[], int b[], int left, int right){

        if(left == right){return;}
        int mid = (left+right)/2;
        // cout<<left<<" "<<right<<endl;
        split(numbers,b,left,mid);
        split(numbers,b,mid+1,right);
        merge(numbers,b,left,right);
}

int main(){
    srand(time(0));
    size_t numbersSize  = 1000000;
    int numbers[numbersSize];// = {9,20,10,1,10,2,3,4,5,6};
    for(int i=0;i<numbersSize;i++) numbers[i] = rand();
    
    int b[numbersSize];
    split(numbers,b,0,numbersSize-1);


    print(b,numbersSize);
    
    


    

}
