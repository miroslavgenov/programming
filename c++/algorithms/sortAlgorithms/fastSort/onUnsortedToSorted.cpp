#include <iostream>
using namespace std;
void swap(int &greater,int &less){
int temp = greater;
greater=less;
less=temp;

}

int main(){
	
	int size=2;
	int a[size]={2,1};
	
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++)
			if(a[j-1]>a[j])swap(a[j-1],a[j]);
		
	
	
	


	
	

	
for(int i=0;i<size;i++)cout<<a[i]<<' ';

	


}











































