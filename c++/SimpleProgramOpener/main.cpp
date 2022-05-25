#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    constexpr char menu_item1[]="Start";
    constexpr char menu_item2[]="Settings";
    constexpr char menu_item3[]="Exit";
    const size_t MENU_SIZE=3;
    const string MENU_PRIMERY[MENU_SIZE]={menu_item1,menu_item2,menu_item3};
    
    constexpr char file[]="my.txt";
    
    ifstream input_file(file);
    ofstream output_file;

    if(!input_file.is_open()){
        cout<<"File doesnt exists"<<endl;
        output_file.open(file);
    }
    
}