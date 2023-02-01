// lenght before 587
#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/GraphFlags.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/vertexConnections.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/KruskalUtil.h"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/Kruskal.h"

using namespace std;

// static bool cycleAuthentication(int repeatedConnections){
//         return repeatedConnections >= 6;
//     }

//  void pushAllVerticiesNumber(int graphSize,std::vector<vertexConnections*>& container){
//         for(int vertexNumber = 0; vertexNumber < graphSize; vertexNumber++){
//             container.push_back(new vertexConnections{vertexNumber});
//         }
//     }

//      void pushAllValidVertexConnections(int** graph,int graphSize,std::vector<vertexConnections*>& listWithVertexConnections){
//         for(int i=0;i<graphSize;i++){
//             for(int j=0;j<graphSize;j++){
//                 if(isConnectionValid(graph[i][j])){
//                     listWithVertexConnections[i]->connections.push_back(j);
//                 }
//             }
//         }
//     }

//      std::vector<vertexConnections*> getOnlyTheVerticiesWithMoreThanOneConnections(std::vector<vertexConnections*> listWithVertexConnections){
//         std::vector<vertexConnections*> potentialLoopVerticies; 
//         for(int i = 0 ;i< listWithVertexConnections.size();i++){
//             if(listWithVertexConnections[i]->connections.size()>=2){
//             potentialLoopVerticies.push_back(listWithVertexConnections[i]);
//             }
//         }

//         return potentialLoopVerticies;

//     }

//  bool isThereACycle(int **graph, int graphSize){
//     //get the connections
//     std::vector<vertexConnections*> listWithVertexConnections;
//     pushAllVerticiesNumber(graphSize, listWithVertexConnections);
//     pushAllValidVertexConnections(graph,graphSize,listWithVertexConnections);
    
//     std::vector<vertexConnections*> potentialLoopVerticies = getOnlyTheVerticiesWithMoreThanOneConnections(listWithVertexConnections);
   
//     //loop detector
//     int repeatedConnections = 0;

//     // loop each vertex
//     for(int i=0;i<potentialLoopVerticies.size();i++){
//         // cout<<"current vertex: "<<potentialLoopVerticies[i]->vertexNumber<<endl;
        
//         // loop each vertex connections
//         // loop and see if the connection from the current vertex occur in the other
//         for(int j=0;j<potentialLoopVerticies[i]->connections.size();j++){
//             // cout<<"connection: "<<potentialLoopVerticies[i]->connections[j]<<endl; // connection from the current vertex
//             // cout<<"checking if that connection occur in the other verticies"<<endl;

//             //loop all verticies
//             // loop throug all verticies except the current vertex to check for similar connections
//             for(int z=0;z<potentialLoopVerticies.size();z++){
//                 //show all verticies except the current one
//                 // all other verticies except the current vertex
//                 if(potentialLoopVerticies[i]->vertexNumber != potentialLoopVerticies[z]->vertexNumber){
//                     // cout<<"vertex: "<<potentialLoopVerticies[z]->vertexNumber<<" : ";

//                     //loop the connections from the verticies and check for similar
//                     //looping throught the other verticies connections and checking for repeted connections
//                     for(int y =0 ; y< potentialLoopVerticies[z]->connections.size();y++){
//                         // cout<<potentialLoopVerticies[z]->connections[y]<<" ";
//                         if(potentialLoopVerticies[i]->connections[j] == potentialLoopVerticies[z]->connections[y]){
//                             // cout<<"connection : "<<potentialLoopVerticies[i]->connections[j]<<" occur !!"<<endl;
//                             repeatedConnections++;
//                         }
//                     }
//                     // cout<<endl;
//                 }
//             }

//         }
//         // cout<<endl;       
//     }
    
//     return cycleAuthentication(repeatedConnections);
// }



class CycleDetector{
    public:
    int **graph = nullptr;
    int graphSize;
    vector<vertexConnections*> listWithVertexConnections;
    vector<vertexConnections*> verticiesWithMoreThanOneConnection; //verticiesWithMoreThanOneConnection
    int repeatedConnections =0;

    void pushNewVertexNumber(int vertexNumber){
        listWithVertexConnections.push_back(new vertexConnections{vertexNumber});
    }

    void pushAllVerticiesNumber(){
        for(int vertexNumber = 0; vertexNumber < graphSize; vertexNumber++){
            pushNewVertexNumber(vertexNumber);
        }
    }

    void pushAllValidVertexConnections(){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0){
                    listWithVertexConnections[i]->connections.push_back(j);
                }
            }
        }
    }

    void setOnlyTheVerticiesWithMoreThanOneConnection(){
        for(int i=0;i<listWithVertexConnections.size();i++){
            if(listWithVertexConnections[i]->connections.size() >= 2){
                // cout<<listWithVertexConnections[i]->vertexNumber<<" ";
                verticiesWithMoreThanOneConnection.push_back(listWithVertexConnections[i]);
            }
        }
    }

    CycleDetector(int **sourceGraph, int sourceGraphSize){
        // copy the graph
        KruskalUtil::setGraphSize(graphSize,sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph,sourceGraph,graphSize);
        // Printer::printGraph(graph,graphSize);

        pushAllVerticiesNumber();
        pushAllValidVertexConnections();
        setOnlyTheVerticiesWithMoreThanOneConnection();

        countForConnectionRepetitions();

        cout<<boolalpha<<isThereACycle()<<endl; 
    }   

    void countHowMuchTimeAVertexNumberAppearsInVertexConnections(int vertexNumber, vector<int> connections){
        for(int i=0;i<connections.size();i++){
            if(vertexNumber == connections[i]){
                repeatedConnections++;
            }
        }
    }


    void countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(int currentVertexNumber,int aVertexNumber){
        
        vector<int> connections;
        for(int i = 0 ; i < verticiesWithMoreThanOneConnection.size(); i++){
            if(currentVertexNumber != verticiesWithMoreThanOneConnection[i]->vertexNumber){
                connections = verticiesWithMoreThanOneConnection[i]->connections;
                countHowMuchTimeAVertexNumberAppearsInVertexConnections(aVertexNumber, connections);        
            }
        }
    }

    void countForConnectionRepetitions(){
        int currentVertexNumber;
        int aVertexNumber;
         for(int i = 0; i < verticiesWithMoreThanOneConnection.size(); i++){
            for(int j = 0; j < verticiesWithMoreThanOneConnection[i]->connections.size(); j++){
                currentVertexNumber = verticiesWithMoreThanOneConnection[i]->vertexNumber;
                aVertexNumber = verticiesWithMoreThanOneConnection[i]->connections[j];
                countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(currentVertexNumber,aVertexNumber);
            } 
        }
    }

    bool isThereACycle(){
        return repeatedConnections >= 6;
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

    CycleDetector* c = new CycleDetector(graph,graphSize);

    // Kruskal* k = new Kruskal(graph, graphSize);
    // k->findPath();
}