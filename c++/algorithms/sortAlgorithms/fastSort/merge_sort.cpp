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

void merge(int A[],int left,int mid,int right,int* B){
	
    int l = left;
	int m = mid+1;
	int r = right;
	int z=left;
	while(l<=mid && m<=right){
		if(A[l]>A[m]){
			B[z]=A[m];
			m++;z++;
		}
		else{
			B[z]=A[l];
			l++;
			z++;
		}
		
	}
	while(l<=mid){
		B[z] = A[l];
		l++;z++;
	}
	while(m<=right){
		B[z]=A[m];
		m++;z++;
	}
    for(int i=left;i<=right;i++){
        A[i]=B[i];
    }
	
	
	
	
	

}


void mergeSort(int a[],int left,int right,int *b){

    if(left==right)return;
    int mid = (left+right)/2;

    mergeSort(a,left,mid,b); 
    mergeSort(a,mid+1,right,b);
    merge(a,left,mid,right,b);

    
    
    
    
    

    
}

  
int main(){
    int size=9;
    int arr[size]={7,6,1,3,5,4,8,2,9};
    int *b = new int[size];
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













