#include <iostream>
#include <vector>
#include "/home/home/Desktop/programming/c++/algorithms/ArrayChecker.cpp"
#include "/home/home/Desktop/programming/c++/algorithms/searchAlgorithms/NumberSearcher.h"

using namespace std;

class BinarySearcher: NumberSearcher{
	int left = 0;
	int right;
	int mid;

public:
	
	BinarySearcher(int numbers[], size_t numbersSize, int findThisNumber):NumberSearcher(numbers, numbersSize, findThisNumber){
			right = numbersSize-1;
			mid = (left+right)/2;
	}

	int search(){
		if(ArrayChecker::areNumbersSorted(numbers,numbersSize)){
			 binarySearchIndexOfFindThisNumber(left,mid,right,findThisNumber);	
			 return foundIndex;
		}
		else{
			cout<<"sort your first array"<<endl;
		}

		return indexIsNotFound;
	}
	
private:
	void binarySearchIndexOfFindThisNumber(int left, int mid, int right, int findThisNumber){
	if(numbers[mid] == findThisNumber){
		// cout<<"number: "<<findThisNumber<<" is at index: "<<mid<<endl;
		foundIndex = mid;
		return ;
	}
	if(left >= right){
		// cout<<findThisNumber<<" is not found"<<endl;
		return;
	}
	if(numbers[mid] < findThisNumber){
		binarySearchIndexOfFindThisNumber(mid + 1, (mid+1 + right) / 2, right, findThisNumber);
	}else{
		binarySearchIndexOfFindThisNumber(left, ((mid - 1) + left) / 2, mid - 1, findThisNumber);
	}
}
};



int main(){
	int numbersSize = 10;
	int numbers[numbersSize] = {1,2,3,4,5,6,7,8,9,10};
	
	BinarySearcher * b = new BinarySearcher(numbers,numbersSize,3);
	cout<<numbers[b->search()];

	


}
