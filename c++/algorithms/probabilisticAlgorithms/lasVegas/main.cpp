#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


struct chessSquare{
	int rowNumber;
	int columnNumber;
};

class ChessBoardUtil{
	public:
	static int MARKED_SYMBOL;

	static bool isThereAQueenOnTheChessBoard(int* chessBoard, int CHESS_BOARD_SIZE){
		for(int i = 0;i<CHESS_BOARD_SIZE*CHESS_BOARD_SIZE;i++){
			if(chessBoard[i] == 1){
				return 1;
			}
		}
		return 0;
	}

	static void clearAllMarkedChessSquaresInConflict(int *chessBoard, int CHESS_BOARD_SIZE){
		for(int i=0;i<CHESS_BOARD_SIZE*CHESS_BOARD_SIZE;i++){
			if(chessBoard[i] == MARKED_SYMBOL){
				chessBoard[i] =0;
			}
		}
	}

	static void clearTheChessBoard(int* chessBoard, int CHESS_BOARD_SIZE){
		for(int i = 0; i < CHESS_BOARD_SIZE*CHESS_BOARD_SIZE; i++){
			chessBoard[i] = 0;
		}
	}

	static vector<chessSquare*> getAllQueensCoordinatesWhichAreOnTheChessBoard(int* chessBoard, int CHESS_BOARD_SIZE){
		vector<chessSquare*> queensCoordinates;

		for(int i = 0; i < CHESS_BOARD_SIZE; i++){
			for(int j = 0; j < CHESS_BOARD_SIZE; j++){
				if(chessBoard[i*CHESS_BOARD_SIZE + j] == 1){
					queensCoordinates.push_back(new chessSquare{i,j});
				}
			}
		}
		return queensCoordinates;
	}

};

int ChessBoardUtil::MARKED_SYMBOL = 2;



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

//ChessBoardUtil
vector<chessSquare*> getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen(){
	vector<chessSquare*> freeChessSquaresCoordinates;

	vector<chessSquare*> queensCoordinates = ChessBoardUtil::getAllQueensCoordinatesWhichAreOnTheChessBoard((int*)chessBoard,CHESS_BOARD_SIZE);
	
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


void lasVegas(){
	srand(time(0));
	
	vector<chessSquare*> freeToPlaceCoordinates = getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
	int choosenFreeToPlaceCoordinatesIndex ;
	chessSquare* freeCoordinate = nullptr;

	// while(queenPlaced < 8){
		while(freeToPlaceCoordinates.size()>0){
			// cout<<"freeToPlaceCoordinates size: "<<freeToPlaceCoordinates.size()<<endl;
			choosenFreeToPlaceCoordinatesIndex = rand() % (freeToPlaceCoordinates.size());

			// cout<<"total free chessSquare's: "<<freeToPlaceCoordinates.size()<<endl;
			// cout<<"the choosedCoordinaes are at index: "<<choosenFreeToPlaceCoordinatesIndex<<" the chessSquare is: "<<endl;
			// printChessSquareCoordinates(freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]);
			 freeCoordinate = new chessSquare{
				freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]->rowNumber,
			 	freeToPlaceCoordinates[choosenFreeToPlaceCoordinatesIndex]->columnNumber
			 };

			chessBoard[freeCoordinate->rowNumber][freeCoordinate->columnNumber] = 1;
			queenPlaced++;

			for(int i=0;i<freeToPlaceCoordinates.size();i++){
				delete freeToPlaceCoordinates[i];
			}
			delete freeCoordinate;
			freeToPlaceCoordinates = getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
			
		}	
			if(freeToPlaceCoordinates.size() == 0 && queenPlaced != 8){
				ChessBoardUtil::clearAllMarkedChessSquaresInConflict((int*)chessBoard, CHESS_BOARD_SIZE);
				// printChessBoard();
				// cout<<"queenPlaced: "<<queenPlaced<<endl;
				ChessBoardUtil::clearTheChessBoard((int*)chessBoard, CHESS_BOARD_SIZE);
				queenPlaced=0;
			}else if(queenPlaced == 8){
				ChessBoardUtil::clearAllMarkedChessSquaresInConflict((int*)chessBoard, CHESS_BOARD_SIZE);
			}
		// }
			
}
	




int main(){
	

	cout<<"finding solutions ..."<<endl;
	while(queenPlaced < 8){
		lasVegas();	
	}
	
	cout<<"Solution found"<<endl;

	printChessBoard();
}