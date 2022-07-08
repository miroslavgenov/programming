#include <iostream>
#include "student.h"

Student::Student(std::string _name):name(_name){
}

Student::Student():Student("Default"){
}

std::string Student::get_name()const{
	return name;
}

void Student::set_next_student(Student * source){
	next=source;
}
Student* Student::get_next_student()const{
	if(next==nullptr)
		return nullptr;
	return next;
	
	}

void Student::set_prev_student(Student* source){
	prev=source;
}
Student* Student::get_prev_student()const{
	if(prev==nullptr)
		return nullptr;
	return prev;
	
}























