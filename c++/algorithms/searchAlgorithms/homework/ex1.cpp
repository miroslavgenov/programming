#include <iostream>
using namespace std;


void print(int arr[],int s){
	for(int i=0;i<s;i++)cout<<arr[i]<<" ";
}

void reverse_array(int src_arr[],int src_arr_size,int dst_arr[],int increment,const int ssrc_arr_size){
	if(src_arr_size==-1)return;
	dst_arr[increment]=src_arr[src_arr_size];
	reverse_array(src_arr,--src_arr_size,dst_arr,++increment,ssrc_arr_size);
	
	
	
	if(src_arr_size>-1){
		cout<<"arr[size]: "<<src_arr[src_arr_size]<<" dst_arr[i]: "<<dst_arr[src_arr_size]<<endl;
		src_arr[src_arr_size]=dst_arr[src_arr_size];
	}
	if(src_arr_size==ssrc_arr_size-2){
		src_arr[src_arr_size+1]=dst_arr[src_arr_size+1];
	}
	

}


int main(){
	
	int size=10;
	int arr[size]={1,2,3,4,5,6,7,8,9,10};
	int darr[size]{};
	reverse_array(arr,size-1,darr,0,size);
	print(arr,size);


}
