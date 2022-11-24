#include "LinkedListException.h"

const std::string LinkedListException::CONSTRUCTOR_ERROR="LinkedListHelper constructor: the data must be pointer";
const std::string LinkedListException::OUT_OF_RANGE="error at deleteAtEnd(): there are no elements to be deleted! size == 0";

    LinkedListException::LinkedListException(std::string _exceptionMessage):exceptionMessage(_exceptionMessage){
    }

    std::string LinkedListException::what(){
        return exceptionMessage;
    }