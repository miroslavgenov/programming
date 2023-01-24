#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/GraphFlags.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/vertexConnections.h"

using namespace std;

class KruskalUtil{
    public:

    static int cycleDeterminationNumber;

    static bool cycleAuthentication(int repeatedConnections){
        return repeatedConnections >= cycleDeterminationNumber;
    }

    static void initializeGraph(int ***graph, int graphSize){
        *graph = new int*[graphSize];

        for(int i=0;i<graphSize;i++){
            *(*graph+i) = new int[graphSize];
        }
    }

    static void initializeVisitedVerticies(bool **visitedVerticies, int graphSize){
        *visitedVerticies = new bool[graphSize];
    }

    static void setGraphSize(int &destinationGraphSize, int sourceGraphSize){
        destinationGraphSize = sourceGraphSize;
    }

    static void copyTheWeightsFromSourceGraph(int ***destinationGraph, int **sourceGraph, int graphSize){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                *(*(*destinationGraph+j)+i) = sourceGraph[i][j];
            }
        }        
    }

    

};

int KruskalUtil::cycleDeterminationNumber = 6;

class Kruskal{
    public:
    vertexConnection* minimumVertexConnection = nullptr;
    int minimumConnectionWeight;
    
    int graphSize;
    int **graph = nullptr;
    int **newGraph = nullptr;

    bool isCycle;
    bool *visitedVerticies = nullptr;
    
    void clearMinimumVertexConnectionAndConnectionWeight(){
        minimumVertexConnection = nullptr;
        minimumConnectionWeight = 0;
    }

    void setMinimumConnectionWeight(int i,int j){
            minimumConnectionWeight = graph[i][j];
    }

    void setMinimumVertexConnection(int i, int j){
        minimumVertexConnection = new vertexConnection{i,j,graph[i][j]};
    }

    void setMinimumVertexConnectionAndMinimumConnectionWeight(int i, int j){
        setMinimumConnectionWeight(i,j);
            setMinimumVertexConnection(i,j);
    }

    void shouldInitializeMinimumVertexConnectionAndMinimumConnectionWeight(int i,int j){
        if(minimumConnectionWeight == 0){
            setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
        }
    }

    void shouldSetTheSmallestWeightConnection(int i, int j){
        if(minimumConnectionWeight !=0){
            if(minimumConnectionWeight > graph[i][j]){
                setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
            }
        }
    }

    void shouldInitializeOrSetTheSmallestWeightConnectionAndVertexConnection(int i,int j){
        shouldInitializeMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
        shouldSetTheSmallestWeightConnection(i,j);
    }

    void findTheMinimumConnection(){
        clearMinimumVertexConnectionAndConnectionWeight();

        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0 ){
                    shouldInitializeOrSetTheSmallestWeightConnectionAndVertexConnection(i,j);
                }
            }
        }

    }

    void addWeightToGraph(int i, int j, int weight){
        graph[i][j] = weight;
        graph[j][i] = weight;
    }

    void removeWeightFromGraph(int i,int j){
        addWeightToGraph(i,j,0);
    }
    

    void findPath(){

    }

    Kruskal(int **sourceGraph, int sourceGraphSize){
        KruskalUtil::setGraphSize(graphSize, sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::initializeGraph(&newGraph,graphSize);
        KruskalUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
        
        findTheMinimumConnection();
        if(minimumVertexConnection != nullptr){
            this->removeWeightFromGraph(minimumVertexConnection->connectionFromVertex,minimumVertexConnection->connectionToVertex);

        }
        print();
    }
    
    void print(int **graph,int graphSize){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
             cout<<graph[i][j]<<" ";
            }cout<<endl;
        }
    }

    void print(){
        print(graph,graphSize);
    }
};

// class variables
vector<int> stack;
constexpr int graphSize = 4;
bool visitedVerticies[graphSize]{};

template <typename T>
void print(T array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

void print(int** graph, int graphSize){
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            cout<<graph[i][j]<<" ";
        }cout<<endl;
    }
}

void setTheMinimumConnectionWeight(int &currentWeight, int newWeight){
    currentWeight = newWeight;
}

void setTheMinimumVertexConnection(vertexConnection** min, int i , int j , int weight){
    *min =  new vertexConnection{i,j, weight};
}

vertexConnection* findTheMinimumConnection(int **graph, int graphSize){
    //! only if the graph is not empty !
    vertexConnection *minimumVertexConnection  = nullptr;

    int minimumConnectionWeight = 0;
    for(int i=0;i<graphSize;i++){
        for(int j=0;j<graphSize;j++){
            
            //shouldCheckOnlyConnectedVerticies
            // only check if the weight is different than 0
            if(graph[i][j] !=0 ){
                
                //initialize the minWeight
                //shouldInitializeTheMinimumVerticiesConnectionWeight
                if(minimumConnectionWeight == 0){
                    setTheMinimumConnectionWeight(minimumConnectionWeight, graph[i][j]);
                    setTheMinimumVertexConnection(&minimumVertexConnection, i,j, minimumConnectionWeight);               
                }
                //if the minWeight is initialized
                else{
                    // check if the graphWeight is lesser then the min weight
                    //shouldStoreTheLesserConnectionWeight
                    if(minimumConnectionWeight > graph[i][j]){
                        setTheMinimumConnectionWeight(minimumConnectionWeight, graph[i][j]);
                        setTheMinimumVertexConnection(&minimumVertexConnection, i,j, minimumConnectionWeight);
                    }
                }
            }
        }
    }
    
    return minimumVertexConnection;
}


//NOTE: some error ocure while trying to replace both functions with one
// duplication
// add the connection to a new graph
// void addTheConnectionToNewGraph()
void addConnectionToGraph(int **graph, vertexConnection* vertexConnection){
    int fromVertex = vertexConnection->connectionFromVertex;
    int toVertex = vertexConnection->connectionToVertex;
    int connectionWeight = vertexConnection->connectionWeight;


    graph[fromVertex][toVertex] = connectionWeight;
    graph[toVertex][fromVertex]  = connectionWeight;
}

//duplication
// remove the connection from the old graph
void removeConnectionFromGraph(int **graph, vertexConnection* vertexConnection){
    int fromVertex = vertexConnection->connectionFromVertex;
    int toVertex = vertexConnection->connectionToVertex;
    int connectionWeight = vertexConnection->connectionWeight;


    graph[fromVertex][toVertex] = 0;
    graph[toVertex][fromVertex]  = 0;
}

//custom dfs class
void dfs(int **graph){
    if(stack.empty() == false && visitedVerticies[stack.back()] == 0) {
        
        int currentVertex = stack.back();
        stack.pop_back();
        visitedVerticies[currentVertex] = 1;
        
        for(int i=0;i<graphSize;i++){
            if(graph[currentVertex][i] != 0){
                if(visitedVerticies[i]==0){

                    stack.push_back(i);
                }
            }
        }

        if(stack.empty() == false){
            dfs(graph);
        }
    }    
}




//TO DO: make algorithm that check for loops
// to long function make class or separate into smaller functions
bool isThereACycle(int **graph, int graphSize){

    //get the connections
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
    

    //get only the stack with >= 2 connections more than 2
    vector<vertexConnections*> potentialLoopVerticies;

    for(int i = 0 ;i< listWithVertexConnections.size();i++){
        if(listWithVertexConnections[i]->connections.size()>=2){
            potentialLoopVerticies.push_back(listWithVertexConnections[i]);
        }
    }
    //getting only the stack with >= 2 size

    
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
    
    return KruskalUtil::cycleAuthentication(repeatedConnections);
}

//TODO: areAllVerticiesVisited, clearVisitedVerticies

bool areAllVerticiesVisited(){
    bool isCurrentVertexVisited;

    for(int i=0;i<graphSize;i++){
        isCurrentVertexVisited = visitedVerticies[i];
            if(isCurrentVertexVisited == 0){
                return false;
            }
    }
    return true;
}

void clearVisitedVerticies(){
    for(int i=0;i<graphSize;i++){
        visitedVerticies[i] = 0;
    }
}

void prepareStackForDfs(vertexConnection* mv){
    stack.clear();
    stack.push_back(mv->connectionFromVertex);
}

void prepareStackAndClearTheVisitedVerticiesForDfs(vertexConnection* mv){
    prepareStackForDfs(mv);
    clearVisitedVerticies();
}

void shouldPrepareAndStartDfs(int **graph,vertexConnection* mv){
    if(mv != nullptr){            
        prepareStackAndClearTheVisitedVerticiesForDfs(mv);
        dfs(graph);
    }
}

void shoudClearTheConnectionFromTheOriginGraph(int **graph, bool cycle, vertexConnection* mv){
    if(cycle == GraphFlags::noCycle){
        removeConnectionFromGraph(graph,mv);
    }
}

void shouldClearTheConnectionThatMakesCycleFromBothGraph(int** oldGraph, int** newGraph, bool cycle, vertexConnection **mv){
    if(cycle == GraphFlags::hasACycle){
            removeConnectionFromGraph(newGraph,*mv);
            removeConnectionFromGraph(oldGraph,*mv);
            *mv = nullptr;
        }
}

void kruskal(int **graph, int graphSize, int **newGraph){
    while(areAllVerticiesVisited() == false){
        vertexConnection* mv = findTheMinimumConnection(graph, graphSize);
        addConnectionToGraph(newGraph, mv);
        
        bool cycle = isThereACycle(newGraph,graphSize);

        shoudClearTheConnectionFromTheOriginGraph(graph,cycle,mv);

        shouldClearTheConnectionThatMakesCycleFromBothGraph(graph, newGraph, cycle, &mv);  

        shouldPrepareAndStartDfs(newGraph,mv);
        
    }

    cout<<__func__<<" spanning tree"<<endl;
    print(newGraph,graphSize);
    cout<<endl;
}

int main(){
    int graphCp[graphSize][graphSize] = {
       //0 1 2 3
        {0,10,6,5}, //0
        {10,0,0,15}, //1
        {6,0,0,4}, //2
        {5,15,4,0}  //3
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

    // kruskal(graph, graphSize, newGraph);
    Kruskal* k = new Kruskal(graph, graphSize);
}