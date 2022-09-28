#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include <ctime>
#include <cstdlib>

using namespace std;

//TODO refactor , clean

class CombSorter : NumberSorter{
    private:
        const double gapShrinkFactor = 1.3;
        int gap;
        bool areNumbersSorted;
    public:
        CombSorter(int numbers[], size_t numbersSize) : NumberSorter(numbers,numbersSize){
            gap = this->numbers.size();
            areNumbersSorted = isArraySorted();
        }
        
        void shouldSetAndDecreaseGapIfGreaterThanOne(){
            if(isGapDevidedByGapShrinkFactorGreaterThanOne()){
                int newGapValue = devideGapByGapShrinkValue();
                setGap(newGapValue);
            }
        }

        bool isGapDevidedByGapShrinkFactorGreaterThanOne(){
            return gap/gapShrinkFactor > 1;
        }

        int devideGapByGapShrinkValue(){
            return gap/gapShrinkFactor;
        }

        void setGap(int value){
            gap = value;
        }

        

        void sort(){
            while(areNumbersSorted == false){       
                shouldSetAndDecreaseGapIfGreaterThanOne();

                for(int i = 0 , j = gap ; j<numbers.size() ; i++,j++){
                    shouldSwapTheGreaterNumberWithLesserNumber(&numbers[i], &numbers[j]);
                }

                areNumbersSorted = isArraySorted();
            }
        }

        private:
            void shouldSwapTheGreaterNumberWithLesserNumber(int *greater, int* lesser){
                if(NumberChecker::isTheNumberGreaterThan(greater,lesser)){
                    NumberSwapper::swapTwoNumbersValue(greater,lesser);
                }
            }
    
    public:
        void printNumbers(){
            NumberSorter::printNumbers();
        }
    private:
    bool isArraySorted(){
    for(int i=1;i<numbers.size();i++){
        if(numbers[i-1] > numbers[i]){
            return false;
        }
    }
    return true;
}


};

int main(){
    srand(time(0));

    size_t numbersSize  =  10;
    int numbers[numbersSize]; // = {10,9,8,7,6,5,4,3,2,1};
    
    for(int i=0; i<numbersSize;i++){
        numbers[i] = rand()% 100;
    }
    
    CombSorter *c = new CombSorter(numbers,numbersSize);
    c->printNumbers();
    c->sort();
    c->printNumbers();
    

}
