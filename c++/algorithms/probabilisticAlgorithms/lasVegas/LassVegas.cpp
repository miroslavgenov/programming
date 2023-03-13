#include "/home/home/Desktop/programming/c++/algorithms/probabilisticAlgorithms/lasVegas/LassVegas.h"

LassVegas::LassVegas(){
    initializeLassVegas();
}

void LassVegas::initializeLassVegas(){
    ChessBoardUtil::initializeTheChessBoard(&chessBoard,size);
    ChessBoardUtil::initializePlacedQueens(placedQueens);
}

void LassVegas::placeQueens(){        
    while( isMaximumNumberOfQueensReached() == false){
        srand(time(nullptr));

        storeAllFreeChessSquareCoordinates();

        if(thereIsNoFreeCoordinatesAndAllQueensAreNotPlaced() == true){
            clearTheChessBoardAndPlacedQueens();
        }
        else{
            choosenFreeToPlaceCoordinatesIndex = rand() % (freeChessSquaresCoordinate.size());

            setTheCurrentQueenCoordinateAndPlaceTheQueenOnTheChessBoard(freeChessSquaresCoordinate[choosenFreeToPlaceCoordinatesIndex]);
            
            freeChessSquaresCoordinate.clear();
        
            this->placedQueens++;
        
            markAllChessSquearesThatAreInConflictWithCurrentQueen();		

        }
    }

    ChessBoardUtil::clearAllMarkedChessSquaresInConflict(&chessBoard,size);		
}

void LassVegas::setPlacedQueensNumber(int numberOfPlacedQueens){
    placedQueens = numberOfPlacedQueens;
}

void LassVegas::clearTheChessBoardAndPlacedQueens(){
    ChessBoardUtil::clearChessBoard(&chessBoard,size);
    setPlacedQueensNumber(0);
}

bool LassVegas::thereIsNoFreeCoordinatesAndAllQueensAreNotPlaced(){
    return isThereFreeChessSquareCoordinates() == false && isMaximumNumberOfQueensReached() == false ;
}

bool LassVegas::isThereFreeChessSquareCoordinates(){
    return freeChessSquaresCoordinate.size() > 0; 
}

bool LassVegas::isMaximumNumberOfQueensReached(){
    return placedQueens == ChessBoardUtil::MAXIMUM_NUMBER_OF_QUEENS;
}

void LassVegas::storeAllFreeChessSquareCoordinates(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(chessBoard[i][j] == ChessBoardUtil::FREE_TO_PLACE_SYMBOL){
                freeChessSquaresCoordinate.push_back(new chessSquare{i,j});
            }
        }
    }
}

void LassVegas::setTheCurrentQueenCoordinateAndPlaceTheQueenOnTheChessBoard(chessSquare* coordinate){
    setCurrentQueenCoordinate(coordinate);
    placeQueenOnTheChessBoard(currentQueen);
}

void LassVegas::setCurrentQueenCoordinate(chessSquare* coordinate){
    currentQueen = new chessSquare{coordinate->rowNumber, coordinate->columnNumber};
}

void LassVegas::placeQueenOnTheChessBoard(chessSquare* coordinate){
    chessBoard[coordinate->rowNumber][coordinate->columnNumber] = ChessBoardUtil::QUEEN_SYMBOL;
}

void LassVegas::markAllChessSquearesThatAreInConflictWithCurrentQueen(){
    if(currentQueen){
        markAllChessSquaresInConflictWithTheCurrentQueenRowNumber();
        markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber();
        markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal();
        markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal();
        markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal();
        markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal();

    }else{
        std::cout<<"\t THERE IS NO QUEEN ON THE CHESS BOARD"<<std::endl;
    }
    
}

void LassVegas::markAllChessSquaresInConflictWithTheCurrentQueenRowNumber(){
    for(int i=0;i<size;i++){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(currentQueen->rowNumber,i,ChessBoardUtil::MARKED_SYMBOL);
    }
}

void LassVegas::markAllChessSquaresInConflictWithTheCurrentQueenColumnNumber(){
    for(int i=0;i<size;i++){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(i,currentQueen->columnNumber,ChessBoardUtil::MARKED_SYMBOL);
    }
}

void LassVegas::markTheChessSquaresInConflictWithCurrentQueenByBottomLeftDiagonal(){
    for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; j >= 0 && i<size; i++, j--){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(i, j, ChessBoardUtil::MARKED_SYMBOL);
    }
}

void LassVegas::markTheChessSquaresInConflictWithCurrentQueenByTopRightDiagonal(){
    for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i>=0 && j<size ; i--, j++){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,ChessBoardUtil::MARKED_SYMBOL);
    }
}

void LassVegas::markChessSquaresInConflictWithCurrentQueenByTheTopLeftDiagonal(){
    for(int i=currentQueen->rowNumber, j = currentQueen->columnNumber;i>=0 && j>=0;i--,j--){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,ChessBoardUtil::MARKED_SYMBOL);
    }
}

void LassVegas::markChessSquaresInConflictWithCurrentQueenByTheBottomRightDiagonal(){
    for(int i = currentQueen->rowNumber, j = currentQueen->columnNumber; i < size; i++, j++){
        shouldSetSpecificChessBoardSquareSumbolToSymbol(i,j,ChessBoardUtil::MARKED_SYMBOL);
    } 
}

void LassVegas::shouldSetSpecificChessBoardSquareSumbolToSymbol(int i,int j, int symbol){
    if(chessBoard[i][j] != ChessBoardUtil::QUEEN_SYMBOL){
        chessBoard[i][j] = symbol;
    }
}

int** LassVegas::getChessBoard(){
    return chessBoard;
}

int LassVegas::getChessBoardSize(){
    return size;
}