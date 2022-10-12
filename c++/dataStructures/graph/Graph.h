#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/Vertex.h"
#include <vector>

class Graph{
private:
	int theGreatesVertexNumber;
	int currentVertexConnectionsSize;
	int connectedVerticiesIterator;
	size_t GRAPH_SIZE;
	int** graph = nullptr;
	Vertex** verticies;

public:
	Graph(Vertex* verticies[], size_t VERTICIES_SIZE){		
		this->verticies = verticies;
		setUpTheGraph(VERTICIES_SIZE);		
		setTheGreatesVertexNumber();
		shouldWriteAllTheVerticiesConnectionsToGraph();
	}

private:
	void setUpTheGraph(int size){
			setGraphSizeAndGraphCapacity(size);
			setInnerArrayCapacity();	
	}
	
	void setGraphSizeAndGraphCapacity(int size){
		this->GRAPH_SIZE = size;
		setGraphCapacity();
	}
	
	void setGraphCapacity(){
		this->graph = new int*[getGraphSize()];
	}

	int getGraphSize(){
		return GRAPH_SIZE;
	}

	void setInnerArrayCapacity(){
		for(int i=0;i<GRAPH_SIZE;i++){
			graph[i] = new int[GRAPH_SIZE];
		}
	}

	void setTheGreatesVertexNumber(){
		size_t TOTAL_VERTICIES = GRAPH_SIZE;
		theGreatesVertexNumber = NumberFinder::findTheMaximumVertexNumberInGraph(verticies,TOTAL_VERTICIES);
	}

	void shouldWriteAllTheVerticiesConnectionsToGraph(){
		goTroughtCurrentVerticiesAndShouldWriteAllConnections();
	}

	void goTroughtCurrentVerticiesAndShouldWriteAllConnections(){
		for(int currentVertex = 0; currentVertex <= theGreatesVertexNumber; currentVertex++){
			shouldWriteAllConnectionsToCurrentVertex(currentVertex);
			prepareConnectedVerticiesIteratorForNextVertex();
		}
	}

	void shouldWriteAllConnectionsToCurrentVertex(int currentVertex){
		for(int vertex = 0; vertex <=  theGreatesVertexNumber; vertex++){
			setCurrentVertexConnectionsSize(currentVertex);
			
			if(isConnectedVerticiesIteratorInRangeOf(currentVertexConnectionsSize)){
				if(isThatVertexConnectedToCurrentVertex(vertex, currentVertex)){
					writeConnectionToVertex(currentVertex, vertex);
					postIncrementConnectedVerticiesIterator();
					continue;
				}
			}			
			writeNoConnectionToVertex(currentVertex, vertex);
		}			
	}

	void setCurrentVertexConnectionsSize(int currentVertexNumber){
		currentVertexConnectionsSize = verticies[currentVertexNumber]->connectedVerticies.size();
	}

	bool isConnectedVerticiesIteratorInRangeOf(int numberOfConnectedVerticiesToOneVertex){
		return connectedVerticiesIterator < numberOfConnectedVerticiesToOneVertex;
	}

	bool isThatVertexConnectedToCurrentVertex(int vertex, int currentVertex){
		return vertex == verticies[currentVertex]->connectedVerticies[connectedVerticiesIterator];
	}

	void writeConnectionToVertex(int currentVertex, int connectedVertex){
		graph[currentVertex][connectedVertex] = 1;
	}

	void postIncrementConnectedVerticiesIterator(){
		connectedVerticiesIterator++;
	}

	void writeNoConnectionToVertex(int currentVertex, int notConnectedVertex){
		graph[currentVertex][notConnectedVertex] = 0;
	}


	void prepareConnectedVerticiesIteratorForNextVertex(){
		connectedVerticiesIterator = 0;
	}

public:
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