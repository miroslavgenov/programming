#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void swapNumber(int *, int *);
void showNumbers(int [],int );
bool isNumberGreater(int *,int *);
void bubbleSortNumbers(int [],int );


int main(){
    int s1 = 5;
    int s2 = 5;
    int s3 = s1+s2;
    
    int a1[s1]={1,3,5,7,10};
    int a2[s2]={2,4,6,8,9};
    int a3[s3]{};

    // not optimal aproach

    int i=0,j=0;
    for(int z=0;z<=s3;z++){
    	if(i<s1){
    		a3[z]=a1[i];
    		i++;
		}else{
			a3[z]=a2[j];
    		j++;
		}
		
	}
	
	for(int i=0;i<s3;i++){
			for(int j=1;j<s3;j++){
				if(a3[j-1]>a3[j]){
					swapNumber(&a3[j-1],&a3[j]);
				}
			}
	}


    showNumbers(a3,s3);
    
   
}

bool isNumberGreater(int *greaterNumber,int *lesserNumber){
    return *greaterNumber>*lesserNumber;
}

void swapNumber(int *greaterNumber , int *lesserNumber){
    int temporaryNumber = *lesserNumber;
    *lesserNumber=*greaterNumber;
    *greaterNumber = temporaryNumber;
}


void showNumbers(int numbers[],int size){
    for(int i =0;i<size;i++)
        cout<<*(numbers+i)<<" ";
}





























































