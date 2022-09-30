#include <iostream>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberFinder.cpp"
#include <ctime>
#include <cstdlib>

using namespace std;
void print(int numbers[],int numbersSize){
    for(int i = 0; i < numbersSize; i++){
        cout<<numbers[i]<<" ";
    }
}

class CountSorter : NumberSorter{
    int maximumNumberFromUnsortedArray;
    int* countOfNumbersRepeated = nullptr;
    int countOfNumbersRepeatedSize;
    

    int getAGreaterNumberThanMaximumNumberByOne(){
        return maximumNumberFromUnsortedArray + 1;
    }

    void setCountOfNumbersRepeatedSize(){
        this->countOfNumbersRepeatedSize = getAGreaterNumberThanMaximumNumberByOne();
    }
    public:
        CountSorter(int numbers[], size_t numbersSize):NumberSorter(numbers, numbersSize){
            maximumNumberFromUnsortedArray = NumberFinder::findMaximumNumberFromUnsortedVector(this->numbers);
            
            setCountOfNumbersRepeatedSize();

            countOfNumbersRepeated = new int[countOfNumbersRepeatedSize];
            
            
        }
        void addByTheIndexOfTheCurrentNumberThatHeAppersOne(int currentNumber){
            countOfNumbersRepeated[currentNumber] += 1;
        }

        ~CountSorter(){
            delete [] countOfNumbersRepeated;
        }
        
        

        

        
        void sort(){
            loopTheUnsortedNumbersAndAddOneToHisValue();

            int currentNumber;
            int timesCurrentNumberRepeats;
            int unsortedNumbersIterator = 0;

            for(int key = 0; key < countOfNumbersRepeatedSize; key++){
                currentNumber = key;
                timesCurrentNumberRepeats = countOfNumbersRepeated[key];
                
                if(isNumberRepeated(timesCurrentNumberRepeats)){
                    replaceUnsortedNumberThatMuchTimeHowMuchNumberRepeats(currentNumber, timesCurrentNumberRepeats,unsortedNumbersIterator);
                }
                    
                
            }

        }

    void replaceUnsortedNumberThatMuchTimeHowMuchNumberRepeats(int currentNumber,int timesCurrentNumberRepeats,int &unsortedNumbersIterator){
        
        for(int j = 0; j < timesCurrentNumberRepeats; j++){
            numbers[unsortedNumbersIterator] = currentNumber;
            unsortedNumbersIterator++;
        }
    }

        bool isNumberRepeated(int key){
            return countOfNumbersRepeated[key] != 0;
        }

        void loopTheUnsortedNumbersAndAddOneToHisValue(){
            for(int i=0;i<numbers.size();i++){
                useCurrentNumberAsKeyToAddOneToHisValue(numbers[i]);
                
            }
        }

        void useCurrentNumberAsKeyToAddOneToHisValue(int key){
            countOfNumbersRepeated[key] +=1;
        }

        void printNumbers(){
            NumberSorter::printNumbers();
        }

        void shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int* lesser){}
};
int main(){  
    srand(time(0));

    size_t numbersSize = 10; //rand()%20;
    int numbers[numbersSize] = {10,9,1,7,6,5,4,3,2,1};

    CountSorter* c = new CountSorter(numbers,numbersSize);
    c->sort();
    c->printNumbers();
    

}
