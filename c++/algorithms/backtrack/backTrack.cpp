#include <iostream>
#include <fstream>


using namespace std;

const size_t MAZE_SIZE = 10;
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

void printMaze(int maze[]){
	for(int i=0;i<MAZE_SIZE;i++){
		cout<<maze[i]<<" ";
	}cout<<endl;
}
void printMaze(int maze[][MAZE_SIZE]){
	ofstream of;
	of.open("allMazeSolutions.txt", std::ios_base::app);
	of<<endl;
	for(int i=0;i<MAZE_SIZE;i++){
		for(int j=0;j<MAZE_SIZE;j++){
			cout<<maze[i][j]<<" ";
			of<<maze[i][j]<<' ';
		}cout<<endl;
		of<<endl;
	}
	of<<endl;
	cout<<endl;
}

void backTrack(int maze[], int i){
  if(maze[i] == 2){
  	cout<<"maze end"<<endl;
  	return;
  }else{
  	maze[i] = 1;
  	printMaze(maze);
  	backTrack(maze, i+1);
  }
  maze[i] = 0;
  
}
void backTrack(int maze[][MAZE_SIZE], int i, int j){
	if(maze[MAZE_SIZE-1][MAZE_SIZE-1] == 1){ 
		printMaze(maze);
		cout<<"solved"<<endl;
		return ;
	}
	else if(maze[i][j] == 2){
//		cout<<"maze end"<<endl;
		return;
	}else{
		if(j == MAZE_SIZE){
			backTrack(maze,i,j+1);
		}
		if(j < MAZE_SIZE && i<MAZE_SIZE){
			maze[i][j] = 1;
			
			
			backTrack(maze,i,j+1);
			
			backTrack(maze,i+1,j);
			maze[i][j] = 0;
		
		}
	}
		
	
	
	

}
int main(){
	backTrack(maze, 0,0);
	

	



	
	



}
































































