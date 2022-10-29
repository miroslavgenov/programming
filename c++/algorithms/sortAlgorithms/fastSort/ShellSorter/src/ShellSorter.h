#pragma once
#include "/home/home/Desktop/programming/c++/algorithms/sortAlgorithms/NumberSorter.cpp"

class ShellSorter : public NumberSorter{
    private:
        int shellStep;
    
    public:
        ShellSorter(int[], int);

        void sort();

    private:
        void sortForwardAndBackwardsWithShellStep(int);

        void sortBackwardsFromCurrentSwapIndexWithShellStep(int, int);

};