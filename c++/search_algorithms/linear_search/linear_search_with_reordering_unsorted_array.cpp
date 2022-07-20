#include <iostream>
using namespace std;

// if the number is found , then it will be send at [0] and the number at [0] will be send at [i]

bool linear_serach_with_reordering_unsorted_array(int array_numbers[],size_t SIZE_ARRAY,int searched_number){
	int temporary_number;
	
	for(int i=0;i<SIZE_ARRAY;i++)
		if(array_numbers[i]==searched_number){
			temporary_number=array_numbers[0];
			array_numbers[0]=array_numbers[i];
			array_numbers[i]=temporary_number;
			return true;
		}
	
	return false;
}

void print_array(int arr[],int SIZE){
	for(int i=0;i<SIZE;i++) cout<<arr[i]<<" ";
}


int main(){
    int array_numbers[]={10,11,13,14,15,16,18,19,20};
    
    constexpr int SIZE_ARRAY = sizeof(array_numbers)/sizeof(*array_numbers);
	
	int searched_number=15;
	linear_serach_with_reordering_unsorted_array(array_numbers,SIZE_ARRAY,searched_number);
	linear_serach_with_reordering_unsorted_array(array_numbers,SIZE_ARRAY,14);
	linear_serach_with_reordering_unsorted_array(array_numbers,SIZE_ARRAY,15);
	print_array(array_numbers,SIZE_ARRAY);
	
}




































































