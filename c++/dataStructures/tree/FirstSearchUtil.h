#pragma once

#include <queue>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/Leaf.h"


class FirstSearchUtil{
    public:
    template <typename T>
    static void shouldAppendLeafTo(T leaf, queue<T> queue){
        if(!isLeafEmpty(leaf)){
                    queue.push(leaf);
        }
    }

    template <typename T>
    static void shouldAppendLeafTo(T Leaf, vector<T> stack){
        if(!isLeafEmpty(leaf)){
            stack.push_back(leaf);
        }
    }


    template <typename T>
    static bool isLeafEmpty(Leaf<T> leaf){
        return leaf == nullptr;
    }
    
};