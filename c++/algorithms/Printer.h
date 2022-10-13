#pragma once
#include <iostream>
#include <vector>

class Printer{
public:
	static void printNumbers(std::vector<int> numbers){
		for(int i=0;i<numbers.size();i++){
			std::cout<<numbers[i]<<" ";
		}std::cout<<std::endl;
	}

	static void printNumbers(int numbers[], const size_t NUMBERS_SIZE){
		for(int i = 0; i < NUMBERS_SIZE; i++){
			std::cout<<numbers[i]<<" ";
		}std::cout<<std::endl;
	}

	static void printGraph(int** graph, const size_t GRAPH_SIZE){
		for(int i = 0; i < GRAPH_SIZE; i++){
			for(int j = 0; j < GRAPH_SIZE; j++){
				std::cout<<graph[i][j]<<" ";
			}std::cout<<std::endl;
		}
	}
};
