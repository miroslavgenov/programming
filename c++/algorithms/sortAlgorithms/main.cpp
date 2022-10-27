#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/BubbleSorter/include/BubbleSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/Printer.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){  
    srand(time(0));
    
    
    size_t numbersSize = rand()%20;
    int numbers[numbersSize];
    
    for(int i=0; i<numbersSize;i++){
        numbers[i] = rand()% 100;
    }

    BubbleSorter* b = new BubbleSorter(numbers,numbersSize);
    b->sort();

    Printer::printArray(b->getNumbers());
}