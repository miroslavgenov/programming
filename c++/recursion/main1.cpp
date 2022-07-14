#include <iostream>
#include <cstring>
using namespace std;

int calculate1(int number,int decrement){
    if(decrement==0){
        return number;
    }
    number+=decrement;
    calculate1(number,--decrement);
}

void reverse_msg(){
    char m;
    cin>>m;
	if(m == '.'){
        return ;
    }
    
    reverse_msg();
    cout<<m<<endl;


    
}
 
int factorial(int n){
    if(n==0) return 0;
    cout<< n*factorial(n-1)<<endl;
}

int fib(int num){
    int prev=0;
    int next=1;
    int temp;
    cout<<prev<<" ";
    for(size_t inc=0;inc<10;inc++){
        temp = prev+next;
        prev=next;
        cout<<next<<" ";
        next=temp;
    }
}

void fib_rec(int num,int prev=0,int next=1){
	if(num==0) return;
	int temp=prev+next;
	prev=next;
	cout<<next<<endl;
	next=temp;
	fib_rec(--num,prev,next);
}

int number_fix=0;
int exer1(int n){
    if(n==0) return n;
    
	exer1(--n);
    cout<<n<<" ";
    if(number_fix-1==n) cout<<n+1<<" ";
}

void ex2(int n){
	if(n==-1)return;
	cout<<n<<" ";
	ex2(--n);
}
void ex3(int n){
	if(n==0)	return;
	cout<<n<<" ";
	n--;
	ex3(n);
	cout<<n<<' ';
	if(n==4)cout<<(n=5)<<" ";
}

void ex4(int n,int c=0){
	if(c==n){return;
	}
	cout<<c<<" ";
	ex4(n,++c);
	cout<<c<<" ";
	if(c==1){
		c=0;
		cout<<c<<" ";
	}
}

int main(){
    //cout<<calculate1(0,2)<<endl;
    //reverse_msg();
    //cout<<"!!!"<<factorial(5);
//    fib(5);
	// fib_rec(10);
//    ::number_fix=5;
//	exer1(5);
	int num=5;
//	ex2(num);
ex3(num);
//ex4(5);
    
}






















