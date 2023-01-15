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
    // if(isEveryVertexVisited() == false){
    //     cout<<"kruskal"<<endl;

    //     vertexConnection* vt = findTheMinimumConnection(graph,graphSize);
    //     cout<<vt->connectionFromVertex<<" "<<vt->connectionToVertex<<" "<<vt->connectionWeight<<endl;

    //     addTheConnectionsToTheNewGraph(newGraph,vt);
        
    //     for(int i=0;i<graphSize;i++){
    //     for(int j=0;j<graphSize;j++){
    //         if(newGraph[i][j] !=0){
    //             stack.push_back(j);
    //             cout<<j<<endl;
    //             break;
    //         }
    //     }
    //         break;
    // }

    // // vV[stack.back()] = 1;
    // // dfs(newGraph);
        
    //     dfs(newGraph);
    //     for(int i: loopS){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    //     // check for loop
    // }

    
}


//TO DO: make algorithm that check for loops



int main(){
    int graphCp[graphSize][graphSize] = {
       //0 1 2 3
        {0,1,0,0}, //0
        {1,0,2,3}, //1
        {0,2,0,2}, //2
        {0,3,0,0}  //3
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
    // kruskal(graph, graphSize, newGraph);

    //  only store verticies that have more than one connection
    // 


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
        cout<<"current vertex: "<<potentialLoopVerticies[i]->vertexNumber<<endl;
        
        // loop each vertex connections
        // loop and see if the connection from the current vertex occur in the other
        for(int j=0;j<potentialLoopVerticies[i]->connections.size();j++){
            cout<<"connection: "<<potentialLoopVerticies[i]->connections[j]<<endl; // connection from the current vertex
            cout<<"checking if that connection occur in the other verticies"<<endl;

            //loop all verticies
            // loop throug all verticies except the current vertex to check for similar connections
            for(int z=0;z<potentialLoopVerticies.size();z++){
                //show all verticies except the current one
                // all other verticies except the current vertex
                if(potentialLoopVerticies[i]->vertexNumber != potentialLoopVerticies[z]->vertexNumber){
                    cout<<"vertex: "<<potentialLoopVerticies[z]->vertexNumber<<" : ";

                    //loop the connections from the verticies and check for similar
                    //looping throught the other verticies connections and checking for repeted connections
                    for(int y =0 ; y< potentialLoopVerticies[z]->connections.size();y++){
                        cout<<potentialLoopVerticies[z]->connections[y]<<" ";
                        if(potentialLoopVerticies[i]->connections[j] == potentialLoopVerticies[z]->connections[y]){
                            cout<<"connection : "<<potentialLoopVerticies[i]->connections[j]<<" occur !!"<<endl;
                            repeatedConnections++;
                        }
                    }cout<<endl;
                }
            }

        }cout<<endl;       
    }
    
    if(repeatedConnections >= 6){
        cout<<"there is a loop"<<endl;
    }else{
        cout<<"there is no loop"<<endl;
    }

    
    
    


    
    
    

}