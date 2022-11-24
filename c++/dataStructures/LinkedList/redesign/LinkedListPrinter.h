#pragma once
#include "linkedListStruct.h"


class LinkedListPrinter{
    public:
    template <typename T>
    static void printElementsData(linkedListStruct<T>* theRootElement){
        
        linkedListStruct<T>* pointer = theRootElement;

        while(pointer){
            std::cout<<*pointer->data<<" ";
            pointer = pointer->next;
        }
    }

    template <typename T>
    static void printElementData(linkedListStruct<T>* element){
        std::cout<<*element->data;
    }

};