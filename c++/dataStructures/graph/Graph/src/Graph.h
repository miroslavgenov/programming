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
	Graph(Vertex*[], size_t );

private:
	void setUpTheGraph(int);

	void setGraphSizeAndGraphCapacity(int);
	
	void setGraphCapacity();

	int getGraphSize();

	void setInnerArrayCapacity();

	void setTheGreatesVertexNumber();

	void shouldWriteAllTheVerticiesConnectionsToGraph();

	void goTroughtCurrentVerticiesAndShouldWriteAllConnections();

	void shouldWriteAllConnectionsToCurrentVertex(int);

	void setCurrentVertexConnectionsSize(int);

	bool isConnectedVerticiesIteratorInRangeOf(int);

	bool isThatVertexConnectedToCurrentVertex(int, int);

	void writeConnectionToVertex(int, int);

	void postIncrementConnectedVerticiesIterator();

	void writeNoConnectionToVertex(int, int);

	void prepareConnectedVerticiesIteratorForNextVertex();

public:
	~Graph();

	int** getGraph();
};