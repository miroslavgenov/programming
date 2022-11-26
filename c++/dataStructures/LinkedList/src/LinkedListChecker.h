#pragma once

#include "linkedListStruct.h"


class LinkedListChecker{
    public:
    static bool isListEmpty(int size){
        return size == LinkedListSizeHelper::EMPTY_SIZE_LENGTH;
    }

    template <typename T>
    static bool isElementNullptr(linkedListStruct<T> * element){
        return element == nullptr;
    }

};