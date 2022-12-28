#include <iostream>

#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"

using namespace std;

struct vertexConnection{
    int connectionFromVertex;
    int connectionToVertex;
    int connectionWeight;
};

// isVertexConnectionMinimum(weight: int): bool
// setTheMinimumVertexConnection(srcData, dstData: srcVertexConnection,vertexConnection**): void

bool isTheNewConnectionWeightLessThan(int currentConnectionWeight, int prevConnectionWeight){
    return prevConnectionWeight > currentConnectionWeight;
}

template <typename T>
vertexConnection* findTheMinimumConnectionWeight(Stack<T>* stack){
    vertexConnection* minimumConnection = nullptr;
    
    if(stack->isEmpty() == false){
        
        linkedListStruct<T>* point =  stack->linkedListHelper->linkedListRoot;

        int minimumConnectionWeight = point->data->connectionWeight; 

        minimumConnection = new vertexConnection{
                    point->data->connectionFromVertex,
                    point->data->connectionToVertex,
                    point->data->connectionWeight
                };

        while(point){
            if(minimumConnectionWeight > point->data->connectionWeight ){                
                // print(point->data);
                
                minimumConnection = new vertexConnection{
                    point->data->connectionFromVertex,
                    point->data->connectionToVertex,
                    point->data->connectionWeight
                };
            }
            
            
            point = point->next;
        }

        
    }

    return minimumConnection;
}

void print(vertexConnection* connection){
    cout<<"connectionFromVertex: "<<connection->connectionFromVertex<<"\nConnectionToVertex: "<<connection->connectionToVertex<<"\nConnectionWeight: "<<connection->connectionWeight<<endl;
}

bool isVertexConnectionsEqual(vertexConnection* first, vertexConnection* sec){
     if(first != nullptr && sec != nullptr){
        if(first->connectionFromVertex == sec->connectionFromVertex & first->connectionToVertex == sec->connectionToVertex & first->connectionWeight == sec->connectionWeight){
            return true;
        }
     }
        

     return false;
}

template <typename T>
void removeFromStackByVertexConnection(Stack<T>* stack,linkedListStruct<T>** t, vertexConnection* target){
    linkedListStruct<T>* p = *t;
    // if the target is first in stack
    if(isVertexConnectionsEqual(p->data, target)){
        p->data->connectionFromVertex = p->next->data->connectionFromVertex;
        p->data->connectionToVertex = p->next->data->connectionToVertex;
        p->data->connectionWeight = p->next->data->connectionWeight;
        p->next = p->next->next;
        stack->linkedListHelper->decrementSize();
    }
    // if target is not first in stack
    else{
        cout<<"the target is not first in stack"<<endl;
    }

    
}

template <typename T>
void print(Stack<T>* stack){
    if(stack->isEmpty() == false){
        linkedListStruct<T> * point = stack->linkedListHelper->linkedListRoot;

        while(point){
            cout<<point->data->connectionWeight<<endl;
            point = point->next;
        }
    }
}

int main(){
    Stack<vertexConnection*> * stack  = new Stack(new vertexConnection{1,1,1});
    stack->push(new vertexConnection{4,4,0});
    stack->push(new vertexConnection{1,2,2});

    vertexConnection* target = findTheMinimumConnectionWeight(stack);
    // print(target);
    // print(stack);
    // cout<<endl;
    // cout<<&stack<<endl; 
    // cout<<"stack size: "<<stack->size()<<endl;
    removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot,target);
    // stack->linkedListHelper->
    // stack->linkedListHelper->decrementSize();

    // cout<<"stack size: "<<stack->size()<<endl;  
    // cout<<endl;
    // print(stack);

}