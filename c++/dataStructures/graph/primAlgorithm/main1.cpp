#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/graph/GraphUtil.h"
#include "/home/home/Desktop/programming/c++/dataStructures/graph/kruskalAlgorithm/CycleDetector.cpp"


using namespace std;

class Graph{
    public:
    int **graph = nullptr;
    int graphSize;
    bool *verticiesVisited = nullptr;
};

class MDFS : Graph{

    
};


class DFS{
    
    int **graph = nullptr;
    int graphSize;
    bool *visitedVerticies = nullptr;
    vector<int> stack;
    vector<int> path;

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
            // cout<<currentVertex<<' ';
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
        int notValidVertex = -1;
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
        stack.push_back(getFirstValidVertex());
        dfs();

        return path;
    }
};


class Prim{
    public:
    int graphSize;
    int **graph = nullptr;
    int **spanningTree = nullptr;
    int totalVerticies = 0;
    vector<int> stack;
    DFS* dfs  = nullptr;
    vertexConnection* minimumVertexConnection = nullptr;


    //TODO: find minimum connection weight in GraphUtil

    Prim(int *g, int graphSize){
        GraphUtil::initializeGraph(&graph,graphSize);
        GraphUtil::setGraphSize(this->graphSize,graphSize);

        GraphUtil::initializeGraph(&spanningTree,graphSize);
        Printer::printGraph(spanningTree,graphSize);

        GraphUtil::copyTheWeightsFromSourceGraph(&graph,(int* )g,graphSize);
        dfs = new DFS(graph,graphSize);

        if(dfs->getPath().size() != graphSize){
            cout<<" not all verticies are connected"<<endl;
            cout<<"call destructur"<<endl;
            delete this;
        }

        minimumVertexConnection = GraphUtil::findMinimumVertexConnection(graph,graphSize);

        GraphUtil::addWeightToGraph(spanningTree,minimumVertexConnection);
        cout<<endl;
        Printer::printGraph(spanningTree,graphSize);

        CycleDetector* cd  = new CycleDetector(spanningTree,graphSize);
        // cout<<boolalpha<<cd->isThereACycle()<<endl;


    }



    // class DFS vector getPath 



};




int main(){
    int graphSize = 5;
    int graph[graphSize][graphSize] = {
        // {0,1,1,1,1},
        // {1,0,1,1,1},
        // {1,1,0,1,1},
        // {0,0,0,1,0},
        // {1,1,1,1,0}
        

        
        {0, 9, 75, 0, 0},
        {9, 0, 95, 19, 42},
        {75, 95, 0, 51, 66},
        {0, 19, 51, 0, 31},
        {0, 42, 66, 31, 0}
        
    };

    // for(int i=0;i<graphSize;i++){
    //     for(int j=0;j<graphSize;j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    Prim* p = new Prim((int*)graph, graphSize);
    // p->span();
    // p->path();
    // int **graphCopy = nullptr;
    // GraphUtil::initializeGraph(&graphCopy,graphSize);
    // GraphUtil::copyTheWeightsFromSourceGraph(&graphCopy, (int* ) graph, graphSize);

    // int **spanningTree = nullptr;
    // GraphUtil::initializeGraph(&spanningTree,graphSize);

    // prim();

}