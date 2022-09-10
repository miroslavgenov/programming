#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

void swapNumber(int *, int *);
void showNumbers(int [],int );
bool isNumberGreater(int *,int *);
void bubbleSortNumbers(int [],int );


void sortInc(int a[],int s1){
	for(int i=0;i<s1;i++)
		for(int j=1;j<s1;j++)
			if(a[j-1]>a[j])
				swapNumber(&a[j-1],&a[j]);
}

void sortDec(int a[],int s1){
	for(int i=0;i<s1;i++){
		for(int j=s1-1;j>0;j--){
			if(a[j]>a[j-1]){
				swapNumber(&a[j],&a[j-1]);
			}
		}
	}
}

int main(){
	int s=6;
	int a[s][s]={
		{1,2,3,4,5,6
		},
		{1,2,3,4,5,6
		},
		{1,2,3,4,5,6
		},
		{1,2,3,4,5,6
		},
		{1,2,3,4,5,6
		},
		{1,2,3,4,5,6
		}
};
	
	
	for(int i=0;i<s;i++){
		if(i<2){
			sortDec(a[i],s);
			
		}else{
			if(i%2==0){
				
				sortInc(a[i],s);
			}else if(i%2!=0){
				
				sortDec(a[i],s);
			}
		}
		
	}
	
	for(int i=0;i<s;i++){
			for(int j=0;j<s;j++)	
			{
				cout<<a[i][j]<<" ";	
			}
			
		cout<<endl;		
			
			
	}
	
	
	
	
	
   
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





























































