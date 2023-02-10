#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"

using namespace std;

const int graphSize=5;
bool visitedVerticies[graphSize]{0};
int totalEdges = 0;


// struct edge{...}; can be replaced by struct VertexConnection{...}; 
// struct edge{
//     int fromVertex;
//     int toVertex;
//     int weight;
// };

void clearVisitedEdgesArray();
void clearEdgesFromGraph(int [][graphSize], vertexConnection* );

template <typename T>
void printOneDimArray(T [],int );
void copySrcGraphIntoDstGraph(int [][graphSize], int [][graphSize]);
// void printGraph(int [][graphSize]);
void appendEdgesToGraph(int [][graphSize], vertexConnection*);

void printVertexNeighbours(int graph[][graphSize], int e){
    for(int i=0;i<graphSize;i++){
        if(graph[e][i] !=0 && visitedVerticies[i] == 0 ){
            cout<<"vertex: "<<e<<" can go to: "<<i<<" with weight: "<<graph[e][i]<<endl;
        }
    }
}

vector<int> getVisitedVerticies(bool visitedVerticies[graphSize]){
    std::vector<int> verticiesVisited;
    for(int i=0;i<graphSize;i++){
        if(visitedVerticies[i] == 1){
            verticiesVisited.push_back(i);
        }
    }
    
    return verticiesVisited;
}


vertexConnection* getShortestEdge(int **graph){
    cout<<endl<<"getShortestEdge"<<endl;
    
    int *minWeight = nullptr;
    int fromVertex;
    int toVertex;
    
    vector<int> verticiesVisited = getVisitedVerticies(visitedVerticies);
    
for(int i=0; i<verticiesVisited.size(); i++){



    for(int j=0;j<graphSize;j++){
		if(graph[verticiesVisited[i]][j] != 0){
    		if(minWeight == nullptr){
    			minWeight = new int{graph[verticiesVisited[i]][j]};
                fromVertex = verticiesVisited[i];
                toVertex = j;

			}
			else{
				if(*minWeight > graph[verticiesVisited[i]][j]){
					minWeight = new int{graph[verticiesVisited[i]][j]};
                	fromVertex = verticiesVisited[i];
                    toVertex = j;
				}
			}
            
        }
    }
}    
    
	return new vertexConnection{fromVertex, toVertex, *minWeight};
    

}

template <typename T>
void printNonZero(T a[graphSize]){
    for(int i=0;i<graphSize;i++){
        if(a[i] !=0){
            cout<<i<<" ";
        }
    }
}



template <typename T>
void printVector(std::vector<T> v){
	for (auto i = begin(v); i != end(v); ++i)
    {
        cout<<*i<<" ";
    }cout<<endl;
}

void clearVisitedVerticiesArray(bool visitedVerticies[]){
  for(int i=0;i<graphSize;i++){
    visitedVerticies[i]=0;
  }
}



bool visitedVerticiesForVertexSkeleton[graphSize]{0};
vector<int> currentVertextForSkeleton;
vector<int> graphSkeleton;

void clearSkeleton(){
    GraphUtil::clearVisitedVerticies(visitedVerticiesForVertexSkeleton,graphSize);
    currentVertextForSkeleton.clear();
    graphSkeleton.clear();
}

void setGraphSkeleton(int graph[][graphSize], int vertex){
    if(visitedVerticiesForVertexSkeleton[vertex] == 0){
        visitedVerticiesForVertexSkeleton[vertex] = 1;
        currentVertextForSkeleton.push_back(vertex);
        graphSkeleton.push_back(vertex);

        for(int i=0;i<graphSize;i++){
            if(graph[vertex][i] != 0 && visitedVerticiesForVertexSkeleton[i] == 0){
                cout<<"from: "<<vertex<<" to: "<<i<<" weight: "<<graph[vertex][i]<<endl;
                currentVertextForSkeleton.push_back(i);
                setGraphSkeleton(graph,currentVertextForSkeleton[currentVertextForSkeleton.size()-1]);
                currentVertextForSkeleton.pop_back();
            }
        }
    }
}

bool isVertexInGraphSkeleton(vector<int> graphSkeleton, int vertex){
//	cout<<"isVertexInGraphSkeleton("<<endl;
	cout<<vertex<<endl;
	for(int i=0;i<graphSkeleton.size();i++){
//    	cout<<graphSkeleton[i]<<" ";	
    	if(graphSkeleton[i] == vertex){
    		return true;
		}
    }
    return false;
}

template <typename T>
void printOneDimArray(T array[],int size){
  for(int i=0;i<size;i++){
    cout<<array[i]<<" ";
  }cout<<endl;
}



void markVerticiesAsVisied(vertexConnection* e){
    visitedVerticies[e->connectionFromVertex] = 1;
    visitedVerticies[e->connectionToVertex] = 1;
}

void prim(int **graph, int *spanningTree, int startingVertex){
    
    vertexConnection* shortestEdge = nullptr;
    
    if(totalEdges == graphSize-1){
    	cout<<"done"<<endl;
	}else{
		
        
	
		cout<<"primAlgorithm"<<endl;
		
		if(GraphUtil::areAllVerticiesNotVisited(visitedVerticies,graphSize)){
            cout<<"all verticies are not visited"<<endl;
            visitedVerticies[startingVertex] = 1;
			shortestEdge = getShortestEdge(graph);
			markVerticiesAsVisied(shortestEdge);
           	totalEdges++;
            // GraphUtil::addWeightToGraph(spanningTree,shortestEdge);
           	GraphUtil::addWeightToGraph(&spanningTree,shortestEdge);
            // appendEdgesToGraph(spanningTree,shortestEdge);
           	GraphUtil::removeWeightFromGraph(&graph,shortestEdge);
            // clearEdgesFromGraph(graph,shortestEdge);
           	// printGraph(graph);
            prim(graph, spanningTree, startingVertex);
			  
        }else{
			cout<<"you have visited verticies "<<endl;
			shortestEdge = getShortestEdge(graph);
           cout<<shortestEdge->connectionFromVertex<<" "<<shortestEdge->connectionToVertex<<" "<<shortestEdge->connectionWeight<<endl;
           setGraphSkeleton(spanningTree,shortestEdge->connectionFromVertex);
           if(graphSkeleton.size()<2){
                cout<<"graphSkeleton.size()<2 you can add"<<endl;
                totalEdges++;
                    markVerticiesAsVisied(shortestEdge);
                    appendEdgesToGraph(spanningTree,shortestEdge);
                    clearEdgesFromGraph(graph,shortestEdge);
                    clearSkeleton();

           }else if(graphSkeleton.size() >= 2){
            cout<<"graphSkeleton.size()>=2 you can't add before checking for loops"<<endl;
            cout<<"then add the verticies as visited"<<endl;


			if(isVertexInGraphSkeleton(graphSkeleton,shortestEdge->connectionFromVertex) && isVertexInGraphSkeleton(graphSkeleton,shortestEdge->connectionToVertex)){
                cout<<"there is a  loop"<<endl;
                clearEdgesFromGraph(graph,shortestEdge);
                clearSkeleton();

	           }else{
	                cout<<"there is no loop"<<endl;
	                totalEdges++;
	                markVerticiesAsVisied(shortestEdge);
                    appendEdgesToGraph(spanningTree,shortestEdge);
	                clearEdgesFromGraph(graph,shortestEdge);
	                clearSkeleton();
	            
	               
	                
	                
	            }
            
           }
                  prim(graph, spanningTree, startingVertex); 


        }
        
	}
}






int main(){

    int graph[][graphSize] = {
        {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}
    };

    int **graphCopy = nullptr;
    GraphUtil::initializeGraph(&graphCopy,graphSize);
    

    int **spanningTree = nullptr;
    GraphUtil::initializeGraph(&spanningTree,graphSize);
    

    // replaced
    // GraphUtil::copy
    GraphUtil::copyTheWeightsFromSourceGraph(&graphCopy,(int*)graph,graphSize);
    // copySrcGraphIntoDstGraph(graph,graphCopy);
    
    prim(graphCopy, spanningTree, 0);
    // prim(graphCopy, spanningTree, 0);
    // prim(graphCopy, spanningTree, 0);
    // prim(graphCopy, spanningTree, 0);
    // prim(graphCopy, spanningTree, 0);
    // prim(graphCopy, spanningTree, 0);
   
   
    // //printGraph(spanningTree);
    // setGraphSkeleton(spanningTree,0);
    // clearSkeleton();


   

}

//can be replaced by addWeightToGraph
void appendEdgesToGraph(int graph[][graphSize], vertexConnection * e){
    graph[e->connectionFromVertex][e->connectionToVertex] = e->connectionWeight;
    graph[e->connectionToVertex][e->connectionFromVertex] = e->connectionWeight;
    
}

//can by replaced by removeWeightFromGraph
void clearEdgesFromGraph(int graph[][graphSize], vertexConnection* e){
    graph[e->connectionFromVertex][e->connectionToVertex] = 0;
    graph[e->connectionToVertex][e->connectionFromVertex] = 0;
}


// can be replaced by printer::printGraph
// void printGraph(int graph[][graphSize]){
//   cout<<endl;
//   for(int i=0;i<graphSize;i++){
    // for(int j=0;j<graphSize;j++){
        // cout<<graph[i][j]<<" ";
    // }cout<<endl;
//   }
//   cout<<endl;
// }


//can be replaced by copyTheWeightsFromSourceGraph
void copySrcGraphIntoDstGraph(int srcGraph[][graphSize], int dstGraph[][graphSize]){
  for(int i=0;i<graphSize;i++){
    for(int j=0; j<graphSize; j++){
      dstGraph[i][j] = srcGraph[i][j];
    }
  }
  
}