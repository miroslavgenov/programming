#include <iostream>
using namespace std;

void print(int [],int);

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


void sort(int a[],int s){
	
	for(int i=0,j=1;j<s;j++,i++){
	    if(a[i]>a[j]){
	        swap(a[i],a[j]);
	    }        
		if(a[i]<a[j]){
			// backwards compare and insert
			for(int z=i,q=i-1;z>=1 && q>=0 ;z--,q--){
				if(a[q]>a[z]){
					swap(a[z],a[q]);					
					continue;
				}
			}
	            
	    }
	}
}

void insertion_sort(int a[],int n){
	
}

int main(){
    int s=7;
    int a[s]{81,12,43,56, 8,6,9};
	
    sort(a,s);
     print(a,s);
    
}
void print(int a[],int s){cout<<endl;for(int i=0;i<s;i++) cout<<a[i]<<" ";cout<<endl;}













































