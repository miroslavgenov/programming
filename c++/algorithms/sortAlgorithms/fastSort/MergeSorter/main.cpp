#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const size_t numbersSize = 2; //rand()%20;
int numbers[numbersSize]{2,1};

void print(){
    for(int i=0;i<numbersSize;i++){
        cout<<numbers[i]<<' ';
    }cout<<endl;
}

void print(int n[], int s){
    for(int i=0;i<s;i++){
        cout<<n[i]<<" ";
    }
    cout<<endl;
}

bool isIndexInRange(int index, int range){
    return index < range;
}

bool isTwoIndexesInRange(int firstIndex, int firstRange, int secondIndex, int secondRange){
    return isIndexInRange(firstIndex, firstRange) && isIndexInRange(secondIndex, secondRange);
}

int main(){  
    // srand(time(0));
    int l = 0;
    int r = numbersSize;
    int mid = (l+r)/2;
    int b[numbersSize];
    int i= 0;
    int j = mid;
    int it = 0;
    cout<<numbers[mid]<<endl;
    
    
    while(i<mid && j<r
        //isTwoIndexesInRange(i,mid,j,r)
        //isIndexInRange(i,mid) && isIndexInRange(j,r)
    ){
        
        if(numbers[i] > numbers[j]){
            b[it] = numbers[j];
            it++;
            // cout<<numbers[j]<<endl;
            j++;
        }

        if(numbers[i] < numbers[j]){
            // cout<<numbers[i]<<endl;
            b[it] = numbers[i];
            it++;
            i++;
        }
    }

    // is i not out of range
    if(i<mid
        //isIndexInRange(i,mid)
        ){
        for(int z = i;z<mid;z++){
            // fill the remaining numbers
            b[it] = numbers[z];
            it++;
        }
    }

    // is j not out of range
    if( j<r
        //isIndexInRange(j,r)
        ){
        // fill the remaining numbers
        for(int z = j; z<r;z++){
            b[it] = numbers[z];
            it++;
        }
    }

    print(b,numbersSize);



    

}
