class ArrayChecker{
    public:
    static bool areNumbersSorter(int numbers[], int numbersSize){
        for(int i=1;i<numbersSize;i++){
            if(numbers[i-1]>numbers[i]){
                return false;
            }
        }
        return true;
    }
};