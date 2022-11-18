#pragma once

template <typename T>
struct Leaf{
	T data;
	Leaf* left;
	Leaf* right;
};
