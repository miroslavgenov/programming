#include <iostream>

using namespace std;

const int s = 4;
void b(int a[][s] , int i, int j){
    if(a[i][s-1]==1){
    	cout<<"solved"<<endl;
		return;
	}else{
		if((a[i][j] == 0 || a[i][j] == 1) && j<s){
            a[i][j]=1;
            b(a,i,++j);        
        }
        
        if(a[i][j] == 2){
        	j--;
        	a[i][j]=0;
			
		}
		if(a[i+1][j] == 2){
			a[i][j]=0;
			--j;
		}
		
		if(a[i+1][j] == 0 && i<s){
			a[i+1][j]=1;
			b(a,++i,j);
		}
        
		
        
	}
    
    
    
	
	
    
}

void print(int a[][s]){
    for(int i=0;i<s;i++){
        for(int j=0; j<s ;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    
    int a[s][s]={
        {0,0,0,2},
        {0,2,2,0},
        {0,0,0,0},
        {0,0,0,0}
    };
    b(a,0,0);
    cout<<endl;
   print(a);

}





















