#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    // initial 
    char menu_item1[]="Start";
    char menu_item2[]="Settings";
    char menu_item3[]="Exit";
    const size_t MENU_SIZE=3;
    const string MENU_PRIMERY[MENU_SIZE]={menu_item1,menu_item2,menu_item3};
    char file[]="my.txt";
    
	ifstream input_file;
    ofstream output_file;

    input_file.open(file);
    
    // check if the file exists and creates new if doest
    if(!input_file.is_open()){
        cout<<"File doesnt exists"<<endl;
        output_file.open(file);
    	
    	for(size_t i=0;i<MENU_SIZE;i++)	{
    		if(i==2){
    			output_file<<i+1<<"."<<MENU_PRIMERY[i];	
			}else{
				output_file<<i+1<<"."<<MENU_PRIMERY[i]<<endl;		
			}
			
			
		}
	}
	input_file.close();
	
	input_file.open(file);
	
	
	ifstream iffile("my.txt");
	
	if(input_file.is_open()){
		string line;
		while(getline(input_file,line)){
			cout<<line<<endl;
		}
		
		
	}
	
	
	
	
	


    // this will append the text in the file without removing it
	//output_file.open(file,ios_base::app);
    //output_file<<"hello";
    
	
    
}






































