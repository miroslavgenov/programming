#include "perfect_number.h"
#include <iostream>

void set_perfect_number_dividers_size(int val){
	perfect_number_dividers_list_size=val;
}

int get_perfect_number_dividers_size(){
	return perfect_number_dividers_list_size;
}

void print_perfect_nuber_dividers_list(int arr[],int size){
	for(int i=0;i<size+1;i++){
		std::cout<<arr[i]<<" ";
	}
}

void set_perfect_number_dividers_list(int arr[],int perfect_number){
	set_perfect_number_dividers_size(0);
	int count=0;
	for(int i=1;i<perfect_number;i++)
			if(perfect_number%i==0){
				arr[count]=i;
				set_perfect_number_dividers_size(count++);
			}
}

int get_sum_of_perfect_number_dividers_list(int arr[],int size){
	int sum=0;
	for(int i=0;i<size+1;i++)
		sum=(sum,sum+arr[i]); // sum+=arr[i];
		
	return sum;
	
}

bool is_number_acceptable(int *number_source){
	if(*number_source<6 || number_source==nullptr || sizeof(*number_source)!=4)return false;
	return true;
}

bool is_two_numbers_equal(int first_number,int second_number){
	return first_number==second_number;
}

bool is_number_perfect(int *number_perfect){
	
	if(!is_number_acceptable(number_perfect)){
		return false;
	}else{
		
		int number_perfect_dividers_list[]{};
		set_perfect_number_dividers_list(number_perfect_dividers_list,*number_perfect);
		int sum=get_sum_of_perfect_number_dividers_list(number_perfect_dividers_list,get_perfect_number_dividers_size());
		
		return is_two_numbers_equal(sum,*number_perfect);
	}
	return false;
	
}

