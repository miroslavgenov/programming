#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct chessSquare{
	int rowNumber;
	int columnNumber;
};

int QUEENS = 8;
int queenPlaced = 0;
constexpr size_t CHESS_BOARD_SIZE = 8;
int MARKED_SYMBOL = 2;
int chessBoard[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE] = {
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0}
};

bool isThereAQueenOnTheChessBoard(){
	for(int i = 0;i<CHESS_BOARD_SIZE;i++){
		for(int j= 0;j<CHESS_BOARD_SIZE;j++){
			if(chessBoard[i][j] == 1){
				return 1;
			}
		}
	}
	return 0;
}

chessSquare* getTheFirstQueenCoordinatesThatComeIntoView(){
	chessSquare* firstQueenThatComeIntoView = nullptr;
	if(isThereAQueenOnTheChessBoard()){
		for(int i=0;i<CHESS_BOARD_SIZE;i++){
			for(int j=0;j<CHESS_BOARD_SIZE;j++){
				if(chessBoard[i][j] == 1){
					firstQueenThatComeIntoView = new chessSquare{i,j};
					return firstQueenThatComeIntoView;
				}
			}
		}	
	}
	return firstQueenThatComeIntoView;
}

int getTheTotalNumberOfQueensThatAreOnTheChessBoard(){
	int totalNumberOfQueens = 0;
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		for(int j=0;j<CHESS_BOARD_SIZE;j++){
			if(chessBoard[i][j] == 1){
				totalNumberOfQueens++;
			}
		}
	}
	return totalNumberOfQueens;
}


void printChessBoard(){
	cout<<endl<<"  ";
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		cout<<i<<" ";
		for(int j=0;j<CHESS_BOARD_SIZE;j++){
			cout<<chessBoard[i][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
}

void printChessSquareCoordinates(chessSquare* chessSquare){
	if(chessSquare){
		cout<<"rowNumber: "<<chessSquare->rowNumber<<" columnNumber: "<<chessSquare->columnNumber<<endl;
	}else{
		cout<<"chessSquare is nullptr !!"<<endl;
	}
}

vector<chessSquare*> getAllQueensCoordinatesWhichAreOnTheChessBoard(){
	vector<chessSquare*> queensCoordinates;

	for(int i = 0; i < CHESS_BOARD_SIZE; i++){
		for(int j = 0; j < CHESS_BOARD_SIZE; j++){
			if(chessBoard[i][j] == 1){
				queensCoordinates.push_back(new chessSquare{i,j});
			}
		}
	}
	return queensCoordinates;
}

void markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(chessSquare* currentQueen){
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		if(chessBoard[currentQueen->rowNumber][i] != 1){
			chessBoard[currentQueen->rowNumber][i] = MARKED_SYMBOL;
		}
	}
}

void markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(chessSquare *currentQueen){
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		if(chessBoard[i][currentQueen->columnNumber] != 1){
			chessBoard[i][currentQueen->columnNumber] = MARKED_SYMBOL;
		}
	}
}


void markAllChessSquaresInConflictWithCurrentQueenByLeftDiagona(chessSquare* currentQueen){
	
	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i >= 0; i--, j--){
		if(chessBoard[i][j] != 1){
			chessBoard[i][j] = MARKED_SYMBOL;
		}
	}


	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i < CHESS_BOARD_SIZE; i++, j++){
		if(chessBoard[i][j] != 1){
			chessBoard[i][j] = MARKED_SYMBOL;		
		}
	}
}

void markAllChessSquaresInConflictWithCurrentQueenByRightDiagona(chessSquare* currentQueen){
	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; j >= 0 && i<CHESS_BOARD_SIZE; i++, j--){
		if(chessBoard[i][j] != 1){
				chessBoard[i][j] = MARKED_SYMBOL;	
		}
	}
	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i>=0 && j<CHESS_BOARD_SIZE ; i--, j++){
		if(chessBoard[i][j] != 1){
			chessBoard[i][j] = MARKED_SYMBOL;
		}
	}
}

void clearAllMarkedChessSquaresInConflict(){
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		for(int j=0;j<CHESS_BOARD_SIZE;j++){
			if(chessBoard[i][j] == MARKED_SYMBOL){
				chessBoard[i][j] = 0;
			}
		}
	}
}

//toto pass the queen
void markAllChessSquearesThatAreInConflictWithCurrentQueen(chessSquare* currentQueen){
	// cout<<"markAllChessSquearesThatAreInConflictWithCurrentQueen"<<endl;
	if(currentQueen){
		markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(currentQueen);
		markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(currentQueen);
		markAllChessSquaresInConflictWithCurrentQueenByLeftDiagona(currentQueen);
		markAllChessSquaresInConflictWithCurrentQueenByRightDiagona(currentQueen);
	}else{
		cout<<"\t THERE IS NO QUEEN ON THE CHESS BOARD"<<endl;
	}
	
}

vector<chessSquare*> getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen(){
	vector<chessSquare*> freeChessSquaresCoordinates;

	vector<chessSquare*> queensCoordinates = getAllQueensCoordinatesWhichAreOnTheChessBoard();
	
	for(int i=0;i<queensCoordinates.size();i++){
		markAllChessSquearesThatAreInConflictWithCurrentQueen(queensCoordinates[i]);
	}

	for(int i = 0; i < CHESS_BOARD_SIZE; i++){
		for(int j = 0; j < CHESS_BOARD_SIZE; j++){
			if(chessBoard[i][j] == 0){
				freeChessSquaresCoordinates.push_back(new chessSquare{i,j});
			}
		}
	}
	// clearAllMarkedChessSquaresInConflict();

	return freeChessSquaresCoordinates;
}

void clearTheChessBoard(){
	for(int i = 0; i < CHESS_BOARD_SIZE; i++){
		for(int j = 0; j < CHESS_BOARD_SIZE; j++){
			chessBoard[i][j] = 0;
		}
	}
}

void fillChessBoardWithSpecificNumber(int number){
	for(int i = 0; i < CHESS_BOARD_SIZE; i++){
		for(int j = 0; j < CHESS_BOARD_SIZE; j++){
			chessBoard[i][j] = number;
		}
	}
}

void lasVegas(){
	srand(time(0));
	
	vector<chessSquare*> freeToPlaceCoordinates = getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
	int choosenFreeToPlaceCoordinatesIndex ;
	
	// while(queenPlaced < 8){
		while(freeToPlaceCoordinates.size()>0){
			// cout<<"freeToPlaceCoordinates size: "<<freeToPlaceCoordinates.size()<<endl;
			choosenFreeToPlaceCoordinatesIndex = rand() % (freeToPlaceCoordinates.size());

			// cout<<"total free chessSquare's: "<<freeToPlaceCoordinates.size()<<endl;
			// cout<<"the choosedCoordinaes are at index: "<<choosenFreeToPlaceCoordinatesIndex<<" the chessSquare is: "<<endl;
			// printChessSquareCoordinates(freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]);
			chessBoard[freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]->rowNumber][freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]->columnNumber] = 1;
			queenPlaced++;
			for(int i=0;i<freeToPlaceCoordinates.size();i++){
				delete freeToPlaceCoordinates[i];
			}
			freeToPlaceCoordinates = getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
			
		}	
			if(freeToPlaceCoordinates.size() == 0 && queenPlaced != 8){
				clearAllMarkedChessSquaresInConflict();
				// printChessBoard();
				// cout<<"queenPlaced: "<<queenPlaced<<endl;
				clearTheChessBoard();
				queenPlaced=0;
			}else if(queenPlaced == 8){
				clearAllMarkedChessSquaresInConflict();
			}
		// }
			
}
	

	


int main(){
	cout<<"Searching for solution! ..."<<endl;
	
	while(queenPlaced < 8){
		lasVegas();	
	}
	
	cout<<"Solution found"<<endl;

	printChessBoard();



	

	

	

}
