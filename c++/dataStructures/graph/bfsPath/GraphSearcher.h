#pragma once

class GraphSearcher: public Graph{
	public:
	std::vector<int> path;
	bool *visitedVerticies = nullptr;

	GraphSearcher(int *, int );

	void clearTheBasicVariables();
};