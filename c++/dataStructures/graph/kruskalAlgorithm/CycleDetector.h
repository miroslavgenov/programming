#pragma once

class CycleDetector{
    public:
    static int cycleDeterminationNumber;
    int **graph = nullptr;
    int graphSize;
    std::vector<vertexConnections*> listWithVertexConnections;
    std::vector<vertexConnections*> verticiesWithMoreThanOneConnection;
    int repeatedConnections = 0;

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
    
    void pushAllValidVertexConnections(int **graph){
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
                verticiesWithMoreThanOneConnection.push_back(listWithVertexConnections[i]);
            }
        }
    }

	
    CycleDetector(int **sourceGraph, int sourceGraphSize){
        KruskalUtil::setGraphSize(graphSize,sourceGraphSize);
        KruskalUtil::initializeGraph(&graph,graphSize);
        KruskalUtil::copyTheWeightsFromSourceGraph(&graph,sourceGraph,graphSize);

        pushAllVerticiesNumber();
        pushAllValidVertexConnections();
        setOnlyTheVerticiesWithMoreThanOneConnection();

        countForConnectionRepetitions();
    }   
	

	
    void countHowMuchTimeAVertexNumberAppearsInVertexConnections(int vertexNumber, std::vector<int> connections){
        for(int i=0;i<connections.size();i++){
            if(vertexNumber == connections[i]){
                repeatedConnections++;
            }
        }
    }


    void countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(int currentVertexNumber,int aVertexNumber){
        std::vector<int> connections;
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
        return repeatedConnections >= cycleDeterminationNumber;
    }
};

int CycleDetector::cycleDeterminationNumber = 6;
