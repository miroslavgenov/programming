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
                // cout<<point->data->connectionFromVertex<<" "<<point->data->connectionToVertex<<" "<<point->data->connectionWeight<<endl;
                
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
void removeFromStackByVertexConnection(Stack<T>* stack, vertexConnection* currectConnection){
    if(stack->isEmpty() == false){
        //search and remove the element
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
    cout<<"lol hello"<<endl;
    cout<<t->connectionFromVertex<<" "<<t->connectionToVertex<<" "<<t->connectionWeight<<endl;
    
}