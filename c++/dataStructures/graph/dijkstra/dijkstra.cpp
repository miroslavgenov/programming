#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/dijkstra.h"


    void dijkstra::fillVerticiesDistanceWithInfinity(){
        int infinity = std::numeric_limits<int>::max();
	
        for(int i= 0;i<graphSize;i++){
            verticiesDistance[i] = infinity;
        }
    }



    // the two dimension graph must be a square matrix
    dijkstra::dijkstra(int graphInSingleDimension[], int twoDimensionGraphSize){

        // initialize the begining        
        // the graph size must be initialize first to get the verticiesdisnces initialized
        graphSize = twoDimensionGraphSize;

        initializeAndFillVerticiesDistancesWithInfinity();
        
        
        //initializeTheGraphAndFillTheInnerArrays();
        //initializeTheGraph();
        graph = new int*[twoDimensionGraphSize];

        //fillTheInnerArrayOfTheGraph();
        // // fill the outer arrays with inner arrays
        for(int i = 0; i < graphSize; i++){
            graph[i] = new int[twoDimensionGraphSize];
        }

        // // transfer the single graph into two dimension
        int iterator = 0;
        for(int i=0;i<graphSize;i++){
            for(int j=0;j<graphSize;j++){
                 graph[i][j]= graphInSingleDimension[iterator++];
            }
        }

        // // init the stack
        stack = new Stack(new vertexConnection{-1,0,0});
        verticiesDistance[stack->getTop()->connectionToVertex] = 0;
        
        
        
    }




    void dijkstra::initializeAndFillVerticiesDistancesWithInfinity(){
        //NOTE: don't change the order of the function calls
        initializeVerticiesDistance(); 
        fillVerticiesDistanceWithInfinity();
    }

    void dijkstra::initializeVerticiesDistance(){
        verticiesDistance = new int[graphSize];
    }


    void dijkstra::initializeTheGraphAndFillTheInnerArrays(){
        
    }

    void dijkstra::initializeTheGraph(){
        
    }

    void dijkstra::fillTheInnerArrayOfTheGraph(){
        
    }

    // the starting vertex is  0
    void dijkstra::findTheSortestPathToAllVerticies(){

        if(stack->isEmpty() == false){
            // cout<<"not empty"<<endl;
            
            vertexConnection* minvc = DijkstraStackUtil::findTheMinimumConnectionWeight(stack);
            DijkstraStackUtil::removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot, minvc);

            

            // cout<<minvc->connectionFromVertex<<endl;
            int pathWeight=0;
            for(int i=0;i<graphSize;i++){
                if(graph[minvc->connectionToVertex][i] != 0){
                    pathWeight = verticiesDistance[minvc->connectionToVertex] + graph[minvc->connectionToVertex][i];

                    if(verticiesDistance[i] > pathWeight){
                        verticiesDistance[i] = pathWeight;
                        stack->push(new vertexConnection{minvc->connectionToVertex,i,pathWeight});
                    }
                    


                }
            }


                findTheSortestPathToAllVerticies();
            

        }
    }


    void dijkstra::showDistances(){
        for(int i=0;i<graphSize;i++){
            std::cout<<verticiesDistance[i]<<" ";
        }
    }
