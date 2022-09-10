#include <iostream>
using namespace std;

void row(int n){
    if(n==-1)return;
    row(n-1);
    cout<<n<<" ";
}
void rec2(int n){
    if(n==-1)return;
    cout<<n<<" ";
    rec2(n-1);
}

void rec3(int n){
    row(n);
    rec2(--n);
}

void rec4(int zero,int to){
    if(zero==to+1)return;
    
    cout<<zero<<" ";
    
    if(zero<to){
        rec4(zero+1,to);
        cout<<zero<<" ";
    }
    
}

void rec5(int n){
    if(n==-1)return;
    
    cout<<n<<" ";
    
    if(n!=0){
        rec5(n-1);
        cout<<n<<" ";
    }
}




int main(){
    row(5);
    cout<<endl;
    rec2(5);
    cout<<endl;
    rec3(5);
    cout<<endl;
    rec4(0,5);
    cout<<endl;
    rec5(5);
    cout<<endl;
}