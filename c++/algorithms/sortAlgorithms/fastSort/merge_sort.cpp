#include <iostream>
#include <vector>
using namespace std;

void swapNum(int &,int &);
bool isGreater(int ,int);


void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";

    cout<<endl;
}

void swap(int &greaterNumber , int &lesserNumber){
    int temporaryNumber = lesserNumber;
    lesserNumber = greaterNumber;
    greaterNumber = temporaryNumber;

}


	
  void merge(int numbers[],int b[], int left,int right){
    int i = left;
    int mid = (left+right)/2;
    int j = mid+1;
    int k = left;
    while(i<=mid && j<=right){
        if(numbers[i]> numbers[j]){
            b[k] = numbers[j];
            k++;
            // cout<<numbers[j]<<" ";
            j++;
        }
        if(numbers[j] > numbers[i]){
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


void mergeSort(int a[],int left,int right,int b[]){

    if(left==right)return;
    int mid = (left+right)/2;

    mergeSort(a,left,mid,b); 
    mergeSort(a,mid+1,right,b);
    merge(a,b,left,right);

    
    
    
    
    

    
}

  
int main(){
    int size=9;
    int arr[size]={7,6,1,3,5,4,8,2,9};
    int b[size];
    mergeSort(arr,0,size-1,b);
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";
    
    
    

    
    
    

}
void swapNum(int &greater,int &less){
    int temp = greater;
    greater=less;
    less=temp;
}
bool isGreater(int greater ,int less){
    return greater>less;
}













