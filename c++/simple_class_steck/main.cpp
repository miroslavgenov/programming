#include <iostream>
#include "student.cpp"

int main(){
    Student *list[5] = {
		new Student("Ivan"),
		new Student("Alex"),
		new Student("Jotaro"),
		new Student("Dio"),
		new Student("Jiorno")
	}; 
	
	for(int i=0;i<5;i++){
		if(i==0) {
			list[i]->set_prev_student(nullptr);
			list[i]->set_next_student(list[i+1]);
			continue;
		}
		else if(i==4){
			list[i]->set_next_student(nullptr);
			list[i]->set_prev_student(list[i-1]);
			break;
		}
		list[i]->set_next_student(list[i+1]);
		list[i]->set_prev_student(list[i-1]);
	}
	
	for(auto item:list){
		std::cout<<"Current student: "<<item->get_name()<<std::endl;
		
		if(item->get_prev_student()==nullptr)std::cout<<"prev null"<<std::endl;
		else std::cout<<"Prev: "<<item->get_prev_student()->get_name()<<std::endl;
		
		if(item->get_next_student()==nullptr) std::cout<<"next null"<<std::endl;
		else std::cout<<"Next: "<<item->get_next_student()->get_name()<<std::endl;
	}
	
	
	
//	Student *s1=new Student("Ivan");
//	Student *s2= new Student("Alex");
//	Student *s3 = new Student("Jotaro");
//	Student *s4 = new Student("Dio");
//	Student *s5 = new Student("Jiorno");
    
    
	
}
















