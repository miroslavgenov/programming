#include <iostream>
#include "student.cpp"

void show(Student *list[],const int SIZE){
	for(int i=0;i<SIZE;i++){
		std::cout<<"Current student: "<<list[i]->get_name()<<std::endl;
		
		if(list[i]->get_prev_student()==nullptr)std::cout<<"prev null"<<std::endl;
		else std::cout<<"Prev: "<<list[i]->get_prev_student()->get_name()<<std::endl;
		
		if(list[i]->get_next_student()==nullptr) std::cout<<"next null"<<std::endl;
		else std::cout<<"Next: "<<list[i]->get_next_student()->get_name()<<std::endl;
	}
}


int main(){
	constexpr int SIZE=5;
    Student *list[SIZE] = {
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
	
	show(list,SIZE);
	
	
	
//	Student *s1=new Student("Ivan");
//	Student *s2= new Student("Alex");
//	Student *s3 = new Student("Jotaro");
//	Student *s4 = new Student("Dio");
//	Student *s5 = new Student("Jiorno");
    
    
	
}
















