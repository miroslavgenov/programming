#include <iostream>

using namespace std;
int queens = 8;
const size_t CHESS_TABLE_SIZE = 8;
int chessTable[CHESS_TABLE_SIZE][CHESS_TABLE_SIZE] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}, // 3,1
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};
int chessSquare;


void printChessTable(){
	cout<<endl;
	for(int i = 0; i < CHESS_TABLE_SIZE; i++){
		for(int j = 0; j < CHESS_TABLE_SIZE; j++){
			cout<<chessTable[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}


bool isChessSquareEmpty(int square){
	return square == 0;
}


bool isTheRowInChessTableEmpty(int rowNumber){	
	for(int column = 0; column < CHESS_TABLE_SIZE; column++){
		chessSquare = chessTable[rowNumber][column];
		if(!isChessSquareEmpty(chessSquare)){
			return false;
		}
	}
	return true;
}

bool isTheColumnsInChessTableEmpty(int columnNumber){
	for(int row = 0; row < CHESS_TABLE_SIZE; row++){
		chessSquare = chessTable[row][columnNumber];
		if(!isChessSquareEmpty(chessSquare)){
			return false;
		}
	}
	return 1;
}

bool isTheLeftDiagonalInChessTableEmpty(int rowNumber, int columnNumber){
	for(int i = rowNumber + 1, j = 1; i < CHESS_TABLE_SIZE; i++, j++){			
		chessSquare = chessTable[i][columnNumber+j];
		if(!isChessSquareEmpty(chessSquare)){
			return 0;
		}
	}
	for(int i = rowNumber -1 , j = columnNumber-1; i >= 0; i--, j--){
		chessSquare = chessTable[i][j];
		if(!isChessSquareEmpty(chessSquare)){
			return 0 ;
		}
	}

	return 1;
}
bool isTheRightDiagonalInChessTableEmpty(int rowNumber, int columnNumber){
	
	
	for(int i = rowNumber-1 ,j = columnNumber+1 ;i >= 0; i--, j++){

		chessSquare = chessTable[i][j];
		if(!isChessSquareEmpty(chessSquare)){
			return 0 ;
		}
	}
	for(int i = rowNumber+1, j = columnNumber -1 ; j>=0;j--,i++){

		chessSquare = chessTable[i][j];
		if(!isChessSquareEmpty(chessSquare)){
			return 0 ;
		}
	}

	return 1;
}

bool isChessSquareInConflict(int rowNumber, int columnNumber){
	return !isTheLeftDiagonalInChessTableEmpty(rowNumber, columnNumber) || !isTheRightDiagonalInChessTableEmpty(rowNumber,columnNumber) ||
		!isTheColumnsInChessTableEmpty(columnNumber) || !isTheRowInChessTableEmpty(rowNumber);
}

bool canYouPlaceQueenThere(int rowNumber, int columnNumber){
	return !isChessSquareInConflict(rowNumber, columnNumber);
}

int cn = 0;

void bc(){
	int i,j;

	if(cn == queens){
		printChessTable();
		cout<<"!!!solved!!!!"<<endl;
		return;
	}

	for(i=0;i<CHESS_TABLE_SIZE;i++){
		for(j=0;j<CHESS_TABLE_SIZE;j++){
			if(canYouPlaceQueenThere(i,j)){
				chessTable[i][j] = 1;
				cn++;
				bc();
				chessTable[i][j] = 0;
				cn--;
			}
		}
	}
}

int main(){
	bc();	
}