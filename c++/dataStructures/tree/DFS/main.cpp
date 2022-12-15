#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"
#include "/home/home/Desktop/programming/c++/dataStructures/tree/FirstSearchUtil.h"

using namespace std;

template <typename T>
class DFS{
    //TO DO: write it down on paper
    public:
    
    vector<T> stack;
    int theIndexOfTheLastElement;

    DFS(T rootLeaf){
        stack.push_back(rootLeaf);
        theIndexOfTheLastElement = stack.size()-1;
    }   

    
    void dfs(){
        if(stack.empty() == false){
            // cout<<"stack: "<<&stack<<endl;
            cout<<*stack[theIndexOfTheLastElement]->data<<endl;
            
            // FirstSearchUtil::shouldAppendLeafTo(stack[theIndexOfTheLastElement]->left, stack);
            // FirstSearchUtil::shouldAppendLeafTo(stack[theIndexOfTheLastElement]->right, stack);
            // shouldAppendLeafToStack(stack[theIndexOfTheLastElement]->right);
            // shouldAppendLeafToStack(stack[theIndexOfTheLastElement]->left);

            if(stack.empty() == false){
                stack.erase(stack.begin()+theIndexOfTheLastElement);
                // dfs();
            }
            cout<<*stack[theIndexOfTheLastElement]->data<<endl;
        }
        
        
    }
    
    void shouldAppendLeafToStack(T leaf){
        if(leaf){
            stack.push_back(leaf);
        }
    }



};

int main(){
   Tree<int*>* tree = new Tree(new int{3});
	
	tree->appendLeaf(new Leaf(new int{5}));
	tree->appendLeaf(new Leaf(new int{4}));
	tree->appendLeaf(new Leaf(new int{1}));
	tree->appendLeaf(new Leaf(new int{2}));
	tree->appendLeaf(new Leaf(new int{7}));
	tree->appendLeaf(new Leaf(new int{6}));
    
    DFS<Leaf<int*>*>* dfs = new DFS(tree->rootLeaf);
    dfs->dfs();



}