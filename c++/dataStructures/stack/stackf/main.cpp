#include <iostream>

using namespace std;

template <typename T>
struct stack{
	T value;
	stack* next;
	stack* prev;
};



void appendStack(stack* stackRoot, stack* stack){
	if(!stackRoot){
		stackRoot->next = stack;
		stack->prev = stackRoot;
		stack->next=nullptr;	
	}
}

int main(){

}













































