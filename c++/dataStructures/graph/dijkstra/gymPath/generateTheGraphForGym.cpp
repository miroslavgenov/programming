#include <iostream>
#include <fstream>

using namespace std;

bool isVerticiesIteratorInRange(int iterator, int totalVerticies){
	return iterator < totalVerticies;
}

int main(){
	std::ofstream writeInThisFile("numbersAndWeightOfVerticiesConnectedToThatVertext.txt");
	const size_t TOTAL_VERTICIES_FROM_GRAPH = 25;
	constexpr bool NO_CONNECTION_TO_VERTEX = 0;
	int verticiesConnectedToThatVertex[] = {
		22,
		23 
	};
	int edgeWeightsOfVerticiesConnectedToThatVertex[] = {
 		100,
 		92
	};


	
	int verticiesConnectedToThatVertexIterator = 0;
	size_t totalVerticiesConnectedToThatVertex = sizeof(verticiesConnectedToThatVertex)/sizeof(*verticiesConnectedToThatVertex);
	
	for(int i=0;i<TOTAL_VERTICIES_FROM_GRAPH;i++){
		writeInThisFile<<i<<"\t";
	}writeInThisFile<<endl;
	

	for(int i = 0; i < TOTAL_VERTICIES_FROM_GRAPH; i++){
		if(isVerticiesIteratorInRange(verticiesConnectedToThatVertexIterator,totalVerticiesConnectedToThatVertex)){
			if(i == verticiesConnectedToThatVertex[verticiesConnectedToThatVertexIterator]){
				writeInThisFile<<edgeWeightsOfVerticiesConnectedToThatVertex[verticiesConnectedToThatVertexIterator]<<"\t";
				verticiesConnectedToThatVertexIterator++;
				continue;
			}
			
		}
		writeInThisFile<<NO_CONNECTION_TO_VERTEX<<"\t";
	}
	
		
		
	
	
	
}






































































