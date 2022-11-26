#pragma once

#include "linkedListStruct.h"

class LinkedListAppender{
    public:

    template <typename T>
    static void appendAtEnd(linkedListStruct<T>** rootElementFromList, T data){
        linkedListStruct<T>* lastElementFromList = 
            LinkedListGetter::getTheLastElementFromTheLinkedList(rootElementFromList);
        LinkedListSetter::setAndInitListElement(&lastElementFromList->next, data);
    }

    template <typename T>
    static void appendAtBegining(linkedListStruct<T>* rootElement, T data){
        linkedListStruct<T>* next = nullptr;
        LinkedListSetter::setAndInitListElement(&next, rootElement->data, rootElement->next);

        LinkedListSetter::setElementData(rootElement,data);
        LinkedListSetter::setTheNextElementOfTheCurrentElementTo(rootElement, next); 
    }

};