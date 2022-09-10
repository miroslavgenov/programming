#include <iostream>
using namespace std;

void reverseCharInput(){
    char input;
    cin>>input;
    if(input=='0'){return;}
    reverseCharInput();
    cout<<input<<" ";
}

int main(){
    reverseCharInput();
}