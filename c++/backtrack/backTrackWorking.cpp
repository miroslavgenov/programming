#include <iostream>

using namespace std;


const int s=5;

void print(int a[][s]){
	for(int i =0 ;i<s;i++){
		for(int j=0; j<s; j++){
			cout<<a[i][j]<<' ';
		}cout<<endl;
	}cout<<endl;

}

void clear(int a[][s]){
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			if(a[i][j]==1){
			a[i][j] =0;
		}	
		}
		
	}
}

void r(int a[][s],int i ,int j){
	if(a[s-1][s-1] == 1){
		print(a);
		cout<<"solved"<<endl;
		clear(a);
		return;
	}
	
	if(j<s){
		if(a[i][j]==0){
			a[i][j]=1;
			print(a);
			r(a,i,j+1);	
		}
		
		if(a[i][j] == 1){
			if(a[i+1][j]==0){
				r(a,1+i,j);
			}
		}
		

	}
	
	if(a[i][j+1] == 2 && a[i+1][j]==2){
		r(a,i,j-1);
	}
	
	if(j==s){
		print(a);
		r(a,i+1,j-1);
	}
	
	
}

int main(){
	int a[s][s]={
		{0,0,2,0,0},
		{0,0,0,0,0},
		{0,0,2,0,2},
		
		{0,2,0,0,0},
		{0,0,0,0,0},
	
	};
	r(a,0,0);


}
































































