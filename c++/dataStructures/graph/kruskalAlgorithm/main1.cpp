// lenght before 587
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

    static bool areAllVerticiesVisited(bool *visitedVerticies, int graphSize){
        bool allVerticiesAreVisited = true;
        bool notAllVerticiesAreVisited = false;
        bool isCurrentVertexVisited;

        for(int i=0;i<graphSize;i++){
            isCurrentVertexVisited = visitedVerticies[i];
                if(isCurrentVertexVisited == 0){
                    return notAllVerticiesAreVisited;
                }
        }
        return allVerticiesAreVisited;
    }

    static void clearVisitedVerticies(bool **visitedVerticies, int graphSize){
        for(int i=0;i<graphSize;i++){
            *(*visitedVerticies+i) = 0;
        }
    }

static bool isThereACycle(int **graph, int graphSize){

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
    
    return cycleAuthentication(repeatedConnections);
}
    static void removeWeightFromGraph(int **graph,vertexConnection* mv){
        mv->connectionWeight = 0;
        addWeightToGraph(graph,mv);
    }
    
    static void addWeightToGraph(int **graph, vertexConnection* mv){
        graph[mv->connectionFromVertex][mv->connectionToVertex] = mv->connectionWeight;
        graph[mv->connectionToVertex][mv->connectionFromVertex] = mv->connectionWeight;
    }

    static void clearMinimumVertexConnectionAndConnectionWeight(vertexConnection** mV, int &mCW){
        *mV = nullptr;
        mCW = 0;
    }

    static void setMinimumConnectionWeight(int &minimumConnectionWeight, int sourceValue){
        minimumConnectionWeight = sourceValue;
    }

    static void setMinimumVertexConnection(vertexConnection** mv,int i, int j, int weight){
        *mv = new vertexConnection{i,j,weight};
    }
};

int KruskalUtil::cycleDeterminationNumber = 6;

class Kruskal{
    public:
    vertexConnection* minimumVertexConnection = nullptr;
    vector<int> stack;
    int minimumConnectionWeight;
    int graphSize;
    int **graph = nullptr;
    int **newGraph = nullptr;
    bool isCycle;
    bool *visitedVerticies = nullptr;
    


    //move into the util class
    void setMinimumVertexConnectionAndMinimumConnectionWeight(int i, int j){
        KruskalUtil::setMinimumConnectionWeight(minimumConnectionWeight,graph[i][j]);
        KruskalUtil::setMinimumVertexConnection(&minimumVertexConnection,i,j,minimumConnectionWeight);
    }

    //move into the util class
    void shouldInitializeMinimumVertexConnectionAndMinimumConnectionWeight(int i,int j){
        if(minimumConnectionWeight == 0){
            setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
        }
    }

    //move into the util class
    void shouldSetTheSmallestWeightConnection(int i, int j){
        if(minimumConnectionWeight !=0){
            if(minimumConnectionWeight > graph[i][j]){
                setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
            }
        }
    }

    bool isMinimumConnectionWeightNotInitialized(){
        return minimumConnectionWeight == 0;
    }

    bool isMinimumConnectionWeightGreaterThan(int i, int j){
        return minimumConnectionWeight > graph[i][j];
    }

    //move into the util class
    void shouldInitializeOrSetTheSmallestWeightConnectionAndVertexConnection(int i,int j){
        shouldInitializeMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
        shouldSetTheSmallestWeightConnection(i,j);
    }

    //move into the util class
    void findTheMinimumConnection(){
        KruskalUtil::clearMinimumVertexConnectionAndConnectionWeight(&minimumVertexConnection,minimumConnectionWeight);

        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0 ){
                    if(isMinimumConnectionWeightNotInitialized()){
                        setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
                    }

                    if(isMinimumConnectionWeightGreaterThan(i,j)){
                        setMinimumVertexConnectionAndMinimumConnectionWeight(i,j);
                    }
                    
                }
            }
        }

    } 

    void findPath(){
        while(KruskalUtil::areAllVerticiesVisited(visitedVerticies,graphSize) == false){
            findTheMinimumConnection();
            KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);

            isCycle = KruskalUtil::isThereACycle(newGraph,graphSize);
            
            if(isCycle == false){
                KruskalUtil::addWeightToGraph(newGraph,minimumVertexConnection);
                KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
            }

            if(isCycle == true){
                KruskalUtil::removeWeightFromGraph(newGraph,minimumVertexConnection);
                KruskalUtil::removeWeightFromGraph(graph,minimumVertexConnection);
            }
            
            prepareStackAndClearVisitedVerticiesForDfs();
            dfs(newGraph);        

        }
        
        print(newGraph, graphSize);

    }

    //move into the util class
    void prepareStackAndClearVisitedVerticiesForDfs(){
            stack.clear();
            stack.push_back(minimumVertexConnection->connectionFromVertex);
            KruskalUtil::clearVisitedVerticies(&visitedVerticies, graphSize);
    }

    //move in to the util class
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

    void prepareForKruskalAlgorithm(int **sourceGraph, int sourceGraphSize){
        KruskalUtil::setGraphSize(graphSize, sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::initializeGraph(&newGraph,graphSize);
        KruskalUtil::initializeVisitedVerticies(&visitedVerticies, graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph, sourceGraph, graphSize);        
    }

    Kruskal(int **sourceGraph, int sourceGraphSize){
        prepareForKruskalAlgorithm(sourceGraph, sourceGraphSize);
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

int main(){
    int  graphSize = 4;
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

    
    Kruskal* k = new Kruskal(graph, graphSize);
    k->findPath();
}