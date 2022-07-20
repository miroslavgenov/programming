#include <iostream>
using namespace std;


//bool linear_search(int arr[],size_t array_size,int searched_value ){
//	// lecture aproach
//	int i=0;
//	while(arr[i]<searched_value && i<array_size
//	){	i++;
//		if(arr[i]==searched_value)return true;
//		
//	}return false;
//	
//}

//bool linear_search(int arr[],size_t array_size,int searched_value ){
//	// my aproach
//	for(int i=0;i<array_size;i++)
//	
//		if(arr[i]==searched_value)return true;
//	return false;
//	
//}

int main(){
    int arr[]={10,11,13,14,15,16,18,19,20};
    
    constexpr int SIZE = sizeof(arr)/sizeof(*arr);
	int value=15;
	cout<<linear_search(arr,SIZE,value)<<endl;
}




























































