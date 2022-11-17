#include <iostream>
#include "/home/home/Desktop/programming/c++/dataStructures/Stack/include/Stack.cpp"

using namespace std;

int main(){
    Stack<int*>  *s = new Stack(new int{5});
    s->push(new int{4});

    cout<<s<<endl;
    
    
}