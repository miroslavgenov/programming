#include <iostream>

using namespace std;

int main(){
	int s=5;
	int g[s][s]={
		{0,1,0,0,1},
		{1,0,1,1,1},
		{0,1,0,1,0},
		{0,1,1,0,1},
		{1,1,0,1,0}
	};
	
	
	for(int i=0; i<s; i++){
	cout<<"edge: "<<i<<" have connection with: ";	
		for(int j=0; j<s; j++){
			if(g[i][j] == 1){
				cout<<j<<' ';	
			}
			

		}cout<<endl;
	}
	
}













































