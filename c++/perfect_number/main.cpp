#include <iostream>
#include "perfect_number.cpp"
using namespace std;


int main(){
	int* number=new int[3]{1,2,3};
	int *number1=new int(6);
	
	cout<<(is_number_perfect(number)==1?"yes":"no")<<endl;
	cout<<(is_number_perfect(number1)==1?"yes":"no")<<endl;
	
	
}






































