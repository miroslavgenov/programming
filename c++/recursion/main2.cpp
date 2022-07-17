#include <iostream>
#include <cstring>
using namespace std;


void WOR(int n,int x){
	if(n==x)return;
	cout<<n<<" ";
	WOR(++n,x);
	cout<<n<<" ";
	
}

void GIF(int n,int x,int z=5){
	if(x==z)return;
	WOR(n,x);
	cout<<n<<" ";
	cout<<endl;
	GIF(n,++x);
	WOR(n,x);
	cout<<n<<" ";
	cout<<endl;
	if(n==x-1)cout<<n<<" ";
	
		
}



void ROW(int n,int x){
	if(n==x)return;
	cout<<n<<' ';
	ROW(--n,x);
	cout<<n<<' ';
	
	
}

void FIG(int n,int x){
	if(x==1)return;
	ROW(n,x);
	cout<<n<<" ";
	cout<<endl;
	FIG(n,--x);
	
	ROW(n,x);
	cout<<n<<" ";
	cout<<endl;
	
	if(n==x+1){
		cout<<n<<" ";
	}
	

	
}



int main(){

GIF(1,1);
cout<<endl<<endl;
FIG(5,5);






	
	
    
    
	
	
	
	
    
    
}



























































