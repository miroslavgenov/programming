#include <iostream>
#include <typeinfo>
#include <cstring>
#include <type_traits>


#include <vector>

using namespace std;

template <typename T>
struct linkedListStruct{
    T data;
    linkedListStruct* next=nullptr;

    linkedListStruct(T data){
        this->data = data;
    }
};


class LinkedListSetter{
    public:
    
    template <typename T>
    static void setAndInitListElement(linkedListStruct<T>** linkedListRoot, T data){
        *linkedListRoot = new linkedListStruct{data};
        linkedListStruct<T>* pointerToRoot = *linkedListRoot;
        pointerToRoot->next = nullptr;
    }
};

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
    
};

class LinkedListChecker{
    public:
    static bool isListEmpty(int size){
        return size == 0;
    }
};

class LinkedListAppender{
    public:

    template <typename T>
    static void appendAtEnd(linkedListStruct<T>** rootElementFromList, T data){
        linkedListStruct<T>* lastElementFromList = 
            LinkedListGetter::getTheLastElementFromTheLinkedList(rootElementFromList);
        LinkedListSetter::setAndInitListElement(&lastElementFromList->next, data);
    }
};

class LinkedListSizeHelper{
    int size=0; 
    static const int EMPTY_SIZE_LENGTH = 0;  
    public:

    LinkedListSizeHelper(){
        this->incrementSize();
    }

    void incrementSize(){
        size++;
    }

    int getSize(){
        return size;
    }
};

class LinkedListHandler{
    public:
    static const string CONSTRUCTOR_ERROR;
};

const string LinkedListHandler::CONSTRUCTOR_ERROR="LinkedListHelper constructor: the data must be pointer";

class LinkedListPrinter{
    
};


template <typename T>
class LinkedListHelper{
    LinkedListSizeHelper *linkedListSizer = nullptr;

    public:
        linkedListStruct<T> *linkedListRoot = nullptr;
        
        
        LinkedListHelper(T data){   
            if(is_pointer<T>::value){
                LinkedListSetter::setAndInitListElement(&linkedListRoot, data);
                linkedListSizer = new LinkedListSizeHelper();
            }else{
                cout<<LinkedListHandler::CONSTRUCTOR_ERROR<<endl;
            }
        }
        
        T top(){
            return LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot)->data;
        }

        int size(){
            return linkedListSizer->getSize();
        }

        void appendAtEnd(T data){
            LinkedListAppender::appendAtEnd(&linkedListRoot, data);
            linkedListSizer->incrementSize();
        }

        bool isListEmpty(){
            return LinkedListChecker::isListEmpty(size());
        }

        void appendAtBegining(T data){
            if(isListEmpty()){
                cout<<"yes"<<endl;
            }else{
                cout<<"no"<<endl;
            }
        }
        
        
};


int main(){    
    LinkedListHelper<int*>* l  = new LinkedListHelper(new int{3});

    l->appendAtBegining(new int{4});
    
    
}