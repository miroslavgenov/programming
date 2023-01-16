#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"

using namespace std;

bool visitedVerticies[6]{};
enum GraphFlags : bool {empty = true, notEmpty = false, visited = true, notVisited = false};

struct vertexConnections{
    int vertexNumber;
    vector<int> connections;
};

//find the minimum connection

vertexConnection* findTheMinimumConnection(int **graph, int graphSize){
    //! only if the graph is not empty !
    vertexConnection *vt  = nullptr;

    int min = 0;
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            // only check if the weight is different than 0
            if(graph[i][j] !=0 ){
                //initialize the minWeight
                if(min == 0){
                    min = graph[i][j];
                    vt = new vertexConnection{i,j,graph[i][j]};
                }
                //if the minWeight is initialized
                else{
                    // check if the graphWeight is lesser then the min weight
                    if(min > graph[i][j]){
                        // store the data
                        min = graph[i][j];
                        vt = new vertexConnection{i,j,graph[i][j]};
                    }
                }
            }
        }
    }
    
    return vt;
}

// bool isVertexVisited(int vertexNumber){
//     return visitedVerticies[vertexNumber] == GraphFlags::visited;
// }

// bool isBothVerticiesVisited(int firstVertex, int secondVertex){
//     return isVertexVisited(firstVertex) && isVertexVisited(secondVertex);
// }


// if they are not visited mark them as visited
void markVertexAsVisited(int vertexNumber){
    visitedVerticies[vertexNumber] = 1;
}

void markBothVerticiesAsVisited(vertexConnection* vt){
    markVertexAsVisited(vt->connectionFromVertex);
    markVertexAsVisited(vt->connectionToVertex);
}


// add the connection to a new graph
// void addTheConnectionToNewGraph()
void addTheConnectionsToTheNewGraph(int **newGraph, vertexConnection* vt){
    newGraph[vt->connectionFromVertex][vt->connectionToVertex] = vt->connectionWeight;
    newGraph[vt->connectionToVertex][vt->connectionFromVertex]  = vt->connectionWeight;
}

// remove the connection from the old graph
void removeTheConnectionsFromTheOldGraph(int **graph, vertexConnection* vt){
    graph[vt->connectionFromVertex][vt->connectionToVertex] =0;
    graph[vt->connectionToVertex][vt->connectionFromVertex] =0;
}

// if only one vertex is visted add the new connection to the new graph
// if(isBothVerticiesVisited == true) check whether one of them are visited or not
// remove the connection from the old graph

//if the verticies are visited don't add the connection to the new graph
//remove the connection

//the algorithm will end if the old graph is empty
// if(isGraphEmpty(oldGraph) == true){
    // finish
// }


bool isGraphEmpty(int **graph, int graphSize){
    
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){

            if(graph[i][j] != 0 ){
                return GraphFlags::notEmpty;
            }
        }
    }


    return GraphFlags::empty;
}

void print(int** graph, int graphSize){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            cout<<graph[i][j]<<" ";
        }cout<<endl;
    }
}


vector<int> stack;
const int graphSize = 4;
bool vv[graphSize]{};

template <typename T>
void print(T array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

void dfs(int **graph){
    if(stack.empty() == false && vv[stack.back()] == 0) {
        
        int currentVertex = stack.back();
        stack.pop_back();
        vv[currentVertex] = 1;
        // cout<<currentVertex<<endl;
        
        for(int i=0;i<graphSize;i++){
            if(graph[currentVertex][i] != 0){
                if(vv[i]==0){

                    stack.push_back(i);
                }
            }
        }

        

        if(stack.empty() == false){
            dfs(graph);
        }
    }
    
}

bool isEveryVertexVisited(){
    for(int i=0;i<graphSize;i++){
        if(visitedVerticies[i] != 1){
            return false;
        }
    }
    return true;
}




//TO DO: make algorithm that check for loops

bool isThereACycle(int **graph, int graphSize){

    //getting the connection in to a stack
    vector<vertexConnections*> listWithVertexConnections;

    for(int i=0;i<graphSize;i++){
        listWithVertexConnections.push_back(new vertexConnections{i});
        for(int j=0;j<graphSize;j++){
            if(graph[i][j] != 0){
                listWithVertexConnections[i]->connections.push_back(j);
            }
        }
    }
    //getting the connection in to a stack
    

    //getting only the stack with >= 2 size
    vector<vertexConnections*> potentialLoopVerticies;

    for(int i = 0 ;i< listWithVertexConnections.size();i++){
        if(listWithVertexConnections[i]->connections.size()>=2){
            potentialLoopVerticies.push_back(listWithVertexConnections[i]);
        }
    }
    //getting only the stack with >= 2 size

    //check if there is 
    // if every vertex has more than 1 connection there is a loop
    // or if only one vertex have only one connection there is a loop
    // if simmilar more thatn 6 than there is loop


    //loop detector
    int repeatedConnections = 0;

    // loop each vertex
    for(int i=0;i<potentialLoopVerticies.size();i++){
        // cout<<"current vertex: "<<potentialLoopVerticies[i]->vertexNumber<<endl;
        
        // loop each vertex connections
        // loop and see if the connection from the current vertex occur in the other
        for(int j=0;j<potentialLoopVerticies[i]->connections.size();j++){
            // cout<<"connection: "<<potentialLoopVerticies[i]->connections[j]<<endl; // connection from the current vertex
            // cout<<"checking if that connection occur in the other verticies"<<endl;

            //loop all verticies
            // loop throug all verticies except the current vertex to check for similar connections
            for(int z=0;z<potentialLoopVerticies.size();z++){
                //show all verticies except the current one
                // all other verticies except the current vertex
                if(potentialLoopVerticies[i]->vertexNumber != potentialLoopVerticies[z]->vertexNumber){
                    // cout<<"vertex: "<<potentialLoopVerticies[z]->vertexNumber<<" : ";

                    //loop the connections from the verticies and check for similar
                    //looping throught the other verticies connections and checking for repeted connections
                    for(int y =0 ; y< potentialLoopVerticies[z]->connections.size();y++){
                        // cout<<potentialLoopVerticies[z]->connections[y]<<" ";
                        if(potentialLoopVerticies[i]->connections[j] == potentialLoopVerticies[z]->connections[y]){
                            // cout<<"connection : "<<potentialLoopVerticies[i]->connections[j]<<" occur !!"<<endl;
                            repeatedConnections++;
                        }
                    }
                    // cout<<endl;
                }
            }

        }
        // cout<<endl;       
    }
    
    if(repeatedConnections >= 6){
        // cout<<"there is a loop"<<endl;
        return true;
    }else{
        // cout<<"there is no loop"<<endl;
        return false;
    }

    return false;


}

bool areAllVerticiesVisited(){
    for(int i=0;i<graphSize;i++){
            if(vv[i] == 0){
                return false;
            }
    }
    return true;
}

void clearVisitedVerticies(){
    for(int i=0;i<graphSize;i++){
        vv[i] = 0;
    }
}


void kruskal(int **graph, int graphSize, int **newGraph){
    while(areAllVerticiesVisited() == false){
        // cout<<__func__<<endl;

        clearVisitedVerticies();

        vertexConnection* mv = findTheMinimumConnection(graph, graphSize);
        
        addTheConnectionsToTheNewGraph(newGraph, mv);
        
        if(isThereACycle(newGraph,graphSize) == false){
            // cout<<"no cycle"<<endl;
            removeTheConnectionsFromTheOldGraph(graph,mv);
            
            stack.push_back(mv->connectionFromVertex);
            dfs(newGraph);
            
            // print(vv,graphSize);cout<<endl;

        }else{
            // cout<<"there will be a cycle remove the new connection"<<endl;
            removeTheConnectionsFromTheOldGraph(newGraph,mv);
        }
        

    }
    
    cout<<__func__<<" spanning tree"<<endl;
    print(newGraph,graphSize);
    cout<<endl;

}


int main(){
    int graphCp[graphSize][graphSize] = {
       //0 1 2 3
        {0,1,2,6}, //0
        {1,0,0,1}, //1
        {2,0,0,3}, //2
        {6,1,3,0}  //3
	};    
    
    
    

    int **graph = new int*[graphSize];
    // make this function
    for(int i=0; i<graphSize;i++){
            graph[i] = new int[graphSize];
    }

    //graph converted to int** graph
    // make this function
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            graph[i][j] = graphCp[i][j];
            // cout<<graph[i][j]<<" ";
        }
    }


    // new graph to store the kruskal path
    int **newGraph = new int*[graphSize];
    for(int i=0;i<graphSize;i++){
        newGraph[i] = new int[graphSize];
    }

    kruskal(graph, graphSize, newGraph);

}