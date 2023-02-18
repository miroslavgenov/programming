#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.cpp"


using namespace std;

class Graph{
    public:
    int **graph = nullptr;
    int graphSize;

    Graph(int *sourceGraph,int sourceGraphSize){
        GraphUtil::setGraphSize(graphSize,sourceGraphSize);
        GraphUtil::initializeGraph(&graph,graphSize);
        GraphUtil::copyTheWeightsFromSourceGraph(&graph,(int* )sourceGraph,graphSize);
    }
};



class DFS{
    
    int **graph = nullptr;
    int graphSize;
    bool *visitedVerticies = nullptr;
    vector<int> stack;
    vector<int> path;
    int notValidVertex = -1;
    int validVertex;

    public:

    DFS(int **scrGraph, int scrGraphSize){
        GraphUtil::initializeGraph(&graph,scrGraphSize);
        GraphUtil::initializeVisitedVerticies(&visitedVerticies,graphSize);
        GraphUtil::setGraphSize(graphSize,scrGraphSize);
        GraphUtil::copyTheWeightsFromSourceGraph(&graph,scrGraph,graphSize);
        
    }

    void dfs(){

        if(stack.empty() == false && visitedVerticies[stack.back()] == 0){
            int currentVertex = stack.back();
            stack.pop_back();
            visitedVerticies[currentVertex] = 1;
            path.push_back(currentVertex);

            for(int i=0;i<graphSize;i++){
                if(graph[currentVertex][i] !=0 && visitedVerticies[i] == 0){
                    stack.push_back(i);
                }
            }

            if(stack.empty() == false){
                dfs();
            }

        }
        
    }
    


    int getFirstValidVertex(){
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                if(graph[i][j] !=0){
                    return i;
                }
            }
        }

        return notValidVertex;
    }

    vector<int> getPath(){

        GraphUtil::clearVisitedVerticies(&visitedVerticies,graphSize);
        stack.clear();
        path.clear();
        validVertex = getFirstValidVertex();

        if(validVertex == notValidVertex){
            return path;
        }else{
            stack.push_back(validVertex);
            dfs();
        }
        return path;
    }
};


class Prim:Graph{
    public:
    
    int **spanningTree = nullptr;
    int totalNumberOfVerticies;
    int numberOfConnectedVerticies;
    DFS* dfs  = nullptr;
    vertexConnection* minimumVertexConnection = nullptr;
    CycleDetector* cd = nullptr;

    Prim(int *sourceGraph, int sourceGraphSize):Graph(sourceGraph,sourceGraphSize){
        totalNumberOfVerticies = graphSize;
    
        GraphUtil::initializeGraph(&spanningTree,graphSize);

        
        dfs = new DFS(graph,graphSize);
        cd = new CycleDetector(spanningTree,graphSize);


        if(dfs->getPath().size() != graphSize){
            cout<<" not all verticies are connected"<<endl;
            cout<<"call destructur"<<endl;
            delete this;
        }else{
            this->skelet();
        }
    }

    private:

    bool allVerticiesAreReachable(){
        dfs = new DFS(spanningTree,graphSize);
        numberOfConnectedVerticies = dfs->getPath().size();
        return numberOfConnectedVerticies == totalNumberOfVerticies;
    }

    bool thereIsACycle(){
        cd =  new CycleDetector(spanningTree,graphSize);
        return cd->isThereACycle();
    }

    void skelet(){
        if(allVerticiesAreReachable() == false){
            minimumVertexConnection = GraphUtil::findMinimumVertexConnection(graph, graphSize);

            GraphUtil::addWeightToGraph(spanningTree, minimumVertexConnection);
            GraphUtil::removeWeightFromGraph(graph, minimumVertexConnection);

            if(thereIsACycle()){
                GraphUtil::removeWeightFromGraph(spanningTree, minimumVertexConnection);
            }

            skelet();
            
        }
    }

    public:
    int** getSpanningTree(){
        return spanningTree;
    }

};



class Test:Graph{
    public:
    Test(int *g, int gs):Graph(g,gs){
        Printer::printGraph(graph,graphSize);
    }
    
};


int main(){
    int graphSize = 5;
    int graph[graphSize][graphSize] = {      
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
    };

    Prim* p = new Prim((int*)graph, graphSize);
    
    Printer::printGraph(p->getSpanningTree(),graphSize);
}