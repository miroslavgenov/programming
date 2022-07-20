#include <iostream>
using namespace std;

class MyException{
	public:
		string msg;
	MyException(string _msg):msg(_msg){
	}
	
	string what()const{
		return msg;
	}
};

bool linear_search(int arr[],size_t array_size,int searched_value ){
	try{
		if(array_size>100 || array_size<2){
			throw MyException("Array size is out of range 2<size<100");
		}else{
		
	
	for(size_t i=0 ; i<array_size;i++){
		if(arr[i]==searched_value) return true;
	}return false;}
	
	}catch(MyException e){
		cout<<e.what()<<endl;
	}return false;
	
	
}

int main(){
    int arr[]={10,5,1,2,3,6,4,7,8,9};
    
    constexpr int SIZE = sizeof(arr)/sizeof(*arr);
	int value=4;
	cout<<linear_search(arr,SIZE,value)<<endl;
}




























































