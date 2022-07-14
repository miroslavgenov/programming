#include <iostream>
using namespace std;

bool is_number_perfect(int *number){
	if(*number<6 || number==nullptr){
		return false;
	}else if(*number>=6){
		int sum=0;
		for(int i=1;i<*number;i++)
			sum+=*number%i==0?i:0;
			
		if(sum==*number)return true;
		
	}
	return false;
}

int main(){
	int* number=new int(6);
	cout<<is_number_perfect(number);
	
}








































