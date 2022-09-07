#include <iostream>

using namespace std;

const size_t GRAPH_SIZE = 4;
const int GRAPH_COLORS[GRAPH_SIZE] = {1,2,3,4};
struct vertex{
	int vertexNumber;
	int color;
};

void printGraph(int [][GRAPH_SIZE]);

int main(){
	vertex *v = new vertex[GRAPH_SIZE] {
		{0,0},
		{1,0},
		{2,0},
		{3,0}
	};
	int graph[GRAPH_SIZE][GRAPH_SIZE] = {
		{0,1,0,0},
		{1,0,1,0},
		{0,1,0,1},
		{0,0,1,0}
	};

	for(int i=0;i<GRAPH_SIZE;i++){
		cout<<"vertexNumber: "<<v[i].vertexNumber<<" vertexColor: "<<v[i].color<<endl;
		for(int j=0;j<GRAPH_SIZE;j++){
			
			if(graph[i][j] != 0){

				cout<<i<<" -> "<<j<<" ";
				if(v[j].color==0){
					cout<<" dont have color"<<endl;
				}else{
					cout<<" have color: "<<v[j].color<<endl;
				}
			}
		}
	}
	
	
	
}

void printGraph(int graph[][GRAPH_SIZE]){
	cout<<endl;
	for (int i = 0; i < GRAPH_SIZE; ++i){
		for (int j = 0; j < GRAPH_SIZE; ++j){
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
