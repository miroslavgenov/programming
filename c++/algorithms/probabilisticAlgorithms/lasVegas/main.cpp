#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "/home/home/Desktop/programming/c++/algorithms/probabilisticAlgorithms/lasVegas/chessSquare.h"
#include "/home/home/Desktop/programming/c++/algorithms/probabilisticAlgorithms/lasVegas/ChessBoardUtil.h"
#include "/home/home/Desktop/programming/c++/algorithms/probabilisticAlgorithms/lasVegas/LassVegas.cpp"

using namespace std;

int main(){
	LassVegas* lg = new LassVegas();
	lg->placeQueens();

	ChessBoardUtil::printChessBoard(lg->getChessBoard(),lg->getChessBoardSize());

	cout<<"placedQueens: "<<lg->placedQueens<<endl;
}