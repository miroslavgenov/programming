























#include <iostream>
using namespace std;

const int size_fib_seq=20;
int arr_fib_seq[size_fib_seq];

void set_fib_list(int size,int n,int p,int a[],int i=0){	
	if(size==0)return;
	int temp=n+p;
	
	a[i++]=p;
	p=n;
	n=temp;
	
	set_fib_list(--size,n,p,a,i);
	
}

int bs(int a[],int l,int r,int v){
	int m=(l+r)/2;
	if(l<=r){
		
		if(a[m]==v){return m;
		}else if(a[m]>v){
			bs(a,l,m-1,v);
		}else if(a[m]<v){
			bs(a,m+1,r,v);
		}
	}else return m+1;
}


	
void generate_fib(){	
	set_fib_list(size_fib_seq,1,0,arr_fib_seq);
}

void fib_seq_arr_init(){
	generate_fib();
}



int find_first_greater_or_equal_number_to_arary_size_and_return_index(int array_size){
	fib_seq_arr_init();
	return bs(::arr_fib_seq,0,::size_fib_seq-1,array_size);
}




int main(){
    int a[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    constexpr int s = sizeof(a)/sizeof(*a);
    const int size=10;
	int arr[size]{1,2,3,4,5,6,7,8,9,10};
	int index = find_first_greater_or_equal_number_to_arary_size_and_return_index(size-1);
	int fibM=arr_fib_seq[index];
	int fibMm1=arr_fib_seq[index-1];
	int fibMm2=arr_fib_seq[index-2];
	cout<<fibMm2<<" + "<<fibMm1<<" = "<<fibM<<endl;
	
	
	
	
	
	
	
}




























































