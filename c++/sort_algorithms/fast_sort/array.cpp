#include <iostream>
using namespace std;

int main(){
	int size=3;
	int a[size]={5,1,6};
	int b[size];
	int left =0 ;
	int mid = (left+size-1)/2;
	int right = size-1;
	
	
	
		int l = left;
		int m = mid+1;
		int r = right;
		int z=left;
		while(l<=mid && m<=right){
			if(a[l]>a[m]){
				b[z]=a[m];
				m++;z++;
			}
			else{
				b[z]=a[l];
				l++;
				z++;
			}
			
		}
		while(l<=mid){
			b[z] = a[l];
			l++;z++;
		}
		while(m<=right){
			b[z]=a[m];
			m++;z++;
		}
		for(int i=left;i<=right;i++){
			a[i]=b[i];
			cout<<a[i]<<" ";
	}
		
		
	
	return 0;

}
























































