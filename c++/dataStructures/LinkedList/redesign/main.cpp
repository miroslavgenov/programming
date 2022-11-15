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

    template <typename T>
    static void setElementData(linkedListStruct<T> *pointer, T data){
        cout<<"setElementData"<<endl;
        pointer->data = data;
        
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

class LinkedListSizeHelper{
    int size=0; 
    
    public:
    static const int EMPTY_SIZE_LENGTH;  

    LinkedListSizeHelper(){
        this->incrementSize();
    }

    void incrementSize(){
        size++;
    }

    void decrementSize(){
        if(size>0){
            size--;
        }
    }

    int getSize(){
        return size;
    }
};

const int LinkedListSizeHelper::EMPTY_SIZE_LENGTH = 0;


class LinkedListChecker{
    public:
    static bool isListEmpty(int size){
        return size == LinkedListSizeHelper::EMPTY_SIZE_LENGTH;
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



class LinkedListHandler{
    public:
    static const string CONSTRUCTOR_ERROR;
};

const string LinkedListHandler::CONSTRUCTOR_ERROR="LinkedListHelper constructor: the data must be pointer";

class LinkedListPrinter{
    public:
    template <typename T>
    static void printElementsData(linkedListStruct<T>* theRootElement){
        // linkedListStruct<T>* pointer = theRootElement;
        // cout<<"hello"<<endl;
        // while(pointer->next){
        //     std::cout<<pointer->data<<" ";
        //     pointer = pointer->next;
        // }

    }

    template <typename T>
    static void printElementData(linkedListStruct<T>* element){
        std::cout<<*element->data;
    }

};


//Issue if the size is 0 then dont delete , get , set enything
// only you can append
template <typename T>
class LinkedListHelper{
    LinkedListSizeHelper *linkedListSizer = nullptr;

    public:
        linkedListStruct<T> *linkedListRoot = nullptr;
        static linkedListStruct<T> *linkedListNullElement;
        
        
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
            // Issue: If the stack is empty then append the data to the root element
            LinkedListAppender::appendAtEnd(&linkedListRoot, data);
            linkedListSizer->incrementSize();
        }

        T deleteAtEnd(){
            
            // Issue throw exception if the size is 0
            if(size() == 1){
                cout<<"There is only one element in the stack."<<endl;
                linkedListRoot->next = nullptr;
                linkedListSizer->decrementSize();
                return linkedListRoot->data;
            }else if(size() > 1){
                cout<<"deleteAtEnd(): There are more elements in the stack!"<<endl;
            }
            
            return linkedListNullElement->data;
        }

        bool isListEmpty(){
            return LinkedListChecker::isListEmpty(size());
        }

        void appendAtBegining(T data){
            if(isListEmpty()){
                LinkedListSetter::setElementData(linkedListRoot, data);
                linkedListSizer->incrementSize();
            }else{
                //Get the first element pass the root 

                linkedListStruct<T>* next = nullptr;
                LinkedListSetter::setAndInitListElement(&next, linkedListRoot->data);
                
                //LinkedListSetter set the next pointer
                next->next = linkedListRoot->next;

                //LinkedListSetter set element
                linkedListRoot->data = data;
                linkedListRoot->next = next;

                cout<<*linkedListRoot->data<<" "<<*linkedListRoot->next->data<<endl;
    
            }
        }
        
        
};

template <typename T>
linkedListStruct<T> * LinkedListHelper<T>::linkedListNullElement = nullptr;


int main(){    
    LinkedListHelper<int*>* l  = new LinkedListHelper(new int{3});
    cout<<l->size()<<endl;
    cout<<*l->deleteAtEnd()<<endl;
    

    cout<<l->size()<<endl;

    l->appendAtBegining(new int{5});
    l->appendAtBegining(new int{4});

    // l->appendAtBegining(new int{3});


    // LinkedListPrinter::printElementData(l->linkedListRoot);
    // l->appendAtBegining(new int{4});
    // LinkedListPrinter::print(l->linkedListRoot);
    
    
}