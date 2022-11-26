#pragma once

class LinkedListSizeHelper{
    int size=0; 
    
public:
    static const int EMPTY_SIZE_LENGTH;  

    LinkedListSizeHelper();

    void incrementSize(); 

    void decrementSize();
    
    int getSize();
};