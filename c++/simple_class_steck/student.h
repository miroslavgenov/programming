#pragma once
#include <iostream>

class Student{
    private:
        Student *next=nullptr;
		Student *prev=nullptr;
        std::string name;
        static int size;
    public:
        Student();
        Student(std::string);
		std::string get_name()const;
		void set_next_student(Student *);
		void set_prev_student(Student *);
		Student* get_next_student()const;
		Student* get_prev_student()const;

};











