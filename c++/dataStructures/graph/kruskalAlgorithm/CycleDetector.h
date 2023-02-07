#pragma once

class CycleDetector{
    public:
    static int cycleDeterminationNumber;
    int **graph = nullptr;
    int graphSize;
    std::vector<vertexConnections*> listWithVertexConnections;
    std::vector<vertexConnections*> verticiesWithMoreThanOneConnection;
    int repeatedConnections = 0;

    CycleDetector(int **, int );

    void pushAllVerticiesNumber();
    void pushNewVertexNumber(int vertexNumber);

    void pushAllValidVertexConnections();
    
    void setOnlyTheVerticiesWithMoreThanOneConnection();

    void countForConnectionRepetitions();
    void countHowMuchTimesAVertexNumberAppersInTheConnecionsOfTheOthers(int ,int );
    void countHowMuchTimeAVertexNumberAppearsInVertexConnections(int , std::vector<int> );

    bool isThereACycle();
};