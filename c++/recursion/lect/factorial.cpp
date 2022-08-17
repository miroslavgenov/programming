#include <iostream>

using namespace std;

int fact=1;

class Number{
    public:
        Number(int _number):number(_number){}

        Number():Number(6){}
        
        int getFactorialNumber(){
            for(int i=1;i<=getNumber();i++){
                multiplayFactorial(i);
            }
            return getFactorial();
        }

        int getNumber()const{return number;}
        
        void setNumber(const int value){
            number=value;
        }

    private:
        int number;
        int factorial = 1;
        
        int multiplayFactorial(int value){
            setFactorial(getFactorial()*value);
        }

        int  getFactorial()const{return factorial;}

        void setFactorial(int value){
            factorial = value;
        }        
};


void factorialRec(int number,int fac){
    
    if(number==0){
        return ;
    }
    cout<<"fac: "<<fac<<" number: "<<number<<endl;
    
    fac*=number;
    fact=fac;
    factorialRec(number-1,fac);
}

int main(){
    // Number *number=new Number(4);
    // cout<<number->getFactorialNumber()<<endl;
   factorialRec(4,1);
   cout<<fact<<endl;
}