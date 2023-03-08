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

	static void printChessBoard(int **chessBoard, int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				cout<<chessBoard[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	static void clearAllMarkedChessSquaresInConflict(int ***chessBoard, int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(*(*(*chessBoard+j)+i) == 2){
					*(*(*chessBoard+j)+i) = 0;
				}
			}
		}
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
	chessSquare* coordinatesToPlaceAQueen = nullptr;

	int placedQueens;

	LassVegas(){

		chessBoard = new int*[size];

		for(int i=0;i<size;i++){
			chessBoard[i] = new int[size];
		} 

		placedQueens = 0;




		lassVegas();
		ChessBoardUtil::clearAllMarkedChessSquaresInConflict(&chessBoard,size);		
		ChessBoardUtil::printChessBoard(chessBoard,size);



	}

	//util
	void clearTheChessBoard(){
		for(int i=0;i<size;i++){
			for(int j =0;j<size;j++){
				chessBoard[i][j] =0;
			}
		}
	}

	void storeAllFreeChessSquareCoordinates(){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(chessBoard[i][j] == 0){
					freeChessSquaresCoordinate.push_back(new chessSquare{i,j});
				}
			}
		}
	}


	void setCoordinatesToPlaceAQueen(int index){
		coordinatesToPlaceAQueen = new chessSquare{
			freeChessSquaresCoordinate[index]->rowNumber,
			freeChessSquaresCoordinate[index]->columnNumber
		};
	}

	chessSquare* getCoordinatesToPlaceAQueen(){
		return coordinatesToPlaceAQueen;
	}

	void lassVegas(){
		
		int choosenFreeToPlaceCoordinatesIndex;

		while(this->placedQueens <8){
			srand(time(nullptr));

		
			// // //the functions must stop work if the total number of queen placed on the chess board == 8

			// //first get all free coordinates
			storeAllFreeChessSquareCoordinates();

			if(freeChessSquaresCoordinate.size() == 0 && this->placedQueens <8){
				this->clearTheChessBoard();
				this->placedQueens = 0;				
			}else{
				choosenFreeToPlaceCoordinatesIndex = rand() % (freeChessSquaresCoordinate.size());

				setCoordinatesToPlaceAQueen(choosenFreeToPlaceCoordinatesIndex);

				int newQueenRowCoordinate = getCoordinatesToPlaceAQueen()->rowNumber;
				int newQueenColumnCoordinate = getCoordinatesToPlaceAQueen()->columnNumber;

				//place the queen on the chess board
				chessBoard[newQueenRowCoordinate][newQueenColumnCoordinate] = 1;
				

				//get the current placed queen coordinates
				//this coordinates will be used to mark the chess table
				currentQueen = new chessSquare{newQueenRowCoordinate,newQueenColumnCoordinate};


				freeChessSquaresCoordinate.clear();
				coordinatesToPlaceAQueen = nullptr;
			
				this->placedQueens++;
			
				markAllChessSquearesThatAreInConflictWithCurrentQueen();		

			}
		}
	}

	void shouldSetSpecificChessBoardSquareSumbolToSymbol(int i,int j, int symbol){
		if(chessBoard[i][j] != LassVegas::queenSymbol){
			chessBoard[i][j] = symbol;
		}
	}

	void markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(){
		for(int i=0;i<size;i++){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(currentQueen->rowNumber,i,MARKED_SYMBOL);
		}
	}

	void markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(){
		for(int i=0;i<size;i++){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(i,currentQueen->rowNumber,MARKED_SYMBOL);
		}
	}


	void markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; j >= 0 && i<size; i++, j--){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(i, j, MARKED_SYMBOL);
		}
	}

	void markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i>=0 && j<size ; i--, j++){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,MARKED_SYMBOL);
		}
	}


	void markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(){
		for(int i=currentQueen->rowNumber, j = currentQueen->columnNumber;i>=0 && j>=0;i--,j--){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,MARKED_SYMBOL);
		}
	}

	void markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal(){
		for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i < size; i++, j++){
			shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,MARKED_SYMBOL);
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
			markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(); //need fix segment fault
			markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal();

		}else{
			cout<<"\t THERE IS NO QUEEN ON THE CHESS BOARD"<<endl;
		}
		
	}
	
};

const int LassVegas::size = 8;
const int LassVegas::queenSymbol = 1;
const int LassVegas::MARKED_SYMBOL = 2;
const int LassVegas::FREE_TO_PLACE_SYMBOL = 0;


int main(){

	LassVegas* lg = new LassVegas();

		
}