#include <iostream>
using namespace std;
int b(int n){
    if (n==0) {
        cout<<endl<<n<<" returing from b"<<endl;
        return 1;
        }
    cout<<"b: "<<n<<endl;
    return b(n-1);
    
}

int a(int n){
    if(n==0){
        cout<<endl<<n<<" returing from a"<<endl;
        return 1;}
    cout<<"a: "<<n<<endl;
    return a(n-1)+b(n-1);


}


int fibonaci(int n){
    if(n<=2)return 1;
     return fibonaci(n-1)+fibonaci(n-2);
}

// void fibonaci(int n,int prev,int next){
//     int num=n;
    
//     if(num==0){return;}
//     cout<<next<<" ";
    
//     int current = next;
//     next= current+prev;
//     prev = current;
    
    
//     fibonaci(num-1,prev,next);
    
    
// }



int main(){
    int prev=0;
    int current = 1;
    a(5);
    //  cout<<fibonaci(12);
    // fibonaci(12,0,1);
    // for(int i=0;i<10;i++){
    //     int next = prev+current;
    //     cout<<current<<" "<<endl;
    //     prev=current;
    //     current=next;
    // }

    
}