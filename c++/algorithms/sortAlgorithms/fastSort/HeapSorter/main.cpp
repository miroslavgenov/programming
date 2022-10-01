#include <iostream>

using namespace std;

int main(){
    int numbersSize = 11;
    int numbers[numbersSize] = {1,2,3,4,5,6,7,8,9,10,11};
    for(int i=0; i*2+1 < numbersSize || i*2+2 <numbersSize ; i++ ){
        if(i*2+1 < numbersSize && i*2+2 < numbersSize ){
            cout<<numbers[i*2+1]<<" "<<numbers[i]<<" "<<numbers[i*2+2]<<endl;
        }
        else{
            if(i*2+1 < numbersSize){
                if(i*2+2 < numbersSize){
                    cout<<numbers[i*2+1]<<" "<<numbers[i]<<" "<<numbers[i*2+2]<<endl;
                }else{
                    cout<<numbers[i*2+1]<<" "<<numbers[i]<<endl;
                }
                
            }

        }
    }
    // for(int i=0;((i*2+1) && (i*2+2))<numbersSize;i++){
        
    // }
}
