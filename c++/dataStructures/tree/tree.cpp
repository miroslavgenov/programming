#include "/home/home/Desktop/programming/c++/dataStructures/tree/tree.h"

	template <typename T>
	Tree<T>::Tree(T data){
		initializeRootLeaf(data);
		initializeListWithTheLeafValues(data);
	}

	template <typename T>
	void Tree<T>::initializeRootLeaf(T data){
		rootLeaf = new Leaf(data);
	}

	template <typename T>
	void Tree<T>::initializeListWithTheLeafValues(T data){
		listWithTheLeafValues = new LinkedListHelper(data);
	}
	
	template <typename T>
	void Tree<T>::appendLeaf(Leaf<T>* leaf){
		appendLeaf(&rootLeaf,leaf);
	}
	
	template <typename T>
	void Tree<T>::appendLeaf(Leaf<T>** rootLeaf, Leaf<T>* leaf){
		if(isLeafNullptr(*rootLeaf)){			
			*rootLeaf = leaf;
		}
		else{
			shouldAppendLeftOrRightLeaf(*rootLeaf, leaf);
		}
	}

template <typename T>
	void Tree<T>::shouldAppendLeftOrRightLeaf(Leaf<T>* rootLeaf,Leaf<T>*leaf){
		if(*rootLeaf->data > *leaf->data){	
			appendLeaf(&rootLeaf->left,leaf);
		}
		else{
			appendLeaf(&rootLeaf->right,leaf);
		}
	}

template <typename T>
	bool Tree<T>::isLeafNullptr(Leaf<T>* leaf){
		return leaf == nullptr;
	}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>* tree){
	Printer::printTree(tree->rootLeaf);
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tree<T>& tree){
	Printer::printTree(tree.rootLeaf);
	return os;
}
