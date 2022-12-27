#pragma once
#include <iostream>
#include <typeinfo>
#include <cstring>
#include <type_traits>

#include "linkedListStruct.h"
#include "LinkedListSetter.h"
#include "LinkedListGetter.h"
#include "LinkedListSizeHelper.cpp"
#include "LinkedListChecker.h"
#include "LinkedListAppender.h"
#include "LinkedListException.cpp"
#include "LinkedListPrinter.h"
#include "LinkedListDeleter.h"


template <typename T>
class LinkedListHelper{
private:
    LinkedListSizeHelper *linkedListSizer = nullptr;

public:
    linkedListStruct<T> *linkedListRoot = nullptr;
    
    LinkedListHelper(T );
    
    void decrementSize(){
        if(linkedListSizer != nullptr){
            linkedListSizer->decrementSize();
        }
    }

    T top();

    int size();

    void appendAtEnd(T );

    // void decrementSize();

    T deleteAtEnd() noexcept(false);

    T deleteAtBegining();
    
    bool isListEmpty();

    void appendAtBegining(T );
    
    void print();

    linkedListStruct<T>* getTop(){
        return LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot);
    }
};