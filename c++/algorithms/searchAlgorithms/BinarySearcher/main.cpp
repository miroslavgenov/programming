#include <iostream>
#include <vector>

using namespace std;

class ArrayChecker{
public:
	template <typename T>
	static bool isArraySorted(T array[], int size){
		for(int i=1;i<size;i++){
			if(array[i-1] > array[i]){
				return false;
			}
		}
		return true;
	}
};


class BinarySearcher{
	int numberToBeFound;
	vector<int> numbers;
	int left = 0;
	int right;
	int mid;

public:
	BinarySearcher(int numbers[], size_t numbersSize, int numberToBeFound){
		if(!ArrayChecker::isArraySorted(numbers,numbersSize)){
			cout<<"sort your first array"<<endl;
		}
		this->numberToBeFound = numberToBeFound;
		for(int i = 0;i<numbersSize;i++){
			this->numbers.push_back(numbers[i]);
		}
		
		right = this->numbers.size()-1;
		mid = (left+right)/2;

	}

	void search(){
		binarySearch(left,mid,right,numberToBeFound);
	}
private:
	void binarySearch(int left, int mid, int right, int toBeFound){
	if(numbers[mid] == toBeFound){
		cout<<"number: "<<toBeFound<<" is at index: "<<mid<<endl;
		return ;
	}
	if(left >= right){
		cout<<toBeFound<<" is not found"<<endl;
		return;
	}
	if(numbers[mid] < toBeFound){
		binarySearch(mid + 1, (mid+1 + right) / 2, right, toBeFound);
	}else{
		binarySearch(left, ((mid - 1) + left) / 2, mid - 1, toBeFound);
	}
}
};



int main(){
	int numbersSize = 10;
	int numbers[numbersSize] = {1,2,3,4,5,6,7,8,9,10};
	
	BinarySearcher * b = new BinarySearcher(numbers,numbersSize,3);
	b->search();

	


}
