#include <iostream>
#include <vector>

#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.cpp"

using namespace std;

template <typename T>
class DFS{
    //TO DO: write it down on paper
    public:
    
    vector<T> stack;
    vector<T> storedPath;
    int theIndexOfTheLastElement;

    DFS(T rootLeaf){
        stack.push_back(rootLeaf);
        theIndexOfTheLastElement = stack.size()-1;
    }   

    
    void dfs(){
        if(stack.empty() == false){
            cout<<*stack[theIndexOfTheLastElement]->data<<endl;
        
            shouldAppendLeafToStack(stack[theIndexOfTheLastElement]->left);
            shouldAppendLeafToStack(stack[theIndexOfTheLastElement]->right);
        
            if(stack.empty() == false){
                stack.erase(stack.begin()+theIndexOfTheLastElement);
                dfs();
            }
        }
        
        
    }
    
    void shouldAppendLeafToStack(T leaf){
        if(leaf){
            stack.push_back(leaf);
        }
    }


    vector<T> getPath(){
        return storedPath;
    }

};

int main(){
    Tree<int*>* tree = new Tree(new int{3});
	
	tree->appendLeaf(new Leaf(new int{4}));
	tree->appendLeaf(new Leaf(new int{1}));
	tree->appendLeaf(new Leaf(new int{2}));
	tree->appendLeaf(new Leaf(new int{7}));
    
    DFS<Leaf<int*>*>* dfs = new DFS(tree->rootLeaf);
    dfs->dfs();



}