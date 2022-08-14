#include <iostream>
using namespace std;
#define throw(MyException)
class MyException{
public:
MyException(){}
string what(){
	return "MyException.hello()";
}
};
void hello()throw (int){
	if(1<2){throw 1;}
}
int main(){
try{
hello();}catch(MyException e){cout<<e.what()<<endl;}
}
