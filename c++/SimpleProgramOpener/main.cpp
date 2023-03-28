#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



vector<string> initialize_menu(const string[],const size_t);

template <typename T>
void add_item_in_menu(vector<T> *source_menu,T new_item){
    source_menu->push_back(new_item);
}

template<typename T>
const int get_menu_size(vector<T> source_menu){
    return source_menu.size();
}

/**
 * @brief Get the menu item by index number
 * 
 * @tparam T the type of data stored in the vector
 * @param source_menu Container whose valus will be accesed by the `MENU_INDEX`
 * @param MENU_INDEX Integer which will be used to access the `source_menu` index
 * @return T the values stored in the container `source_menu`
 */
template <typename T>
T get_menu_item_by_index(vector<T> source_menu,const int MENU_INDEX){
    /* TODO :    Check if the index is out of range and return exception. */
    return source_menu[MENU_INDEX];
}

/**
 * @brief Shows numbered the value in the vector 
 * 
 * @tparam T the type of data stored in the vector
 * @param src_menu Container whose value will be printed
 */
template <typename T>
void show_menu(vector<T> src_menu){
    
    for(int i=0;i<get_menu_size(src_menu);i++){
        cout<<(i+1)<<"."<<get_menu_item_by_index(src_menu,i)<<endl;
    }
}


int main(){
    // initial 
    const size_t menu_size=3;
    string menu[menu_size]={"Star","Stop","Exit"};
    vector<string> menu_primary=initialize_menu(menu,menu_size);
    show_menu(menu_primary);

    

    // const size_t MENU_LENGHT=3;
	// string primary_menu[MENU_LENGHT]={"Start","Settings","Exit"};
    // vector<string> p_menu;
    // add_items_in_menu(&p_menu,primary_menu,MENU_LENGHT);
    // show_menu(p_menu);
	
    //const size_t MENU_SIZE=3;
    //const string MENU_PRIMERY[MENU_SIZE]={menu_item1,menu_item2,menu_item3};
    //char file[]="my.txt";
    
	//ifstream input_file;
    //ofstream output_file;

    //input_file.open(file);
    
    // check if the file exists and creates new if doest
//    if(!input_file.is_open()){
//        cout<<"File doesnt exists"<<endl;
//        output_file.open(file);
//    	
//    	for(size_t i=0;i<MENU_SIZE;i++)	{
//    		if(i==2){
//    			output_file<<i+1<<"."<<MENU_PRIMERY[i];	
//			}else{
//				output_file<<i+1<<"."<<MENU_PRIMERY[i]<<endl;		
//			}
//			
//			
//		}
//	}
//	input_file.close();
//	
//	input_file.open(file);
//	
//	
//	ifstream iffile("my.txt");
//	
//	if(input_file.is_open()){
//		string line;
//		while(getline(input_file,line)){
//			cout<<line<<endl;
//		}
//		
//		
//	}
//	
	
	
	
	


    // this will append the text in the file without removing it
	//output_file.open(file,ios_base::app);
    //output_file<<"hello";
    
	
    
}

vector<string> initialize_menu(const string SOURCE_MENU[],const size_t SOURCE_MENU_LENGHT){
    vector<string> menu;
    for(size_t i=0;i<SOURCE_MENU_LENGHT;i++){
        menu.push_back(SOURCE_MENU[i]);
    }
    return menu;
}