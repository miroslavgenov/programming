#pragma once

//NOTE: This class is not cleaned



class Bfs:GraphSearcher{
	private:
	std::queue<int> bfsQueue;
	vertexAndChilds** history = nullptr;
	int *currentVertex = nullptr;

	public:
	Bfs(int *, int );

	void clearTheBasicVariables();

	bool isChildVertexAlreadyInParentChilds(int , vertexAndChilds** );

	void initializeHistory();

	public:
std::vector<int> bfs(int startVertex, int *targetVertex = nullptr){	
    int vertexAppendedTheTg;

    clearTheBasicVariables();
    initializeHistory();	

    bfsQueue.push(startVertex);

    while(bfsQueue.empty() == false){

        *currentVertex = bfsQueue.front();

        if(visitedVerticies[*currentVertex] == 0){
            
            path.push_back(*currentVertex);

            visitedVerticies[*currentVertex] = 1;

            for(int i=0;i<graphSize;i++){

                if(graph[*currentVertex][i] != 0 && visitedVerticies[i] == 0){

                    if(isChildVertexAlreadyInParentChilds(i,history) == false && targetVertex != nullptr){
                        
                        history[*currentVertex]->child.push_back(i);

                        bfsQueue.push(i);

                        if(i == *targetVertex ){
                            
                            path.push_back(i);

                            vertexAppendedTheTg=*currentVertex;
                            makeStartVertexPathToTargetVertexPathReadable(*targetVertex,history);
                            return path;
                        }
                    }else{
                        bfsQueue.push(i);							
                    }

                }
            }
        }
        bfsQueue.pop();
    }

    return path;
}

	std::vector<int> getPath();

	void printPath(std::vector<int> );


	private:
	int getTheParrentOfThatChildVertex(int , vertexAndChilds** );

	std::vector<int> getTheChildernsAndTheStartingParent(int , vertexAndChilds** );

	std::vector<int> getThePathReversed();

	void makeStartVertexPathToTargetVertexPathReadable(int , vertexAndChilds** );

};