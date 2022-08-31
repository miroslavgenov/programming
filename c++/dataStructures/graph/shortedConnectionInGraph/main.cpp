#include <iostream>

using namespace std;

const int s = 3;

void printShortesConnectionInGraph(int g[][s]){
  int *min = nullptr;
  int *edgeNumber = nullptr;
  int *fromEdge = nullptr;
  
  for(int i = 0; i < s; i++){
    for(int j=0; j<s; j++){
      if(g[i][j] != 0){
    	if(min == nullptr){
        min = new int{g[i][j]};
        edgeNumber = new int{j};
        fromEdge = new int{i};
      }else{
        if(*min > g[i][j]){
          min = new int{g[i][j]};
          fromEdge = new int{i};
          edgeNumber = new int{j};
        }
      }
    }
    }
    
  }
  cout<<"from: "<<*fromEdge<<" to: "<<*edgeNumber<<" is: "<<*min<<endl;
  
  delete fromEdge;
  delete edgeNumber;
  delete min;
  
  
}

int main(){
	int g[s][s] = {
		{0,10,30},
		{10,0,22},
		{30,22,0}
	};
	
	printShortesConnectionInGraph(g);
}




















































