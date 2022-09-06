#include <iostream>
#include <fstream>

using namespace std;

int main(){
	std::ofstream of("numbers.txt");
	size_t lenght = 25;
	int num[] = {
 22 ,
 23 



	};
	int val[] = {
 100,
 	92
	};


	
	int idx=0;
	size_t size = sizeof(num)/sizeof(*num);
	for(int i=0;i<lenght;i++){
		of<<i<<"\t";
	}of<<endl;
	
	
	for(int i = 0; i < lenght; i++){
		if(idx<size){
			if(i == num[idx]){
				of<<val[idx]<<"\t";
				idx++;
				continue;
			}
			
		}
		of<<"0"<<"\t";
	}
	
		
		
	
	
	
}






































































