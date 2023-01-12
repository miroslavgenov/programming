#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"

using namespace std;

bool visitedVerticies[6]{};
enum GraphFlags : bool {empty = true, notEmpty = false, visited = true, notVisited = false};


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

bool isVertexVisited(int vertexNumber){
    return visitedVerticies[vertexNumber] == GraphFlags::visited;
}

bool isBothVerticiesVisited(int firstVertex, int secondVertex){
    return isVertexVisited(firstVertex) && isVertexVisited(secondVertex);
}


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
vector<int> loopS;
const int graphSize = 4;
bool vV[graphSize]{};

void dfs(int **graph){
    while(stack.empty() == false){
        int cv = stack.back();
        stack.pop_back();

        
        cout<<cv<<endl;

            for(int i=0;i<graphSize;i++){
                if(graph[cv][i] !=0){
                    if(vV[i] == 0){
                        //no loop
                        vV[i] = 1;
                        stack.push_back(i);
                        cout<<"no loop from: "<<cv<<" to: "<<i<<endl;
                        loopS.push_back(i);
                    }else{
                        //loop
                        // cout<<"from: "<<cv<<" to: "<<i<<" there will be a loop"<<endl;
                    }
                }
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

void kruskal(int **graph, int graphSize, int **newGraph){
    
    /**
     * is every vertex visited
     * no 
     * find the minimum vertex to vertex connection
     * check if you add it to the new graph there will be a loop
     * store the verticies that doesn't make a loop
     * if there is no loop then add it to the graph
     * continue until all verticies are visited
     * yes end
     * 
     */
    if(isEveryVertexVisited() == false){
        cout<<"kruskal"<<endl;

        vertexConnection* vt = findTheMinimumConnection(graph,graphSize);
        cout<<vt->connectionFromVertex<<" "<<vt->connectionToVertex<<" "<<vt->connectionWeight<<endl;

        addTheConnectionsToTheNewGraph(newGraph,vt);
        
        for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            if(newGraph[i][j] !=0){
                stack.push_back(j);
                cout<<j<<endl;
                break;
            }
        }
            break;
    }

    // vV[stack.back()] = 1;
    // dfs(newGraph);
        
        dfs(newGraph);
        for(int i: loopS){
            cout<<i<<" ";
        }
        cout<<endl;
        // check for loop
    }

    
}






int main(){
    int graphCp[graphSize][graphSize] = {
       //0 1 2 3
        {0,1,2,0}, //0
        {1,0,2,3}, //1
        {2,2,0,2}, //2
        {0,3,2,0}  //3
	};    
    
    
    

    int **graph = new int*[graphSize];
    // make this function
    for(int i=0; i<graphSize;i++){
            graph[i] = new int[graphSize];
    }
    // make this function
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            graph[i][j] = graphCp[i][j];
            // cout<<graph[i][j]<<" ";
        }
    }

    int **newGraph = new int*[graphSize];
    for(int i=0;i<graphSize;i++){
        newGraph[i] = new int[graphSize];
    }

    // dfs(graph);
    kruskal(graph, graphSize, newGraph);

    
    

    
    
    


    
    
    

}