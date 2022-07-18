#include <iostream>
#include <vector>
using namespace std;
vector<int> getMoreAndLess(int arr[], int n, int x) {
	vector<int> list;
	int count_left=0,count_right=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=x)count_left++;
		if(arr[i]>=x)count_right++;
	}
	list.push_back(count_left);
	list.push_back(count_right);
	
}

int main(){
	int arr[5]{1,2,3,4,5};
	int l=0,r=0;
	for(int i=0;i<5;i++){
		if(arr[i]<=4) l++;
		if(arr[i]>=4) r++;
			
	}
	vector<int>list;
	list.push_back(l);
	list.push_back(r);
	cout<<list[0]<<" "<<list[1];
	
	
}































