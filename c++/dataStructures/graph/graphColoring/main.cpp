#include <iostream>
#include <vector>

using namespace std;

const size_t GRAPH_SIZE = 5;
int GRAPH_COLORS[GRAPH_SIZE]{};
struct vertex{
	int vertexNumber;
	int color;
};

vertex *verticies = new vertex[GRAPH_SIZE] {
		{0,0},
		{1,0},
		{2,0},
		{3,0},
		{4,0}
	};

void printGraph(int [][GRAPH_SIZE]);

vector<vertex> getAllNeigbourColors(int graph[][GRAPH_SIZE], int currentVertex){
	vector<vertex> coloredVertex;
	for(int i=0;i<GRAPH_SIZE;i++){
		if(graph[currentVertex][i] != 0 ){
			if(verticies[i].color != 0){
				coloredVertex.push_back(verticies[i]);
			}
		}
	}
	return coloredVertex;
}

bool isNumberInVector(vector<int> usedColors,int number){
	for(int i=0;i<usedColors.size();i++){
		if(number == usedColors[i]){
			return true;
		}
	}
	return false;
}

vector<int> colorHistory;
int getFirstUnUsedColor(vector<int> usedColors){
	int firstUnUsedColor;
	for(int i=0;i<GRAPH_SIZE;i++){
		if(!isNumberInVector(usedColors,GRAPH_COLORS[i])){
			colorHistory.push_back(GRAPH_COLORS[i]);
			return firstUnUsedColor = GRAPH_COLORS[i];
			
		}
	}
	return -1;
}

vector<int> getIntegerColors(vector<vertex> coloredVertex){
	vector<int> usedColors;
	for(int i=0;i<coloredVertex.size();i++){
		usedColors.push_back(coloredVertex[i].color);
	}
	return usedColors;
}

void printUsedColors(vector<int> usedColors){
	cout<<endl<<"usedColors: ";
	for (int i=0;i<usedColors.size();i++)
	{cout<<usedColors[i] <<" ";
		
	}cout<<endl;
}

void colorGraph(int graph[][GRAPH_SIZE], int currentVertex){
	if(currentVertex == GRAPH_SIZE){
		return;
	}else{
		cout<<"currentVertex: "<<currentVertex<<" ";
		vector<vertex> coloredVertex = getAllNeigbourColors(graph,currentVertex);
		vector<int> usedColors = getIntegerColors(coloredVertex);
		printUsedColors(usedColors);
		int firstUnUsedColor = getFirstUnUsedColor(usedColors);
		verticies[currentVertex].color = firstUnUsedColor;
		cout<<"currentVertex color: "<<verticies[currentVertex].color<<endl;
		colorGraph(graph, currentVertex+1);
		
		
	}
	
}


void fillColorPalet(){
	for(int i=0,j=1;i<GRAPH_SIZE;i++,j++){
		GRAPH_COLORS[i] = j;
		cout<<GRAPH_COLORS[i]<<" ";
	}
}
int main(){
	
	int graph[GRAPH_SIZE][GRAPH_SIZE] = {
		{0,1,1,0,0},
		{1,0,1,1,0},
		{1,1,0,1,0},
		{0,1,1,0,1},
		{0,0,0,1,0}
	};
	fillColorPalet();
	

	colorGraph(graph, 0);
	cout<<endl;
	int totalColorsUsed = 0;
	for(int i=0;i<colorHistory.size();i++){
		if(isNumberInVector(colorHistory,GRAPH_COLORS[i])){
			totalColorsUsed++;
		}
	}
	cout<<totalColorsUsed<<endl;
	

	
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
