#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Vertex.h"
#include <vector>

class Graph{
	int** graph = nullptr;
	size_t GRAPH_SIZE;
	int connectedVerticiesIterator;
	Vertex** verticies;
	int theGreatesVertexNumber;

	void setGraphCapacity(){
		this->graph = new int*[getGraphSize()];
	}
	void setInnerArrayCapacity(){
		for(int i=0;i<GRAPH_SIZE;i++){
			graph[i] = new int[GRAPH_SIZE];
		}
	}

	void setGraphSizeAndGraphCapacity(int size){
		this->GRAPH_SIZE = size;
		setGraphCapacity();
	}

	int getGraphSize(){
		return GRAPH_SIZE;
	}

	void setUpTheGraph(int size){
			setGraphSizeAndGraphCapacity(size);
			setInnerArrayCapacity();	
	}

	bool isConnectedVerticiesIteratorInRangeOf(int numberOfConnectedVerticiesToOneVertex){
		return connectedVerticiesIterator < numberOfConnectedVerticiesToOneVertex;
	}

	bool isThatVertexConnectedToCurrentVertex(int vertex, int currentVertex){
		return vertex == verticies[currentVertex]->connectedVerticies[connectedVerticiesIterator];
	}
	
	void postIncrementConnectedVerticiesIterator(){
		connectedVerticiesIterator++;
	}

	void writeConnectionToVertex(int currentVertex, int connectedVertex){
		graph[currentVertex][connectedVertex] = 1;
	}

	void writeNoConnectionToVertex(int currentVertex, int notConnectedVertex){
		graph[currentVertex][notConnectedVertex] = 0;
	}
	
	void prepareConnectedVerticiesIteratorForNextVertex(){
		connectedVerticiesIterator = 0;
	}

	void writeTheGraphTable(){

	}

public:
	Graph(Vertex* verticies[], size_t VERTICIES_SIZE){		
		this->verticies = verticies;
		setUpTheGraph(VERTICIES_SIZE);		


		theGreatesVertexNumber = NumberFinder::findTheMaximumVertexNumberInGraph(verticies, VERTICIES_SIZE);
		int currentVertexConnectionsSize;

		// write graph table
		// go trought all the verticies  and check if there is vertex who is connected to the current vertex
		// when write in the graph
		for(int currentVertex = 0; currentVertex <= theGreatesVertexNumber; currentVertex++){
			
			// go trought all the verticies and see if it is connected to currentVertex
			for(int vertex = 0; vertex <=  theGreatesVertexNumber; vertex++){
				currentVertexConnectionsSize = verticies[currentVertex]->connectedVerticies.size();
				

				if(isConnectedVerticiesIteratorInRangeOf(currentVertexConnectionsSize)){
					
					// should write connection
					if(isThatVertexConnectedToCurrentVertex(vertex, currentVertex)){
						postIncrementConnectedVerticiesIterator();
						writeConnectionToVertex(currentVertex, vertex);
						continue;
					}

				}			
				writeNoConnectionToVertex(currentVertex, vertex);
			}			
			prepareConnectedVerticiesIteratorForNextVertex();
		}

	}

	~Graph(){
		for(int i =0;i<GRAPH_SIZE;i++){
				delete [] graph[i];
		}

		delete [] graph;
	}

	int** getGraph(){
		return graph;
	}
};

















