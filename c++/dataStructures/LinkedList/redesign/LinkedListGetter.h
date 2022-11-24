#pragma once

#include "linkedListStruct.h"

class LinkedListGetter{
    public:

    template <typename T>
    static linkedListStruct<T>* getTheLastElementFromTheLinkedList(linkedListStruct<T>** linkedList){
        linkedListStruct<T>* pointer = *linkedList;

        while(pointer->next){
            pointer = pointer->next;
        }
        return pointer;
    }

    template <typename T>
    static linkedListStruct<T> * getThePreviouseElementBeforeTheLastElement(linkedListStruct<T> * root){
        linkedListStruct<T>* pointer = root;
        
        while(pointer->next->next){
            pointer = pointer->next;
        }
        
        return pointer;
    }
};