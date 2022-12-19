#pragma once

#include <queue>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"


class FirstSearchUtil{
    public:

    template <typename T>
    static void shouldAppendLeafsTo(T leaf, queue<T>& queue){
        shouldAppendLeafTo(leaf->right, queue);
        shouldAppendLeafTo(leaf->left, queue);

    }

    template <typename T>
    static void shouldAppendLeafsTo(T leaf, vector<T>& stack){
        shouldAppendLeafTo(leaf->right, stack);
        shouldAppendLeafTo(leaf->left, stack);
    }

    template <typename T>
    static void shouldAppendLeafTo(T leaf, queue<T>& queue){
        if(!isLeafEmpty(leaf)){
                    queue.push(leaf);
        }
    }

    template <typename T>
    static void shouldAppendLeafTo(T leaf, vector<T>& stack){
        // cout<<"util stack: "<<&stack<<endl;
        if(!isLeafEmpty(leaf)){
            stack.push_back(leaf);
        }
    }


    template <typename T>
    static bool isLeafEmpty(T leaf){
        return leaf == nullptr;
    }
    
};