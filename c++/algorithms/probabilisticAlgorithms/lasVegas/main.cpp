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

	static void printChessSquareCoordinates(chessSquare* chessSquare){
		if(chessSquare){
			cout<<"rowNumber: "<<chessSquare->rowNumber<<" columnNumber: "<<chessSquare->columnNumber<<endl;
		}else{
			cout<<"chessSquare is nullptr !!"<<endl;
		}
	}

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

//move into ChessTableUtil
static void markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal(int *chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){
	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; j >= 0 && i<CHESS_BOARD_SIZE; i++, j--){
		if(chessBoard[i*CHESS_BOARD_SIZE+j] != 1){
				chessBoard[i*CHESS_BOARD_SIZE+j] = MARKED_SYMBOL;	
		}
	}
}

//move into ChessTableUtil
static void markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal(int *chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){
	for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i>=0 && j<CHESS_BOARD_SIZE ; i--, j++){
		if(chessBoard[i*CHESS_BOARD_SIZE + j] != 1){
			chessBoard[i*CHESS_BOARD_SIZE + j] = MARKED_SYMBOL;
		}
	}
}



//move into ChessTableUtil
static void markAllChessSquaresInConflictWithCurrentQueenByTHeFullTopRightAndBottolLeftDiagonal(int *chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){

	markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal(chessBoard,CHESS_BOARD_SIZE,currentQueen);
	markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal(chessBoard,CHESS_BOARD_SIZE,currentQueen);
}



static void markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(int* chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i >= 0; i--, j--){
		if(chessBoard[i*CHESS_BOARD_SIZE + j] != 1){
			chessBoard[i*CHESS_BOARD_SIZE + j] = MARKED_SYMBOL;
		}
	}
}

static void markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal(int* chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){
for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i < CHESS_BOARD_SIZE; i++, j++){
		if(chessBoard[i*CHESS_BOARD_SIZE + j] != 1){
			chessBoard[i*CHESS_BOARD_SIZE + j] = MARKED_SYMBOL;		
		}
	} 
}

static void markAllChessSquaresInConflictWithCurrentQueenByTheBottomRightAndTopLeftDiagonal(int* chessBoard, int CHESS_BOARD_SIZE, chessSquare* currentQueen){
	markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(chessBoard, CHESS_BOARD_SIZE, currentQueen);
	markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal(chessBoard, CHESS_BOARD_SIZE, currentQueen);	
}

};

int ChessBoardUtil::MARKED_SYMBOL = 2;

class LassVegas{
	public:
	static const int MARKED_SYMBOL;
	static const int FREE_TO_PLACE_SYMBOL;
	static const int size;
	int **chessBoard = nullptr;
	chessSquare* currentQueen = nullptr;
	static const int queenSymbol;
	vector<chessSquare*> queensCoordinatesThatAreOnChessBoard;
	vector<chessSquare*> freeChessSquaresCoordinate;

	int placedQueens;

	LassVegas(){

		chessBoard = new int*[size];

		for(int i=0;i<size;i++){
			chessBoard[i] = new int[size];
		} 

		placedQueens = 0;

		// printChessBoard();
		// lassVegas();

		// chessBoard[4][4] = 1;
		// chessBoard[3][2] = 1;

		// getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
		// printChessBoard();
		this->lassVegas();
		// this->lassVegas();
		printChessBoard();
		


	}

	void clearTheChessBoard(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				chessBoard[i][j] = LassVegas::FREE_TO_PLACE_SYMBOL;
			}
		}
	}

	void getAllQueensCoordinatesWhichAreOnTheChessBoard(){
		queensCoordinatesThatAreOnChessBoard.clear();

		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(chessBoard[i][j] == LassVegas::queenSymbol){
					queensCoordinatesThatAreOnChessBoard.push_back(new chessSquare{i,j});
				}
			}

		}
	}

	void storeAllFreeCoordinates(){
		freeChessSquaresCoordinate.clear();

		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(chessBoard[i][j]  == FREE_TO_PLACE_SYMBOL){
					freeChessSquaresCoordinate.push_back(new chessSquare{i,j});
				}
			}
		}
	}

	void clearAllMarkedChessSquaresInConflict(){
		for(int i =0;i<size;i++){
			for(int j=0;j<size;j++){
				if(chessBoard[i][j] == LassVegas::MARKED_SYMBOL){
					chessBoard[i][j] =0;
				}
			}
		}
	}

	void getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen(){

		getAllQueensCoordinatesWhichAreOnTheChessBoard();
		
		for(int i=0;i<queensCoordinatesThatAreOnChessBoard.size();i++){
			currentQueen = queensCoordinatesThatAreOnChessBoard[i];
			markAllChessSquearesThatAreInConflictWithCurrentQueen();
		}
		
		storeAllFreeCoordinates();
	}

	void lassVegas();

	void printChessBoard(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<chessBoard[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	void markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(){
		for(int i=0;i<size;i++){
			if(chessBoard[currentQueen->rowNumber][i] != 1){
				chessBoard[currentQueen->rowNumber][i] = MARKED_SYMBOL;
			}
		}
	}

	void markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(){
		for(int i=0;i<size;i++){
			if(chessBoard[i][currentQueen->columnNumber] != 1){
				chessBoard[i][currentQueen->columnNumber] = MARKED_SYMBOL;
			}
		}
	}


	void markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; j >= 0 && i<size; i++, j--){
			if(chessBoard[i][j] != 1){
					chessBoard[i][j] = MARKED_SYMBOL;	
			}
		}
	}

	void markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i>=0 && j<size ; i--, j++){
			if(chessBoard[i][j] != 1){
				chessBoard[i][j] = MARKED_SYMBOL;
			}
		}
	}

	void markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i >= 0; i--, j--){
			if(chessBoard[i][j] != 1){
				chessBoard[i][j] = MARKED_SYMBOL;
			}
		}
	}

	void markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i < size; i++, j++){
			if(chessBoard[i][j] != 1){
				chessBoard[i][j] = MARKED_SYMBOL;		
			}
		} 
	}

	void markAllChessSquearesThatAreInConflictWithCurrentQueen(){
		if(
			// if current queen != nullptr
			currentQueen
		){
			// ChessBoardUtil
			markAllChessSquaresInConflictWithTheCurrentQueenRowNumber();
			markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber();
			markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal();
			markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal();
			markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal();
			markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal();

		}else{
			cout<<"\t THERE IS NO QUEEN ON THE CHESS BOARD"<<endl;
		}
		
	}
	
	 
	/**
	THIS FUNCTIONS FIRST GET THE free chessSquare coordinates and save them into
		vector and then checs if the vector.size is > 0 
	
	*/
	bool isThereFreeChessSquare(){
			
		getAllChessSquaresCoordinatesWhereYouCanPlaceAQueen();
		return freeChessSquaresCoordinate.size() > 0;
	}


};

const int LassVegas::size = 8;
const int LassVegas::queenSymbol = 1;
const int LassVegas::MARKED_SYMBOL = 2;
const int LassVegas::FREE_TO_PLACE_SYMBOL = 0;




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



//ChessBoardUtil
void markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(chessSquare* currentQueen){
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		if(chessBoard[currentQueen->rowNumber][i] != 1){
			chessBoard[currentQueen->rowNumber][i] = MARKED_SYMBOL;
		}
	}
}

//ChessBoardUtil
void markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(chessSquare *currentQueen){
	for(int i=0;i<CHESS_BOARD_SIZE;i++){
		if(chessBoard[i][currentQueen->columnNumber] != 1){
			chessBoard[i][currentQueen->columnNumber] = MARKED_SYMBOL;
		}
	}
}




//toto pass the queen
void markAllChessSquearesThatAreInConflictWithCurrentQueen(chessSquare* currentQueen){
	// cout<<"markAllChessSquearesThatAreInConflictWithCurrentQueen"<<endl;
	if(
		// if current queen != nullptr
		currentQueen
	){
		// ChessBoardUtil
		markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(currentQueen);
		markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(currentQueen);


		ChessBoardUtil::markAllChessSquaresInConflictWithCurrentQueenByTheBottomRightAndTopLeftDiagonal((int*)chessBoard,CHESS_BOARD_SIZE,currentQueen);


		ChessBoardUtil::markAllChessSquaresInConflictWithCurrentQueenByTHeFullTopRightAndBottolLeftDiagonal((int*)chessBoard,CHESS_BOARD_SIZE,currentQueen);
		// markAllChessSquaresInConflictWithCurrentQueenByRightDiagona(currentQueen);
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

void LassVegas::lassVegas(){
	//NEED TO FIX THE ALGORITHM
	cout<<__func__<<endl;

	srand(time(0));

	int chooseFreeToPlaceCoordinatesIndex;
	chessSquare* freeCoordinatesToPlaceAQueen = nullptr;

	while(placedQueens<=8 && isThereFreeChessSquare() ){
	chooseFreeToPlaceCoordinatesIndex = rand() % (freeChessSquaresCoordinate.size());


	freeCoordinatesToPlaceAQueen = new chessSquare{
		freeChessSquaresCoordinate[chooseFreeToPlaceCoordinatesIndex]->rowNumber,
		freeChessSquaresCoordinate[chooseFreeToPlaceCoordinatesIndex]->columnNumber
	};

	chessBoard[freeCoordinatesToPlaceAQueen->rowNumber][freeCoordinatesToPlaceAQueen->columnNumber] = 1;

	placedQueens++;
	
	for(int i=0;i<freeChessSquaresCoordinate.size();i++){
		delete freeChessSquaresCoordinate[i];
	}

	
	freeChessSquaresCoordinate.clear();
	delete freeCoordinatesToPlaceAQueen;
	}

	

	// printChessBoard();


	
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
			freeToPlaceCoordinates.clear();

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

	LassVegas* lg = new LassVegas();

		
	// cout<<"finding solutions ..."<<endl;
	// while(queenPlaced < 8){
	// 	lasVegas();	
	// }
	
	// cout<<"Solution found"<<endl;

	// printChessBoard();
}