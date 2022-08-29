/**
 * @file myGraphTraversal.cpp
 * @author your name (you@domain.com)
 * @brief My graph traversal
 * @version 0.1
 * @date 2022-08-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

bool isNumberInArray(vector<int> v, int n){
	if(v.size()==0){
		return 0;	
	}else{
		for(int i=0;i<v.size();i++){
		if(n == v[i]){
			return 1;
		}
	}	
	}
	
	return 0;
}

template <typename T>
void printV(vector<T>v){
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}
const int s=5;
void printGraphEdgeArc(int [][s]);

int main(){
	vector<int> v;
	v.push_back(0);
	
	
	int g[s][s]={
		{0,1,0,0,1},
		{1,0,1,1,1},
		{0,1,0,1,0},
		{0,1,1,0,1},
		{1,1,0,1,0}
	};
	
	
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			if(g[i][j] == 1)  {
				if(!isNumberInArray(v,j)){
					v.push_back(j);
				}		
			}
		}
	}
	
	printV(v);
	printGraphEdgeArc(g);
	

	
	
	
}
void printGraphEdgeArc(int g[][s]){
	cout<<endl;
	for(int i=0;i<s;i++){
		cout<<"edge: "<<i<<" arc: ";
		for(int j=0;j<s;j++){
			if(g[i][j] == 1){
				cout<<j<<" ";
			}
		}cout<<endl;
	}
}













































