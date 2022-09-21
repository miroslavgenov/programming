#include "NumberSorter.h"

NumberSorter::NumberSorter(int numbers[],size_t numberSize){
    setNumbers(numbers,numberSize);
}

void NumberSorter::setNumbers(int numbers[], int numberSize){
    for(int i=0;i<numberSize;i++){
        this->numbers.push_back(numbers[i]);
    }
}

void NumberSorter::printNumbers(){
    std::cout<<std::endl;
    for(int i=0;i<numbers.size();i++){
        std::cout<<numbers[i]<<" ";
    }
    std::cout<<std::endl;
}













    
