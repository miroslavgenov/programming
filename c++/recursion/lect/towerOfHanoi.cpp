#include <iostream>
using namespace std;



///........................
void towerOfHanoi(int n,int left,int mid,int right){
    int l=left,m=mid,r=right;
    
    if(n==1){
        cout<<"Premesti "<<n<< " na disk "<< right<<endl;
    }else{
        towerOfHanoi(n-1,l,m,r);
        cout<<"Premesti "<<n<<" ot" <<l << " na disk "<< right<<endl;
        towerOfHanoi(n-1,m,l,r);

    }
    

        
   


        

    

}

int main(){
    towerOfHanoi(3,1,2,3);
    


}