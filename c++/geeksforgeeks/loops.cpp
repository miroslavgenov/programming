#include <iostream>
#include <vector>

using namespace std;

vector<int> getMoreAndLess(int arr[], int n, int x) {
	vector<int> list;
	int count_left=0;
	int count_right=0;

	for(int i=0;i<n;i++){
		if(arr[i]<=x){
			count_left++;
		}
		
		if(arr[i]>=x){
			count_right++;
		}
	}

	list.push_back(count_left);
	list.push_back(count_right);
	
}

int main(){
	constexpr int numbersSize=5;
	int numbers[numbersSize]{1,2,3,4,5};
	int l=0,r=0; // ?
	vector<int>list; // ?
	int number=4; // ?

	for(int i=0;i<numbersSize;i++){
		if(numbers[i]<=number) {
			l++;
		}
		
		if(numbers[i]>=number) {
			r++;
		}	
	}
	
	list.push_back(l);
	list.push_back(r);
	cout<<list[0]<<" "<<list[1];
	
	
}































