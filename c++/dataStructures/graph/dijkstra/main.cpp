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
     if(first->connectionFromVertex == sec->connectionFromVertex & first->connectionToVertex == sec->connectionToVertex & first->connectionWeight == sec->connectionWeight){
        return true;
     }

     return false;
}

template <typename T>
void removeFromStackByVertexConnection(Stack<T>* stack, vertexConnection* currectConnection){
    if(stack->isEmpty() == false){
        linkedListStruct<T>* point = stack->linkedListHelper->linkedListRoot;

        while(point){

            
            if(isVertexConnectionsEqual(point->data, currectConnection) == true){
                //remove the element from the stack
                
                break;

            }

            point = point->next;
            
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
    Stack<vertexConnection*> * stack  = new Stack(new vertexConnection{1,1,3});
    stack->push(new vertexConnection{4,4,2});
    stack->push(new vertexConnection{1,2,1});

    vertexConnection* t = findTheMinimumConnectionWeight(stack);

    removeFromStackByVertexConnection(stack,t);
}