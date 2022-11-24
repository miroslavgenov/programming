#pragma once
#include <iostream>

class LinkedListException{
    public:
    std::string exceptionMessage;
    static const std::string CONSTRUCTOR_ERROR;
    static const std::string OUT_OF_RANGE;

    LinkedListException(std::string _exceptionMessage):exceptionMessage(_exceptionMessage){
    }

    std::string what(){
        return exceptionMessage;
    }
};

const std::string LinkedListException::CONSTRUCTOR_ERROR="LinkedListHelper constructor: the data must be pointer";
const std::string LinkedListException::OUT_OF_RANGE="error at deleteAtEnd(): there are no elements to be deleted! size == 0";