#include "/home/home/Desktop/programming/c++/dataStructures/tree/DFS/dfs.h"



template <typename T>
    DFS<T>::DFS(T rootLeaf){
        stack.push_back(rootLeaf);
    }   
template <typename T>
    void DFS<T>::dfs(){
        if(stack.empty() == false){
            T data = stack.back();
            cout<<*data->data<<endl;
            stack.pop_back();

			//NOTE: To edit the order of appending leafs in the container change the function algorithm.
            FirstSearchUtil::shouldAppendLeafsTo(data, stack);

            if(stack.empty() == false){
                dfs();
            }
        }        
    }
