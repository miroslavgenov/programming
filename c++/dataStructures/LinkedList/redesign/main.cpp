#include <iostream>
#include <typeinfo>
#include <cstring>
#include <type_traits>

#include "linkedListStruct.h"
#include "LinkedListSetter.h"
#include "LinkedListGetter.h"
#include "LinkedListSizeHelper.cpp"
#include "LinkedListChecker.h"
#include "LinkedListAppender.h"
#include "LinkedListException.h"
#include "LinkedListPrinter.h"
#include "LinkedListDeleter.h"

using namespace std;

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
                cout<<LinkedListException::CONSTRUCTOR_ERROR<<endl;
            }
        }
        
        T top(){
            return LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot)->data;
        }

        int size(){
            return linkedListSizer->getSize();
        }

        void appendAtEnd(T data){
            if(isListEmpty()){
                LinkedListSetter::setElementData(linkedListRoot,data);
            }else{
                LinkedListAppender::appendAtEnd(&linkedListRoot, data);
            }

            linkedListSizer->incrementSize();
        }

        //LinkedListDeleter
        T deleteAtEnd() noexcept(false){
            if(isListEmpty()){
                throw LinkedListException(LinkedListException::OUT_OF_RANGE);
            }
            else{
                if(size() == 1){
                    LinkedListSetter::setTheNextElementOfTheCurrentElementTo(linkedListRoot);
                    linkedListSizer->decrementSize();
                    return linkedListRoot->data;
                }else if(size() > 1){
                    linkedListSizer->decrementSize();
                    return LinkedListDeleter::deleteAtEnd(linkedListRoot);
                }
            }
            
            return nullptr;
        }

        T deleteAtBegining(){
            if(isListEmpty()){
                throw LinkedListException("deleteAtBegining(): size==0");
            }else{
                linkedListSizer->decrementSize();
                return LinkedListDeleter::deleteAtBeginning(linkedListRoot);
            }
            return nullptr;
        }
        
        bool isListEmpty(){
            return LinkedListChecker::isListEmpty(size());
        }

        void appendAtBegining(T data){
            if(isListEmpty()){
                LinkedListSetter::setElementData(linkedListRoot, data);
            }else{
                LinkedListAppender::appendAtBegining(linkedListRoot,data);   
            }

            linkedListSizer->incrementSize();
        }

        
        void print(){
            if(!isListEmpty()){
                LinkedListPrinter::printElementsData(linkedListRoot);
            }
        }
};

int main(){    
    LinkedListHelper<int*>* l  = new LinkedListHelper(new int{3});
    l->appendAtBegining(new int{2});
    
    l->print();
    cout<<endl;

    l->deleteAtEnd();
    l->deleteAtEnd();
    

    l->print();
    cout<<endl;
}