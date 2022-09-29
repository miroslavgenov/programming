
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/MergeSorter/include/MergeSorter.cpp"

using namespace std;


int main(){
    srand(time(0));
    
    size_t numbersSize  = 10;
    int numbers[numbersSize];// = {9,20,10,1,10,2,3,4,5,6};
    
    for(int i=0;i<numbersSize;i++){
        numbers[i] = rand() % 100;
    }
    
    MergeSorter * m = new MergeSorter(numbers,numbersSize);
    m->printNumbers();
    m->sort();
    m->printNumbers();
}
