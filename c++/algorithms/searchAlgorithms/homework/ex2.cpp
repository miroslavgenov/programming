#include<iostream>
#include <vector>
using namespace std;

void print(vector<int> a,int s){
	for(auto i=end(a)-1;i>=begin(a);i--)cout<<*i<<" ";
}

int get_number_while_reversing_vector(vector<int> a,int s){
	int num=0;
	for(auto i=end(a)-1;i>=begin(a);i--)
	{
		num*=10;
		num+=*i;
	}
	return num;
}


vector<int> list;
int fill_number_zeros_with_nine(int num){
	if(!num) { 
		return get_number_while_reversing_vector(list,list.size());
	}
	::list.push_back(num%10==0?9:num%10);
	num=num/10;
	fill_number_zeros_with_nine(num);
	
	
	
}

int main(){
	cout<<fill_number_zeros_with_nine(2010);
	
	
}
