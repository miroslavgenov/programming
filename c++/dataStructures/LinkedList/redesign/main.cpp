#include <iostream>
#include "LinkedListHelper.cpp"

int main(){
    LinkedListHelper<int*> *tree = new LinkedListHelper(new int{4});
    tree->appendAtBegining(new int{3});
    tree->appendAtEnd(new int{5});
    tree->deleteAtBegining();
    tree->deleteAtEnd();
    tree->print();
}