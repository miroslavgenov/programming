#pragma once
#include "linkedListStruct.h"


class LinkedListDeleter{
    public:
    template <typename T>
    static T deleteAtBeginning(linkedListStruct<T>* linkedListRoot) noexcept(false) {
            T data = nullptr;
                

                if(LinkedListChecker::isElementNullptr(linkedListRoot->next)){
                    data = linkedListRoot->data;
                }else{
                    
                    data = linkedListRoot->data;
                    LinkedListSetter::setElementData(linkedListRoot, linkedListRoot->next->data);
                    LinkedListSetter::setTheNextElementOfTheCurrentElementTo(linkedListRoot, linkedListRoot->next->next);
                }

            
            return data;

        }
    template <typename T>
    static T deleteAtEnd(linkedListStruct<T>* linkedListRoot) noexcept(false){
         
                linkedListStruct<T>* pointer = LinkedListGetter::getThePreviouseElementBeforeTheLastElement(linkedListRoot);
                
                T dataFromDeletedTarget = pointer->next->data;
                LinkedListSetter::setTheNextElementOfTheCurrentElementTo(pointer->next);
                delete pointer->next->next;
                LinkedListSetter::setTheNextElementOfTheCurrentElementTo(pointer);                
                
                return dataFromDeletedTarget;
            
            
            
        }
};