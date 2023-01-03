#pragma once

#include "/home/home/Desktop/programming/c++/dataStructures/graph/dijkstra/vertexConnection.h"
#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"


class DijkstraStackUtil{
    public:
    static bool isVertexConnectionsEqualTo(vertexConnection* first, vertexConnection* sec){
        if(first != nullptr && sec != nullptr){
            if(first->connectionFromVertex == sec->connectionFromVertex & first->connectionToVertex == sec->connectionToVertex & first->connectionWeight == sec->connectionWeight){
                return true;
            }
        }
            
        return false;
    }

template <typename T>
static vertexConnection* findTheMinimumConnectionWeight(Stack<T>* stack){
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


    template <typename T>
static void removeFromStackByVertexConnection(Stack<T>* stack,linkedListStruct<T>** linkedListRoot, vertexConnection* target){
    if(stack->isEmpty() == false){
        linkedListStruct<T>* linkedListRootPointer = *linkedListRoot;
        // if the target is first in stack
        if(DijkstraStackUtil::isVertexConnectionsEqualTo(linkedListRootPointer->data, target)){
            stack->linkedListHelper->deleteAtBegining();
        }
        // if target is not first in stack
        else{
            // cout<<"the target is not first in stack"<<endl;
            while(linkedListRootPointer->next){
                if(DijkstraStackUtil::isVertexConnectionsEqualTo(linkedListRootPointer->next->data, target)){
                    // print(linkedListRootPointer->data);
                    // print(linkedListRootPointer->next->data);

                    // if next don't have next do this ...
                    if(linkedListRootPointer->next->next == nullptr){
                        // cout<<"next  dont have next"<<endl;
                        stack->linkedListHelper->deleteAtEnd();
                        
                    }
                    // if the next have next->next do this ...
                    else if(linkedListRootPointer->next->next != nullptr){
                        // cout<<"next has next"<<endl;
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

};