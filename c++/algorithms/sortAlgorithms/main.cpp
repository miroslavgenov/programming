#include <iostream>
#include "BubbleSorter/include/BubbleSorter.cpp"
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

    BubbleSorter* bubbleSorter = new BubbleSorter(numbers,numbersSize);
    bubbleSorter->printNumbers();
    bubbleSorter->sort();
    bubbleSorter->printNumbers();

}
