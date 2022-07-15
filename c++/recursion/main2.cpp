#include <iostream>
#include <cstring>
using namespace std;


void row(int n,int i){
	if(n==i) {return;}
	
	cout<<n<<' ';
	row(++n,i);
	cout<<n<<' ';
	
}

void fig(int n,int i){
	if(i==5)return;
	
	row(n,i);
	cout<<1<<' ';
	cout<<endl;
	
	fig(n,++i);
	
	cout<<endl;row(n,i);
	
	cout<<n<<" ";
	if(n==(--i))cout<<'\n'<<1<<" ";
		
}





int main(){

fig(1,1);



	
	
    
    
	
	
	
	
    
    
}


















































