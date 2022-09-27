#include <iostream>
#include <ctime>
#include <cstdlib>
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

using namespace std;

class MergeSorter : NumberSorter{
    private:
        int *arrayToStoreSortedNumbers = nullptr;
    
    public:    
        MergeSorter(int [], size_t);

        void sort();
        
    private:
        void merge(int left,int right);

        void split(int left, int right);

        void shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser);

    public:
        void printNumbers();
};


MergeSorter::MergeSorter(int numbers[], size_t numbersSize):NumberSorter(numbers,numbersSize){
    this->arrayToStoreSortedNumbers = new int[numbersSize];
}

void MergeSorter::sort(){
    split(0,numbers.size()-1);
}

void MergeSorter::merge(int left,int right){
    int i = left;
    int mid = (left+right)/2;
    int j = mid + 1;
    
    // moving from the left to save the correct number position for
    // arrayToStoreSortedNumbers
    int k = left;

    while(i<=mid && j<=right){
        if(numbers[i]>= numbers[j]){
            arrayToStoreSortedNumbers[k] = numbers[j];
            k++;
            // cout<<numbers[j]<<" ";
            j++;
        }
        if(numbers[j] >= numbers[i]){
            // cout<<numbers[i]<<" ";
            arrayToStoreSortedNumbers[k] = numbers[i];
            k++;
            i++;
        }
    }

    while(i<=mid){
        // cout<<numbers[i]<<" ";
        arrayToStoreSortedNumbers[k] = numbers[i];
        k++;
        i++;
    }
    while(j<=right){
        // cout<<numbers[j]<<" ";
        arrayToStoreSortedNumbers[k] = numbers[j];
        k++;
        j++;
    }
    // cout<<endl;
    for(int i = left ; i<=right;i++){
        numbers[i] = arrayToStoreSortedNumbers[i];
    }
}

void MergeSorter::split(int left, int right){

    if(left == right){
        return;
    }

    int mid = (left+right)/2;
    
    split(left,mid);
    split(mid+1,right);
    merge(left,right);
}

    
void MergeSorter::shouldSwapTheGreaterNumberWithLesserNumber(int* greater,int *lesser){}
    
void MergeSorter::printNumbers(){
    NumberSorter::printNumbers();
}


int main(){
    srand(time(0));
    
    size_t numbersSize  = 10;
    int numbers[numbersSize];// = {9,20,10,1,10,2,3,4,5,6};
    
    for(int i=0;i<numbersSize;i++) numbers[i] = rand() % 100;
    
    MergeSorter * m = new MergeSorter(numbers,numbersSize);
    m->printNumbers();
    m->sort();
    m->printNumbers();
}
