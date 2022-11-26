#include "/home/home/Desktop/programming/c++/dataStructures/LinkedList/src/LinkedListHelper.h"

template <typename T>        
LinkedListHelper<T>::LinkedListHelper(T data){   
    if(std::is_pointer<T>::value){
        LinkedListSetter::setAndInitListElement(&linkedListRoot, data);
        linkedListSizer = new LinkedListSizeHelper();
    }else{
        std::cout<<LinkedListException::CONSTRUCTOR_ERROR<<std::endl;
    }
}
        
template <typename T>        
T LinkedListHelper<T>::top(){
    return LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot)->data;
}

template <typename T>        
int LinkedListHelper<T>::size(){
    return linkedListSizer->getSize();
}

template <typename T>        
void LinkedListHelper<T>::appendAtEnd(T data){
    if(isListEmpty()){
        LinkedListSetter::setElementData(linkedListRoot,data);
    }else{
        LinkedListAppender::appendAtEnd(&linkedListRoot, data);
    }

    linkedListSizer->incrementSize();
}

template <typename T>        
T LinkedListHelper<T>::deleteAtEnd() noexcept(false){
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

template <typename T>        
T LinkedListHelper<T>::deleteAtBegining(){
    if(isListEmpty()){
        throw LinkedListException("deleteAtBegining(): size==0");
    }else{
        linkedListSizer->decrementSize();
        return LinkedListDeleter::deleteAtBeginning(linkedListRoot);
    }
    return nullptr;
}

template <typename T>        
bool LinkedListHelper<T>::isListEmpty(){
    return LinkedListChecker::isListEmpty(size());
}

template <typename T>        
void LinkedListHelper<T>::appendAtBegining(T data){
    if(isListEmpty()){
        LinkedListSetter::setElementData(linkedListRoot, data);
    }else{
        LinkedListAppender::appendAtBegining(linkedListRoot,data);   
    }

    linkedListSizer->incrementSize();
}

template <typename T>        
void LinkedListHelper<T>::print(){
    if(!isListEmpty()){
        LinkedListPrinter::printElementsData(linkedListRoot);
    }
}