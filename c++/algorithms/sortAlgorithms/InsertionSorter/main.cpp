#include "InsertionSorter.cpp"

int main(){
    size_t numbersSize = 9;
    int numbers[numbersSize]{9,6,7,5,3,2,1,4,8};
    
    InsertionSorter *i = new InsertionSorter(numbers,numbersSize);
    i->printNumbers();
    i->sort();
    i->printNumbers();
}