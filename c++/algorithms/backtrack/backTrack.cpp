#include <iostream>
#include <fstream>

#define MAZE_SIZE 10

using namespace std;

void printTheResultAndSaveItInFile(int [][MAZE_SIZE]);

void backTrack(int [][MAZE_SIZE], int , int );

int maze[MAZE_SIZE][MAZE_SIZE] = {
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,2,2,0,2,0,0,0,2},
	{0,0,0,0,0,0,0,2,2,2},
	{2,0,2,0,0,0,0,0,0,2},
	{0,0,0,2,2,2,0,0,0,2},
	{0,0,0,0,0,0,2,2,0,2},
	{0,0,0,0,0,0,0,2,2,2},
	{0,0,0,0,2,0,0,0,0,2},
	{0,2,2,0,0,2,2,0,0,2},
	{0,0,0,0,0,2,2,0,0,0}

};

bool canGoThere(int maze[][MAZE_SIZE], int i, int j){
	return maze[i][j] != 2;
}


int main(){
	backTrack(maze, 0,0);
}


void printTheResultAndSaveItInFile(int maze[][MAZE_SIZE]){
	ofstream outPutFileStream;
	string fileName = "allMazeSolutions.txt";
	auto appendToFile= std::ios_base::app;
	outPutFileStream.open(fileName, appendToFile);
	outPutFileStream<<endl;

	for(int i = 0; i < MAZE_SIZE; i++){
		for(int j = 0; j < MAZE_SIZE; j++){
			cout<<maze[i][j]<<" ";
			outPutFileStream<<maze[i][j]<<' ';
		}cout<<endl;
		outPutFileStream<<endl;
	}
	outPutFileStream<<endl;
	cout<<endl;
}


void backTrack(int maze[][MAZE_SIZE], int i, int j){
	if(maze[MAZE_SIZE - 1][MAZE_SIZE - 1] == 1){ 
		printTheResultAndSaveItInFile(maze);
		cout<<"solved"<<endl;
		return ;
	}
	else if(!canGoThere(maze,i,j)){
		return;
	}else{
		if(j == MAZE_SIZE){
			backTrack(maze, i, j + 1);
		}
		if(j < MAZE_SIZE && i < MAZE_SIZE){
			maze[i][j] = 1;
			
			backTrack(maze, i, j + 1);
			
			backTrack(maze, i + 1, j);
			maze[i][j] = 0;
		
		}
	}
}






























































