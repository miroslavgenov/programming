#include "/home/home/Desktop/programming/c++/dataStructures/Stack/src/Stack.h"

template <typename T>
Stack<T>::Stack(T data){
    linkedListHelper = new LinkedListHelper(data);
}

template <typename T>
void Stack<T>::push(T data){
    if(linkedListHelper == nullptr){
        linkedListHelper = new LinkedListHelper(data);
    }else{
        linkedListHelper->appendAtEnd(data);
    }    
}

template <typename T>
T Stack<T>::getTop(){
    return linkedListHelper->top();
}

template <typename T>
T Stack<T>::pop(){
    return linkedListHelper->deleteAtEnd();
}

template <typename T>
int Stack<T>::size(){
    return linkedListHelper->size();
}

template <typename T>
bool Stack<T>::isEmpty(){
    return linkedListHelper->isListEmpty();
}

template <typename T>
void Stack<T>::print(){
    linkedListHelper->print();
}

template <typename X>
std::ostream& operator<<(std::ostream& os, Stack<X>* stack){
stack->print();
return os;
}