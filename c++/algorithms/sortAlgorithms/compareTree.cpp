#include <iostream>
using namespace std;

void compareTree(int x,int y ,int z){
    if(x<y){
        if(y<z){
            cout<<x<<" "<<y<<" "<<z<<endl;
        }else if(y>z){
            if(x<z){
                cout<<x<<" "<<z<<" "<<y<<endl;
            }else if(x>z){
                cout<<z<<" "<<x<<" "<<y<<endl;
            }
        }
    }else if(x>y){
        if(x>z){
            if(y>z){
                cout<<z<<" "<<y<<" "<<x<<endl;
            }else if(y<z){
                cout<<y<<" "<<z<<" "<<x<<endl;
            }
        }else if(x<z){
            cout<<y<<" "<<x<<" "<<z<<endl;
        }
    }
}

int main(){
    int x=3,y=2,z=5;
    
    compareTree(x,y,z);
}
