/**
 * 
 * 
 * @file stack.cpp
 * @author Miroslav (you@domain.com)
 * @brief  Not done!!! @see stack_simple.cpp
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;


class Stack{
    static int index;
    int value;
    Stack *next;
    public:
        Stack(int,Stack *);
        Stack(int );
        Stack (Stack *dst){
            this->value = dst->getValue();
            this->next = dst->getNext();
        }
        void appendNext(Stack *);
        bool isNextNullptr();
        Stack * getNext()const;
        void setNext(Stack *);
        int getValue()const;
        void printStack();
        Stack* getLastElement(){
            Stack *stack=nullptr;
            for(int i=0;i<index;i++){
                if(i==index-1)
                stack = this;
            }
            return stack;
        }
        
};

int Stack::index=0;

Stack::Stack(int value,Stack *next):value(value),next(next){
    index++;
}
Stack::Stack(int value):Stack(value,nullptr){};



void Stack::appendNext(Stack * destination){
    setNext(destination);
}
void Stack::setNext(Stack * destination){
    this->next=destination;
}

bool Stack::isNextNullptr(){
    return getNext()==nullptr;
}

Stack * Stack::getNext()const{return this->next;}

int Stack::getValue()const{return value;}

void Stack::printStack(){
    Stack *s = this;
    for(int i=0;i<index;i++){
        cout<<s->getValue()<<" ";
        s=s->getNext();
    }
}
// Stack::Stack *pop_back(){
    // return nullptr;
// }

int main(){
    Stack *root = new Stack(3);
    Stack *r1 = new Stack(1);
    Stack *r2 = new Stack(5);
    Stack *r3 = new Stack(4);

    root->setNext(r1);
    r1->setNext(r2);
    r2->setNext(r3);

    // root->printStack();
    cout<<root->getLastElement()->getValue()<<endl;



}










