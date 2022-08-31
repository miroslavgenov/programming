#include <iostream>

using namespace std;

const int s = 3;

void printShortesConnectionInEdge(int g[][s], int targetEdge){
  int *min = nullptr;
  int *edgeNumber = nullptr;
  
  for(int i = 0; i < s; i++){
    if(g[targetEdge][i] != 0){
    	if(min == nullptr){
        min = new int{g[targetEdge][i]};
        edgeNumber = new int{i};
      }else{
        if(*min > g[targetEdge][i]){
          min = new int{g[targetEdge][i]};
          edgeNumber = new int{i};
        }
      }
    }
  }
  
  cout<<"minumum from: "<<targetEdge<<" to edge: "<<*edgeNumber<<" with weight: "<<*min<<endl;
  
}

int main(){
	int g[s][s] = {
		{0,11,15},
		{11,0,22},
		{15,20,0}
	};
	
	printShortesConnectionInEdge(g,0);
}




















































