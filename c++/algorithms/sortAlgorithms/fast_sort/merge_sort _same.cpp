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

void merge(int a[],int left,int mid,int right,int b[]){
	
    int l = left;
	int m = mid+1;
	int r = right;
	int z=left;
    cout<<"merger"<<endl;
    for(int i=left;i<=right;i++)cout<<a[i]<<' ';
    cout<<endl;
	while(l<=mid && m<=right){
		
		cout<<"l<=mid && m<=right"<<endl;
		cout<<l<<' '<<mid<<' '<<m<<' '<<right<<endl;
		if(a[l]>a[m]){
			cout<<"a[l]>a[m]"<<endl;
			cout<<a[l]<<" "<<a[m]<<endl;
			b[z]=a[m];
			m++;z++;
		}
		else{
			cout<<"a[l]<a[m]"<<endl;
			cout<<a[l]<<" "<<a[m]<<endl;
			b[z++]=a[l++];
			
		}
		
	}
	while(l<=mid){
		cout<<"l<=mid"<<endl;
		cout<<l<<' '<<mid<<endl;
		cout<<a[l]<<endl;
		b[z] = a[l];
		l++;z++;
	}
	while(m<=right){
		cout<<"m<=right"<<endl;
		cout<<m<<" "<<right<<endl;
		cout<<a[m]<<endl;
		b[z]=a[m];
		m++;z++;
	}
    for(int i=left;i<=right;i++){
        a[i]=b[i];
        cout<<b[i]<<" ";
    }cout<<endl;
    cout<<"merger end"<<endl<<endl;
	
	
	
	
	

}


void mergeSort(int a[],int left,int right,int b[]){
    if(left==right)return;
    int mid = (left+right)/2;
//    cout<<"left: "<<left<<" mid: "<<mid<<" right: "<<right<<endl;
//  cout<<" "<<a[left]<<"  "<<a[mid]<<" "<<a[right]<<endl;
    mergeSort(a,left,mid,b);
    
    mergeSort(a,mid+1,right,b);
    if(left+1==right){
    	if(a[left]>a[right])swap(a[left],a[right]);
	}
    merge(a,left,mid,right,b);
    
    
    
    
    
    

    
}

  
int main(){
    int size=9;
    int arr[size]={7,6,1,3,5,4,8,2,9};
    int b[size]{};
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













