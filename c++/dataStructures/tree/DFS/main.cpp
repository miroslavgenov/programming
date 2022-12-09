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

    DFS(T rootLeaf){
        stack.push_back(rootLeaf);
    }   

    void dfs(){
        if(stack.empty() == false){
            if(stack.back()->left){
                stack.push_back(stack.back()->left);
            }

             
            // if(stack.back()->left){
            //     stack.push_back(stack.back()->left);
            // }
            // if(stack.back()->right){
            //     stack.push_back(stack.back()->right);
            // }

            // if(stack.empty() == false){
            //     stack.pop_back();
            //     dfs();
            // }
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