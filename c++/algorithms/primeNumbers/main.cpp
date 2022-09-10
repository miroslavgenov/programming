#include <iostream>

class MyException;

bool is_number_not_devidible(int );
bool is_number_valid_and_greater(int *);
bool is_number_prime(int *);
bool is_number_greater_than_two(int *);
bool is_number_valid_and_greater(int *);

int main(){
	
	// int *number=new int(11);
	// std::cout<<is_number_prime(number);
	for(int i=0;i<5;i++){
		std::cout<<i<<std::endl;
	}
}



class MyException{
	private:
		std::string error_message;
		int error_number;

	public:
		MyException(int,std::string);
		MyException();
		std::string what()const;
		int get_error_number()const;
		std::string get_error_message()const;
		//#TODO: add ostream operator overload to print the error
};

MyException::MyException(int _error_number,std::string _error_message):error_number(_error_number),error_message(_error_message){
}

MyException::MyException():MyException(999,"Deffault exception"){
}

int MyException::get_error_number()const{
	return error_number;
}

std::string MyException::get_error_message()const{
	return error_message;
}

std::string MyException::what()const{
	return std::to_string(get_error_number())+" "+get_error_message();
}


bool is_number_not_devidible(int source_number){
	
	for(int number_increment=2;number_increment<source_number;number_increment++)
		if(source_number%number_increment==0) return false;
		
	return true;
}

bool is_number_greater_than_two(int *source_number){
	try{
		if( *source_number<2) throw MyException(2,"is_number_less_than_requared yes");
		else return true;
	}catch(MyException e){
		std::cout<<e.what()<<std::endl;
		return false;
	}
	return true;
}

bool is_number_not_nullptr(int *source_number){
	try{	
		if(source_number==nullptr) throw MyException(0,"is_number_valid no");
		else return true;
	}catch(MyException e){
		std::cout<<e.what()<<std::endl;
		return false;
	}
	return true;
}

bool is_number_valid_and_greater(int *source_number){
	if(is_number_not_nullptr(source_number))
		if(is_number_greater_than_two(source_number))return true;
			
	return false;
	
}

bool is_number_prime(int *source_number){
	if(is_number_valid_and_greater(source_number) && is_number_not_devidible(*source_number))
		return true;	
			
	return false;
}













































