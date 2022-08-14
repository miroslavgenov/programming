#include <iostream>
using namespace std;

int number;

void row(int n,int x){
    
    if(n==x)return;
    
    cout<<n<<" ";
    
    row(n-1,x);
    
    if(x!=n-1){
        cout<<n<<" ";
    }
    
}

void cow(int n,int x){
    
    if(n==number && n==x+1)cout<<n<<endl;
    
    if(x==0)return;
    
    row(n,x-1);
    cout<<endl;
    cow(n,x-1);
    
    if(x!=1){
        row(n,x-1);
        cout<<endl;

        if(n==number && n==x+1){
            cout<<n<<endl;
        }
    }
}

void row1(int x,int n){
    
    if(x==n){
        return;
    }
    cout<<x<<" ";
    row1(x+1,n);
    
    if(x+1!=n){
        cout<<x<<" ";
    }  
}

void cow1(int n,int stop)
{

    if(n==stop){
        return;
    }
    
    row1(1,n+1);
    
    cout<<endl;
    
    cow1(n+1,stop);
    
    if(n!=stop-1){
        row1(1,n+1);
        cout<<endl;
    }

    
}


int main(){
    ::number=5;
    cow1(1,::number);
}