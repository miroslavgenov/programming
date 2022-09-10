#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int size=5;
    string a[size][2]={
		{"b"},
		{"a"},
		{"e"},
		{"c"},
		{"d"}
	};
	for(int i=0;i<size;i++){
		for(int j=1;i<size;j++){
			if(strcpy(a[j-1],(const char*)a[j])>0){
				string temp = a[j-1];
				a[j-1]=a[j];
				a[j]=temp;
			}
		}
	}
	
	
    

}























