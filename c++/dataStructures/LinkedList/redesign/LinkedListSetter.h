#pragma once

#include "linkedListStruct.h"

class LinkedListSetter{
    public:
    
    template <typename T>
    static void setAndInitListElement(linkedListStruct<T>** linkedListRoot, T data){
        *linkedListRoot = new linkedListStruct{data};
        linkedListStruct<T>* pointerToRoot = *linkedListRoot;
        pointerToRoot->next = nullptr;
    }
    
    template <typename T>
    static void setAndInitListElement(linkedListStruct<T>** linkedListElement, T data , linkedListStruct<T>* nextElement){
        *linkedListElement = new linkedListStruct{data};
        linkedListStruct<T>* pointerToElement = *linkedListElement;
        pointerToElement->next = nextElement;
    }

    template <typename T>
    static void setElementData(linkedListStruct<T> *pointer, T data){
        pointer->data = data;
    }

    template <typename T>
    static void setTheNextElementOfTheCurrentElementTo(
        linkedListStruct<T>* currentElement, linkedListStruct<T> * pointToThatElement = nullptr){
        currentElement->next = pointToThatElement;
    }
};