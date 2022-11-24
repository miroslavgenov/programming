#include "LinkedListSizeHelper.h"

const int LinkedListSizeHelper::EMPTY_SIZE_LENGTH = 0;

    LinkedListSizeHelper::LinkedListSizeHelper(){
        this->incrementSize();
    }

    void LinkedListSizeHelper::incrementSize(){
        size++;
    }

    void LinkedListSizeHelper::decrementSize(){
        if(size>0){
            size--;
        }
    }

    int LinkedListSizeHelper::getSize(){
        return size;
    }


