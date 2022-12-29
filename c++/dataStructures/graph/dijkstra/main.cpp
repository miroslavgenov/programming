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
void removeFromStackByVertexConnection(Stack<T>* stack,linkedListStruct<T>** linkedListRoot, vertexConnection* target){
    if(stack->isEmpty() == false){
        linkedListStruct<T>* linkedListRootPointer = *linkedListRoot;
        // if the target is first in stack
        if(isVertexConnectionsEqual(linkedListRootPointer->data, target)){
            stack->linkedListHelper->deleteAtBegining();
        }
        // if target is not first in stack
        else{
            cout<<"the target is not first in stack"<<endl;
            while(linkedListRootPointer->next){
                if(isVertexConnectionsEqual(linkedListRootPointer->next->data, target)){
                    // print(linkedListRootPointer->data);
                    // print(linkedListRootPointer->next->data);

                    // if next don't have next do this ...
                    if(linkedListRootPointer->next->next == nullptr){
                        cout<<"next  dont have next"<<endl;
                        stack->linkedListHelper->deleteAtEnd();
                        
                    }
                    // if the next have next->next do this ...
                    else if(linkedListRootPointer->next->next != nullptr){
                        cout<<"next has next"<<endl;
                        linkedListRootPointer->next = linkedListRootPointer->next->next;
                        stack->linkedListHelper->decrementSize();

                    }

                    break;
                }
                
                linkedListRootPointer = linkedListRootPointer->next;
            }

        }
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
    stack->push(new vertexConnection{4,4,2});
    stack->push(new vertexConnection{1,2,0});

    vertexConnection* target = findTheMinimumConnectionWeight(stack);
    
    removeFromStackByVertexConnection(stack,&stack->linkedListHelper->linkedListRoot,target);
}