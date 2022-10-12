#include "/home/home/Desktop/programming/c++/dataStructures/graph/Graph/src/Graph.h"



Graph::Graph(Vertex* verticies[], size_t VERTICIES_SIZE){		
	this->verticies = verticies;
	setUpTheGraph(VERTICIES_SIZE);		
	setTheGreatesVertexNumber();
	shouldWriteAllTheVerticiesConnectionsToGraph();
}


void Graph::setUpTheGraph(int size){
		setGraphSizeAndGraphCapacity(size);
		setInnerArrayCapacity();	
}

void Graph::setGraphSizeAndGraphCapacity(int size){
	this->GRAPH_SIZE = size;
	setGraphCapacity();
}

void Graph::setGraphCapacity(){
	this->graph = new int*[getGraphSize()];
}

int Graph::getGraphSize(){
	return GRAPH_SIZE;
}

void Graph::setInnerArrayCapacity(){
	for(int i=0;i<GRAPH_SIZE;i++){
		graph[i] = new int[GRAPH_SIZE];
	}
}

void Graph::setTheGreatesVertexNumber(){
	size_t TOTAL_VERTICIES = GRAPH_SIZE;
	theGreatesVertexNumber = NumberFinder::findTheMaximumVertexNumberInGraph(verticies,TOTAL_VERTICIES);
}

void Graph::shouldWriteAllTheVerticiesConnectionsToGraph(){
	goTroughtCurrentVerticiesAndShouldWriteAllConnections();
}

void Graph::goTroughtCurrentVerticiesAndShouldWriteAllConnections(){
	for(int currentVertex = 0; currentVertex <= theGreatesVertexNumber; currentVertex++){
		shouldWriteAllConnectionsToCurrentVertex(currentVertex);
		prepareConnectedVerticiesIteratorForNextVertex();
	}
}

void Graph::shouldWriteAllConnectionsToCurrentVertex(int currentVertex){
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

void Graph::setCurrentVertexConnectionsSize(int currentVertexNumber){
	currentVertexConnectionsSize = verticies[currentVertexNumber]->connectedVerticies.size();
}

bool Graph::isConnectedVerticiesIteratorInRangeOf(int numberOfConnectedVerticiesToOneVertex){
	return connectedVerticiesIterator < numberOfConnectedVerticiesToOneVertex;
}

bool Graph::isThatVertexConnectedToCurrentVertex(int vertex, int currentVertex){
	return vertex == verticies[currentVertex]->connectedVerticies[connectedVerticiesIterator];
}

void Graph::writeConnectionToVertex(int currentVertex, int connectedVertex){
	graph[currentVertex][connectedVertex] = 1;
}

void Graph::postIncrementConnectedVerticiesIterator(){
	connectedVerticiesIterator++;
}

void Graph::writeNoConnectionToVertex(int currentVertex, int notConnectedVertex){
	graph[currentVertex][notConnectedVertex] = 0;
}


void Graph::prepareConnectedVerticiesIteratorForNextVertex(){
	connectedVerticiesIterator = 0;
}


Graph::~Graph(){
	for(int i =0;i<GRAPH_SIZE;i++){
			delete [] graph[i];
	}

	delete [] graph;
}

int** Graph::getGraph(){
	return graph;
}