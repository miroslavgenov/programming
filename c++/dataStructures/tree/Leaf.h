#pragma once

template <typename T>
struct Leaf{
	T data;
	Leaf* left;
	Leaf* right;
	Leaf(T data, Leaf* left = nullptr, Leaf* right = nullptr){
		this->data = data;
		this->left = left;
		this->right = right;
		
	}
};
