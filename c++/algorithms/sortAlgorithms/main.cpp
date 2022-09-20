#include <iostream>
#include "ShakeSorter/include/ShakeSorter.cpp"
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

    ShakeSorter* shakeSorter = new ShakeSorter(numbers , numbersSize);
    shakeSorter->printNumbers();
    shakeSorter->sort();
    shakeSorter->printNumbers();

}
