#include <iostream>
#include <typeinfo>
#include <cstring>
#include <type_traits>


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

class LinkedListAppender{
    public:

};

template <typename T>
class LinkedListHelper{

    public:
        linkedListStruct<T> *linkedListRoot = nullptr;
        
        LinkedListHelper(T data){   
            if(is_pointer<T>::value){
                LinkedListSetter::setAndInitListElement(&linkedListRoot, data);
                        
            }else{
                cout<<"LinkedListHelper constructor: the data must be pointer"<<endl;
            }
        }
        
        T getTheDataAtTheTop(){
            return LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot)->data;
        }

        void appendAtEnd(T data){
            LinkedListSetter::setAndInitListElement(&LinkedListGetter::getTheLastElementFromTheLinkedList(&linkedListRoot)->next, data);
        }
        
        
};


int main(){    
    LinkedListHelper<int*> * l = new LinkedListHelper(new int{3});
    l->appendAtEnd(new int{4});
    l->appendAtEnd(new int{5});
    
    cout<<*l->getTheDataAtTheTop()<<endl;
    
    
    
}