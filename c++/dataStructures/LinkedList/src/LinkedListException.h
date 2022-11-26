#pragma once
#include <iostream>

class LinkedListException{
    public:
    std::string exceptionMessage;
    static const std::string CONSTRUCTOR_ERROR;
    static const std::string OUT_OF_RANGE;

    LinkedListException(std::string );

    std::string what();
};

