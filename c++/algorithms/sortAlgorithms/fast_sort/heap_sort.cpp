#include <iostream>

using namespace std;
void mySwap(int &great,int &less){
	int temp = great;
	great=less;
	less=temp;
	
}

void swapChild(int a[],int left,int root,int right){
	if(a[root]>a[left] && a[root]>a[right]){
			cout<<"(a[root]>a[left] && a[root]>a[right])"<<endl;
		}
		else if(a[left]>a[root] && a[left]>a[right]){
			cout<<"else if(a[left]>a[root] && a[left]>a[right])"<<endl;
			mySwap(a[left],a[root]);
		}
		else if(a[right]>a[root]&& a[right]>a[left]){
			cout<<"else if(a[right]>a[root]&& a[right]>a[left])"<<endl;
			mySwap(a[right],a[root]);
		}
}
void swapChild(int a[],int left,int root){
	if(a[left]>a[root]){
		cout<<"if(a[left]>a[root])"<<endl;
		mySwap(a[left],a[root]);
	}else if(a[root]>a[left]){
		cout<<"else if(a[root]<a[left])"<<endl;
	}
}

void maxHeap(int a[],int root,int size){
	int left = root*2;
	int right = root*2+1;
	if(root==size)return;
	
	if(root*2+1<size){
		cout<<"if(root*2+1<size)"<<endl;
		swapChild(a,left,root,right);
		
	}
	else if(root*2<size){
		cout<<"else if(root*2<size)"<<endl;
		swapChild(a,left,root);
	}
	maxHeap(a,++root,size);
	
	
	
}
void heapSort(int a[],int root,int size){
	if(root==size)return;
	cout<<"HeapSort"<<endl;
	
	if(root<size){
		cout<<"if(root<size)"<<endl;
		cout<<a[root]<<" "<<a[size-1]<<endl;
		mySwap(a[root],a[size-1]);
	}
	--size;
	maxHeap(a,root,size);
	
	heapSort(a,root,size);
	
}

int main(){
	int size=6;
	int a[size]={0,4,10,3,5,1};
	int copySize=size;
	
	maxHeap(a,1,copySize);
	heapSort(a,1,size);
	
	
	for(int i=1;i<size;i++){
		cout<<a[i]<<" ";
	}
	
	
}


















