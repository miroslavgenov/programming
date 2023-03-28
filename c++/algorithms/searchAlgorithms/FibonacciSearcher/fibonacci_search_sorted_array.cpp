#include <iostream>

using namespace std;

// DON'T UNDERSTAND HOW FIBONACI SEARCH WORKS

const int size_fib_seq=20;
int arr_fib_seq[size_fib_seq];

void print(int arr[],int size){
	for(int i=0;i<size;i++)cout<<arr[i]<<" ";
}

void set_fib_list(int size,int n,int p,int a[],int i=0){	
	if(size==0)return;
	int temp=n+p;
	
	a[i++]=p;
	p=n;
	n=temp;
	
	set_fib_list(--size,n,p,a,i);
	
}

int get_greater_or_equal_to_the_given_value(int a[],int l,int r,int v){
	int m=(l+r)/2;
	if(l<=r){
		
		if(a[m]==v){return m;
		}else if(a[m]>v){
			get_greater_or_equal_to_the_given_value(a,l,m-1,v);
		}else if(a[m]<v){
			get_greater_or_equal_to_the_given_value(a,m+1,r,v);
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
	return get_greater_or_equal_to_the_given_value(::arr_fib_seq,0,::size_fib_seq-1,array_size);
}

// finds the number
void fib_find(int fm2,int fm1,int fm,int offset,int i,int arr[],int v){
	cout<<"fm2: "<<fm2<<" fm1: "<<fm1<<" fm: "<<fm<<" offset: "<<offset<<" i:"<<i<<" v: "<<v<<endl;
	int prev=0;
	if(fm>1){
		cout<<"arr[i]: "<<arr[i]<<endl;
		if(arr[i]==v){
			cout<<"arr[i]: "<<arr[i]<<" v: "<<v<<endl;
			cout<<"found"<<endl;
			return;	
		}else if(arr[i]<v){
			cout<<arr[i]<<" < "<<v<<endl;
			cout<<"fm2: "<<fm2<<" fm2-1: "<<::arr_fib_seq[fm2-1]<<endl;
			prev=fm1;
			fm1=arr_fib_seq[fm2];
			fm=prev;
			fm2=::arr_fib_seq[fm2-1]	;
			cout<<"offset: "<<offset<<" i: "<<i<<endl;
			offset=i;
			cout<<"offset: "<<offset<<endl;
			i=offset+fm2;
			cout<<"i: "<<i<<endl;
			cout<<"fm2: "<<fm2<<" fm1: "<<fm1<<" fm: "<<fm<<" offset: "<<offset<<" i:"<<i<<" v: "<<v<<endl;
			
			fib_find(fm2,fm1,fm,offset,i,arr,v);
			
//			cout<<"arr_fib_seq[fm2-1]: "<<::arr_fib_seq[fm2]<<endl;
		}else if(arr[i]>v){
			cout<<"arr[i]>v"<<endl;
			//TODO 
			

		}
	}else{
		return;
	}
}


void fib_search(int arr[],int size,int v){
	int index = find_first_greater_or_equal_number_to_arary_size_and_return_index(size-1);
	int fibM=arr_fib_seq[index];
	int fibMm1=arr_fib_seq[index-1];
	int fibMm2=arr_fib_seq[index-2];
	int offset=1;
	int i  = fibMm2-offset;
	
	cout<<"arr size: "<<size<<" fib index: "<<index<<" fibM: "<<fibM<<" fibMm2: "<<fibMm2<<" fibMm1: "<<fibMm1<<" offset: "<<offset<<" i: "<<i<<endl;
	
	
	fib_find(fibMm2,fibMm1,fibM,offset,i,arr,v);
}




int main(){
    int a[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    constexpr int s = sizeof(a)/sizeof(*a);
    const int size=10;
	int arr[size]{1,2,3,4,5,6,7,8,9,10};
	int v=2;
	
	fib_search(arr,size,v);	
}