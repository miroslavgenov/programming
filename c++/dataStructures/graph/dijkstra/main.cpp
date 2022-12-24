#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"

using namespace std;

struct connection{
    int connectionFromVertex;
    int connectionToVertex;
    int weight;
};

template <typename T>
void findTheMinimumConnectionWeight(Stack<T>* stack){
    // find the element and remove it
    if(stack->isEmpty() == false){
        linkedListStruct<T>* point =  stack->linkedListHelper->linkedListRoot;

        int minimumConnectionWeight = point->data->weight; 

        while(point){
            //finding minimum the element
            minimumConnectionWeight = minimumConnectionWeight >  point->data->weight ? point->data->weight : minimumConnectionWeight;
            point = point->next;
        }
        cout<<minimumConnectionWeight<<endl;
    }
}

template <typename T>
void removeFromStackByConnection(Stack<T>* stack, connection* currectConnection){
    if(stack->isEmpty() == false){
        //search and remove the element
    }
}

int main(){
    Stack<connection*> * stack  = new Stack(new connection{1,1,3});
    stack->push(new connection{4,4,2});
    stack->push(new connection{1,2,1});

    findTheMinimumConnectionWeight(stack);
    removeFromStackByConnection(stack, stack->linkedListHelper->linkedListRoot->data);
    
}