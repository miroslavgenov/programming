#include <iostream>
#include <vector>
using namespace std;



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

void merge(int a[],int left,int right,int b[],int c[]){
	// todo in b compare the numbers from left to right and sort them as the previous exercise
	// then rewratite them it a[]
	//cout<<endl<<"merge"<<endl;

//	cout<<"rangeFrom: "<<left<<" rangeEnd: "<<right<<endl;

	for(int i=right;i>=0;i--)
		for(int j=left+1;j<=right;j++)
			if(a[j-1]>a[j])swap(a[j-1],a[j]);
	
//	for(int i=left;i<=right;i++)cout<<a[i]<<" ";
//	cout<<endl<<"merge end"<<endl;



}

void mergeSort(int a[],int left,int right,int b[],int c[]){
    if(left==right)return;
    int mid = (left+right)/2;
//    cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<endl;
//  cout<<" "<<a[left]<<"  "<<a[mid]<<" "<<a[right]<<endl;
    mergeSort(a,left,mid,b,c);
    
    mergeSort(a,mid+1,right,b,c);
    
    merge(a,left,right,b,c);
    
    

    
}

  
int main(){
    int arr[8]={7,6,1,3,5,4,8,2};
    int b[8],c[8];
    mergeSort(arr,0,sizeof(arr)/sizeof(*arr)-1,b,c);

    
    
    

    
    
    

}














