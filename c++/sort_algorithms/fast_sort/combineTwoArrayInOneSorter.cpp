#include <iostream>
using namespace std;

int main(){
	int a[5]={1,3,5,7,8};
	int b[5]={2,4,6,9,10};
	int c[10]{};
	int j=0,z=0;
	
	for(int i=0;i<10;i++){
		if(a[j]>b[z] && z<5){
			cout<<b[z];
			z++;
		}
		if(b[z]>a[j] && j<5){
			cout<<a[j];
			j++;
		}
	}
	cout<<endl;
}

























































