#include <iostream>
using namespace std;

void b(int a[],int l,int m,int r,int v){

	
	if(l<=r){
		if(a[m]==v) {
			cout<<a[m]<<" "<<"found"<<endl;
		return;
	}
	if(a[m]>v){
		b(a,l,(l+m)/2,m-1,v);


		

	}
	if(a[m]<v){
		b(a,m+1,(m+r)/2,r,v);


		
	}
	}else return;
	
	
}


int main(){
    int array_numbers[]={0, 1 ,2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int SIZE_ARRAY = sizeof(array_numbers)/sizeof(*array_numbers);
	int searched_number=13;
	
		
		b(array_numbers,0,(0+SIZE_ARRAY)/2,SIZE_ARRAY,searched_number);
	
	
	
	
	
}




























































