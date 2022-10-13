#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/fastSort/CountSorter/src/CountSorter.h"

CountSorter::CountSorter(int numbers[], size_t numbersSize):NumberSorter(numbers, numbersSize){
    maximumNumberFromUnsortedArray = NumberFinder::findMaximumNumberFromUnsortedVector(this->numbers);
    setCountOfNumbersRepeatedSize();
    countOfNumbersRepeated = new int[countOfNumbersRepeatedSize];
}

void CountSorter::setCountOfNumbersRepeatedSize(){
    this->countOfNumbersRepeatedSize = getAGreaterNumberThanMaximumNumberByOne();
}

int CountSorter::getAGreaterNumberThanMaximumNumberByOne(){
    return maximumNumberFromUnsortedArray + 1;
}

CountSorter::~CountSorter(){
    delete [] countOfNumbersRepeated;
}

void CountSorter::sort(){
    loopTheUnsortedNumbersAndAddOneToHisValue();

    int currentNumber;
    int timesCurrentNumberRepeats;
    int unsortedNumbersIterator = 0;

    for(int key = 0; key < countOfNumbersRepeatedSize; key++){
        currentNumber = key;
        timesCurrentNumberRepeats = countOfNumbersRepeated[key];

        if(isNumberRepeated(timesCurrentNumberRepeats)){
            replaceUnsortedNumberThatTimesHowMuchNumberRepeats(currentNumber, timesCurrentNumberRepeats, unsortedNumbersIterator);
        }
    }
}

void CountSorter::loopTheUnsortedNumbersAndAddOneToHisValue(){
    for(int i = 0; i < numbers.size() ;i++){
        useCurrentNumberAsKeyToAddOneToHisValue(numbers[i]);
    }
}

void CountSorter::useCurrentNumberAsKeyToAddOneToHisValue(int key){
    countOfNumbersRepeated[key]+=1;
}

bool CountSorter::isNumberRepeated(int key){
    return countOfNumbersRepeated[key] != 0;
}

void CountSorter::replaceUnsortedNumberThatTimesHowMuchNumberRepeats(int currentNumber, int timesCurrentNumberRepeats, int &unsortedNumbersIterator){
    for(int j = 0; j < timesCurrentNumberRepeats; j++){
        numbers[unsortedNumbersIterator] = currentNumber;
        unsortedNumbersIterator++;
    }
}

void CountSorter::shouldSwapTheGreaterNumberWithLesserNumber(int* greater, int* lesser){}