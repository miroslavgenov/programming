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

bool linear_search_unsorted_array(int array_number[],size_t ARRAY_SIZE,int searched_value ){
	try{
		if(ARRAY_SIZE>100 || ARRAY_SIZE<2){
			throw MyException("Array size is out of range 2<size<100");
		}else{
		
	
	for(size_t i=0 ; i<ARRAY_SIZE;i++){
		if(array_number[i]==searched_value) return true;
	}return false;}
	
	}catch(MyException e){
		cout<<e.what()<<endl;
	}return false;
	
	
}

int main(){
    int array_number[]={10,5,1,2,3,6,4,7,8,9};
    
    constexpr int SIZE_ARRAY = sizeof(array_number)/sizeof(*array_number);
	int searched_number=4;
	cout<<linear_search_unsorted_array(array_number,SIZE_ARRAY,searched_number)<<endl;
}




























































