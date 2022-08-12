#include <iostream>
using namespace std;

// my aproach
int gcdDivision(int greaterNumber,int lesserNumber){
    int result =0 ;

    for(int i=1;i<lesserNumber;i++){
        if(lesserNumber%i==0 && greaterNumber%i==0)
            result=i;
    }

    return result;
}

// my aproach
int gcdSubtraction(int greaterNumber,int lesserNumber){
    while(greaterNumber-lesserNumber>0){
            greaterNumber-=lesserNumber;
    }
    
    return greaterNumber;
}


// my aproach
int gcdRec(int greaterNumber,int lesserNumber){
    
    if(greaterNumber-lesserNumber<=0)
        return greaterNumber;
    
    gcdRec(greaterNumber-lesserNumber,lesserNumber);
  
}


int main(){
    int n1 = 18,n2=8;
    
    cout<<gcdDivision(n1,n2)<<endl;
    
    cout<<gcdSubtraction(n1,n2)<<endl;

    cout<<gcdRec(n1,n2)<<endl;
    
    
}