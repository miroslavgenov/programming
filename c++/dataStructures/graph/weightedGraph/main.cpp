#include <iostream>

using namespace std;

const int s = 3;

void printEdgeConnections(int g[][s],int targetEdge){
    
    for(int i = 0; i<s; i++){
      if(g[targetEdge][i] != 0 ){
          cout<<"targetEdge: "<<targetEdge<<" have connections to: "<<i<<" withi cost of: "<< g[targetEdge][i]<<endl;
      }
    }
}

int main(){
	int g[s][s] = {
		{0,11,15},
		{11,0,22},
		{15,20,0}
	};
	
	printEdgeConnections(g,0);
}




















































