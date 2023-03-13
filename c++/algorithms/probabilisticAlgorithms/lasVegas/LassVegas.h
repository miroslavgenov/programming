#pragma once

//NEED TO BE CLEANED

class LassVegas{
	public:

	static const int size;

	int **chessBoard = nullptr;
	chessSquare* currentQueen = nullptr;
	std::vector<chessSquare*> freeChessSquaresCoordinate;

	int placedQueens;
	int choosenFreeToPlaceCoordinatesIndex;


	LassVegas();
	void initializeLassVegas();


	void placeQueens();
	void storeAllFreeChessSquareCoordinates();

	bool isThereFreeChessSquareCoordinates();
	bool isMaximumNumberOfQueensReached();
	bool thereIsNoFreeCoordinatesAndAllQueensAreNotPlaced();
	void clearTheChessBoardAndPlacedQueens();
	void setPlacedQueensNumber(int);

	void setTheCurrentQueenCoordinateAndPlaceTheQueenOnTheChessBoard(chessSquare*);
	void setCurrentQueenCoordinate(chessSquare* );
	void placeQueenOnTheChessBoard(chessSquare* );

	void markAllChessSquearesThatAreInConflictWithCurrentQueen();
	
	void markAllChessSquaresInConflictWithTheCurrentQueenRowNumber();
	void markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber();
	void markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal();
	void markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal();
	void markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal();
	void markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal();

	void shouldSetSpecificChessBoardSquareSumbolToSymbol(int ,int , int );

	int** getChessBoard();
	int getChessBoardSize();
	
};

const int LassVegas::size = 8;