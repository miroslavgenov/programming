#include <iostream>
using namespace std;

bool linear_search_sorted_desc_order(int array_numbers[],int SIZE_ARRAY,int searched_number,int step){
	
	for(int i=SIZE_ARRAY-1;i>=SIZE_ARRAY-step;i--) {
		if(array_numbers[i]==searched_number){
			return true; 
		}
	}
	return false;
	
}

bool search(int array_numbers[],int SIZE_ARRAY,int searched_number,int step){
	
	for(int increment=0;increment<=SIZE_ARRAY;increment+=step-1){
		if(array_numbers[increment]==searched_number)return 1;
		if(array_numbers[increment]>searched_number){
			bool result = linear_search_sorted_desc_order(array_numbers,increment,searched_number,step);
			if(result) return 1;
			return false;
		}
	}
	return 0;
}


int main(){
    int array_numbers[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    constexpr int SIZE_ARRAY = sizeof(array_numbers)/sizeof(*array_numbers);
	int step=sqrt(SIZE_ARRAY);
	int searched_number=55;
	
	cout<<search(array_numbers,SIZE_ARRAY,searched_number,step)<<endl;
	
}




























































