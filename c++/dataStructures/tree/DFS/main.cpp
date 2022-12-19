#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/FirstSearchUtil.h"

using namespace std;

template <typename T>
class DFS{
public:    
    vector<T> stack;

    DFS(T rootLeaf){
        stack.push_back(rootLeaf);
    }   

    void dfs(){
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
};