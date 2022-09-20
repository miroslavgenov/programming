#include <iostream>
#include "include/ShakeSorter.cpp"

using namespace std;

int main(){
    int numbersSize = 5;
    int numbers[numbersSize] = {5,4,3,2,1};
    
    ShakeSorter* shakeSorter = new ShakeSorter(numbers , numbersSize);
    shakeSorter->printNumbers();
    shakeSorter->sort();
    shakeSorter->printNumbers();
}
