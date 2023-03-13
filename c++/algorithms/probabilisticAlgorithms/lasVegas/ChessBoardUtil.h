#pragma once

class ChessBoardUtil{
	public:

	static const int MARKED_SYMBOL;
	static const int FREE_TO_PLACE_SYMBOL;
	static const int QUEEN_SYMBOL;
	static const int MAXIMUM_NUMBER_OF_QUEENS;

	static void initializeTheChessBoard(int ***chessBoard,int size){
		*chessBoard = new int*[size];

		for(int i=0;i<size;i++){
			*(*chessBoard+i) = new int[size];
		}
	}

	static void initializePlacedQueens(int &placedQueens){
		placedQueens = 0;
	}

	static void printChessSquareCoordinates(chessSquare* chessSquare){
		if(chessSquare){
			std::cout<<"rowNumber: "<<chessSquare->rowNumber<<" columnNumber: "<<chessSquare->columnNumber<<std::endl;
		}else{
			std::cout<<"chessSquare is nullptr !!"<<std::endl;
		}
	}

	static void printChessBoard(int **chessBoard, int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				std::cout<<chessBoard[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
	}
	
	static void clearAllMarkedChessSquaresInConflict(int ***chessBoard, int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				if(*(*(*chessBoard+j)+i) == ChessBoardUtil::MARKED_SYMBOL){
					*(*(*chessBoard+j)+i) = 0;
				}
			}
		}
	}

	static void clearChessBoard(int ***chessBoard, int size){
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				*(*(*chessBoard+j)+i) = ChessBoardUtil::FREE_TO_PLACE_SYMBOL;
			}
		}
	}
};

const int ChessBoardUtil::QUEEN_SYMBOL = 1;
const int ChessBoardUtil::MARKED_SYMBOL = 2;
const int ChessBoardUtil::FREE_TO_PLACE_SYMBOL = 0;
const int ChessBoardUtil::MAXIMUM_NUMBER_OF_QUEENS = 8;